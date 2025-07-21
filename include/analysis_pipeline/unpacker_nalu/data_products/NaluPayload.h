#ifndef NALUPAYLOAD_HH
#define NALUPAYLOAD_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include <vector>
#include <sstream>
#include <iostream>

namespace dataProducts {

class NaluPayload : public DataProduct {
public:
    NaluPayload();
    ~NaluPayload();

    std::vector<uint16_t> trace;

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluPayload,1)
};

} // namespace dataProducts

#endif // NALUPAYLOAD_HH
