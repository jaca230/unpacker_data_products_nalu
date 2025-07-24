#ifndef NALUTIMECOLLECTION_HH
#define NALUTIMECOLLECTION_HH

#include "analysis_pipeline/unpacker_nalu/data_products/NaluTime.h"
#include <TObject.h>
#include <vector>

namespace dataProducts {

class NaluTimeCollection : public TObject {
public:
    NaluTimeCollection();
    ~NaluTimeCollection();

    void AddTime(NaluTime&& t);
    void SetTimes(std::vector<NaluTime>&& new_times);
    const std::vector<NaluTime>& GetTimes() const;

    void Clear();
    void Print(Option_t* option = "") const override;

    std::vector<NaluTime> times;

    ClassDefOverride(NaluTimeCollection, 1);
};

} // namespace dataProducts

#endif // NALUTIMECOLLECTION_HH
