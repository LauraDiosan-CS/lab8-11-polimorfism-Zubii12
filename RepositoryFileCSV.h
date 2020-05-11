#pragma once
#include "RepositoryFile.h"
#include <fstream>
#include <string>
#include "Serializer.h"
#include "MyException.h"

template<class T>
class RepositoryFileCSV : public RepositoryFile<T> {
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char* fileName, Serializer<T>* serializer);
	~RepositoryFileCSV();
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(){
}

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fileName, Serializer<T>* serializer)
	:RepositoryFile<T>(fileName, serializer){
}

template<class T>
inline RepositoryFileCSV<T>::~RepositoryFileCSV(){
}

template<class T>
inline void RepositoryFileCSV<T>::loadFromFile(){
	std::string linie;
	std::ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, linie)) {
		try {
			RepositoryFile<T>::add(RepositoryFile<T>::serializer->fromString(linie, ','));
		}
		catch (const MyException& ex) {
			std::cout << ex.what();
		}
	}
}

template<class T>
inline void RepositoryFileCSV<T>::saveToFile() {
	std::ofstream f(RepositoryFile<T>::fileName);
	for (auto itr = RepositoryFile<T>::storage.begin(); itr != RepositoryFile<T>::storage.end(); itr++) {
		f << itr->second->toString(std::string(",")) << std::endl;
	}
}