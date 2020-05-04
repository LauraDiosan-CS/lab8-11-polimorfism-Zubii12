#pragma once
#include "RepositoryTemplate.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

template<class T>
class RepositoryTemplateTXT : public RepositoryTemplate<T>{
private:
	const char* fileName;
public:
	RepositoryTemplateTXT();
	RepositoryTemplateTXT(const char* fileName);
	~RepositoryTemplateTXT();

	void loadFromFile();
	void saveToFile();
	void clearFile();

	void add(const T& t);
	bool remove(const T& t);
	bool update(T& t, const T& tNou);
	bool find(const T& t);
	int size();

	std::map<int, T> getAll();
};

template<class T>
RepositoryTemplateTXT<T>::RepositoryTemplateTXT() {
	this->fileName = NULL;
}

template<class T>
RepositoryTemplateTXT<T>::RepositoryTemplateTXT(const char* fileName) {
	this->fileName = fileName;
}

template<class T>
RepositoryTemplateTXT<T>::~RepositoryTemplateTXT() {
}

template<class T>
void RepositoryTemplateTXT<T>::loadFromFile(){
	std::ifstream f(this->fileName);
	//if (f) {
	//	while (!f.eof()) {
	//		T* t = new T;
	//		std::cout << *f << " ";
	//		f >> *t;
	//		
	//		RepositoryTemplate<T>::add(*t);
	//		delete t;
	//	}
	//}
	//else {
	//	throw "";
	//}
	//f.close();

	std::stringstream ss, ssNou;
	std::string linie, cuvant;

	if (f) {
		while (std::getline(f, linie)) {
			std::stringstream ss(linie);
			bool emptyLine = false;
			while (std::getline(ss, cuvant, ' ') && emptyLine == false) {
				if (cuvant.empty()) {
					emptyLine = true;
				}
				else {
					ssNou << cuvant << ' ';
				}
			}
			if (!emptyLine) {
				T* t = new T;
				ssNou >> *t;
				RepositoryTemplate<T>::add(*t);
				delete t;
			}
			else {
				emptyLine = false;
			}
		}
	}
	else {
		throw "";
	}
	f.close();

}

template<class T>
void RepositoryTemplateTXT<T>::saveToFile(){
	std::ofstream f(this->fileName);
	for (auto itr = RepositoryTemplate<T>::storage.begin(); itr != RepositoryTemplate<T>::storage.end(); itr++) {
		f << itr->second;
	}
	f.close();
}

template<class T>
void RepositoryTemplateTXT<T>::clearFile(){
	std::ofstream f;
	f.open(fileName, std::ofstream::out | std::ofstream::trunc);
	f.close();
}

template<class T>
void RepositoryTemplateTXT<T>::add(const T& t) {
	loadFromFile();
	RepositoryTemplate<T>::add(t);
	saveToFile();
	RepositoryTemplate<T>::clearStorage();
}

template<class T>
bool RepositoryTemplateTXT<T>::remove(const T& t) {
	loadFromFile();
	if (RepositoryTemplate<T>::find(t)) {
		RepositoryTemplate<T>::remove(t);
		saveToFile();
		RepositoryTemplate<T>::clearStorage();
		return true;
	}
	return false;
}

template<class T>
bool RepositoryTemplateTXT<T>::update(T& t, const T& tNou) {
	loadFromFile();
	if (RepositoryTemplate<T>::find(t)) {
		RepositoryTemplate<T>::update(t, tNou);
		saveToFile();
		RepositoryTemplate<T>::clearStorage();
		return true;
	}
	return false;
}

template<class T>
bool RepositoryTemplateTXT<T>::find(const T& t) {
	loadFromFile();
	if (RepositoryTemplate<T>::find(t)) {
		RepositoryTemplate<T>::clearStorage();
		return true;
	}
	return false;
}

template<class T>
int RepositoryTemplateTXT<T>::size() {
	loadFromFile();
	int size = RepositoryTemplate<T>::size();
	RepositoryTemplate<T>::clearStorage();
	return size;
}

template<class T>
std::map<int, T> RepositoryTemplateTXT<T>::getAll() {
	loadFromFile();
	auto all = RepositoryTemplate<T>::getAll();
	RepositoryTemplate<T>::clearStorage();
	return all;
}
