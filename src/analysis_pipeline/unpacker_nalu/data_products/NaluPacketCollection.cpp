#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketCollection.h"

ClassImp(dataProducts::NaluPacketCollection)

namespace dataProducts {

void NaluPacketCollection::AddPacket(NaluPacket&& pkt) {
    packets.emplace_back(std::move(pkt));
}

void NaluPacketCollection::SetPackets(std::vector<NaluPacket>&& new_packets) {
    packets = std::move(new_packets);
}

void NaluPacketCollection::Clear() {
    packets.clear();
}

void NaluPacketCollection::Print(Option_t*) const {
    std::cout << "NaluPacketCollection with " << packets.size() << " packet(s)" << std::endl;
}

void NaluPacketCollection::Show() const {
    Print();
}

} // namespace dataProducts
