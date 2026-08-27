#pragma once
#include <string>
#include <fstream>
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

uint64_t readValue(std::string);

void readCpuData(CpuData&);
