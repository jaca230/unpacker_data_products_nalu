#include "analysis_pipeline/unpacker_nalu/data_products/NaluEvent.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"

#include <unordered_map>

ClassImp(dataProducts::NaluEvent);

using namespace dataProducts;

NaluEvent::NaluEvent()
    : DataProduct()
    , header()
    , packets()
    , footer()
{}

NaluEvent::~NaluEvent() {}

void NaluEvent::BuildWaveformsFromPackets() {
    waveforms.Clear();

    // Map channel -> vector of pointers to packets (no copies)
    std::unordered_map<uint64_t, std::vector<const NaluPacket*>> channel_to_packet_ptrs;

    for (const auto& pkt : packets.packets) {
        channel_to_packet_ptrs[pkt.channel].push_back(&pkt);
    }

    // Build waveforms per channel
    for (auto& [channel, pkt_ptrs] : channel_to_packet_ptrs) {
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

