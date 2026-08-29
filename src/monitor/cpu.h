#pragma once

#include "reader.h"
#include <iomanip>
#include <cstdint>
#include <algorithm>

struct CpuData{
	//static info
	std::string _model;
	size_t _core_count;

	//dynamic info
	uint64_t _curr_freq;

	CpuData();
};

void processCpuStatic(std::string,std::string,CpuData&);

void readCpuData(CpuData&);
