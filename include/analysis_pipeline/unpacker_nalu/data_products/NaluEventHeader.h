#ifndef NALUEVENTHEADER_HH   
#define NALUEVENTHEADER_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
namespace dataProducts {

    /**
     * @class NaluEventHeader
     * @brief Represents the header information for a NALU event.
     *
     * Inherits from DataProduct. Stores metadata such as the event index and number of packets.
     */
    class NaluEventHeader : public DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            NaluEventHeader();

            /**
             * @brief Destructor.
             */
            ~NaluEventHeader();

            /**
             * @brief Event header.
             */
            uint16_t event_header;

            /**
             * @brief Event info.
             */
            uint8_t event_info;

            /**
             * @brief Index of the event.
             */
            uint32_t event_index;

            /**
             * @brief Event reference time.
             */
            uint32_t event_reference_time;

            /**
             * @brief Packet size.
             */
            uint16_t packet_size;

            /**
             * @brief Channel mask
             */
            uint64_t channel_mask;

            /**
             * @brief Number of windows
             */
            uint8_t num_windows;

            /**
             * @brief Number of packets.
             */
            uint16_t num_packets;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the NaluEventHeader.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(NaluEventHeader,1)
    };

} // namespace dataProducts

#endif // NALUEVENTHEADER_HH
