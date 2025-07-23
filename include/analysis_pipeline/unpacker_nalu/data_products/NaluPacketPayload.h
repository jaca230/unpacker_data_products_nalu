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

    std::array<uint16_t, 32> trace;  // *OPTIONS={GetMethod="GetTrace"; SetMethod="SetTrace"}

    const uint16_t* GetTrace() const { return trace.data(); }

    void SetTrace(const uint8_t* buffer, size_t offset) {
        // Copy from buffer+offset into trace array
        std::memcpy(trace.data(), buffer + offset, trace.size() * sizeof(uint16_t));
    }

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluPacketPayload, 1)
};


} // namespace dataProducts

#endif // NALU_PACKET_PAYLOAD_HH
