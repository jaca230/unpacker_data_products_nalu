#ifndef NALUEVENTCOLLECTION_HH
#define NALUEVENTCOLLECTION_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluEvent.h"

#include <vector>
#include <ostream>

namespace dataProducts {

class NaluEventCollection : public DataProduct {
public:
    NaluEventCollection();
    ~NaluEventCollection();

    void AddEvent(NaluEvent evt);
    void Clear();
    const std::vector<NaluEvent>& GetEvents() const;

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluEventCollection, 1);

private:
    std::vector<NaluEvent> events_;
};

}  // namespace dataProducts

#endif  // NALUEVENTCOLLECTION_HH
