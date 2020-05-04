#include "TestService.h"
#include "Service.h"
#include "RepositoryTemplate.h"
#include "Mancare.h"
#include <assert.h>


using std::cout;
using std::endl;

TestService::TestService(){
}

TestService::~TestService(){
}

void TestService::testServiceMancare() {
	/*RepositoryTemplate<Mancare> repo;
	Service<RepositoryTemplate<Mancare>,Mancare> service(repo);

	Mancare m1("zubii1", "1Dec", "oua1", 1.1);
	Mancare m2("zubii2", "2Dec", "oua2", 1.2);
	Mancare m3("zubii3", "3Dec", "oua2", 1.3);

	assert(service.size() == 0);

	service.add(m1);
	service.add(m2);
	service.add(m3);

	assert(service.size() == 3);

	assert(service.remove(m3));

	assert(service.size() == 2);

	assert(service.update(m1, m2));

	assert(service.find(m2));

	assert(!service.find(m3));

	auto all = service.getAll();

	assert(all[1] == m2);
	assert(all[2] == m2);
	*/
}

void TestService::testServiceShopping() {
}
void TestService::runTeste(){
	cout << " TESTE SERVICE . . . " << endl;
	testServiceMancare();
	testServiceShopping();
	cout << " OK ! " << endl;
}
