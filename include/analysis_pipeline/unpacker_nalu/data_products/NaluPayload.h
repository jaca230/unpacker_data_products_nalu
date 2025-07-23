#ifndef NALUPAYLOAD_HH
#define NALUPAYLOAD_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <array>
#include <string>

namespace dataProducts {

class NaluPayload : public DataProduct {
public:
    NaluPayload();
    ~NaluPayload();

    std::array<uint16_t, 32> trace;

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluPayload, 1)
};

} // namespace dataProducts

#endif // NALUPAYLOAD_HH
