#ifndef NALUWAVEFORMCOLLECTION_HH
#define NALUWAVEFORMCOLLECTION_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"
#include <vector>

namespace dataProducts {

class NaluWaveformCollection : public DataProduct {
public:
    NaluWaveformCollection();
    ~NaluWaveformCollection();

    void AddWaveform(NaluWaveform&& wf);
    void SetWaveforms(std::vector<NaluWaveform>&& new_waveforms);

    void Clear();
    void Print(Option_t* option = "") const override;
    void Show() const override;

    // now public for PyROOT access
    std::vector<NaluWaveform> waveforms;

    ClassDefOverride(NaluWaveformCollection, 1);
};

} // namespace dataProducts

#endif // NALUWAVEFORMCOLLECTION_HH
