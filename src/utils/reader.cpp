#include "reader.h"

uint64_t readValue(std::string fileAdr){
	uint64_t val;
	std::ifstream file(fileAdr);
	file>>val;
	return val;
}
