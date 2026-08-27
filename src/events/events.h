#pragma once

#include <string>
#include <poll.h>
#include <iostream>

enum EventType{
	RUNNING,
	QUIT,
};

struct Event{
	EventType _type;
	Event();
};

bool handleEvents(Event& event);

bool check_in_queue();

void readUserInput(Event&);

