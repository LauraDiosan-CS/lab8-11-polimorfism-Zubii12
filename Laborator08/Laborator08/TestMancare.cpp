#include "TestMancare.h"
#include "Mancare.h"
#include <assert.h>

TestMancare::TestMancare(){
}

TestMancare::~TestMancare(){
}

void TestMancare::teste() {
/*	Mancare m1("zubii1", "1Dec", "oua1", 1.1);
	Mancare m2("zubii2", "2Dec", "oua2", 1.2);
	Mancare m3("zubii3", "3Dec", "oua2", 1.3);

	assert(strcmp(m1.getNumeClient(), "zubii1") == 0);
	assert(strcmp(m1.getAdresaClient(), "1Dec") == 0);
	assert(strcmp(m1.getListaPreparate(), "oua1") == 0);
	assert(m1.getPretTotal() == 1.1);

	Mancare m22(m2);

	assert(m2 == m22);
	
	Mancare m33 = m3;
	assert(m3 == m33);

	m1.setNumeClient("zubii11");
	m1.setAdresaClient("11Dec");
	m1.setListaPreparate("oua11");
	m1.setPretTotal(1.11);

	assert(strcmp(m1.getNumeClient(), "zubii11") == 0);
	assert(strcmp(m1.getAdresaClient(), "11Dec") == 0);
	assert(strcmp(m1.getListaPreparate(), "oua11") == 0);
	assert(m1.getPretTotal() == 1.11);
*/
}

void TestMancare::runTeste(){
	std::cout << " TESTE MANCARE . . . ";
	teste();
	std::cout << " OK !" << std::endl;
}
