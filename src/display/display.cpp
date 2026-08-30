
#include "display.h"

void tuiDisplay(CpuData& cpu,MemData & mem,TempData & temp, NetData& Net, double elipsed_time)
{
	std::cout<<cpu._model<<std::endl;
	std::cout<<cpu._core_count<<std::endl;
	
	double temp_c_float = temp._temp/1000.0f;
	std::cout<<std::fixed<<std::setprecision(1)<<temp_c_float<<std::endl;
	
	double usage_gb = mem._curr_usage/1024.0f/1024.0f;
	double max_gb = mem._max_memory/1024.0f/1024.0f;
	std::cout<<"mem: ["<<printBar(usage_gb,max_gb,20)<<"]"<<std::endl;

	if (Net._old_upload_reads.size() !=0){
	for(size_t i =0;i<Net._net_names.size();i++){
		double upload_speed = (Net._new_upload_reads[i] - Net._old_upload_reads[i])/elipsed_time;
		double download_speed =(Net._new_download_reads[i] - Net._old_download_reads[i])/elipsed_time;
		std::cout<<Net._net_names[i]<<" up:"<<upload_speed<<" down:"<<download_speed<<std::endl;

	}
	}
	Net._old_upload_reads = Net._new_upload_reads;
	Net._old_download_reads = Net._new_download_reads;

	Net._new_upload_reads.clear();
	Net._new_download_reads.clear();

	Net._net_names.clear();
	//std::cout<<_frequency<<std::endl;
}
