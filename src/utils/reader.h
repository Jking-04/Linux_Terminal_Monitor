#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>

template<auto processing_func,typename T>
void readFile(const std::string& file_path, T& data)
{
	std::ifstream file (file_path);
	
	std::string line;

	if(file.is_open()){

		while(std::getline(file,line)){

			processing_func(line,data);
		}
	}
}

template<auto processing_func,typename T>
void processKV(std::string line,T& data)
{	

	line.erase(std::remove_if(line.begin(),line.end(),[](char c){return std::isspace(c);}),line.end());
	const size_t divider = line.find(':');
	
	if(divider == std::string::npos)
		return;

	std::string key = line.substr(0,divider);
	std::string val = line.substr(divider+1);
	
	processing_func(key,val,data);
}

template <auto processing_func,typename T>
void processTabular(std::string line,T& data)
{
	const size_t divider = line.find(':');
	
	if(divider == std::string::npos)
		return;
	
	std::vector<std::string> values;

	std::stringstream ss(line);
	std::string value;

	while(ss>>value)
	{
		values.push_back(value);
	}

	processing_func(values,data);

}

uint64_t readValue(std::string);
