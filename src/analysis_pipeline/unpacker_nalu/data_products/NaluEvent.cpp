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

    for (const auto& pkt : packets.GetPackets()) {
        channel_to_packet_ptrs[pkt.header.channel].push_back(&pkt);
    }

    // Build waveforms per channel
    for (auto& [channel, pkt_ptrs] : channel_to_packet_ptrs) {
        NaluWaveform wf;
        wf.buildFromPackets(pkt_ptrs);
        waveforms.AddWaveform(std::move(wf));
    }
}

std::string NaluEvent::String() const {
    std::ostringstream oss;
    oss << "\nNaluEvent:\n";
    for (const auto& pkt : packets.GetPackets()) {
        oss << pkt.String();
    }
    return oss.str();
}

void NaluEvent::Show() const {
    std::cout << this->String();
}
