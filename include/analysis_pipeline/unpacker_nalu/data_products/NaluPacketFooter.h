#ifndef NALUPACKETFOOTER_HH   
#define NALUPACKETFOOTER_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

namespace dataProducts {

    /**
     * @class NaluPacketFooter
     * @brief Represents the footer information for a NALU packet.
     *
     * Inherits from DataProduct.
     */
    class NaluPacketFooter : public DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            NaluPacketFooter();

            /**
             * @brief Destructor.
             */
            ~NaluPacketFooter();

            /**
             * @brief Parser index.
             */
            uint16_t parser_index;

            /**
             * @brief Packet footer.
             */
            uint16_t packet_footer;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the NaluPacketFooter.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(NaluPacketFooter,1)
    };

} // namespace dataProducts

#endif // NALUPACKETFOOTER_HH
