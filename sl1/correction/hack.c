#include <openssl/sha.h>

// hash of "hacked"
unsigned char passwd_hash[SHA256_DIGEST_LENGTH] =
{
	0xb7, 0x94, 0x89, 0x44, 0x89, 0x89, 0x3e, 0xac,
	0x1f, 0x2d, 0xbf, 0xff, 0xb1, 0x7b, 0x85, 0xe5,
	0x0e, 0xdd, 0x5b, 0xa8, 0xde, 0x00, 0x05, 0xb0,
	0xf4, 0xa4, 0x2b, 0x24, 0x88, 0x31, 0x9b, 0x18
};
