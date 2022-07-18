#include <kernel/lib/memory.h>

void memcpy(uint8_t* source, uint8_t* dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memset(uint8_t* dest, uint8_t val, uint32_t len) {
    uint8_t* temp = (uint8_t*) dest;
    for ( ; len != 0; len--) *temp++ = val;
}

int memcmp(const void* s1, const void* s2, int n) {
    const uint8_t* _s1 = (uint8_t*) s1;
    const uint8_t* _s2 = (uint8_t*) s2;

    while (n--){
        if (*_s1 != *_s2) {
            return *_s1 - *_s2;
        }
        _s1++;
        _s2++;
    }

    return 0;
}