#pragma once
#include <string>

using std::string;

template<class T>
class Serializer {
public:
	Serializer() {};
	~Serializer() {};
	virtual T fromString(string linie, char delim) = 0;
};