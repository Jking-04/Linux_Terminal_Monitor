#include "cpu.h"

void processCpuStatic(std::string key,std::string val,CpuData& cpu)
{

	if (key == "Model"){
		cpu._model = val;
	}

	else if (key == "processor"){
		cpu._core_count += 1;
	}
}

CpuData::CpuData(): _model{},_core_count{}{	
	readFile<processCpuStatic>("/proc/cpuinfo",*this);
}

void readCpuData(CpuData& cpu){
	cpu._curr_freq = readValue("/sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq");
}

