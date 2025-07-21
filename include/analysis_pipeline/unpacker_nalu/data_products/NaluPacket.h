#ifndef NALUPACKET_HH
#define NALUPACKET_HH

#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketHeader.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPayload.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketFooter.h"
#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include <sstream>
#include <iostream>

namespace dataProducts {

class NaluPacket : public DataProduct {
public:
    NaluPacket();
    ~NaluPacket();

    NaluPacketHeader header;
    NaluPayload payload;
    NaluPacketFooter footer;

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluPacket,1)
};

typedef std::vector<NaluPacket> NaluPacketCollection;

} // namespace dataProducts

#endif // NALUPACKET_HH
