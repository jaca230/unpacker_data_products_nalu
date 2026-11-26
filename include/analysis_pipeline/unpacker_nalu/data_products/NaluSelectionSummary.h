#pragma once
#include <TObject.h>
#include <cstdint>
#include <string>
namespace dataProducts {
class NaluSelectionSummary : public TObject {
  public:
    uint16_t version = 1;
    uint64_t cycle_id = 0;
    std::string id;
    bool enabled = false;
    int32_t priority = 0;
    uint64_t evaluated_events = 0, modified_events = 0;
    uint64_t evaluated_packets = 0, removed_packets = 0;
    ClassDefOverride(NaluSelectionSummary, 1);
};
} // namespace dataProducts
