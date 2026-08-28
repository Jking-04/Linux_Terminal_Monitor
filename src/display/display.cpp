
#include "display.h"

void tuiDisplay(CpuData& cpu,MemData & mem,TempData & temp){
	std::cout<<cpu._model<<std::endl;
	std::cout<<cpu._core_count<<std::endl;
	
	double temp_c_float = temp._temp/1000.0f;
	std::cout<<std::fixed<<std::setprecision(1)<<temp_c_float<<std::endl;
	
	double usage_gb = mem._curr_usage/1024.0f/1024.0f;
	double max_gb = mem._max_memory/1024.0f/1024.0f;
	std::cout<<std::fixed<<std::setprecision(1)<<usage_gb <<"/"<<max_gb;
	
	//std::cout<<_frequency<<std::endl;
};
