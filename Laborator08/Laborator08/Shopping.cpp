#include "Shopping.h"
#include "Comanda.h"
#include <sstream>

Shopping::Shopping():Comanda(){
	this->numeMagazin = NULL;
	this->all = NULL;
}

Shopping::Shopping(const char* numeClient, const char* adresaClient, vector<string> listaCumparaturi, double pretTotal, const char* numeMagazin) 
:Comanda(numeClient, adresaClient, pretTotal){
	for (unsigned int i = 0; i < listaCumparaturi.size(); i++) {
		this->listaCumparaturi.push_back(listaCumparaturi[i]);
	}
	this->numeMagazin = new char[strlen(numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(numeMagazin) + 1, numeMagazin);
}

Shopping::Shopping(const Shopping& shopping)
:Comanda(shopping){
	for (unsigned int i = 0; i < shopping.listaCumparaturi.size(); i++) {
		this->listaCumparaturi.push_back(shopping.listaCumparaturi[i]);
	}

	this->numeMagazin = new char[strlen(shopping.numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(shopping.numeMagazin) + 1, shopping.numeMagazin);
}

Shopping::~Shopping(){
	if (this->listaCumparaturi.size()) {
		//this->listaCumparaturi.clear();
	}

	if(this->numeMagazin) {
		delete[] this->numeMagazin;
	}
	this->numeMagazin = NULL;
	if (this->all) {
		//delete[] this->all;
	}
	this->all = NULL;
}

vector<string> Shopping::getListaCumparaturi(){
	return this->listaCumparaturi;
}

char* Shopping::getNumeMagazin(){
	return this->numeMagazin;
}

void Shopping::setListaCumparaturi(vector<string> listaCumparaturiNoua){
	this->listaCumparaturi.clear();
	for (unsigned int i = 0; i < listaCumparaturiNoua.size(); i++) {
		this->listaCumparaturi.push_back(listaCumparaturiNoua[i]);
	}
}

void Shopping::setNumeMagazin(const char* numeMagazinNou){
	if (this->numeMagazin) {
		delete[] this->numeMagazin;
		this->numeMagazin = NULL;
	}
	this->numeMagazin = new char[strlen(numeMagazinNou) + 1];
	strcpy_s(this->numeMagazin, strlen(numeMagazinNou) + 1, numeMagazinNou);
}

char* Shopping::toStringForCSV() {
	char* c = new char[10];
	std::stringstream ss;
	ss << this->pretTotal;
	ss >> c;
	int lenLista = 0;
	for (unsigned int i = 0; i < this->listaCumparaturi.size(); i++) {
		lenLista = lenLista + this->listaCumparaturi[i].size();
	}
	char* lista = new char[lenLista + 1];

	int len = strlen(this->numeClient) +
		strlen(this->adresaClient) +
		strlen(lista) +
		strlen(c) + 
		strlen(this->numeMagazin) + 1 + 4;

	this->all = new char[len];

	strcpy_s(all, len, this->numeClient);
	strcat_s(all, len, ",");
	strcat_s(all, len, this->adresaClient);
	strcat_s(all, len, ",");
	for (unsigned int i = 0; i < this->listaCumparaturi.size(); i++) {
		strcat_s(all, len, this->listaCumparaturi[i].c_str());
		strcat_s(all, len, ",");
	}
	strcat_s(all, len, c);
	strcat_s(all, len, ",");
	strcat_s(all, len, this->numeMagazin);

	delete[] c, lista;
	return all;
}

Shopping& Shopping::operator=(const Shopping& shopping){
	this->Comanda::operator=(shopping);
	this->listaCumparaturi.clear();
	for (unsigned int i = 0; i < shopping.listaCumparaturi.size(); i++) {
		this->listaCumparaturi.push_back(shopping.listaCumparaturi[i]);
	}

	if (this->numeMagazin) {
		delete[] this->numeMagazin;
		this->numeMagazin = NULL;
	}
	this->numeMagazin = new char[strlen(shopping.numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(shopping.numeMagazin) + 1, shopping.numeMagazin);

	return *this;
}

bool Shopping::operator==(const Shopping& shopping){
	return (this->Comanda::operator==(shopping) &&
		this->listaCumparaturi == shopping.listaCumparaturi &&
		strcmp(this->numeMagazin, shopping.numeMagazin) == 0);
}

std::ostream& operator<<(std::ostream& os, Shopping& shopping){
	os << shopping.numeClient << " "
		<< shopping.adresaClient << " ";
	for (unsigned int i = 0; i < shopping.listaCumparaturi.size(); i++) {
		os << shopping.listaCumparaturi[i] << " ";
	} 
	os << shopping.pretTotal << " "
		<< shopping.numeMagazin << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Shopping& shopping){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	string len;
	vector<string> listaCumparaturi;
	string s;
	double pretTotal = 0.0;
	char* numeMagazin = new char[10];

	is >> numeClient;
	is >> adresaClient;
	is >> len;
	int lenn = stoi(len);
	for (int i = 0; i < lenn; i++) {
		is >> s;
		listaCumparaturi.push_back(s);
	}
	listaCumparaturi.insert(listaCumparaturi.begin(), len);
	is >> pretTotal;
	is >> numeMagazin;

	shopping.setNumeClient(numeClient);
	shopping.setAdresaClient(adresaClient);
	shopping.setListaCumparaturi(listaCumparaturi);
	shopping.setPretTotal(pretTotal);
	shopping.setNumeMagazin(numeMagazin);

	delete[] numeClient, adresaClient, numeMagazin;
	
	return is;
}
