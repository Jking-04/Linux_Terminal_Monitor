#include "cpu.h"

#include "mem.h"
#include "temp.h"
#include "network.h"

#include "events.h"
#include "display.h"
#include "timekeeper.h"

#include <thread>
#include <chrono>

int main(){
	Event event;

	CpuData cpu_data;
	MemData mem_data;
	TempData temp_data;
	NetData net_data;

	TimeKeeper& time = TimeKeeper::getInstance();

	openAlternateTerminal();

	while(handleEvents(event)){
		double elapsed_time = time.calcElapsedTime();

		// get cpu data
		readCpuData(cpu_data);

		//get memory data
		readMemData(mem_data);

		//get temperature data
		readTempData(temp_data);
		
		//get network data
		readNetData(net_data);
		
		//display the info
		tuiDisplay(cpu_data,mem_data,temp_data,net_data,elapsed_time);
		
		//read istream
		readUserInput(event);

		//wait
		std::this_thread::sleep_for(std::chrono::seconds(1));

	}
	closeAlternateTerminal();
	
	return 0;
}
