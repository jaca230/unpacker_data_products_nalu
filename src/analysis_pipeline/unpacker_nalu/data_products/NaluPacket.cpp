#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacket.h"

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
    oss << header.String();
    oss << payload.String();
    oss << footer.String();
    return oss.str();
}

void NaluPacket::Show() const {
    std::cout << this->String();
}
