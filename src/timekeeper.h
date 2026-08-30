#pragma once
#include <chrono>

class TimeKeeper{
public:
	static TimeKeeper& getInstance();
	double calcElapsedTime();
private:
	TimeKeeper();
	std::chrono::steady_clock::time_point _last;
	
};
