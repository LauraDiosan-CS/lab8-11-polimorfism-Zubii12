#include "TestService.h"
#include "Service.h"
#include <assert.h>
#include "Serializer.h"
#include "SerializerComanda.h"
#include "RepositoryFileTXT.h"
#include "Comanda.h"
#include <iostream>

TestService::TestService() {
}

TestService::~TestService() {
}

void TestService::teste() {
	Serializer<Comanda*>* serializer = new SerializerComanda;
	IRepository<Comanda*>* repo = new RepositoryFileTXT<Comanda*>("TestComandaService.txt", serializer);
	((RepositoryFile<Comanda*>*)repo)->clearFile();
	Service service(repo);

	vector<string> s1 = { "2", "oua1", "oua1" };
	vector<string> s2 = { "2", "oua2", "oua2" };
	vector<string> s3 = { "2", "oua3", "oua3" };
	string a1 = "zubii1", a2 = "1Dec";
	string b1 = "zubii2", b2 = "2Dec";
	string c1 = "zubii3", c2 = "3Dec";
	string d1 = "profi1", d2 = "profi2", d3 = "profi3";
	assert(service.size() == 0);

	service.add("Mancare", a1, a2, 1.10, s1);
	service.add("Mancare", b1, b2, 1.20, s2);
	service.add("Mancare", c1, c2, 1.30, s3);
	assert(service.size() == 3);

	service.add("Shopping", a1, a2, 1.10, d1, s1);
	service.add("Shopping", b1, b2, 1.20, d2, s2);
	service.add("Shopping", c1, c2, 1.30, d3, s3);
	assert(service.size() == 6);

	assert(service.find("Mancare", c1, c2, 1.30, s3));
	service.remove("Mancare", c1, c2, 1.30, s3);
	assert(!service.find("Mancare", c1, c2, 1.30, s3));

	assert(service.size() == 5);

	service.update("Shopping", a1, a2, 1.10, d1, s1, a1, a2, 1.2, d2, s2);
	assert(!service.find("Shopping", a1, a2, 1.10, d1, s1));
	assert(service.find("Shopping", b1, b2, 1.20, d2, s2));

	auto all = service.getAll();
	Comanda* m1 = new Mancare("zubii1", "1Dec", 1.1, s1);
	Comanda* m2 = new Mancare("zubii2", "2Dec", 1.2, s2);
	
	assert(all[0]->toString(string(" ")) == m1->toString(string(" ")));
	assert(all[1]->toString(string(" ")) == m2->toString(string(" ")));

	auto allGood = service.searchByName("zubii2");
	Comanda* sp2 = new Shopping("zubii2", "2Dec", 1.2, "profi2", s2);
	assert(allGood[0]->toString(string(" ")) == m2->toString(string(" ")));
	assert(allGood[1]->toString(string(" ")) == sp2->toString(string(" ")));
}

void TestService::runTeste() {
	std::cout << " TESTE Service . . . ";
	teste();
	std::cout << " OK ! " << std::endl;
}
