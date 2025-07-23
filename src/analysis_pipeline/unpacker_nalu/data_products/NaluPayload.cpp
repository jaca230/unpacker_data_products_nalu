#include "analysis_pipeline/unpacker_nalu/data_products/NaluPayload.h"
#include <iostream>
#include <sstream>

ClassImp(dataProducts::NaluPayload);

using namespace dataProducts;

NaluPayload::NaluPayload()
    : DataProduct()
    , trace{}
{}

NaluPayload::~NaluPayload() {}

std::string NaluPayload::String() const {
    std::ostringstream oss;
    oss << "NaluPayload: trace = [";
    for (size_t i = 0; i < trace.size(); ++i) {
        oss << trace[i];
        if (i != trace.size() - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}

void NaluPayload::Show() const {
    std::cout << this->String() << std::endl;
}
