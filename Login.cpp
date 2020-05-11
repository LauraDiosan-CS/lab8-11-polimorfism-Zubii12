#include "Login.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;

Login::Login() {
}

Login::Login(string userName, string password) {
	this->userName = userName;
	this->password = password;
}

Login::~Login() {
}
bool Login::runLogin(string userName,string password) {
	return (userName == this->userName && password == this->password);
}
