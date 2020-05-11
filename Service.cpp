#include "Service.h"
#include <vector>
#include "ValidareMancare.h"
#include "ValidareShopping.h"

using std::string;
using std::vector;

Service::Service(){
	this->repoComanda = nullptr;
}

Service::Service(IRepository<Comanda*>* repoComanda){
	this->repoComanda = repoComanda;
}

Service::~Service(){
	this->repoComanda = nullptr;
}

void Service::setRepo(IRepository<Comanda*>* repoComanda){
	this->repoComanda = repoComanda;
}

void Service::add(const char* type, ...){
	va_list args;
	va_start(args, type);
	((RepositoryFile<Comanda*>*)repoComanda)->clearStorage();
	((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
	if (strcmp(type, "Mancare") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		vector<string> d = va_arg(args, vector<string>);

		ValidareMancare valid(Mancare(a, b, c, d));

		Comanda* m = new Mancare(a, b, c, d);
		
		((RepositoryFile<Comanda*>*)repoComanda)->add(m);
	}
	else if (strcmp(type, "Shopping") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		string d = va_arg(args, string);
		vector<string> e= va_arg(args, vector<string>);
		
		ValidareShopping valid(Shopping(a, b, c, d, e));

		Comanda* s = new Shopping(a, b, c, d, e);

		((RepositoryFile<Comanda*>*)repoComanda)->add(s);
	}
	va_end(args);
	((RepositoryFile<Comanda*>*)repoComanda)->saveToFile();
}

void Service::remove(const char* type, ...){
	va_list args;
	va_start(args, type);
	((RepositoryFile<Comanda*>*)repoComanda)->clearStorage();
	((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
	if (strcmp(type, "Mancare") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		vector<string> d = va_arg(args, vector<string>);
		ValidareMancare valid(Mancare(a, b, c, d));

		Comanda* m = new Mancare(a, b, c, d);

		((RepositoryFile<Comanda*>*)repoComanda)->remove(m);
	}
	else if (strcmp(type, "Shopping") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		string d = va_arg(args, string);
		vector<string> e = va_arg(args, vector<string>);

		ValidareShopping valid(Shopping(a, b, c, d, e));

		Comanda* s = new Shopping(a, b, c, d, e);

		((RepositoryFile<Comanda*>*)repoComanda)->remove(s);
	}
	va_end(args);
	((RepositoryFile<Comanda*>*)repoComanda)->saveToFile();
}

void Service::update(const char* type, ...){
	va_list args;
	va_start(args, type);
	((RepositoryFile<Comanda*>*)repoComanda)->clearStorage();
	((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
	if (strcmp(type, "Mancare") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		vector<string> d = va_arg(args, vector<string>);
		ValidareMancare valid(Mancare(a, b, c, d));

		Comanda* m = new Mancare(a, b, c, d);

		string aa = va_arg(args, string);
		string bb = va_arg(args, string);
		double cc = va_arg(args, double);
		vector<string> dd = va_arg(args, vector<string>);
		ValidareMancare validd(Mancare(aa, bb, cc, dd));

		Comanda* mNou = new Mancare(aa, bb, cc, dd);


		((RepositoryFile<Comanda*>*)repoComanda)->update(m, mNou);
	}
	else if (strcmp(type, "Shopping") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		string d = va_arg(args, string);
		vector<string> e = va_arg(args, vector<string>);
		
		ValidareShopping valid(Shopping(a, b, c, d, e));

		Comanda* s = new Shopping(a, b, c, d, e);
		
		string aa = va_arg(args, string);
		string bb = va_arg(args, string);
		double cc = va_arg(args, double);
		string dd = va_arg(args, string);
		vector<string> ee = va_arg(args, vector<string>);

		ValidareShopping validd(Shopping(aa, bb, cc, dd, ee));

		Comanda* sNou = new Shopping(aa, bb, cc, dd, ee);
		
		((RepositoryFile<Comanda*>*)repoComanda)->update(s, sNou);
	}
	va_end(args);
	((RepositoryFile<Comanda*>*)repoComanda)->saveToFile();
}

bool Service::find(const char* type, ...){
	va_list args;
	va_start(args, type);
	((RepositoryFile<Comanda*>*)repoComanda)->clearStorage();
	((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
	if (strcmp(type, "Mancare") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		vector<string> d = va_arg(args, vector<string>);

		ValidareMancare valid(Mancare(a, b, c, d));

		Comanda* m = new Mancare(a, b, c, d);

		if (repoComanda->find(m)) {
			va_end(args);
			return true;
		}
		va_end(args);
		return false;
	}
	else if (strcmp(type, "Shopping") == 0) {
		string a = va_arg(args, string);
		string b = va_arg(args, string);
		double c = va_arg(args, double);
		string d = va_arg(args, string);
		vector<string> e = va_arg(args, vector<string>);

		ValidareShopping valid(Shopping(a, b, c, d, e));

		Comanda* s = new Shopping(a, b, c, d, e);

		if (((RepositoryFile<Comanda*>*)repoComanda)->find(s)) {
			va_end(args);
			return true;
		}
		va_end(args);
		return false;
	}
	va_end(args);
}

int Service::size(){
	((RepositoryFile<Comanda*>*)repoComanda)->clearStorage();
	((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();
	return ((RepositoryFile<Comanda*>*)repoComanda)->size();
}

vector<Comanda*> Service::searchByName(string name){
	auto all = ((RepositoryFile<Comanda*>*)repoComanda)->getAll();
	vector<Comanda*> allGood;
	for (unsigned int i = 0; i < all.size(); i++) {
		if (all[i]->getNumeClient() == name) {
			allGood.push_back(all[i]);
		}
	}
	return allGood;
}

std::vector<Comanda*> Service::getAll(){
	((RepositoryFile<Comanda*>*)repoComanda)->clearStorage();
	((RepositoryFile<Comanda*>*)repoComanda)->loadFromFile();

	return ((RepositoryFile<Comanda*>*)repoComanda)->getAll();
}
