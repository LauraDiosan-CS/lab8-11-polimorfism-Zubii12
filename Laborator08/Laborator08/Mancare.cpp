#include "Mancare.h"
#include "Comanda.h"
#include <sstream>

Mancare::Mancare()
:Comanda(){
	this->all = NULL;
}

Mancare::Mancare(const char* numeClient, const char* adresaClient, vector<string> listaPreparate, double pretTotal)
:Comanda(numeClient, adresaClient, pretTotal){
	for (unsigned int i = 0; i < listaPreparate.size(); i++) {
		this->listaPreparate.push_back(listaPreparate[i]);
	}
}

Mancare::Mancare(const Mancare& mancare)
:Comanda(mancare){
	for (unsigned int i = 0; i < mancare.listaPreparate.size(); i++) {
		this->listaPreparate.push_back(mancare.listaPreparate[i]);
	}

}

Mancare::~Mancare(){
	//this->listaPreparate.clear();
	this->all = NULL;
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

char* Mancare::toStringForCSV() {
	char* c = new char[10];
	std::stringstream ss;
	ss << this->pretTotal;
	ss >> c;
	
	int lenLista = 0;
	for (unsigned int i = 0; i < this->listaPreparate.size(); i++) {
		lenLista = lenLista + this->listaPreparate[i].size();
	}
	char* lista = new char[lenLista + 1];

	int len = strlen(this->numeClient) +
		strlen(this->adresaClient) +
		strlen(lista) +
		strlen(c) + 1 + 3;

	this->all = new char[len];	

	strcpy_s(all, len, this->numeClient);
	strcat_s(all, len, ",");
	strcat_s(all, len, this->adresaClient);
	strcat_s(all, len, ",");
	for (unsigned int i = 0; i < this->listaPreparate.size(); i++) {
		strcat_s(all, len, this->listaPreparate[i].c_str());
		strcat_s(all, len, ",");
	}
	strcat_s(all, len, c);

	delete[] c, lista;
	return all;
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

std::ostream& operator<<(std::ostream& os, Mancare& mancare){
	os << mancare.numeClient << " "
		<< mancare.adresaClient << " ";
	for (unsigned int i = 0; i < mancare.listaPreparate.size(); i++) {
		os << mancare.listaPreparate[i] << " ";
	}
	os << mancare.pretTotal << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Mancare& mancare){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	string len;
	vector<string> listaPreparate;
	string s;
	double pretTotal = 0.0;

	is >> numeClient;
	is >> adresaClient;
	is >> len;
	int lenn = stoi(len);
	for (int i = 0; i < lenn; i++) {
		is >> s;
		listaPreparate.push_back(s);
	}
	listaPreparate.insert(listaPreparate.begin(), len);
	
	is >> pretTotal;

	mancare.setNumeClient(numeClient);
	mancare.setAdresaClient(adresaClient);
	mancare.setListaPreparate(listaPreparate);
	mancare.setPretTotal(pretTotal);

	delete[] numeClient, adresaClient;
	
	return is;
}
