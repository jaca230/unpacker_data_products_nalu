#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketCollection.h"
#include <iostream>

ClassImp(dataProducts::NaluPacketCollection)

namespace dataProducts {

NaluPacketCollection::NaluPacketCollection() = default;
NaluPacketCollection::~NaluPacketCollection() = default;

void NaluPacketCollection::AddPacket(NaluPacket&& pkt) {
    packets.emplace_back(std::move(pkt));
}

void NaluPacketCollection::SetPackets(std::vector<NaluPacket>&& new_packets) {
    packets = std::move(new_packets);
}

const std::vector<NaluPacket>& NaluPacketCollection::GetPackets() const {
    return packets;
}

void NaluPacketCollection::Clear() {
    packets.clear();
}

void NaluPacketCollection::Print(Option_t*) const {
    std::cout << "NaluPacketCollection with " << packets.size() << " packet(s)" << std::endl;
}

} // namespace dataProducts
