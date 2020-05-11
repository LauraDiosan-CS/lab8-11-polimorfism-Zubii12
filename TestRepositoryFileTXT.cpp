#include "TestRepositoryFileTXT.h"
#include "Comanda.h"
#include "Serializer.h"
#include "SerializerComanda.h"
#include "RepositoryFileTXT.h"
#include <assert.h>

TestRepositoryFileTXT::TestRepositoryFileTXT(){
}

TestRepositoryFileTXT::~TestRepositoryFileTXT(){
}

void TestRepositoryFileTXT::teste(){
	Serializer<Comanda*>* serializer = new SerializerComanda;
	IRepository<Comanda*>* repo = new RepositoryFileTXT<Comanda*>("TestComanda.txt", serializer);
	
	vector<string> s1 = { "2", "oua1", "oua1" };
	vector<string> s2 = { "2", "oua2", "oua2" };
	vector<string> s3 = { "2", "oua3", "oua3" };
	Comanda* m1 = new Mancare("zubii1", "1Dec", 1.1, s1);
	Comanda* m2 = new Mancare("zubii2", "2Dec", 1.2, s2);
	Comanda* m3 = new Mancare("zubii3", "3Dec", 1.3, s3);
	Comanda* sp1 = new Shopping("zubii1", "1Dec", 1.1, "profi1", s1);
	Comanda* sp2 = new Shopping("zubii2", "2Dec", 1.2, "profi2", s2);
	Comanda* sp3 = new Shopping("zubii3", "3Dec", 1.3, "profi3", s3);
	assert(((RepositoryFile<Comanda*>*)repo)->size() == 0);

	//assert(((RepositoryFile<Comanda*>*)repo)->find(m2));
	
	((RepositoryFile<Comanda*>*)repo)->add(m1);
	((RepositoryFile<Comanda*>*)repo)->add(m2);
	((RepositoryFile<Comanda*>*)repo)->add(m3);
	assert(((RepositoryFile<Comanda*>*)repo)->size() == 3);

	((RepositoryFile<Comanda*>*)repo)->add(sp1);
	((RepositoryFile<Comanda*>*)repo)->add(sp2);
	((RepositoryFile<Comanda*>*)repo)->add(sp3);
	assert(((RepositoryFile<Comanda*>*)repo)->size() == 6);

	((RepositoryFile<Comanda*>*)repo)->saveToFile();

	((RepositoryFile<Comanda*>*)repo)->clearStorage();
	assert(((RepositoryFile<Comanda*>*)repo)->size() == 0);
	
	((RepositoryFile<Comanda*>*) repo)->loadFromFile();
	assert(((RepositoryFile<Comanda*>*)repo)->size() == 6);
}

void TestRepositoryFileTXT::runTeste(){
	std::cout << " TESTE RepositoryFileTXT . . . ";
	teste();
	std::cout << " OK !" << std::endl;
}
