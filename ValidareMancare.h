#pragma once
#include "Mancare.h"
#include "MyException.h"

class ValidareMancare{
private:
	void validare(Mancare& mancare);
public:
	ValidareMancare();
	ValidareMancare(const Mancare& mancare);
	~ValidareMancare();
};

