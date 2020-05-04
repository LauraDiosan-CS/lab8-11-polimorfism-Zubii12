#include <iostream>
#include "TestMancare.h"
#include "TestShopping.h"
#include "TestRepositoryTemplate.h"
#include "TestRepositoryTemplateTXT.h"
#include "TestRepositoryTemplateCSV.h"
#include "TestRunLogin.h"
#include "TestService.h"
#include "UserInterface.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Service.h"
#include "RepositoryTemplateTXT.h"
#include "RepositoryTemplateCSV.h"

int main(){
	/* INCEPUT TESTE */
	TestMancare testMancare;
	//testMancare.runTeste();

	TestShopping testShopping;
	//testShopping.runTeste();

	TestRepositoryTemplate testRepositoryTemplate;
	//testRepositoryTemplate.runTeste();

	TestRepositoryTemplateTXT testRepositoryTemplateTXT;
	//testRepositoryTemplateTXT.runTeste();

	TestRepositoryTemplateCSV testRepositoryTemplateCSV;
	//testRepositoryTemplateCSV.runTeste();

	TestRunLogin testRunLogin;
	//testRunLogin.runTeste();

	TestService testService;
	//testService.runTeste();
	/* SFARSIT TESTE */
	
	RepositoryTemplateTXT<Mancare> repoTXTMancare("mancare.txt");
	RepositoryTemplateTXT<Shopping> repoTXTShopping("shopping.txt");

	RepositoryTemplateCSV<Mancare> repoCSVMancare("mancare.csv");
	RepositoryTemplateCSV<Shopping> repoCSVShopping("shopping.csv");

	Service<RepositoryTemplateTXT<Mancare>, Mancare> serviceTXTMancare(repoTXTMancare);
	Service<RepositoryTemplateTXT<Shopping>, Shopping> serviceTXTShopping(repoTXTShopping);

	Service<RepositoryTemplateCSV<Mancare>, Mancare> serviceCSVMancare(repoCSVMancare);
	Service<RepositoryTemplateCSV<Shopping>, Shopping> serviceCSVShopping(repoCSVShopping);

	UserInterface userInterface(serviceTXTMancare, serviceTXTShopping, 
		serviceCSVMancare, serviceCSVShopping);

	userInterface.showUI();
	
}
