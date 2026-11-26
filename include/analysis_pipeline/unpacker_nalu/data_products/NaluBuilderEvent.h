#pragma once
#include "analysis_pipeline/unpacker_nalu/data_products/NaluBuilderSource.h"
#include <TObject.h>
#include <cstdint>
#include <vector>
namespace dataProducts {
class NaluBuilderEvent : public TObject {
  public:
    uint16_t version = 1, flags = 0;
    uint64_t start_ns = 0, end_ns = 0;
    uint32_t source_events = 0, packets = 0;
    std::vector<NaluBuilderSource> sources;
    ClassDefOverride(NaluBuilderEvent, 1);
};
} // namespace dataProducts
