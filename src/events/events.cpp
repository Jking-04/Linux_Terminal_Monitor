#include "events.h"
#include <unistd.h>

Event::Event(){
	_type = EventType::RUNNING;
}

bool handleEvents(Event& event){
	
	if(event._type == EventType::QUIT){
		return false;
	}

	return true;
};

bool check_in_queue(){

	pollfd pfd{};

	pfd.fd = STDIN_FILENO;
	pfd.events = POLLIN;

	int result = poll(&pfd,1,0);

	return result;
}

void readUserInput(Event& event){
	if(check_in_queue()){
		char c;
		std::cin.get(c);
		if(c == 'q'){
			event._type=EventType::QUIT;
		}
	}
}
