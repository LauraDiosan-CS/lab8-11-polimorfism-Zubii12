#pragma once
#include "Shopping.h"

class ValidareShopping{
private:
	void validare(Shopping& s);
public:
	ValidareShopping(const Shopping& s);
	~ValidareShopping();
};

