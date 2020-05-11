#pragma once
#include <string>

using std::string;

class Login{
private:
	string userName;
	string password;
public:
	Login();
	Login(string userName, string password);
	~Login();
	bool runLogin(string userName, string password);

};

