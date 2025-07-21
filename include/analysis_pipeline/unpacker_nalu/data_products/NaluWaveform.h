#ifndef NALUWAVEFORM_HH 
#define NALUWAVEFORM_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_nalu/data_products/NaluPacket.h"

namespace dataProducts {

    class NaluWaveform : public DataProduct {

        public:

            NaluWaveform();
            ~NaluWaveform();

            void buildFromPackets(const NaluPacketCollection& packets);

            uint64_t channel_num = 0;
            std::vector<short> trace;

            std::string String() const;
            void Show() const override;

            ClassDefOverride(NaluWaveform, 1)
    };

    typedef std::vector<NaluWaveform> NaluWaveformCollection;

} // namespace dataProducts

#endif // NALUWAVEFORM_HH
