#include "utility.h"

#include <cstdio>
#include <cstring>

void printHex(const uint8_t *bytes, uint32_t bytesCount, bool printNewline)
{
	for(uint32_t i = 0; i < bytesCount; i++)
	{
		if(i)
		{
			if((i % 8) == 0)
				printf(" ");
			
			if((i % 16) == 0)
				printf("\n");
		}
		
		printf("%.2X ", bytes[i]);
	}
	
	if(printNewline)
		printf("\n");
}

void printMAC(const uint8_t *macAddr, uint32_t length)
{
	for(uint32_t i = 0; i < length; i++)
	{
		char delimeter = (i == (length - 1)) ? ' ' : ':';
		printf("%.2X%c", macAddr[i], delimeter);
	}
}
