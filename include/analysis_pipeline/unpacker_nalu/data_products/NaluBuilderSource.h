#pragma once
#include "analysis_pipeline/unpacker_nalu/data_products/NaluEvent.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluTimeData.h"
#include <TObject.h>
#include <cstdint>
namespace dataProducts {
class NaluBuilderSource : public TObject {
  public:
    uint16_t board = 0;
    bool has_timing = false;
    NaluEvent event;
    NaluTimeData timing{};
    ClassDefOverride(NaluBuilderSource, 1);
};
} // namespace dataProducts
