#ifndef HEADER_BIT_MANIPULATOR
#define HEADER_BIT_MANIPULATOR

int setBitsInByteArray(char destination[],
					   const unsigned int destinationBitStart,
					   const char source[],
					   const unsigned int sourceBitSize);

int getBitsInByteArray(char destination[],
					   const char source[],
					   const unsigned int sourceBitStart,
					   const unsigned int sourceBitsToCopy);

void setBitInByteArray(char destination[],
		               const unsigned int destinationBit,
					   const char bitToSetVal);

void getBitInByteArray(char* retVal,
		               const char source[],
					   const unsigned int bitNo);

#endif
