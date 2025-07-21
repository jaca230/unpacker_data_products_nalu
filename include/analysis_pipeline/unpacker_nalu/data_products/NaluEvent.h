#ifndef NALUEVENT_HH
#define NALUEVENT_HH

#include "analysis_pipeline/unpacker_nalu/data_products/NaluEventHeader.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacket.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluEventFooter.h"
#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include <vector>
#include <sstream>
#include <iostream>

namespace dataProducts {

class NaluEvent : public DataProduct {
public:
    NaluEvent();
    ~NaluEvent();

    NaluEventHeader header;
    std::vector<NaluPacket> packets;
    NaluEventFooter footer;

    std::string String() const;
    void Show() const override;

    ClassDefOverride(NaluEvent,1)
};

using NaluEventCollection = std::vector<NaluEvent>;

} // namespace dataProducts

#endif // NALUEVENT_HH
