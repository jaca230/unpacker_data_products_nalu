#ifndef NALUWAVEFORM_HH 
#define NALUWAVEFORM_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacket.h"

#include <vector>
#include <string>

namespace dataProducts {

class NaluWaveform : public DataProduct {
public:
    NaluWaveform();
    ~NaluWaveform();

    void buildFromPackets(const std::vector<const NaluPacket*>& packets);

    uint64_t channel_num = 0;
    std::vector<short> trace;

    // New member: samples per packet, default 32
    size_t samples_per_packet = 32;

    void Print(Option_t* option = "") const override;
    void Show() const override;

    ClassDefOverride(NaluWaveform, 1)
};


} // namespace dataProducts

#endif // NALUWAVEFORM_HH
