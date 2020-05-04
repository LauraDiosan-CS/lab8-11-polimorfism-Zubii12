#include "TestShopping.h"
#include "Shopping.h"
#include <assert.h>

TestShopping::TestShopping()
{
}

TestShopping::~TestShopping()
{
}

void TestShopping::teste() {
/*
	Shopping s1("zubii1", "1Dec", "oua1", 1.1, "profi1");
	Shopping s2("zubii2", "2Dec", "oua2", 1.2, "profi2");
	Shopping s3("zubii3", "3Dec", "oua2", 1.3, "profi3");

	assert(strcmp(s1.getNumeClient(), "zubii1") == 0);
	assert(strcmp(s1.getAdresaClient(), "1Dec") == 0);
	assert(strcmp(s1.getListaCumparaturi(), "oua1") == 0);
	assert(s1.getPretTotal() == 1.1);
	assert(strcmp(s1.getNumeMagazin(), "profi1") == 0);

	Shopping s22(s2);

	assert(s2 == s22);

	Shopping s33 = s3;
	assert(s3 == s33);

	s1.setNumeClient("zubii11");
	s1.setAdresaClient("11Dec");
	s1.setListaCumparaturi("oua11");
	s1.setPretTotal(1.11);
	s1.setNumeMagazin("profi11");

	assert(strcmp(s1.getNumeClient(), "zubii11") == 0);
	assert(strcmp(s1.getAdresaClient(), "11Dec") == 0);
	assert(strcmp(s1.getListaCumparaturi(), "oua11") == 0);
	assert(s1.getPretTotal() == 1.11);
	assert(strcmp(s1.getNumeMagazin(), "profi11") == 0);
	*/
}

void TestShopping::runTeste(){
	std::cout << " TESTE SHOPPING . . . ";
	teste();
	std::cout << " OK !" << std::endl;
}
