#include "Comanda.h"
#include <string.h>
#include <vector>
#include "Utils.h"
#include <sstream>
#include <iostream>

using std::vector;

Comanda::Comanda() {
	this->pretTotal = 0.0;
}

Comanda::Comanda(string numeClient,string adresaClient, double pretTotal) {
	this->numeClient = numeClient;
	this->adresaClient = adresaClient;
	this->pretTotal = pretTotal;
}

Comanda::Comanda(string linie, char delim) {
	vector<string> split = splitLinie(linie, delim);
	this->numeClient = split[0];
	this->adresaClient = split[1];
	this->pretTotal = stringToDouble(split[2], 2);
}

Comanda::Comanda(const Comanda& comanda) {
	this->numeClient = comanda.numeClient;
	this->adresaClient = comanda.adresaClient;
	this->pretTotal = comanda.pretTotal;
}

Comanda::~Comanda() {
	this->pretTotal = 0.0;
}

string Comanda::getNumeClient(){
	return this->numeClient;
}

string Comanda::getAdresaClient(){
	return this->adresaClient;
}

double Comanda::getPretTotal(){
	return this->pretTotal;
}

void Comanda::setNumeClient(string numeClientNou){
	this->numeClient = numeClientNou;
}

void Comanda::setAdresaClient(string adresaClientNoua){
	this->adresaClient = adresaClientNoua;
}

void Comanda::setPretTotal(double pretTotalNou){
	this->pretTotal = pretTotalNou;

}

string Comanda::toString(string delim) {
	return this->numeClient + delim +
		this->adresaClient + delim +
		doubleToString(this->pretTotal, 2);
}

Comanda& Comanda::operator=(const Comanda& comanda){
	if (this == &comanda) {
		return *this;
	}
	this->numeClient = comanda.numeClient;
	this->adresaClient = comanda.adresaClient;
	this->pretTotal = comanda.pretTotal;

	return *this;
}

bool Comanda::operator==(const Comanda& comanda){
	return(this->numeClient ==  comanda.numeClient  &&
		this->adresaClient == comanda.adresaClient &&
		this->pretTotal == comanda.pretTotal);
}
