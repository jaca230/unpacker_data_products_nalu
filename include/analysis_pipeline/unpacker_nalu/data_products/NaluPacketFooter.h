#ifndef NALUPACKETFOOTER_HH
#define NALUPACKETFOOTER_HH

#include <cstdint>  // for uint16_t
#include <TObject.h> // if ROOT macro ClassDef is used

namespace dataProducts {

#pragma pack(push, 1)
struct NaluPacketFooter {
    uint16_t parser_index;
    uint16_t packet_footer;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // NALUPACKETFOOTER_HH
