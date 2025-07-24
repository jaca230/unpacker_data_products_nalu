#ifndef NALUEVENTFOOTER_HH   
#define NALUEVENTFOOTER_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

namespace dataProducts {

    /**
     * @class NaluEventFooter
     * @brief Represents the footer information for a NALU event.
     *
     * Inherits from DataProduct. 
     */
    class NaluEventFooter : public DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            NaluEventFooter();

            /**
             * @brief Destructor.
             */
            ~NaluEventFooter();

            /**
             * @brief Index of the event.
             */
            uint16_t event_footer;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the NaluEventFooter.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(NaluEventFooter,1)
    };

} // namespace dataProducts

#endif // NALUEVENTFOOTER_HH
