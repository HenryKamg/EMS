#include "Landing.h"

#ifndef _CONST_H
#define _CONST_H

const int NUM = 2;
const unsigned ADMPOPEDOM = 0XFFFFFFFF;
const unsigned USERPOPEDOM = 0X00000000;
const unsigned ADM = 0XFFFF0000;
const unsigned USERR = 0X0000FFFF;

CLanding obj[NUM] =
{
	CLanding("∫Ó’º…Ω", "19851210", ADM),
		CLanding("USER", "123456", USERR)
};

#endif