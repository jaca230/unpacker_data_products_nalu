#include "analysis_pipeline/unpacker_nalu/data_products/NaluTimeCollection.h"
#include <iostream>

ClassImp(dataProducts::NaluTimeCollection)

namespace dataProducts {

NaluTimeCollection::NaluTimeCollection() = default;
NaluTimeCollection::~NaluTimeCollection() = default;

void NaluTimeCollection::AddTime(NaluTime&& t) {
    times.emplace_back(std::move(t));
}

void NaluTimeCollection::SetTimes(std::vector<NaluTime>&& new_times) {
    times = std::move(new_times);
}

const std::vector<NaluTime>& NaluTimeCollection::GetTimes() const {
    return times;
}

void NaluTimeCollection::Clear() {
    times.clear();
}

void NaluTimeCollection::Print(Option_t*) const {
    std::cout << "NaluTimeCollection with " << times.size() << " time object(s)" << std::endl;
}

} // namespace dataProducts
