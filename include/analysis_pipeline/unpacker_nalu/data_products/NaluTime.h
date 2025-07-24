#ifndef NALUTIME_HH   
#define NALUTIME_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

namespace dataProducts {

    /**
     * @class NaluTime
     * @brief Represents the footer information for a NALU event.
     *
     * Inherits from DataProduct. 
     */
    class NaluTime : public DataProduct {

        public:
            /**
             * @brief Default constructor.
             */
            NaluTime();

            /**
             * @brief Destructor.
             */
            ~NaluTime();

            /**
             * @brief Collection cycle index
             */
            uint64_t collection_cycle_index;

            /**
             * @brief Collection cycle timestamp in ns
             */
            uint64_t collection_cycle_timestamp_ns;

            /**
             * @brief upd time
             */
            double udp_time;

            /**
             * @brief Parse time
             */
            double parse_time;

            /**
             * @brief Event time
             */
            double event_time;

            /**
             * @brief Total time
             */
            double total_time;

            /**
             * @brief Data processed
             */
            uint64_t data_processed;

            /**
             * @brief Data rate
             */
            double data_rate;

            /**
             * @brief Make a string of this class's contents.
             */
            std::string String() const;

            /**
             * @brief Display the contents of the NaluTime.
             */
            void Show() const override;

            /// ROOT class definition macro with versioning
            ClassDefOverride(NaluTime,1)
    };

} // namespace dataProducts

#endif // NALUTIME_HH
