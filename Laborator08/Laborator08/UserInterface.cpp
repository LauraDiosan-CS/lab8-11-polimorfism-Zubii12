#include "UserInterface.h"
#include <iostream>
#include <vector>
#include "MyException.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

UserInterface::UserInterface(){
	this->REPO = 0;
}

UserInterface::UserInterface(const Service<RepositoryTemplateTXT<Mancare>, Mancare>& serviceMancareTXT,
	const Service<RepositoryTemplateTXT<Shopping>, Shopping>& serviceShoppingTXT,
	const Service<RepositoryTemplateCSV<Mancare>, Mancare>& serviceMancareCSV,
	const Service<RepositoryTemplateCSV<Shopping>, Shopping>& serviceShoppingCSV){

	this->serviceMancareTXT = serviceMancareTXT;
	this->serviceShoppingTXT = serviceShoppingTXT;

	this->serviceMancareCSV = serviceMancareCSV;
	this->serviceShoppingCSV = serviceShoppingCSV;
}

UserInterface::~UserInterface(){
	this->REPO = 0;
}

void UserInterface::mancareAdd(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaPreparate;
	string s;
	double pretTotal = 0.0;
	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de preparate: ";
	cout << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul " << i + 1 << ": ";
		cin >> s;
		listaPreparate.push_back(s);
 	}
	listaPreparate.insert(listaPreparate.begin(), std::to_string(len));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	if (this->REPO == 1) {
		serviceMancareTXT.add(Mancare(numeClient, adresaClient, listaPreparate, pretTotal));
	}
	else if (this->REPO == 2) {
		serviceMancareCSV.add(Mancare(numeClient, adresaClient, listaPreparate, pretTotal));
	}
	delete[] numeClient, adresaClient;
}

void UserInterface::mancareRemove(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaPreparate;
	string s;
	double pretTotal = 0.0;

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de preparate: ";
	cout << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul " << i + 1 << ": ";
		cin >> s;
		listaPreparate.push_back(s);
	}
	listaPreparate.insert(listaPreparate.begin(), std::to_string(len));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	if (this->REPO == 1) {
		if (serviceMancareTXT.find(Mancare(numeClient, adresaClient, listaPreparate, pretTotal))) {
			serviceMancareTXT.remove(Mancare(numeClient, adresaClient, listaPreparate, pretTotal));
			cout << "Stergere reusita !" << endl;
		}
		else {
			cout << "Stergere nereusita! " << endl;
		}
	}
	else if (this->REPO == 2) {
		if (serviceMancareCSV.find(Mancare(numeClient, adresaClient, listaPreparate, pretTotal))) {
			serviceMancareCSV.remove(Mancare(numeClient, adresaClient, listaPreparate, pretTotal));
			cout << "Stergere reusita !" << endl;
		}
		else {
			cout << "Stergere nereusita! " << endl;
		}

	}
	delete[] numeClient, adresaClient;
}

