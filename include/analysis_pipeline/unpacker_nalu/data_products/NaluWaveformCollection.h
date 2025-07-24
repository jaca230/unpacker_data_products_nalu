#ifndef NALUWAVEFORMCOLLECTION_HH
#define NALUWAVEFORMCOLLECTION_HH

#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveform.h"
#include <TObject.h>
#include <vector>

namespace dataProducts {

class NaluWaveformCollection : public TObject {
public:
    NaluWaveformCollection();
    ~NaluWaveformCollection();

    void AddWaveform(NaluWaveform&& wf);
    void SetWaveforms(std::vector<NaluWaveform>&& new_waveforms);
    const std::vector<NaluWaveform>& GetWaveforms() const;

    void Clear();
    void Print(Option_t* option = "") const override;

    std::vector<NaluWaveform> waveforms;

    ClassDefOverride(NaluWaveformCollection, 1);
};

} // namespace dataProducts

#endif // NALUWAVEFORMCOLLECTION_HH
