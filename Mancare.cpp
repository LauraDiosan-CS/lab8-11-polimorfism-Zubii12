#include "Mancare.h"
#include "Comanda.h"
#include <sstream>
#include "Utils.h"
#include <iostream>

Mancare::Mancare() 
	:Comanda(){
}

Mancare::Mancare(string numeClient, string adresaClient, double pretTotal, vector<string> listaPreparate)
	:Comanda(numeClient, adresaClient, pretTotal){
	for (unsigned int i = 0; i < listaPreparate.size(); i++) {
		this->listaPreparate.push_back(listaPreparate[i]);
	}
}

Mancare::Mancare(string linie, char delim)
	:Comanda(linie, delim) {
	vector<string> split = splitLinie(linie, delim);
	for (unsigned int i = 3; i < split.size(); i++) {
		this->listaPreparate.push_back(split[i]);
	}
}

Mancare::Mancare(const Mancare& mancare)
	:Comanda(mancare){
	for (unsigned int i = 0; i < mancare.listaPreparate.size(); i++) {
		this->listaPreparate.push_back(mancare.listaPreparate[i]);
	}
}

Mancare::~Mancare(){
	this->listaPreparate.clear();
}

vector<string> Mancare::getListaPreparate(){
	return this->listaPreparate;
}

void Mancare::setListaPreparate(vector<string> listaPreparateNoua){
	this->listaPreparate.clear();
	for (unsigned int i = 0; i < listaPreparateNoua.size(); i++) {
		this->listaPreparate.push_back(listaPreparateNoua[i]);
	}
}

string Mancare::toString(string delim){
	string out = this->Comanda::toString(delim);
	out.insert(0, string("Mancare") + delim);
	for (unsigned int i = 0; i < this->listaPreparate.size(); i++) {
		out = out + delim + this->listaPreparate[i];
	}
	return out;
}

Mancare& Mancare::operator=(const Mancare& mancare){
	this->Comanda::operator=(mancare);
	this->listaPreparate.clear();
	for (unsigned int i = 0; i < mancare.listaPreparate.size(); i++) {
		this->listaPreparate.push_back(mancare.listaPreparate[i]);
	}
	return *this;
}

bool Mancare::operator==(const Mancare& mancare){
	return (this->Comanda::operator==(mancare) &&
		this->listaPreparate == mancare.listaPreparate);
}

std::istream& operator>>(std::istream& is, Mancare& mancare){
	string numeClient, adresaClient;
	double pretTotal;
	int len;
	vector<string> listaPreparate;
	string s;

	is >> numeClient >> adresaClient >> pretTotal >> len;
	for (int i = 0; i < len; i++) {
		is >> s;
		listaPreparate.push_back(s);
	}
	listaPreparate.insert(listaPreparate.begin(), std::to_string(len));

	mancare.setNumeClient(numeClient);
	mancare.setAdresaClient(adresaClient);
	mancare.setListaPreparate(listaPreparate);
	mancare.setPretTotal(pretTotal);
	mancare.setListaPreparate(listaPreparate);
	
	return is;
}

std::ostream& operator<<(std::ostream& os, Mancare& mancare) {
	os << mancare.numeClient << " "
		<< mancare.adresaClient << " "
		<< mancare.pretTotal<< " ";
	for (unsigned int i = 0; i < mancare.listaPreparate.size(); i++) {
		os << mancare.listaPreparate[i] << " ";
	}
	os << std::endl;
	return os;
}
