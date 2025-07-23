#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketPayload.h"
#include <iostream>
#include <sstream>

ClassImp(dataProducts::NaluPacketPayload);

using namespace dataProducts;

NaluPacketPayload::NaluPacketPayload()
    : DataProduct()
    , trace{}
{}

NaluPacketPayload::~NaluPacketPayload() {}

std::string NaluPacketPayload::String() const {
    std::ostringstream oss;
    oss << "NaluPacketPayload: trace = [";
    for (size_t i = 0; i < trace.size(); ++i) {
        oss << trace[i];
        if (i != trace.size() - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}

void NaluPacketPayload::Show() const {
    std::cout << this->String() << std::endl;
}
