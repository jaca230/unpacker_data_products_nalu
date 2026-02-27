#include "analysis_pipeline/unpacker_nalu/data_products/NaluEvent.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"

#include <unordered_map>

ClassImp(dataProducts::NaluEvent);

using namespace dataProducts;

NaluEvent::NaluEvent()
    : header()
    , packets()
    , footer()
{}

NaluEvent::~NaluEvent() {}

void NaluEvent::BuildWaveformsFromPackets() {
    waveforms.Clear();

    // Map (channel, trigger_time) -> vector of pointers to packets (no copies)
    std::unordered_map<uint64_t, std::vector<const NaluPacket*>> grouped_packet_ptrs;
    auto make_key = [](uint8_t channel, uint32_t trigger_time) -> uint64_t {
        return (static_cast<uint64_t>(channel) << 32) |
               static_cast<uint64_t>(trigger_time);
    };

    for (const auto& pkt : packets.packets) {
        const uint64_t key = make_key(pkt.channel, pkt.trigger_time);
        grouped_packet_ptrs[key].push_back(&pkt);
    }

    // Build waveforms per (channel, trigger_time)
    for (auto& [key, pkt_ptrs] : grouped_packet_ptrs) {
        NaluWaveform wf;
        wf.buildFromPackets(pkt_ptrs);
        waveforms.AddWaveform(std::move(wf));
    }
}

void NaluEvent::Print(Option_t* option) const {
    std::cout << "NaluEvent Summary:\n";
    std::cout << "  Event Index: " << header.event_index << "\n";
    std::cout << "  Trigger time: " << header.event_reference_time << "\n";
    std::cout << "  Number of packets: " << packets.packets.size() << "\n";
    std::cout << "  Number of waveforms: " << waveforms.waveforms.size() << "\n";

    // Optionally add more verbose output if requested
    if (std::string(option) == "full") {
        std::cout << "  (Full dump not implemented yet)\n";
    }
}

void NaluEvent::Show() const {
    Print();
}
