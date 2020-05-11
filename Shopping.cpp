#include "Shopping.h"
#include "Comanda.h"
#include <sstream>
#include "Utils.h"

Shopping::Shopping()
	:Comanda(){
}

Shopping::Shopping(string numeClient, string adresaClient, double pretTotal, string numeMagazin, vector<string> listaCumparaturi)
	:Comanda(numeClient, adresaClient, pretTotal){
	for (unsigned int i = 0; i < listaCumparaturi.size(); i++) {
		this->listaCumparaturi.push_back(listaCumparaturi[i]);
	}
	this->numeMagazin = numeMagazin;
}

Shopping::Shopping(string linie, char delim)
	:Comanda(linie, delim){
	vector<string> split = splitLinie(linie, delim);
	this->numeMagazin = split[3];
	for (unsigned int i = 4; i < split.size(); i++) {
		this->listaCumparaturi.push_back(split[i]);
	}
}

Shopping::Shopping(const Shopping& shopping)
	:Comanda(shopping){
	for (unsigned int i = 0; i < shopping.listaCumparaturi.size(); i++) {
		this->listaCumparaturi.push_back(shopping.listaCumparaturi[i]);
	}
	this->numeMagazin = shopping.numeMagazin;
}

Shopping::~Shopping(){
	if (this->listaCumparaturi.size()) {
		this->listaCumparaturi.clear();
	}
}

vector<string> Shopping::getListaCumparaturi(){
	return this->listaCumparaturi;
}

string Shopping::getNumeMagazin(){
	return this->numeMagazin;
}

void Shopping::setListaCumparaturi(vector<string> listaCumparaturiNoua){
	this->listaCumparaturi.clear();
	for (unsigned int i = 0; i < listaCumparaturiNoua.size(); i++) {
		this->listaCumparaturi.push_back(listaCumparaturiNoua[i]);
	}
}

void Shopping::setNumeMagazin(string numeMagazinNou){
	this->numeMagazin = numeMagazinNou;
}

string Shopping::toString(string delim) {
	string out = Comanda::toString(delim);
	out.insert(0, string("Shopping") + delim);
	out = out + delim + this->numeMagazin;
	for (unsigned int i = 0; i < this->listaCumparaturi.size(); i++) {
		out = out + delim + this->listaCumparaturi[i];
	}
	return out;
}

Shopping& Shopping::operator=(const Shopping& shopping){
	this->Comanda::operator=(shopping);
	this->listaCumparaturi.clear();
	for (unsigned int i = 0; i < shopping.listaCumparaturi.size(); i++) {
		this->listaCumparaturi.push_back(shopping.listaCumparaturi[i]);
	}
	this->numeMagazin = shopping.numeMagazin;
	return *this;
}

bool Shopping::operator==(const Shopping& shopping){
	return (this->Comanda::operator==(shopping) &&
		this->listaCumparaturi == shopping.listaCumparaturi &&
		this->numeMagazin == shopping.numeMagazin);
}

std::ostream& operator<<(std::ostream& os, Shopping& shopping){
	os << shopping.numeClient << " "
		<< shopping.adresaClient << " "
		<< shopping.pretTotal << " "
		<< shopping.numeMagazin << " ";
	for (unsigned int i = 0; i < shopping.listaCumparaturi.size(); i++) {
		os << shopping.listaCumparaturi[i] << " ";
	} 
	os << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Shopping& shopping){
	string numeClient, adresaClient;
	double pretTotal;
	int len;
	string numeMagazin;
	vector<string> listaCumparaturi;
	string s;

	is >> numeClient >> adresaClient >> pretTotal >> numeMagazin >> len;
	for (int i = 0; i < len; i++) {
		is >> s;
		listaCumparaturi.push_back(s);
	}
	listaCumparaturi.insert(listaCumparaturi.begin(), std::to_string(len));

	shopping.setNumeClient(numeClient);
	shopping.setAdresaClient(adresaClient);
	shopping.setPretTotal(pretTotal);
	shopping.setNumeMagazin(numeMagazin);
	shopping.setListaCumparaturi(listaCumparaturi);

	return is;
}
