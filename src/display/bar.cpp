#include "bar.h"

std::string printBar(double current,double max, size_t width)
{
	double ratio = current/max;
	size_t fill_size = static_cast<size_t>(ratio * width);
	return std::string(fill_size,'#')+std::string(width-fill_size,'-');

}
