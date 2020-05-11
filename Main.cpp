#include <iostream>
#include "TestMancare.h"
#include "TestShopping.h"
#include "TestRunLogin.h"
#include "TestService.h"
#include "UserInterface.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Service.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "Serializer.h"
#include "SerializerComanda.h"
#include "TestIRepository.h"
#include "TestRepositoryFileTXT.h"
#include "TestRepositoryFileCSV.h"

int main(){
	/* INCEPUT TESTE */
	TestMancare testMancare;
	testMancare.runTeste();

	TestShopping testShopping;
	testShopping.runTeste();

	TestIRepository testIRepository;
	testIRepository.runTeste();

	TestRepositoryFileTXT testRepositoryFileTXT;
	testRepositoryFileTXT.runTeste();

	TestRepositoryFileCSV testRepositoryFileCSV;
	testRepositoryFileCSV.runTeste();

	TestService testService;
	testService.runTeste();

	TestRunLogin testRunLogin;
	testRunLogin.runTeste();
	
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	/* SFARSIT TESTE */
	
	Service service;
	UserInterface userInterface(service);

	userInterface.showUI();
	
}
