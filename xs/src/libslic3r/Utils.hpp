#ifndef slic3r_Utils_hpp_
#define slic3r_Utils_hpp_

namespace Slic3r {

extern void set_logging_level(unsigned int level);
extern void trace(unsigned int level, const char *message);

// Compute the next highest power of 2 of 32-bit v
// http://graphics.stanford.edu/~seander/bithacks.html
template<typename T>
inline T next_highest_power_of_2(T v)
{
	if (v != 0)
	    -- v;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    if (sizeof(T) >= sizeof(uint16_t))
    	v |= v >> 8;
    if (sizeof(T) >= sizeof(uint32_t))
	    v |= v >> 16;
    if (sizeof(T) >= sizeof(uint64_t))
	    v |= v >> 32;
    return ++ v;
}

} // namespace Slic3r

#endif // slic3r_Utils_hpp_
