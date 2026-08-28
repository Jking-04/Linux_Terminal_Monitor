#pragma once

#include <string>
#include <fstream>
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct MemData{
	//static info
	uint64_t _max_memory =0;

	//dynamic info
	uint64_t _curr_usage=0;

	MemData();
};

void readMemData(MemData&);

