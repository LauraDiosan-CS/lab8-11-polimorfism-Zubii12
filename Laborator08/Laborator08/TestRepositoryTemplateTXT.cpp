#include "TestRepositoryTemplateTXT.h"
#include "RepositoryTemplateTXT.h"
#include "Mancare.h"
#include "Shopping.h"
#include <assert.h>

TestRepositoryTemplateTXT::TestRepositoryTemplateTXT(){
}

TestRepositoryTemplateTXT::~TestRepositoryTemplateTXT(){
}

void TestRepositoryTemplateTXT::testLoadFromFile() {
	RepositoryTemplateTXT<Mancare> repoM("zubiiLoadMancare.txt");
	//RepositoryTemplateTXT<Shopping> repoS("zubiiLoadShopping.txt");
	
	repoM.loadFromFile();

	auto allMancare = repoM.getAll();
	//auto allShopping = repoS.getAll();

	
	assert(repoM.size() == 3);
	//assert(repoS.size() == 2);
}

void TestRepositoryTemplateTXT::testSaveToFile() {
/*	RepositoryTemplateTXT<Mancare> repoM("zubiiSaveMancare.txt");
	
	Mancare m1("zubii1", "1Dec", "oua1", 1.1);
	Mancare m2("zubii2", "2Dec", "oua2", 1.2);
	Mancare m3("zubii3", "3Dec", "oua2", 1.3);

	repoM.add(m1);
	repoM.add(m2);
	repoM.add(m3);

	repoM.saveToFile();
	*/
}

void TestRepositoryTemplateTXT::runTeste(){
	std::cout << " TESTE REPO FILE . . . " << std::endl;
	testLoadFromFile();
	testSaveToFile();
	std::cout << " OK ! " << std::endl;

}
