#include <openssl/sha.h>

// SHA256 of 'password'
unsigned char passwd_hash[SHA256_DIGEST_LENGTH] = {
    0x5e, 0x88, 0x48, 0x98, 0xda, 0x28, 0x04, 0x71, 
    0x51, 0xd0, 0xe5, 0x6f, 0x8d, 0xc6, 0x29, 0x27, 
    0x73, 0x60, 0x3d, 0x0d, 0x6a, 0xab, 0xbd, 0xd6, 
    0x2a, 0x11, 0xef, 0x72, 0x1d, 0x15, 0x42, 0xd8
};
