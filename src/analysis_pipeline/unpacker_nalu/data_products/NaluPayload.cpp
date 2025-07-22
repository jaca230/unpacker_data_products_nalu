#include "analysis_pipeline/unpacker_nalu/data_products/NaluPayload.h"

ClassImp(dataProducts::NaluPayload);

using namespace dataProducts;

NaluPayload::NaluPayload()
    : DataProduct()
    , trace()
{}

NaluPayload::~NaluPayload() {}

std::string NaluPayload::String() const {
    std::ostringstream oss;
    oss << "NaluPayload: trace.size() = " << trace.size() << std::endl;
    // Optionally print first N elements, or summary stats if trace too large
    return oss.str();
}

void NaluPayload::Show() const {
    std::cout << this->String();
}
