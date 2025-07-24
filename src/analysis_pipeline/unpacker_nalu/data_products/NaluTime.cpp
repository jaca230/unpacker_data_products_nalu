#include "analysis_pipeline/unpacker_nalu/data_products/NaluTime.h"

ClassImp(dataProducts::NaluTime);

using namespace dataProducts;

/**
 * @brief Default constructor for NaluTime.
 *
 * Initializes the event footer to 0.
 */
NaluTime::NaluTime()
    : DataProduct()
    ,collection_cycle_index(0)
    ,collection_cycle_timestamp_ns(0)
    ,udp_time(0)
    ,parse_time(0)
    ,event_time(0)
    ,total_time(0)
    ,data_processed(0)
    ,data_rate(0)
{}

/**
 * @brief Destructor for NaluTime.
 */
NaluTime::~NaluTime() {}

/**
 * @brief Make a string of the contents of the class
 *
 * Displays the event footer value in hexadecimal format.
 */
std::string NaluTime::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "NaluTime: " << std::endl;
    oss << "    collection_cycle_index:         " << collection_cycle_index << std::endl;
    oss << "    collection_cycle_timestamp_ns:  " << collection_cycle_timestamp_ns << std::endl;
    oss << "    udp_time:                       " << udp_time << std::endl;
    oss << "    parse_time:                     " << parse_time << std::endl;
    oss << "    event_time:                     " << event_time << std::endl;
    oss << "    total_time:                     " << total_time << std::endl;
    oss << "    data_processed:                 " << data_processed << std::endl;
    oss << "    data_rate:                      " << data_rate << std::endl;
    return oss.str();
}

/**
 * @brief Print the contents of the NaluTime to standard output.
 *
 * Displays the class as a string
 */
void NaluTime::Show() const { 
    std::cout << this->String();
}