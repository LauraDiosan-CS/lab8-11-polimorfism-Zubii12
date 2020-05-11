#pragma once
#include "Service.h"

class UserInterface{
private:
	Service service;
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

	void chooseRepo();

	void searchByName();

public:
	UserInterface();
	UserInterface(Service& service);
	~UserInterface();
	void showUI();
};

