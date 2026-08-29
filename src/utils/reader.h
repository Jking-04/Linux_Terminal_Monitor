#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

template<auto processing_func,typename T>
void readFile(const std::string& file_path, T& data)
{
	std::ifstream file (file_path);
	
	std::string line;
	std::string key;
	std::string val;
	size_t divider;

	if(file.is_open()){

		while(std::getline(file,line)){
			line.erase(std::remove_if(line.begin(),line.end(),[](char c){return std::isspace(c);}),line.end());
			divider = line.find(':');
			
			key = line.substr(0,divider);
			val = line.substr(divider+1);
			
			processing_func(key,val,data);
		}
	}
}

uint64_t readValue(std::string);
