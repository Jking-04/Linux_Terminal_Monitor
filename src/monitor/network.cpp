#include "network.h"
#include "iostream"

void processNetDynamic(std::vector<std::string>& values,NetData& net)
{
	net._net_names.push_back(values[0]);
	net._new_upload_reads.push_back(std::stoi(values[1]));
	net._new_download_reads.push_back(std::stoi(values[9]));
}

void readNetData(NetData& net)
{
	readFile<processTabular<processNetDynamic,NetData>>("/proc/net/dev",net);
}


