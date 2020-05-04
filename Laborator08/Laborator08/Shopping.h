#pragma once
#include <iostream>
#include "Comanda.h"
#include <vector>

using std::vector;
using std::string;

class Shopping : public Comanda{
private:
	vector<string> listaCumparaturi;
	char* numeMagazin;
	char* all;
public:
	Shopping();
	Shopping(const char* numeClient, const char* adresaClient, vector<string> listaCumparaturi, double pretTotal, const char* numeMagazin);
	Shopping(const Shopping& shopping);
	~Shopping();

	vector<string> getListaCumparaturi();
	char* getNumeMagazin();

	void setListaCumparaturi(vector<string> listaCumparaturiNoua);
	void setNumeMagazin(const char* numeMagazinNou);

	char* toStringForCSV();

	Shopping& operator=(const Shopping& shopping);
	bool operator==(const Shopping& shopping);

	friend std::ostream& operator<<(std::ostream& os, Shopping& shopping);
	friend std::istream& operator>>(std::istream& is, Shopping& shopping);
};

