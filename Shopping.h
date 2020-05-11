#pragma once
#include <iostream>
#include "Comanda.h"
#include <vector>

using std::vector;
using std::string;

class Shopping : public Comanda{
private:
	string numeMagazin;
	vector<string> listaCumparaturi;
public:
	Shopping();
	Shopping(string numeClient, string adresaClient, double pretTotal, string numeMagazin, vector<string> listaCumparaturi);
	Shopping(string linie, char delim);
	Shopping(const Shopping& shopping);
	~Shopping();

	vector<string> getListaCumparaturi();
	string getNumeMagazin();

	void setListaCumparaturi(vector<string> listaCumparaturiNoua);
	void setNumeMagazin(string numeMagazinNou);

	string toString(string delim);

	Shopping& operator=(const Shopping& shopping);
	bool operator==(const Shopping& shopping);

	friend std::istream& operator>>(std::istream& is, Shopping& shopping);
	friend std::ostream& operator<<(std::ostream& os, Shopping& shopping);
};

