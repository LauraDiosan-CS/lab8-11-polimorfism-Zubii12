#include "TestRepositoryTemplateCSV.h"
#include "RepositoryTemplateCSV.h"
#include "Mancare.h"
#include <assert.h>

TestRepositoryTemplateCSV::TestRepositoryTemplateCSV(){
}

TestRepositoryTemplateCSV::~TestRepositoryTemplateCSV(){
}

void TestRepositoryTemplateCSV::testLoadFromFile(){
	RepositoryTemplateCSV<Mancare> repoM("zubiiLoadMancare.csv");

	repoM.loadFromFile();

	auto allM = repoM.getAll();

	assert(repoM.size() == 3);
}

void TestRepositoryTemplateCSV::testSaveToFile(){
	/*RepositoryTemplateCSV<Mancare> repoM("zubiiSaveMancare.csv");

	Mancare m1("zubii1", "1Dec", "oua1", 1.1);
	Mancare m2("zubii2", "2Dec", "oua2", 1.2);
	Mancare m3("zubii3", "3Dec", "oua2", 1.3);

	repoM.add(m1);
	repoM.add(m2);
	repoM.add(m3);

	repoM.saveToFile();
	*/
}

void TestRepositoryTemplateCSV::runTeste(){
	std::cout << " TESTE REPO CSV . . . " << std::endl;
	testLoadFromFile();
	testSaveToFile();
	std::cout << " OK !" << std::endl;
}
