#include "TestMancare.h"
#include "Mancare.h"
#include <assert.h>
#include <vector>
#include <string>

TestMancare::TestMancare(){
}

TestMancare::~TestMancare(){
}

void TestMancare::teste() {

	vector<string> s1 = { "2", "oua1", "oua1" };
	vector<string> s2 = { "2", "oua2", "oua2" };
	vector<string> s3 = { "2", "oua3", "oua3" };

	Mancare m1("zubii1", "1Dec", 1.1, s1);
	Mancare m2("zubii2", "2Dec", 1.2, s2);
	Mancare m3("zubii3", "3Dec", 1.3, s3);

	assert(m1.getNumeClient() == "zubii1");
	assert(m1.getAdresaClient() == "1Dec");
	assert(m1.getPretTotal() == 1.1);
	assert(m1.getListaPreparate() == s1);
	assert(m1.getPretTotal() == 1.1);

	Mancare m22(m1);
	assert(m1 == m22);
	
	Mancare m33 = m3;
	assert(m3 == m33);


	m1.setNumeClient(string("zubii11"));
	m1.setAdresaClient(string("11Dec"));
	m1.setListaPreparate(s2);
	m1.setPretTotal(1.11);
	assert(m1.getNumeClient() == "zubii11");
	assert(m1.getAdresaClient() == "11Dec");
	assert(m1.getListaPreparate() == s2);
	assert(m1.getPretTotal() == 1.11);

	Mancare m4(string("zubii4 4Dec 1.10 3 oua1 oua2 oua3"), ' ');
	assert(m4.getNumeClient() == "zubii4");
	assert(m4.getAdresaClient() == "4Dec");
	assert(m4.getPretTotal() == 1.1);
	vector<string> s4 = { "3", "oua1", "oua2", "oua3" };
	assert(m4.getListaPreparate() == s4);

	string ss = m4.toString(string(" "));
	assert(ss == "Mancare zubii4 4Dec 1.10 3 oua1 oua2 oua3");

	Mancare m5(string("zubii4,4Dec,1.10,3,oua1,oua2,oua3"), ',');
	assert(m5.getNumeClient() == "zubii4");
	assert(m5.getAdresaClient() == "4Dec");
	assert(m5.getPretTotal() == 1.1);
	vector<string> s5 = { "3", "oua1", "oua2", "oua3" };
	assert(m5.getListaPreparate() == s5);

	string sss = m5.toString(string(","));
	assert(sss == "Mancare,zubii4,4Dec,1.10,3,oua1,oua2,oua3");
}

void TestMancare::runTeste(){
	std::cout << " TESTE Mancare . . . ";
	teste();
	std::cout << " OK !" << std::endl;
}
