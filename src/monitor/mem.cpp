#include "mem.h"

void processMemStatic(std::string& key,std::string& val, MemData& mem){
	if(key == "MemTotal"){
		mem._max_memory = std::stoi(val);
	}

}

void processMemDynamic(std::string& key,std::string& val,MemData& mem){
	if(key == "MemAvailable"){
		mem._curr_usage = std::stoi(val);
	}

}

MemData::MemData(){
	readFile<processKV<processMemStatic,MemData>>("/proc/meminfo",*this);
}

void readMemData(MemData& mem){
	readFile<processKV<processMemDynamic,MemData>>("/proc/meminfo",mem);
}
