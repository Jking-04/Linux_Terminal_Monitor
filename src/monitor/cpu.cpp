#include "cpu.h"

CpuData::CpuData(): _model{},_core_count{}{
	std::string line;

	std::ifstream file("/proc/cpuinfo");
	if(file.is_open()){
		while(std::getline(file,line)){
			line.erase(std::remove_if(line.begin(),line.end(),[](char c){return std::isspace(c);}),line.end());

			size_t divider = line.find(':');
			std::string key = line.substr(0,divider);

			if (key == "Model"){
				_model = line.substr(divider+1);
			}

			else if (key == "processor"){
				_core_count += 1;
			}
		}
	}
}

uint64_t readValue(std::string fileAdr){
	uint64_t val;

	std::ifstream file(fileAdr);
	file>>val;
	return val;
}


void readCpuData(CpuData& cpu){
	cpu._curr_freq = readValue("/sys/devices/system/cpu/cpu*/cpufreq/scaling_cur_freq");
}

