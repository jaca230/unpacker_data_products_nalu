#ifndef NALUPACKETFOOTER_HH
#define NALUPACKETFOOTER_HH

#include <cstdint>  // for uint16_t
#include <TObject.h> // if ROOT macro ClassDef is used

namespace dataProducts {

struct NaluPacketFooter {
    uint16_t parser_index;
    uint16_t packet_footer;

    ClassDef(NaluPacketFooter, 1);
};

} // namespace dataProducts

#endif // NALUPACKETFOOTER_HH
