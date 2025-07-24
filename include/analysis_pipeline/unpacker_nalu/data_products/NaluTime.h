#ifndef NALUTIME_HH
#define NALUTIME_HH

#include <cstdint>

namespace dataProducts {

#pragma pack(push, 1)
struct NaluTime {
    uint64_t collection_cycle_index;
    uint64_t collection_cycle_timestamp_ns;
    double udp_time;
    double parse_time;
    double event_time;
    double total_time;
    uint64_t data_processed;
    double data_rate;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // NALUTIME_HH
