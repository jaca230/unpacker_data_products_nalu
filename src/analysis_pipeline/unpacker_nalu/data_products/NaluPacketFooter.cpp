#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketFooter.h"

using namespace dataProducts;

NaluPacketFooter::NaluPacketFooter()
    : DataProduct(),
    parser_index(0),
    packet_footer(0)
{}

NaluPacketFooter::~NaluPacketFooter() {};

std::string NaluPacketFooter::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "NaluPacketFooter: " << std::endl;
    oss << "    parser_index: " << std::dec << parser_index << std::endl;
    oss << "    packet_footer: " << std::hex << "0x" << packet_footer << std::endl;
    return oss.str();
}

void NaluPacketFooter::Show() const { 
    std::cout << this->String();
}