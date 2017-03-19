#include "../inc/bit_manipulator.h"
#include <stdio.h>

#define NUM_BITS_IN_BYTE (8u)

int setBitsInByteArray(char destination[],
					   const unsigned int destinationBitStart,
					   const char source[],
					   const unsigned int sourceBitSize)
{
	unsigned int destByteOffset = destinationBitStart / (NUM_BITS_IN_BYTE);
	unsigned int bitOffsetInDestByte = destinationBitStart - destByteOffset * (NUM_BITS_IN_BYTE);

	unsigned int numBitsToSetCounter = 0u;
	unsigned int sourceByteOffset = 0u;
	unsigned int bitOffsetInSourceByte = 0u;

	for( ; numBitsToSetCounter < sourceBitSize; ++numBitsToSetCounter)
	{
		char toSet = ((1u << bitOffsetInSourceByte) & (source[sourceByteOffset])) >> bitOffsetInSourceByte;

		destination[destByteOffset] &= ~(1u << bitOffsetInDestByte);
		destination[destByteOffset] |= (toSet << bitOffsetInDestByte);

		bitOffsetInDestByte += 1u;

		if(bitOffsetInDestByte == (NUM_BITS_IN_BYTE))
		{
			bitOffsetInDestByte = 0u;
			destByteOffset += 1u;
		}

		bitOffsetInSourceByte += 1u;

		if(bitOffsetInSourceByte == (NUM_BITS_IN_BYTE))
		{
			bitOffsetInSourceByte = 0u;
			sourceByteOffset += 1u;
		}
	}

	return numBitsToSetCounter;
}


int getBitsInByteArray(char destination[],
					   const char source[],
					   const unsigned int sourceBitStart,
					   const unsigned int sourceBitsToCopy)
{
	unsigned int destByteOffset = 0u;
	unsigned int bitOffsetInDestByte = 0u;

	unsigned int sourceByteOffset = sourceBitStart / (NUM_BITS_IN_BYTE);
	unsigned int bitOffsetInSourceByte = sourceBitStart - sourceByteOffset * (NUM_BITS_IN_BYTE);

	unsigned int numBitsToSetCounter = 0u;

	for( ; numBitsToSetCounter < sourceBitsToCopy; ++numBitsToSetCounter)
	{
		char toSet = ((1u << bitOffsetInSourceByte) & (source[sourceByteOffset])) >> bitOffsetInSourceByte;

		destination[destByteOffset] &= ~(1u << bitOffsetInDestByte);
		destination[destByteOffset] |= (toSet << bitOffsetInDestByte);

		bitOffsetInDestByte += 1u;

		if(bitOffsetInDestByte == (NUM_BITS_IN_BYTE))
		{
			bitOffsetInDestByte = 0u;
			destByteOffset += 1u;
		}

		bitOffsetInSourceByte += 1u;

		if(bitOffsetInSourceByte == (NUM_BITS_IN_BYTE))
		{
			bitOffsetInSourceByte = 0u;
			sourceByteOffset += 1u;
		}
	}

	return numBitsToSetCounter;
}

void setBitInByteArray(char destination[],
		               const unsigned int destinationBit,
					   const char bitToSetVal)
{
	(void) setBitsInByteArray(destination, destinationBit, &bitToSetVal, 1u);
}

void getBitInByteArray(char* retVal,
		               const char source[],
					   const unsigned int bitNo)
{
	(void) getBitsInByteArray(retVal, source, bitNo, 1u);
}
