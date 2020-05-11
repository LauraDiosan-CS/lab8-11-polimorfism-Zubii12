#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "Shopping.h"
#include "Mancare.h"
#include "Login.h"
#include <cstdarg>

class Service {
private:
	IRepository<Comanda*>* repoComanda;
public:
	Service();
	Service(IRepository<Comanda*>* repoComanda);
	~Service();

	void setRepo(IRepository<Comanda*>* repoComanda);
	void add(const char* type, ...);
	void remove(const char* type, ...);
	void update(const char* type, ...);
	bool find(const char* type, ...);
	int size();

	vector<Comanda*> searchByName(string name);

	vector<Comanda*> getAll();
};
