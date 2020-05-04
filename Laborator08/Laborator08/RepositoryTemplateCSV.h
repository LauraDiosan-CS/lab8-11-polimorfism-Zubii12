#pragma once
#include "RepositoryTemplate.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

// T - Tipul entitatii
template<class T>
class RepositoryTemplateCSV : public RepositoryTemplate<T>{
private:
	const char* fileName;
public:
	RepositoryTemplateCSV();
	RepositoryTemplateCSV(const char* fileName);
	~RepositoryTemplateCSV();

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
RepositoryTemplateCSV<T>::RepositoryTemplateCSV(){
	this->fileName = NULL;
}

template<class T>
RepositoryTemplateCSV<T>::RepositoryTemplateCSV(const char* fileName){
	this->fileName = fileName;
}

template<class T>
RepositoryTemplateCSV<T>::~RepositoryTemplateCSV(){
}

template<class T>
void RepositoryTemplateCSV<T>::loadFromFile(){
	std::ifstream f(this->fileName);

	std::stringstream ss, ssNou;
	std::string linie, cuvant;

	if (f) {
		while (std::getline(f, linie)) {
			std::stringstream ss(linie);
			bool emptyLine = false;
			while (std::getline(ss, cuvant, ',') && emptyLine == false) {
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
void RepositoryTemplateCSV<T>::saveToFile(){
	std::ofstream f(this->fileName);
	for (auto itr = this->storage.begin(); itr != this->storage.end(); itr++) {
		f << itr->second.toStringForCSV();
		f << std::endl;
	}
}

template<class T>
void RepositoryTemplateCSV<T>::clearFile(){
	std::ofstream f;
	f.open(fileName, std::ofstream::out | std::ofstream::trunc);
	f.close();
}

template<class T>
void RepositoryTemplateCSV<T>::add(const T& t){
	loadFromFile();
	RepositoryTemplate<T>::add(t);
	saveToFile();
	RepositoryTemplate<T>::clearStorage();
}

template<class T>
bool RepositoryTemplateCSV<T>::remove(const T& t){
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
bool RepositoryTemplateCSV<T>::update(T& t, const T& tNou){
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
bool RepositoryTemplateCSV<T>::find(const T& t){
	loadFromFile();
	if (RepositoryTemplate<T>::find(t)) {
		RepositoryTemplate<T>::clearStorage();
		return true;
	}
	return false;
}

template<class T>
int RepositoryTemplateCSV<T>::size(){
	loadFromFile();
	int size = RepositoryTemplate<T>::size();
	RepositoryTemplate<T>::clearStorage();
	return size;
}

template<class T>
std::map<int, T> RepositoryTemplateCSV<T>::getAll(){
	loadFromFile();
	std::map<int, T> all = RepositoryTemplate<T>::getAll();
	RepositoryTemplate<T>::clearStorage();
	return all;
}
