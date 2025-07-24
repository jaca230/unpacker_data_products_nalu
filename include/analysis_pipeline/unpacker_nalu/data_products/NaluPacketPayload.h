#ifndef NALUPACKETPAYLOAD_HH
#define NALUPACKETPAYLOAD_HH

#include <array>
#include <cstdint>
#include <TObject.h>

namespace dataProducts {

struct NaluPacketPayload {
    std::array<uint16_t, 32> trace;

    ClassDef(NaluPacketPayload, 1);
};

} // namespace dataProducts

#endif // NALUPACKETPAYLOAD_HH
