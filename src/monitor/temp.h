#pragma once
#include "cpu.h"

struct TempData{
	//dynamic type
	uint64_t _temp;
};

void readTempData(TempData&);
