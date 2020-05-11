#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Comanda{
protected:
	string numeClient, adresaClient;
	double pretTotal;
public:
	Comanda();
	Comanda(string numeClient,string adresaClient, double pretTotal);
	Comanda(string linie, char delim);
	Comanda(const Comanda& comanda);
	~Comanda();

	string getNumeClient();
	string getAdresaClient();
	double getPretTotal();

	void setNumeClient(string numeClientNou);
	void setAdresaClient(string adresaClientNoua);
	void setPretTotal(double pretTotalNou);

	virtual string toString(string delim);
	
	Comanda& operator=(const Comanda& comanda);
	bool operator==(const Comanda& comanda);

	virtual void print(ostream& os) {
		os << toString(string(" ")) << std::endl;
	};

	friend ostream& operator<< (ostream& out, Comanda& comanda) {
		comanda.print(out);
		return out;
	}
};