void UserInterface::mancareUpdate(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaPreparate;
	string s;
	double pretTotal = 0.0;

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de preparate: ";
	cout << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul " << i + 1 << ": ";
		cin >> s;
		listaPreparate.push_back(s);
	}
	listaPreparate.insert(listaPreparate.begin(), std::to_string(len));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	if (this->REPO == 1) {
		if (serviceMancareTXT.find(Mancare(numeClient, adresaClient, listaPreparate, pretTotal))) {
			char* numeNou = new char[10];
			char* adresaNoua = new char[10];
			int len = 0;
			vector<string> listaNoua;
			string s;
			double pretNou = 0.0;

			cout << "Introduceti numele nou al clientului: ";
			cin >> numeNou;
			cout << endl << "Introduceti adresa noua a clientului: ";
			cin >> adresaNoua;
			cout << endl << "Introduceti lista noua de preparate: ";
			cout << "Introduceti numarul de elemente: ";
			cin >> len;
			for (int i = 0; i < len; i++) {
				cout << "Introduceti elementul " << i + 1 << ": ";
				cin >> s;
				listaNoua.push_back(s);
			}
			listaNoua.insert(listaNoua.begin(), std::to_string(len));
			cout << endl << "Introduceti pretul nou total: ";
			cin >> pretNou;

			Mancare* m = new Mancare(numeClient, adresaClient, listaPreparate, pretTotal);
			serviceMancareTXT.update(*m, Mancare(numeNou, adresaNoua, listaNoua, pretNou));
			delete m;
			delete[] numeNou, adresaNoua;
			cout << "Update reusit! " << endl;
		}
		else {
			cout << "Update nereusit! " << endl;
		}
	}
	else if (this->REPO == 2) {
		if (serviceMancareCSV.find(Mancare(numeClient, adresaClient, listaPreparate, pretTotal))) {
			char* numeNou = new char[10];
			char* adresaNoua = new char[10];
			int len = 0;
			vector<string> listaNoua;
			string s;
			double pretNou = 0.0;

			cout << "Introduceti numele nou al clientului: ";
			cin >> numeNou;
			cout << endl << "Introduceti adresa noua a clientului: ";
			cin >> adresaNoua;
			cout << endl << "Introduceti lista noua de preparate: ";
			cin >> len;
			for (int i = 0; i < len; i++) {
				cout << "Introduceti elementul " << i + 1 << ": ";
				cin >> s;
				listaNoua.push_back(s);
			}
			listaNoua.insert(listaNoua.begin(), std::to_string(len));
			cout << endl << "Introduceti pretul nou total: ";
			cin >> pretNou;

			Mancare* m = new Mancare(numeClient, adresaClient, listaPreparate, pretTotal);
			serviceMancareCSV.update(*m, Mancare(numeNou, adresaNoua, listaNoua, pretNou));
			delete m;
			delete[] numeNou, adresaNoua;
			cout << "Update reusit! " << endl;
		}
		else {
			cout << "Update nereusit! " << endl;
		}
	}
	delete[] numeClient, adresaClient;
}

void UserInterface::mancareFind(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaPreparate;
	string s;
	double pretTotal = 0.0;

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de preparate: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul " << i + 1 << ": ";
		cin >> s;
		listaPreparate.push_back(s);
	}
	listaPreparate.insert(listaPreparate.begin(), std::to_string(len));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	if (this->REPO == 1) {
		if (serviceMancareTXT.find(Mancare(numeClient, adresaClient, listaPreparate, pretTotal))) {
			cout << "Cautare reusita !" << endl;
		}
		else {
			cout << "Cautare nereusita !" << endl;
		}
	}
	else if (this->REPO == 2) {
		if (serviceMancareCSV.find(Mancare(numeClient, adresaClient, listaPreparate, pretTotal))) {
			cout << "Cautare reusita !" << endl;
		}
		else {
			cout << "Cautare nereusita !" << endl;
		}
	}
	delete[] numeClient, adresaClient;
}

void UserInterface::shoppingAdd(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaCumparaturi;
	string s;
	double pretTotal = 0.0;
	char* numeMagazin = new char[10];

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de cumparaturi: ";
	cout << endl << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul  " << i << ": ";
		cin >> s;
		listaCumparaturi.push_back(s);
	}
	listaCumparaturi.insert(listaCumparaturi.begin(), std::to_string(listaCumparaturi.size()));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	cout << endl << "Introduceti numele magazinului: ";
	cin >> numeMagazin;
	if (this->REPO == 1) {
		serviceShoppingTXT.add(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeClient));
	}
	else if (this->REPO == 2) {
		serviceShoppingCSV.add(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeClient));
	}
	
	delete[] numeClient, adresaClient, numeMagazin;
}

