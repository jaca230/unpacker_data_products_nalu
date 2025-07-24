#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacket.h"

ClassImp(dataProducts::NaluPacket);

using namespace dataProducts;

NaluPacket::NaluPacket()
    : DataProduct()
    , header()
    , payload()
    , footer()
{}

NaluPacket::~NaluPacket() {}

std::string NaluPacket::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "NaluPacket:" << std::endl;
    // omit printing header, payload, footer details
    return oss.str();
}

void NaluPacket::Show() const {
    std::cout << this->String();
}
