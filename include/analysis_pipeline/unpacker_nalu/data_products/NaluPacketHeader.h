#ifndef NALUPACKETHEADER_HH
#define NALUPACKETHEADER_HH

#include <cstdint>
#include <TObject.h>
#include <array>

namespace dataProducts {

#pragma pack(push, 1)
struct NaluPacketHeader {
    uint16_t packet_header;
    uint8_t packet_info;
    uint8_t channel;
    uint32_t trigger_time;
    uint16_t logical_position;
    uint16_t window_position;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // NALUPACKETHEADER_HH