void UserInterface::shoppingRemove(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaCumparaturi;
	string s;
	double pretTotal = 0.0;
	char* numeMagazin = new char[10];

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de cumparaturi: ";
	cout << endl << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul  " << i + 1 << ": ";
		cin >> s;
		listaCumparaturi.push_back(s);
	}
	listaCumparaturi.insert(listaCumparaturi.begin(), std::to_string(listaCumparaturi.size()));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	cout << endl << "Introduceti numele magazinului: ";
	cin >> numeMagazin;
	
	if (this->REPO == 1) {
		if (serviceShoppingTXT.find(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin))) {
			serviceShoppingTXT.remove(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin));
			cout << "Stergere reusita! " << endl;
		}
		else {
			cout << "Stergere nereusita! " << endl;
		}
	}
	else if (this->REPO == 2) {
		if (serviceShoppingCSV.find(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin))) {
			serviceShoppingCSV.remove(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin));
			cout << "Stergere reusita! " << endl;
		}
		else {
			cout << "Stergere nereusita! " << endl;
		}

	}
	delete[] numeClient, adresaClient, listaCumparaturi, numeMagazin;
}

void UserInterface::shoppingUpdate(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaCumparaturi;
	string s;
	double pretTotal = 0.0;
	char* numeMagazin = new char[10];

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de cumparaturi: ";
	cout << endl << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul  " << i + 1 << ": ";
		cin >> s;
		listaCumparaturi.push_back(s);
	}
	listaCumparaturi.insert(listaCumparaturi.begin(), std::to_string(listaCumparaturi.size()));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	cout << endl << "Introduceti numele magazinului: ";
	cin >> numeMagazin;

	if (this->REPO == 1) {
		if (serviceShoppingTXT.find(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin))) {
			char* numeNou = new char[10];
			char* adresaNoua = new char[10];
			int len = 0;
			vector<string> listaNoua;
			string st;
			double pretNou = 0.0;
			char* numeMagazinNou = new char[10];

			cout << "Introduceti numele nou al clientului: ";
			cin >> numeNou;
			cout << endl << "Introduceti adresa noua a clientului: ";
			cin >> adresaNoua;
			cout << endl << "Introduceti lista noua de preparate: ";
			cout << endl << "Introduceti numarul de elemente: ";
			cin >> len;
			for (int i = 0; i < len; i++) {
				cout << "Introduceti elementul  " << i + 1 << ": ";
				cin >> st;
				listaNoua.push_back(st);
			}
			listaNoua.insert(listaNoua.begin(), std::to_string(listaNoua.size()));
			cout << endl << "Introduceti pretul nou total: ";
			cin >> pretNou;
			cout << endl << "Introduceti numele nou al magazinului: ";

			Shopping* s = new Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin);
			serviceShoppingTXT.update(*s, Shopping(numeNou, adresaNoua, listaNoua, pretNou, numeMagazinNou));
			delete s;
			delete[] numeNou, adresaNoua, numeMagazinNou;
			cout << "Update reusit! " << endl;
		}
		else {
			cout << "Update nereusit! " << endl;
		}
	}
	else if (this->REPO == 2) {
		if (serviceShoppingCSV.find(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin))) {
			char* numeNou = new char[10];
			char* adresaNoua = new char[10];
			int len = 0;
			vector<string> listaNoua;
			string st;
			double pretNou = 0.0;
			char* numeMagazinNou = new char[10];

			cout << "Introduceti numele nou al clientului: ";
			cin >> numeNou;
			cout << endl << "Introduceti adresa noua a clientului: ";
			cin >> adresaNoua;
			cout << endl << "Introduceti lista noua de preparate: ";
			cout << endl << "Introduceti numarul de elemente: ";
			cin >> len;
			for (int i = 0; i < len; i++) {
				cout << "Introduceti elementul  " << i + 1 << ": ";
				cin >> st;
				listaNoua.push_back(st);
			}
			listaNoua.insert(listaNoua.begin(), std::to_string(listaNoua.size()));
			cout << endl << "Introduceti pretul nou total: ";
			cin >> pretNou;
			cout << endl << "Introduceti numele nou al magazinului: ";

			Shopping* s = new Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin);
			serviceShoppingCSV.update(*s, Shopping(numeNou, adresaNoua, listaNoua, pretNou, numeMagazinNou));
			delete s;
			delete[] numeNou, adresaNoua, numeMagazinNou;
			cout << "Update reusit! " << endl;
		}
		else {
			cout << "Update nereusit! " << endl;
		}

	}
	delete[] numeClient, adresaClient, numeMagazin;
}

