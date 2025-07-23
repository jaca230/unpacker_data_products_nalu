#ifndef NALU_PACKET_PAYLOAD_HH
#define NALU_PACKET_PAYLOAD_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <array>
#include <string>

namespace dataProducts {

class NaluPacketPayload : public DataProduct {
public:
    NaluPacketPayload();
    ~NaluPacketPayload();

    std::array<uint16_t, 32> trace;

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluPacketPayload, 1)
};

} // namespace dataProducts

#endif // NALU_PACKET_PAYLOAD_HH
