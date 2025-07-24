#ifndef NALUPACKETPAYLOAD_HH
#define NALUPACKETPAYLOAD_HH

#include <array>
#include <cstdint>
#include <TObject.h>

namespace dataProducts {

#pragma pack(push, 1)
struct NaluPacketPayload {
    std::array<uint16_t, 32> trace;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // NALUPACKETPAYLOAD_HH