void UserInterface::shoppingFind(){
	char* numeClient = new char[10];
	char* adresaClient = new char[10];
	int len = 0;
	vector<string> listaCumparaturi;
	string st;
	double pretTotal = 0.0;
	char* numeMagazin = new char[10];

	cout << "Introduceti numele clientului: ";
	cin >> numeClient;
	cout << endl << "Introduceti adresa clientului: ";
	cin >> adresaClient;
	cout << endl << "Introduceti lista de cumparaturi: ";
	cout << endl << "Introduceti numarul de elemente: ";
	cin >> len;
	for (int i = 0; i < len; i++) {
		cout << "Introduceti elementul  " << i + 1 << ": ";
		cin >> st;
		listaCumparaturi.push_back(st);
	}
	listaCumparaturi.insert(listaCumparaturi.begin(), std::to_string(listaCumparaturi.size()));
	cout << endl << "Introduceti pretul total: ";
	cin >> pretTotal;
	cout << endl << "Introduceti numele magazinului: ";
	cin >> numeMagazin;
	if (this->REPO == 1) {
		if (serviceShoppingTXT.find(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin))) {
			cout << "Cautare reusita! " << endl;
		}
		else {
			cout << "Cautare nereusita! " << endl;
		}
	}
	else if (this->REPO == 2) {
		if (serviceShoppingCSV.find(Shopping(numeClient, adresaClient, listaCumparaturi, pretTotal, numeMagazin))) {
			cout << "Cautare reusita! " << endl;
		}
		else {
			cout << "Cautare nereusita! " << endl;
		}
	}

	delete[] numeClient, adresaClient, numeMagazin;
}

void UserInterface::showAll(){
	if (this->REPO == 1) {
		auto allMancare = serviceMancareTXT.getAll();
		auto allShopping = serviceShoppingTXT.getAll();
		cout << " MANCARE " << endl;
		for (auto itr = allMancare.begin(); itr != allMancare.end(); itr++) {
			cout << itr->second << endl;
		}

		cout << " SHOPPING " << endl;
		for (auto itr = allShopping.begin(); itr != allShopping.end(); itr++) {
			cout << itr->second << endl;
		}
	}
	else if (this->REPO == 2) {
		auto allMancare = serviceMancareCSV.getAll();
		auto allShopping = serviceShoppingCSV.getAll();
		cout << " MANCARE " << endl;
		for (auto itr = allMancare.begin(); itr != allMancare.end(); itr++) {
			cout << itr->second << endl;
		}

		cout << " SHOPPING " << endl;
		for (auto itr = allShopping.begin(); itr != allShopping.end(); itr++) {
			cout << itr->second << endl;
		}
	}
}

void UserInterface::searchByName(){
	char* name = new char[10];
	cout << " Introduceti numele: ";
	cin >> name;
	if (this->REPO == 1) {
		vector<Mancare> allM = serviceMancareTXT.searchByName(name);
		cout << "MANCARE :" << endl;
		for (vector<Mancare>::iterator itr = allM.begin(); itr < allM.end(); itr++) {
			cout << *itr << endl;
		}
		vector<Shopping> allS = serviceShoppingTXT.searchByName(name);
		cout << "SHOPPING: " << endl;
		for (vector<Shopping>::iterator itr = allS.begin(); itr < allS.end(); itr++) {
			cout << *itr << endl;
		}
	}
	else if (this->REPO == 2) {
		vector<Mancare> allM = serviceMancareCSV.searchByName(name);
		cout << "MANCARE :" << endl;
		for (vector<Mancare>::iterator itr = allM.begin(); itr < allM.end(); itr++) {
			cout << *itr << endl;
		}
		vector<Shopping> allS = serviceShoppingCSV.searchByName(name);
		cout << "SHOPPING: " << endl;
		for (vector<Shopping>::iterator itr = allS.begin(); itr < allS.end(); itr++) {
			cout << *itr << endl;
		}
	}
	delete[] name;
}

