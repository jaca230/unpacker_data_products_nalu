#ifndef NALUEVENTFOOTER_HH
#define NALUEVENTFOOTER_HH

#include <cstdint>

namespace dataProducts {

#pragma pack(push, 1)
struct NaluEventFooter {
    uint16_t event_footer;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // NALUEVENTFOOTER_HH
