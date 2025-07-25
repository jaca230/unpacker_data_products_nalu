#ifndef NALUTIME_HH
#define NALUTIME_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluTimeData.h"

#include <TObject.h>

namespace dataProducts {

class NaluTime : public DataProduct {
public:
    NaluTime();
    ~NaluTime();

    NaluTimeData time;

    void Print(Option_t* option = "") const override;
    void Show() const override;

    ClassDefOverride(NaluTime, 1);
};

}  // namespace dataProducts

#endif  // NALUTIME_HH
