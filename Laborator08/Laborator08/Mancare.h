#pragma once
#include <iostream>
#include "Comanda.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Mancare : public Comanda{
private:
	vector<string> listaPreparate;
	char* all;
public:
	Mancare();
	Mancare(const char* numeClient, const char* adresaClient, vector<string> listaPreparate, double pretTotal);
	Mancare(const Mancare& mancare);
	~Mancare();

	vector<string> getListaPreparate();

	void setListaPreparate(vector<string> listaPreparateNoua);

	char* toStringForCSV();

	Mancare& operator=(const Mancare& mancare);
	bool operator==(const Mancare& mancare);

	friend std::ostream& operator<<(std::ostream& os, Mancare& mancare);
	friend std::istream& operator>>(std::istream& os, Mancare& mancare);
};

