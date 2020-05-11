#pragma once
#include "Serializer.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"

class SerializerComanda : public Serializer<Comanda*>{
public:
	SerializerComanda();
	~SerializerComanda();
	Comanda* fromString(string linie, char delim);
};

