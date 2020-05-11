#include "TestIRepository.h"
#include "Mancare.h"
#include <vector>
#include <string>
#include "IRepository.h"
#include <assert.h>

TestIRepository::TestIRepository(){
}

TestIRepository::~TestIRepository(){
}

void TestIRepository::teste(){

	IRepository<Comanda*> repo;

	vector<string> s1 = { "2", "oua1", "oua1" };
	vector<string> s2 = { "2", "oua2", "oua2" };
	vector<string> s3 = { "2", "oua3", "oua3" };

	Comanda* m1 = new Mancare("zubii1", "1Dec", 1.1, s1);
	Comanda* m2 = new Mancare("zubii2", "2Dec", 1.2, s2);
	Comanda* m3 = new Mancare("zubii3", "3Dec", 1.3, s3);

	assert(repo.size() == 0);
	repo.add(m1);
	assert(repo.size() == 1);
	repo.add(m2);
	repo.add(m3);
	assert(repo.size() == 3);

	repo.remove(m3);
	assert(repo.size() == 2);
	assert(!repo.find(m3));

	repo.update(m1, m2);
	assert(!repo.find(m1));

	auto all = repo.getAll();
	assert(all.size() == 2);
	assert(all[0] == m2);
}

void TestIRepository::runTeste(){
	std::cout << " TESTE IRepository . . . ";
	teste();
	std::cout << " OK !" << std::endl;
}
