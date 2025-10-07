#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"
#include <algorithm>
#include <iostream>
#include <sstream>

ClassImp(dataProducts::NaluWaveform);

using namespace dataProducts;

NaluWaveform::NaluWaveform() {}
NaluWaveform::~NaluWaveform() {}

void NaluWaveform::buildFromPackets(const std::vector<const NaluPacket*>& packets) {
    trace.clear();
    if (packets.empty()) return;

    channel_num = packets.front()->channel;

    // Pair window_position with packet pointer
    std::vector<std::pair<uint16_t, const NaluPacket*>> ordered_packets;
    ordered_packets.reserve(packets.size());
    for (const auto* pkt : packets) {
        ordered_packets.emplace_back(pkt->window_position, pkt);
    }

    // Sort by window_position
    std::sort(ordered_packets.begin(), ordered_packets.end(),
              [](const auto& a, const auto& b) { return a.first < b.first; });

    // --- Detect pivot by largest gap between consecutive window_positions ---
    size_t pivot_idx = 0;
    uint16_t max_gap = 0;
    for (size_t i = 1; i < ordered_packets.size(); ++i) {
        uint16_t prev = ordered_packets[i - 1].first;
        uint16_t curr = ordered_packets[i].first;
        uint16_t gap = static_cast<uint16_t>(curr - prev);
        if (gap > max_gap) {
            max_gap = gap;
            pivot_idx = i;
        }
    }

    // --- Reorder to start from pivot index ---
    std::vector<const NaluPacket*> final_order;
    final_order.reserve(ordered_packets.size());
    for (size_t i = 0; i < ordered_packets.size(); ++i) {
        final_order.push_back(ordered_packets[(pivot_idx + i) % ordered_packets.size()].second);
    }

    // --- Build trace with endian correction (big-endian -> little-endian) ---
    trace.reserve(samples_per_packet * final_order.size());
    for (const auto* pkt : final_order) {
        for (uint16_t be_sample : pkt->trace) {
            uint16_t le_sample = (be_sample >> 8) | (be_sample << 8);
            trace.push_back(le_sample);
        }
    }
}

void NaluWaveform::Print(Option_t* option) const {
    std::cout << "NaluWaveform: channel " << channel_num << ", samples: " << trace.size() << "\n";
    if (std::string(option) == "full") {
        std::cout << "Trace data: ";
        for (auto s : trace) std::cout << s << ", ";
        std::cout << "\n";
    }
}

void NaluWaveform::Show() const {
    Print();
}
