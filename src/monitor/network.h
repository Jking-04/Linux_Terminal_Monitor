#pragma once

#include "reader.h"
#include <vector>
#include <string>

struct NetData
{
	//dynamic info
	
	std::vector<std::string> _net_names;
	std::vector<double> _new_upload_reads;
	std::vector<double> _new_download_reads;

	std::vector<double> _old_upload_reads;
	std::vector<double> _old_download_reads;
};

void processNetDynamic(std::vector<std::string>&,NetData&);

void readNetData(NetData&);
