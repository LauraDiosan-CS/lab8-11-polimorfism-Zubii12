#include "SerializerComanda.h"
#include "Utils.h"
#include "MyException.h"

SerializerComanda::SerializerComanda():Serializer(){
}

SerializerComanda::~SerializerComanda(){
}

Comanda* SerializerComanda::fromString(string linie, char delim){
	vector<string> split = splitLinie(linie, delim);
	if (split[0] == "Mancare") {
		linie.erase(linie.begin(), linie.begin() + 8);
		Comanda* comanda = new Mancare(linie, delim);
		return comanda;
	}
	else if (split[0] == "Shopping") {
		linie.erase(linie.begin(), linie.begin() + 9);
		Comanda* comanda = new Shopping(linie, delim);
		return comanda;
	}
	throw MyException("Linia din fisier este incorecta! \n");
}

