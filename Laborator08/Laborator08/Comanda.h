#pragma once
#include <iostream>

class Comanda{
protected:
	char* numeClient, *adresaClient;
	double pretTotal;
public:
	Comanda();
	Comanda(const char* numeClient, const char* adresaClient, double pretTotal);
	Comanda(const Comanda& comanda);
	~Comanda();

	char* getNumeClient();
	char* getAdresaClient();
	double getPretTotal();

	void setNumeClient(const char* numeClientNou);
	void setAdresaClient(const char* adresaClientNoua);
	void setPretTotal(double pretTotalNou);

	Comanda& operator=(const Comanda& comanda);
	bool operator==(const Comanda& comanda);
};

