#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

extern unsigned char passwd_hash[SHA256_DIGEST_LENGTH]; 

int main(int argc, char * argv[]) {
	if (argc < 2){
		printf("Error, missing argument");
		return 1;
	}

	unsigned char buffer[SHA256_DIGEST_LENGTH];
	
	const size_t  sz = strnlen(argv[1], 40);
	unsigned char in[40];
	memset(in, 0, 40);
	memcpy(in, argv[1], sz);

	printf("You entered \"%s\".\n", argv[1]);

	(void) SHA256((unsigned char *) in, sz, buffer);

#ifndef NDEBUG
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", buffer[i]);
	printf("\n");
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", passwd_hash[i]);
#endif
	int result = 0;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		result |= buffer[i] != passwd_hash[i];

#ifndef NDEBUG
	printf("\nRESULT = %d\n", result);
#endif

	return result;
}
