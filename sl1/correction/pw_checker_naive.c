#include <stdio.h>
#include <string.h>

const unsigned char passwd[8] = "wordpass"; 

int main(int argc, char * argv[]) {
	if (argc < 2){
		printf("Error, missing argument");
		return 1;
	}
	
	const size_t  sza = strlen(argv[1]);
	if (sza > 8) {
		printf("Error, argument too long.");
		return 1;
	}

	const size_t  sz = strnlen(argv[1], 8);
	unsigned char in[8];
	memset(in, 0, 8);
	memcpy(in, argv[1], sz);

	printf("You entered \"%s\".\n", argv[1]);


#ifndef NDEBUG
	for (int i = 0; i < 8; i++)
		printf("%c", in[i]);
	printf("\n");
	for (int i = 0; i < 8; i++)
		printf("%c", passwd[i]);
#endif
	int result = 0;
	for (int i = 0; i < 8; i++)
		result |= in[i] != passwd[i];

#ifndef NDEBUG
	printf("\nRESULT = %d\n", result);
#endif

	return result;
}
