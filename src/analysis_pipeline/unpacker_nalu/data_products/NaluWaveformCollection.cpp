#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveformCollection.h"
#include <iostream>

ClassImp(dataProducts::NaluWaveformCollection)

namespace dataProducts {

NaluWaveformCollection::NaluWaveformCollection() = default;
NaluWaveformCollection::~NaluWaveformCollection() = default;

void NaluWaveformCollection::AddWaveform(NaluWaveform&& wf) {
    waveforms.emplace_back(std::move(wf));
}

void NaluWaveformCollection::SetWaveforms(std::vector<NaluWaveform>&& new_waveforms) {
    waveforms = std::move(new_waveforms);
}

void NaluWaveformCollection::Clear() {
    waveforms.clear();
}

void NaluWaveformCollection::Print(Option_t*) const {
    std::cout << "NaluWaveformCollection with " << waveforms.size() << " waveform(s)" << std::endl;
}

void NaluWaveformCollection::Show() const {
    Print();
}

} // namespace dataProducts
