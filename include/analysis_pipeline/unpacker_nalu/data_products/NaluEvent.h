#ifndef NALUEVENT_HH
#define NALUEVENT_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include "analysis_pipeline/unpacker_nalu/data_products/NaluEventHeader.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacketCollection.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluEventFooter.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluWaveformCollection.h"

#include <vector>
#include <sstream>
#include <iostream>

namespace dataProducts {

class NaluEvent : public TObject {
public:
    NaluEvent();
    ~NaluEvent();

    NaluEventHeader header;
    NaluPacketCollection packets;
    NaluEventFooter footer;
    NaluWaveformCollection waveforms;

    void BuildWaveformsFromPackets();

    void Print(Option_t* option = "") const;
    void Show() const;

    ClassDefOverride(NaluEvent,1)
};

} // namespace dataProducts

#endif // NALUEVENT_HH
