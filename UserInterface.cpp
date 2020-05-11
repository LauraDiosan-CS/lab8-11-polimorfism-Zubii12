#include "UserInterface.h"
#include <iostream>
#include <vector>
#include "MyException.h"
#include "SerializerComanda.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

UserInterface::UserInterface(){
}

UserInterface::UserInterface(Service& service){
	this->service = service;
}

UserInterface::~UserInterface(){
}

void UserInterface::mancareAdd(){
	try {
		string numeClient;
		string adresaClient;
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
		cout << endl;
		service.add("Mancare", numeClient, adresaClient, pretTotal, listaPreparate);
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
}

void UserInterface::mancareRemove(){
	try {
		string numeClient;
		string adresaClient;
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

		if (service.find("Mancare", numeClient, adresaClient, pretTotal, listaPreparate)) {
			service.remove("Mancare", numeClient, adresaClient, pretTotal, listaPreparate);
			cout << "Stergere reusita !" << endl;
		}
		else {
			cout << "Stergere nereusita! " << endl;
		}
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
}

void UserInterface::mancareUpdate(){
	try {
		string numeClient;
		string adresaClient;
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
		if (service.find("Mancare", numeClient, adresaClient, pretTotal, listaPreparate)) {
			string numeNou;
			string adresaNoua;
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

			service.update("Mancare", numeClient, adresaClient, pretTotal, listaPreparate,
				"Mancare", numeNou, adresaNoua, pretNou, listaNoua);
			cout << "Update reusit! " << endl;
		}
		else {
			cout << "Update nereusit! " << endl;
		}
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}

}

void UserInterface::mancareFind(){
	try {
		string numeClient;
		string adresaClient;
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
		if (service.find("Mancare", numeClient, adresaClient, pretTotal, listaPreparate)) {
			cout << "Cautare reusita !" << endl;
		}
		else {
			cout << "Cautare nereusita !" << endl;
		}
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
}

void UserInterface::shoppingAdd() {
	try {
		string numeClient;
		string adresaClient;
		int len = 0;
		vector<string> listaCumparaturi;
		string s;
		double pretTotal = 0.0;
		string numeMagazin;

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
		service.add("Shopping", numeClient, adresaClient, pretTotal, numeClient, listaCumparaturi);
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
}

void UserInterface::shoppingRemove(){
	try {
		string numeClient;
		string adresaClient;
		int len = 0;
		vector<string> listaCumparaturi;
		string s;
		double pretTotal = 0.0;
		string numeMagazin;

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
		if (service.find("Shopping", numeClient, adresaClient, pretTotal, numeMagazin, listaCumparaturi)) {
			service.remove("Shopping", numeClient, adresaClient, pretTotal, numeMagazin, listaCumparaturi);
			cout << "Stergere reusita! " << endl;
		}
		else {
			cout << "Stergere nereusita! " << endl;
		}
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
}

void UserInterface::shoppingUpdate(){
	string numeClient;
	string adresaClient;
	int len = 0;
	vector<string> listaCumparaturi;
	string s;
	double pretTotal = 0.0;
	string numeMagazin;
	try {
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
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
	if (service.find("Shopping", numeClient, adresaClient, pretTotal, numeMagazin, listaCumparaturi)) {
		string numeNou;
		string adresaNoua;
		int len = 0;
		vector<string> listaNoua;
		string st;
		double pretNou = 0.0;
		string numeMagazinNou;
		try {
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

			service.update("Shopping", numeClient, adresaClient, pretTotal, numeMagazin, listaCumparaturi,
				"Shopping", numeNou, adresaNoua, listaNoua, pretNou, numeMagazinNou);
		}
		catch (const MyException& ex) {
			cout << ex.what();
		}
		cout << "Update reusit! " << endl;
	}
	else {
		cout << "Update nereusit! " << endl;
	}
}


void UserInterface::shoppingFind(){
	string numeClient;
	string adresaClient;
	int len = 0;
	vector<string> listaCumparaturi;
	string st;
	double pretTotal = 0.0;
	string numeMagazin;
	try {
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
		if (service.find("Shopping", numeClient, adresaClient, pretTotal, numeMagazin, listaCumparaturi)) {
			cout << "Cautare reusita! " << endl;
		}
		else {
			cout << "Cautare nereusita! " << endl;
		}
	}
	catch (const MyException& ex) {
		cout << ex.what();
	}
}

void UserInterface::showAll(){
	auto all = service.getAll();
	if (all.size()) {
		for (auto crt : all) {
			cout << *crt << endl;
		}
	}
	else {
		cout << " Nu s-a gasit nimic! " << endl;
	}
}

void UserInterface::searchByName(){
	string name;
	cout << " Introduceti numele: ";
	cin >> name;
	vector<Comanda*> allM = service.searchByName(name);
	if (allM.size()) {
		//for (vector<Comanda*>::iterator itr = allM.begin(); itr < allM.end(); itr++) {
		for(auto crt : allM){
			cout << *crt << endl;
		}
	}
	else {
		cout << " Nu s-a gasit nimic! " << endl;
	}
}

bool UserInterface::loginUser() {
	string userName;
	string password;
	int incercare = 0;

	cout << " \t LOGIN " << endl;

	cout << "Introduceti user name: ";
	cin >> userName;
	cout << endl << "Introduceti parola: ";
	cin >> password;

	while (incercare < 4) {
		if (login->runLogin(userName, password)) {
			cout << "LOGARE REUSITA! " << endl;
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
	return false;
}

void UserInterface::chooseRepo() {
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
		case '1': {
			Serializer<Comanda*>* serializer = new SerializerComanda;
			IRepository<Comanda*>* repoComanda = new RepositoryFileTXT<Comanda*>("Comanda.txt", serializer);
			((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
			service.setRepo(repoComanda);
			cout << " Repository TXT setat cu succes! \n";
			stop = true;
			break;
		}
		case '2': {
			Serializer<Comanda*>* serializer = new SerializerComanda;
			IRepository<Comanda*>* repoComanda = new RepositoryFileCSV<Comanda*>("Comanda.csv", serializer);
			((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
			service.setRepo(repoComanda);
			cout << " Repository CSV setat cu succes! \n";
			stop = true;
			break; 
		}
		case 'x': {stop = true; break; }
		default: {cout << "OPTIUNE INEXISTENTA! " << endl; delete[] op; break; }
		}
	}
}

void UserInterface::showUI() {
	if (loginUser()) {
		chooseRepo();
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

