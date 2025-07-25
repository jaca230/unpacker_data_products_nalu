#include "analysis_pipeline/unpacker_nalu/data_products/NaluTime.h"

#include <iostream>

ClassImp(dataProducts::NaluTime);

namespace dataProducts {

NaluTime::NaluTime() = default;
NaluTime::~NaluTime() = default;

void NaluTime::Print(Option_t*) const {
    std::cout << "NaluTime:\n"
              << "  collection_cycle_index: " << time.collection_cycle_index << "\n"
              << "  collection_cycle_timestamp_ns: " << time.collection_cycle_timestamp_ns << "\n"
              << "  udp_time: " << time.udp_time << "\n"
              << "  parse_time: " << time.parse_time << "\n"
              << "  event_time: " << time.event_time << "\n"
              << "  total_time: " << time.total_time << "\n"
              << "  data_processed: " << time.data_processed << "\n"
              << "  data_rate: " << time.data_rate << "\n";
}

void NaluTime::Show() const {
    Print();
}

}  // namespace dataProducts
