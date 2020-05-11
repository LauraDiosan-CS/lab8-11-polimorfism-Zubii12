#pragma once
#include "Comanda.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Mancare : public Comanda{
private:
	vector<string> listaPreparate;
public:
	Mancare();
	Mancare(string numeClient, string adresaClient, double pretTotal, vector<string> listaCumparaturi);
	Mancare(string linie, char delim);
	Mancare(const Mancare& mancare);
	~Mancare();

	vector<string> getListaPreparate();

	void setListaPreparate(vector<string> listaPreparateNoua);

	string toString(string delim);

	Mancare& operator=(const Mancare& mancare);
	bool operator==(const Mancare& mancare);

	friend std::istream& operator>>(std::istream& os, Mancare& mancare);
	friend std::ostream& operator<<(std::ostream& os, Mancare& mancare);
};

