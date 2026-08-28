#include "temp.h"

void readTempData(TempData& temp){
	temp._temp = readValue("/sys/class/thermal/thermal_zone0/temp");
}
