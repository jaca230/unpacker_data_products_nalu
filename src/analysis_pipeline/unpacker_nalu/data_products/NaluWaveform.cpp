#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"
#include <algorithm>
#include <iostream>
#include <sstream>

ClassImp(dataProducts::NaluWaveform);

using namespace dataProducts;

NaluWaveform::NaluWaveform() : DataProduct() {}
NaluWaveform::~NaluWaveform() {}

void NaluWaveform::buildFromPackets(const std::vector<const NaluPacket*>& packets) {
    trace.clear();

    if (packets.empty()) return;

    channel_num = packets.front()->header.channel;

    std::vector<std::pair<uint16_t, const NaluPacket*>> ordered_packets;
    ordered_packets.reserve(packets.size());

    for (const auto* pkt : packets) {
        ordered_packets.emplace_back(pkt->header.window_position, pkt);
    }

    // Sort by window_position
    std::sort(ordered_packets.begin(), ordered_packets.end(),
              [](const auto& a, const auto& b) { return a.first < b.first; });

    // Detect rollover pivot
    size_t pivot_idx = 0;
    for (size_t i = 1; i < ordered_packets.size(); ++i) {
        if (ordered_packets[i].first < ordered_packets[i - 1].first) {
            pivot_idx = i;
            break;
        }
    }

    // Reorder to fix rollover
    std::vector<const NaluPacket*> final_order;
    final_order.reserve(ordered_packets.size());
    for (size_t i = 0; i < ordered_packets.size(); ++i) {
        final_order.push_back(ordered_packets[(pivot_idx + i) % ordered_packets.size()].second);
    }

    // Pre-allocate and build trace
    trace.reserve(samples_per_packet * final_order.size());

    for (const auto* pkt : final_order) {
        trace.insert(trace.end(), pkt->payload.trace.begin(), pkt->payload.trace.end());
    }
}

std::string NaluWaveform::String() const {
    std::ostringstream oss;
    oss << "\nNaluWaveform:\n";
    oss << "    channel_num: " << channel_num << "\n";
    oss << "    trace: ";
    for (const auto& sample : trace) {
        oss << sample << ", ";
    }
    oss << "\n";
    return oss.str();
}

void NaluWaveform::Show() const {
    std::cout << this->String();
}
