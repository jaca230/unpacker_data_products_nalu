#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketHeader.h"

using namespace dataProducts;

NaluPacketHeader::NaluPacketHeader()
    : DataProduct()
    ,packet_header(0)
    ,packet_info(0)
    ,channel(0)
    ,trigger_time(0)
    ,logical_position(0)
    ,window_position(0)
{}

NaluPacketHeader::~NaluPacketHeader() {};

std::string NaluPacketHeader::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "NaluPacketHeader: " << std::endl;
    oss << "    packet_header:          " << std::hex << std::setw(4) << std::setfill('0') << packet_header << std::endl;
    oss << "    packet_info:            " << std::dec << packet_info << std::endl;
    oss << "    channel:                " << std::dec << channel << std::endl;
    oss << "    trigger_time:           " << std::dec << trigger_time << std::endl;
    oss << "    logical_position:       " << std::dec << logical_position << std::endl;
    oss << "    window_position:        " << std::dec << window_position << std::endl;
    return oss.str();
}

void NaluPacketHeader::Show() const { 
    std::cout << this->String();
}