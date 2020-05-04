#include "TestRepositoryTemplate.h"
#include "Mancare.h"
#include "RepositoryTemplate.h"
#include <assert.h>

TestRepositoryTemplate::TestRepositoryTemplate(){
}

TestRepositoryTemplate::~TestRepositoryTemplate(){
}

void TestRepositoryTemplate::teste(){
/*	RepositoryTemplate<Mancare> repo;

	Mancare m1("zubii1", "1Dec", "oua1", 1.1);
	Mancare m2("zubii2", "2Dec", "oua2", 1.2);
	Mancare m3("zubii3", "3Dec", "oua2", 1.3);

	assert(repo.size() == 0);

	repo.add(m1);
	repo.add(m2);
	repo.add(m3);

	assert(repo.size() == 3);

	repo.remove(m3);

	assert(!repo.find(m3));
	assert(repo.size() == 2);

	repo.update(m1, m2);

	auto all = repo.getAll();

	assert(all[1] == m2);
	*/
}

void TestRepositoryTemplate::runTeste(){
	std::cout << " TESTE REPO TEMPLATE . . .";
	teste();
	std::cout << " OK !" << std::endl;
}
