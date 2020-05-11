#include "TestShopping.h"
#include "Shopping.h"
#include <assert.h>

TestShopping::TestShopping(){
}

TestShopping::~TestShopping(){
}

void TestShopping::teste() {
	vector<string> s1 = { "2", "oua1", "oua1" };
	vector<string> s2 = { "2", "oua2", "oua2" };
	vector<string> s3 = { "2", "oua3", "oua3" };

	Shopping sp1("zubii1", "1Dec", 1.1, "profi1", s1);
	Shopping sp2("zubii2", "2Dec", 1.2, "profi2", s2);
	Shopping sp3("zubii3", "3Dec", 1.3, "profi3", s3);

	assert(sp1.getNumeClient() == "zubii1");
	assert(sp1.getAdresaClient() == "1Dec");
	assert(sp1.getPretTotal() == 1.1);
	assert(sp1.getNumeMagazin() == "profi1");
	assert(sp1.getListaCumparaturi() == s1);


	Shopping sp22(sp2);

	assert(sp2 == sp22);

	Shopping sp33 = sp3;
	assert(sp3 == sp33);

	sp1.setNumeClient("zubii11");
	sp1.setAdresaClient("11Dec");
	sp1.setListaCumparaturi(s2);
	sp1.setPretTotal(1.11);
	sp1.setNumeMagazin("profi11");
	assert(sp1.getNumeClient() == "zubii11");
	assert(sp1.getAdresaClient() == "11Dec");
	assert(sp1.getPretTotal() == 1.11);
	assert(sp1.getNumeMagazin() == "profi11");
	assert(sp1.getListaCumparaturi() == s2);
	
	Shopping sp4(string("zubii4 4Dec 1.40 profi4 2 oua1 oua2"), ' ');
	assert(sp4.getNumeClient() == "zubii4");
	assert(sp4.getAdresaClient() == "4Dec");
	assert(sp4.getPretTotal() == 1.40);
	assert(sp4.getNumeMagazin() == "profi4");
	vector<string> s4 = { "2", "oua1", "oua2" };
	assert(sp4.getListaCumparaturi() == s4);

	string ss = sp4.toString(string(" "));
	assert(ss == "Shopping zubii4 4Dec 1.40 profi4 2 oua1 oua2");

	Shopping sp5(string("zubii4,4Dec,1.40,profi4,2,oua1,oua2"), ',');
	assert(sp5.getNumeClient() == "zubii4");
	assert(sp5.getAdresaClient() == "4Dec");
	assert(sp5.getPretTotal() == 1.40);
	assert(sp5.getNumeMagazin() == "profi4");
	vector<string> s5 = { "2", "oua1", "oua2" };
	assert(sp5.getListaCumparaturi() == s5);

	string sss = sp4.toString(string(","));
	assert(sss == "Shopping,zubii4,4Dec,1.40,profi4,2,oua1,oua2");

}

void TestShopping::runTeste(){
	std::cout << " TESTE Shopping . . . ";
	teste();
	std::cout << " OK !" << std::endl;
}
