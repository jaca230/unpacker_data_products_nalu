#include "analysis_pipeline/unpacker_nalu/data_products/NaluEventFooter.h"

ClassImp(dataProducts::NaluEventFooter);

using namespace dataProducts;

/**
 * @brief Default constructor for NaluEventFooter.
 *
 * Initializes the event footer to 0.
 */
NaluEventFooter::NaluEventFooter()
    : DataProduct(),
      event_footer(0)
{}

/**
 * @brief Destructor for NaluEventFooter.
 */
NaluEventFooter::~NaluEventFooter() {}

/**
 * @brief Make a string of the contents of the class
 *
 * Displays the event footer value in hexadecimal format.
 */
std::string NaluEventFooter::String() const {
    std::ostringstream oss;
    oss << std::endl;
    oss << "NaluEventFooter: " << std::endl;
    oss << "    event_footer: " << std::hex << "0x" << event_footer << std::endl;
    return oss.str();
}

/**
 * @brief Print the contents of the NaluEventFooter to standard output.
 *
 * Displays the class as a string
 */
void NaluEventFooter::Show() const { 
    std::cout << this->String();
}
