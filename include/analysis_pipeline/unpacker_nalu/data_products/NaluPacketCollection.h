#ifndef NALUPACKETCOLLECTION_HH
#define NALUPACKETCOLLECTION_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacket.h"
#include <TObject.h>
#include <vector>
#include <iostream>

namespace dataProducts {

class NaluPacketCollection : public DataProduct {
public:
    NaluPacketCollection() = default;
    ~NaluPacketCollection() = default;

    void AddPacket(NaluPacket&& pkt);
    void SetPackets(std::vector<NaluPacket>&& new_packets);

    void Clear();
    void Print(Option_t* option = "") const override;
    void Show() const override;

    // Exposed directly, no getter
    std::vector<NaluPacket> packets;

    ClassDefOverride(NaluPacketCollection, 1);
};

} // namespace dataProducts

#endif // NALUPACKETCOLLECTION_HH
