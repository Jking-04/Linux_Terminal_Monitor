#include "timekeeper.h"

TimeKeeper& TimeKeeper::getInstance()
{
	static TimeKeeper obj;
	return obj;
}

double TimeKeeper::calcElapsedTime()
{
	auto now = std::chrono::steady_clock::now();
	
	double elapsed = std::chrono::duration<double>(now - _last).count();

	_last = now;

	return elapsed;
}

TimeKeeper::TimeKeeper()
{
	_last = std::chrono::steady_clock::now();
}
