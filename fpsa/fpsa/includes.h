#pragma once



#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>
#include <string>


#include <iomanip>



#define DEH_SELLS			1.0
#define DEH_BUYS			0.5




#define BID_LINEAR			0
#define BID_EXP				1
#define BID_QUAD			2
#define BID_MULT_COEF		3

#define BWIN_BIGEST_BID		0

#define AUCTION_SEALED		0

#define NO_WINNER			-1



float Urand(int low, int high)
{
	return low + static_cast<double>(std::rand()) / RAND_MAX * (high - low);
}