#pragma once
#include "Service.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Login.h"
#include "RepositoryTemplateTXT.h"
#include "RepositoryTemplateCSV.h"

class UserInterface{
private:
	int REPO;
	Service<RepositoryTemplateTXT<Mancare>, Mancare> serviceMancareTXT;
	Service<RepositoryTemplateTXT<Shopping>, Shopping> serviceShoppingTXT;

	Service<RepositoryTemplateCSV<Mancare>, Mancare> serviceMancareCSV;
	Service<RepositoryTemplateCSV<Shopping>, Shopping> serviceShoppingCSV;

	Login* login = new Login("admin", "admin");

	void mancareAdd();
	void mancareRemove();
	void mancareUpdate();
	void mancareFind();

	void shoppingAdd();
	void shoppingRemove();
	void shoppingUpdate();
	void shoppingFind();

	void showAll();

	bool loginUser();

	int chooseRepo();

	void searchByName();

public:
	UserInterface();
	UserInterface(const Service<RepositoryTemplateTXT<Mancare>, Mancare>& serviceMancareTXT,
		const Service<RepositoryTemplateTXT<Shopping>, Shopping>& serviceShoppingTXT,
		const Service<RepositoryTemplateCSV<Mancare>, Mancare>& serviceMancareCSV,
		const Service<RepositoryTemplateCSV<Shopping>, Shopping>& serviceCSVShopping);
	~UserInterface();
	void showUI();
};

