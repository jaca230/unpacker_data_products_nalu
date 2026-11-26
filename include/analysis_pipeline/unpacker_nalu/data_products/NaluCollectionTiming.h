#pragma once
#include <TObject.h>
#include <cstdint>

namespace dataProducts {
class NaluCollectionTiming : public TObject {
  public:
    uint16_t version = 1;
    uint64_t cycle_id = 0, start_ns = 0, end_ns = 0;
    uint64_t input_events = 0, input_packets = 0;
    uint64_t output_events = 0, output_packets = 0;
    uint64_t processing_ns = 0, flags = 0;
    ClassDefOverride(NaluCollectionTiming, 1);
};
} // namespace dataProducts
