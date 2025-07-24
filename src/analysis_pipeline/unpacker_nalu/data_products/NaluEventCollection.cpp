#include "analysis_pipeline/unpacker_nalu/data_products/NaluEventCollection.h"

ClassImp(dataProducts::NaluEventCollection)

using namespace dataProducts;

NaluEventCollection::NaluEventCollection() : DataProduct(), events_() {}

NaluEventCollection::~NaluEventCollection() {}

void NaluEventCollection::AddEvent(NaluEvent evt) {
    events_.emplace_back(std::move(evt));
}

void NaluEventCollection::Clear() {
    events_.clear();
}

const std::vector<NaluEvent>& NaluEventCollection::GetEvents() const {
    return events_;
}

std::string NaluEventCollection::String() const {
    std::ostringstream oss;
    oss << "\nNaluEventCollection:\n";
    for (const auto& evt : events_) {
        oss << evt.String();
    }
    return oss.str();
}

void NaluEventCollection::Show() const {
    std::cout << this->String();
}
