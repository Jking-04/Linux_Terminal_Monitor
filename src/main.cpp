#include "cpu.h"
#include "mem.h"
#include "temp.h"

#include "events.h"
#include "display.h"
#include <thread>
#include <chrono>

int main(){
	
	std::cout<<"2";
	
	Event event;

	CpuData cpu_data;
	MemData mem_data;
	TempData temp_data;

	while(handleEvents(event)){
		std::cout<<"1";
		// get cpu data
		readCpuData(cpu_data);

		//get memory data
		readMemData(mem_data);

		//get temperature data
		readTempData(temp_data);
		
		//display the info
		tuiDisplay(cpu_data,mem_data,temp_data);
		
		//read istream
		readUserInput(event);

		//wait
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}
	
	return 0;
}
