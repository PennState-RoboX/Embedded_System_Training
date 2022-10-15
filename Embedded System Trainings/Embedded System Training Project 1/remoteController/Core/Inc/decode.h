#ifndef __DECODE__
#define __DECODE__

#include "main.h"

struct 
{
	int16_t ch[4];
	char s[2];
}rc_t;


void decodeData(volatile const uint8_t *pData);

#endif