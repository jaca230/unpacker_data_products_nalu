#include "analysis_pipeline/unpacker_nalu/data_products/NaluEvent.h"

using namespace dataProducts;

NaluEvent::NaluEvent()
    : DataProduct()
    , header()
    , packets()
    , footer()
{}

NaluEvent::~NaluEvent() {}

std::string NaluEvent::String() const {
    std::ostringstream oss;
    oss << "\nNaluEvent:\n";
    oss << header.String();
    for (const auto& pkt : packets) {
        oss << pkt.String();
    }
    oss << footer.String();
    return oss.str();
}

void NaluEvent::Show() const {
    std::cout << this->String();
}
