
#include "display.h"

void tuiDisplay(CpuData& cpu,MemData & mem,TempData & temp, NetData& net, double elapsed_time)
{
	clearTerminal();

	displayCpuData(cpu,temp);
	displayGap();

	displayMemData(mem);
	displayGap();

	displayNetData(net,elapsed_time);
	displayGap();
}

void openAlternateTerminal()
{
	std::cout<<"\033[?1049h";
}

void closeAlternateTerminal()
{
	std::cout<<"\033[?1049l";
}

void clearTerminal()
{
	std::cout<<"\033[2J\033[H";
}

void displayCpuData(CpuData& cpu,TempData& temp)
{
	std::cout<<"CPU: "<<std::endl;

	std::cout<<cpu._model<<std::endl;
	std::cout<<cpu._core_count<<std::endl;
	
	double temp_c_float = temp._temp/1000.0f;
	std::cout<<std::fixed<<std::setprecision(1)<<temp_c_float<<std::endl;
}

void displayMemData(MemData& mem)
{
	std::cout<<"Memory: "<<std::endl;

	double usage_gb = mem._curr_usage/1024.0f/1024.0f;
	double max_gb = mem._max_memory/1024.0f/1024.0f;
	std::cout<<"mem: ["<<printBar(usage_gb,max_gb,20)<<"]"<<std::endl;
}

void displayNetData(NetData& net,double elapsed_time)
{
	std::cout<<"Network: "<<std::endl;

	if (net._old_upload_reads.size() !=0){
	for(size_t i =0;i<net._net_names.size();i++){
		double upload_speed = (net._new_upload_reads[i] - net._old_upload_reads[i])/elapsed_time;
		double download_speed =(net._new_download_reads[i] - net._old_download_reads[i])/elapsed_time;
		std::cout<<net._net_names[i]<<" up:"<<upload_speed<<" down:"<<download_speed<<std::endl;

	}
	}
	net._old_upload_reads = net._new_upload_reads;
	net._old_download_reads = net._new_download_reads;

	net._new_upload_reads.clear();
	net._new_download_reads.clear();

	net._net_names.clear();
}

void displayGap()
{
	std::cout<<std::endl;
}
