#pragma once
#include "RepositoryFile.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Serializer.h"
#include "MyException.h"

template <class T>
class RepositoryFileTXT :public RepositoryFile<T> {
public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char* fileName, Serializer<T>* serializer);
	~RepositoryFileTXT();
	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(){
}

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(const char* fileName, Serializer<T>* serializer)
	:RepositoryFile<T>(fileName, serializer){
}

template<class T>
inline RepositoryFileTXT<T>::~RepositoryFileTXT(){
}

template<class T>
inline void RepositoryFileTXT<T>::loadFromFile() {
	std::string linie;
	std::ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, linie)) {
		try {
			RepositoryFile<T>::add(RepositoryFile<T>::serializer->fromString(linie, ' '));
		}
		catch (const MyException& ex) {
			std::cout << ex.what();
		}
	}
}

template<class T>
inline void RepositoryFileTXT<T>::saveToFile(){
	std::ofstream f(RepositoryFile<T>::fileName);
	for (auto itr = RepositoryFile<T>::storage.begin(); itr != RepositoryFile<T>::storage.end(); itr++) {
		f << itr->second->toString(std::string(" ")) << std::endl;
	}
}
