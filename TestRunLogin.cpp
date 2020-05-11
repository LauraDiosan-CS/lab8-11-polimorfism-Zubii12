#include "TestRunLogin.h"
#include "Login.h"
#include <assert.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

TestRunLogin::TestRunLogin(){
}

TestRunLogin::~TestRunLogin(){
}

void TestRunLogin::teste(){
	Login login("admin", "admin");

	assert(login.runLogin("admin", "admin") == true);
	assert(login.runLogin("asda", "asda") == false);

}


void TestRunLogin::runTeste(){
	cout << " TESTE LOGIN . . .";
	teste();
	cout << " OK ! " << endl;
}