bool UserInterface::loginUser() {
	char* userName = new char[10];
	char* password = new char[10];
	int incercare = 0;

	cout << " \t LOGIN " << endl;

	cout << "Introduceti user name: ";
	cin >> userName;
	cout << endl << "Introduceti parola: ";
	cin >> password;

	while (incercare < 4) {
		if (login->runLogin(userName, password)) {
			cout << "LOGARE REUSITA! " << endl;
			delete[] userName, password;
			return true;
		}
		else {
			incercare++;
			cout << "DATE DE LOGARE GRESITE, MAI AVETI " << (4 - incercare) + 1 << " INCERCARI DE LOGARE !" << endl;
			cout << "Introduceti user name: ";
			cin >> userName;
			cout << endl << "Introduceti parola: ";
			cin >> password;
		}
	}
	if (incercare == 4) {
		cout << "LOGARE NEREUSITA, PROGRAMUL SE VA INCHIDE ! " << endl;
	}
	delete[] userName, password;
	return false;
}

int UserInterface::chooseRepo() {
	int choose = 0;
	bool stop = false;
	while (!stop) {
		cout << "ALEGETI UN REPO: " << endl;
		cout << "1. TXT" << endl;
		cout << "2. CSV" << endl;
		cout << "x. Iesire" << endl;
		cout << "Introduceti optiunea aleasa!" << endl;
		char* op = new char[3];
		cin >> op;
		switch (*op) {
		case '1': {return 1; break; }
		case '2': {return 2; break; }
		case 'x': {stop = true; break; }
		default: {cout << "OPTIUNE INEXISTENTA! " << endl; delete[] op; break; }
		}
	}
	return -1;
}

void UserInterface::showUI() {
	if (loginUser()) {
		int repoID = chooseRepo();
		if (repoID == 1) { // 1 - TXT
			this->REPO = 1; 
		}
		else if (repoID == 2) { // 2 - CSV
			this->REPO = 2;
		}
		else if (repoID == -1) {
			return;
		}
		bool stop = false;
		while (!stop) {
			cout << endl;
			cout << "OPTIUNI: " << endl;
			cout << "1. Mancare" << endl;
			cout << "2. Shopping  " << endl;
			cout << "3. Afiseaza Mancare && Shopping " << endl;
			cout << "4. Cautare dupa nume " << endl;
			cout << "x. Iesire " << endl;
			cout << "Introduceti optiunea dorita: ";
			char* op = new char[3];
			cin >> op;
			switch (*op) {
			case '1': {
				cout << "OPTIUNI MANCARE: " << endl;
				cout << "1. Adaugare mancare " << endl;
				cout << "2. Stergere mancare " << endl;
				cout << "3. Modifica mancare " << endl;
				cout << "4. Cauta mancare " << endl;
				cout << "5. Inapoi " << endl;
				cout << "Introduceti optiunea dorita: ";
				char op1;
				cin >> op1;
				switch (op1) {
				case '1': {mancareAdd(); break; }
				case '2': {mancareRemove(); break; }
				case '3': {mancareUpdate(); break; }
				case '4': {mancareFind(); break; }
				case'5': {break; }
				default: {cout << "OPTIUNE INEXISTENTA"; }
				}
				break;
			}
			case '2': {
				cout << "OPTIUNI SHOPPING: " << endl;
				cout << "1. Adaugare shopping " << endl;
				cout << "2. Stergere shopping " << endl;
				cout << "3. Modifica shopping " << endl;
				cout << "4. Cauta shopping " << endl;
				cout << "5. Inapoi " << endl;
				cout << "Introduceti optiunea dorita: ";
				char op1;
				cin >> op1;
				switch (op1) {
				case '1': {shoppingAdd(); break; }
				case '2': {shoppingRemove(); break; }
				case '3': {shoppingUpdate(); break; }
				case '4': {shoppingFind(); break; }
				case'5': {break; }
				default: {cout << "OPTIUNE INEXISTENTA" << endl; }
				}
				break;
			}
			case '3': {showAll(); break; }
			case '4': {searchByName(); break; }
			case 'x': {stop = true; break; }
			default: {cout << "OPTIUNE INEXISTENTA" << endl; delete[] op; break; }
			}
		}
	}
	else {
		return;
	}
}

