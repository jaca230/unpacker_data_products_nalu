#ifndef NALUWAVEFORM_HH 
#define NALUWAVEFORM_HH

#include "data_products/common/DataProduct.h"
#include "data_products/nalu/NaluPacket.h"

namespace dataProducts {


    /**
     * @class NaluWaveform
     * @brief Represents the waveform information for a NALU event.
     *
     * Inherits from DataProduct. Stores the waveforms.
     */
    class NaluWaveform : public DataProduct {

        public:

            /**
             * @brief Default constructor.
             */
            NaluWaveform();

            /**
             * @brief Constructor with nalu packets.
             * @param nalu_packets A collection of nalu packets
             */
            NaluWaveform(NaluPacketCollection nalu_packets);

            /**
             * @brief Destructor.
             */
            ~NaluWaveform();

            /**
             * @brief Index of the event.
             */
            uint64_t channel_num;

            /**
             * @brief Trace for this channel
             */
            std::vector<short> trace;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the NaluHeader.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(NaluWaveform,1)

    };

    /**
     * @typedef NaluWaveformCollection
     * @brief A collection (vector) of NaluWaveform objects.
     */
    typedef std::vector<NaluWaveform> NaluWaveformCollection;

} // namespace dataProducts

#endif // NALUWAVEFORM_HH