#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"
#include <numeric>

ClassImp(dataProducts::NaluWaveform);

using namespace dataProducts;

NaluWaveform::NaluWaveform() : DataProduct() {}

NaluWaveform::~NaluWaveform() {}

void NaluWaveform::buildFromPackets(const NaluPacketCollection& nalu_packets) {
    trace.clear();

    if (nalu_packets.empty()) return;

    channel_num = nalu_packets.front().header.channel;

    // Step 1: Extract (window_position, packet) pairs
    std::vector<std::pair<uint16_t, const NaluPacket*>> ordered_packets;
    ordered_packets.reserve(nalu_packets.size());

    for (const auto& pkt : nalu_packets) {
        ordered_packets.emplace_back(pkt.header.window_position, &pkt);
    }

    // Step 2: Sort by raw window_position (modulo semantics allow direct comparison)
    std::sort(ordered_packets.begin(), ordered_packets.end(),
              [](const auto& a, const auto& b) {
                  return a.first < b.first;
              });

    // Step 3: Detect rollover pivot (first backward jump)
    size_t pivot_idx = 0;
    for (size_t i = 1; i < ordered_packets.size(); ++i) {
        if (ordered_packets[i].first < ordered_packets[i - 1].first) {
            pivot_idx = i;
            break;
        }
    }

    // Step 4: Reorder to correct for rollover
    std::vector<const NaluPacket*> final_order;
    final_order.reserve(ordered_packets.size());
    for (size_t i = 0; i < ordered_packets.size(); ++i) {
        final_order.push_back(ordered_packets[(pivot_idx + i) % ordered_packets.size()].second);
    }

    // Step 5: Pre-allocate trace
    constexpr size_t samples_per_packet = 32;  // magic number
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
