#ifndef NALUEVENTHEADER_HH
#define NALUEVENTHEADER_HH

#include <cstdint>

namespace dataProducts {

#pragma pack(push, 1)
struct NaluEventHeader {
    uint16_t event_header;
    uint8_t event_info;
    uint32_t event_index;
    uint32_t event_reference_time;
    uint32_t time_threshold;
    uint32_t event_completion_time_us;
    uint32_t clock_frequency;
    uint16_t packet_size;
    uint64_t channel_mask;
    uint8_t num_windows;
    uint16_t num_packets;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // NALUEVENTHEADER_HH
