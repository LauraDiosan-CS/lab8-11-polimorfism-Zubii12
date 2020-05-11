#pragma once
#include <exception>
#include <iostream>

using std::exception;

class MyException :virtual public exception {
private:
	char* file, * line, * function, * info, * allInfo;
public:
	MyException(const char* msg, const char* file = nullptr, const char* line = nullptr, const char* function = nullptr, const char* info = nullptr) :
		exception(msg), file((char*)(file)), line((char*)(line)), function((char*)function), info((char*)info), allInfo(NULL) {}
	~MyException() {
		if (this->file) {
			delete[] this->file;
		}
		this->file = NULL;
		if (this->line) {
			delete[] this->line;
		}
		this->line = NULL;
		if (this->function) {
			delete[] this->function;
		}
		this->function = NULL;
		if (this->info) {
			delete[] this->info;
		}
		this->info = NULL;
		if (this->allInfo) {
			delete[] this->allInfo;
		}
		this->allInfo = NULL;
	}

	const char* showAll() {
		int len = strlen(this->file) +
			strlen(this->function) +
			strlen(this->info) +
			strlen(this->line) + 1 + 6;

		char* allInfo = new char[len];

		strcpy_s(allInfo, len, this->file);
		strcat_s(allInfo, len, ", ");
		strcat_s(allInfo, len, this->line);
		strcat_s(allInfo, len, ", ");
		strcat_s(allInfo, len, this->function);
		strcat_s(allInfo, len, ", ");
		strcat_s(allInfo, len, this->info);

		return allInfo;
	}
};
