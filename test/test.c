#include "../inc/bit_manipulator.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXPECT(this, that) \
{\
	if(this != that)\
	{\
		printf("Test failed. %s (%d) !=  %s (%d)\n", #this, this, #that, that);\
		abort();\
	}\
	else\
	{\
		printf("Verified %s (%d) == %s (%d) OK\n", #this, this, #that, that);\
	}\
}\

int main(void)
{
	char test[] = "abcde\0";
	char toSet = 'f';

	setBitsInByteArray(test, 8u, &toSet, 8u);

	EXPECT(strcmp("afcde", test), 0);

	toSet = 'a';

	setBitsInByteArray(test, 16u, &toSet, 8u);

	EXPECT(strcmp("afade", test), 0);

	char toVerify = 0u;

	getBitsInByteArray(&toVerify, test, 8u, 8u);

	EXPECT(toVerify, 'f');

	toVerify = 0u;

	setBitInByteArray(test, 2u, 0u);
	getBitInByteArray(&toVerify, test, 2u);

	EXPECT(0u, toVerify);

	setBitInByteArray(test, 2u, 1u);
	getBitInByteArray(&toVerify, test, 2u);

	EXPECT(1u, toVerify);

	unsigned int bitIndex = 0u;
	const unsigned int numBitsToSet = 8u * 5u;

	for(bitIndex = 0; bitIndex < numBitsToSet; ++bitIndex)
	{
		setBitInByteArray(test, bitIndex, 0u);
		getBitInByteArray(&toVerify, test, bitIndex);
		EXPECT(0u, toVerify);
	}

	setBitInByteArray(test, 27u, 1u);
	getBitInByteArray(&toVerify, test, 27u);
	EXPECT(1u, toVerify);

	toVerify = 0u;

	getBitsInByteArray(&toVerify, test, 26u, 3u);

	EXPECT(2u, toVerify);

	toVerify = 0u;

	for(bitIndex = 0; bitIndex < numBitsToSet; ++bitIndex)
	{
		setBitInByteArray(test, bitIndex, 1u);
		getBitInByteArray(&toVerify, test, bitIndex);
		EXPECT(1u, toVerify);
	}

	return 0;
}
