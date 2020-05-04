#include "Comanda.h"
#include <string.h>

Comanda::Comanda() {
	this->numeClient = new char[1];
	//this->numeClient = NULL;
	this->adresaClient = new char[1];
	//this->adresaClient = NULL;
	this->pretTotal = 0.0;
}

Comanda::Comanda(const char* numeClient, const char* adresaClient, double pretTotal) {
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);

	this->adresaClient = new char[strlen(adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);

	this->pretTotal = pretTotal;
}

Comanda::Comanda(const Comanda& comanda) {
	this->numeClient = new char[strlen(comanda.numeClient) + 1];
	strcpy_s(this->numeClient, strlen(comanda.numeClient) + 1, comanda.numeClient);

	this->adresaClient = new char[strlen(comanda.adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(comanda.adresaClient) + 1, comanda.adresaClient);

	this->pretTotal = comanda.pretTotal;
}

Comanda::~Comanda() {
	if (this->numeClient) {
		delete[] this->numeClient;
	}
	this->numeClient = NULL;
	if (this->adresaClient) {
		delete[] this->adresaClient;
	}
	this->adresaClient = NULL;
	this->pretTotal = 0.0;

}

char* Comanda::getNumeClient(){
	return numeClient;
}

char* Comanda::getAdresaClient(){
	return adresaClient;
}

double Comanda::getPretTotal(){
	return pretTotal;
}

void Comanda::setNumeClient(const char* numeClientNou){
	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	this->numeClient = new char[strlen(numeClientNou) + 1];
	strcpy_s(this->numeClient, strlen(numeClientNou) + 1, numeClientNou);
}

void Comanda::setAdresaClient(const char* adresaClientNoua){
	if (this->adresaClient) {
		delete[] this->adresaClient;
		this->adresaClient = NULL;
	}
	this->adresaClient = new char[strlen(adresaClientNoua) + 1];
	strcpy_s(this->adresaClient, strlen(adresaClientNoua) + 1, adresaClientNoua);
}

void Comanda::setPretTotal(double pretTotalNou){
	this->pretTotal = pretTotalNou;

}

Comanda& Comanda::operator=(const Comanda& comanda){
	if (this == &comanda) {
		return *this;
	}

	if (this->numeClient) {
		delete[] this->numeClient;
		this->numeClient = NULL;
	}
	this->numeClient = new char[strlen(comanda.numeClient) + 1];
	strcpy_s(this->numeClient, strlen(comanda.numeClient) + 1, comanda.numeClient);

	if (this->adresaClient) {
		delete[] this->adresaClient;
		this->adresaClient = NULL;
	}
	this->adresaClient = new char[strlen(comanda.adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(comanda.adresaClient) + 1, comanda.adresaClient);

	this->pretTotal = comanda.pretTotal;

	return *this;
}

bool Comanda::operator==(const Comanda& comanda){
	return(strcmp(this->numeClient, comanda.numeClient) == 0 &&
		strcmp(this->adresaClient, comanda.adresaClient) == 0 &&
		this->pretTotal == comanda.pretTotal);
}
