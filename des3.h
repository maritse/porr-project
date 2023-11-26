#ifndef DES3_H
#define DES3_H

#include "des.h"

class DES3 {
public:
    DES3(uint64_t k1, uint64_t k2, uint64_t k3);

    uint64_t encrypt(uint64_t block);

    uint64_t decrypt(uint64_t block);

private:
    DES des1;
    DES des2;
    DES des3;
};

#endif // DES3_H