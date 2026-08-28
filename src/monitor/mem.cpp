#include "mem.h"

MemData::MemData(){
	std::string line;
	size_t divider;
	std::string key;

	std::ifstream file("/proc/meminfo");
	if (file.is_open()){
		while(std::getline(file,line)){
			line.erase(std::remove_if(line.begin(),line.end(),[](char c){return std::isspace(c);}),line.end());
			divider =line.find(':');
			key = line.substr(0,divider);

			if(key == "MemTotal"){
				_max_memory = std::stoi(line.substr(divider+1));
			}
		}
	}
}

void readMemData(MemData& mem){

	std::string line;
	size_t divider;
	std::string key;

	std::ifstream file("/proc/meminfo");
	if (file.is_open()){
		while(std::getline(file,line)){
			line.erase(std::remove_if(line.begin(),line.end(),[](char c){return std::isspace(c);}),line.end());
			divider =line.find(':');
			key = line.substr(0,divider);

			if(key == "MemAvailable"){
				mem._curr_usage = std::stoi(line.substr(divider+1));
			}
		}
	}

}
