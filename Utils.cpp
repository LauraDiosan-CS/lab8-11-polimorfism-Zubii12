#include "Utils.h"
#include <sstream>
#include <iomanip>

std::vector<std::string> splitLinie(std::string linie, char delim){
	std::stringstream ss;
	std::string str;
	std::vector<std::string> v;
	
	ss << linie;
	while (std::getline(ss, str, delim)) {
		v.push_back(str);
	}

	return v;
}

double stringToDouble(std::string nr, int precision) {
	std::stringstream ss;

	ss << std::setprecision(precision) << std::fixed << nr;

	double nrD = 0.0;
	ss >> nrD;
	
	return nrD;
}

std::string doubleToString(double nr, int precision) {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << nr;
	std::string s = stream.str();
	return s;
}