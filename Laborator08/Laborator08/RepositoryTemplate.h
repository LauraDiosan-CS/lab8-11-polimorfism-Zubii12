#pragma once
#include <map>
#include <iostream>

template<class T>
class RepositoryTemplate{
protected:
	std::map<int, T> storage;
	int ID;
public:
	RepositoryTemplate();
	~RepositoryTemplate();

	void clearStorage();
	void add(const T& t);
	bool remove(const T& t);
	bool update(T& t, const T& tNou);
	bool find(const T& t);
	int size();

	std::map<int, T> getAll();
};

template<class T>
RepositoryTemplate<T>::RepositoryTemplate(){
	this->ID = 0;
}

template<class T>
RepositoryTemplate<T>::~RepositoryTemplate(){
	this->ID = 0;
}

template<class T>
void RepositoryTemplate<T>::clearStorage(){
	this->storage.clear();
}

template<class T>
void RepositoryTemplate<T>::add(const T& t){
	storage.insert(std::pair<int, T>(++this->ID, t));
}

template<class T>
bool RepositoryTemplate<T>::remove(const T& t){
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		if (storage.find(itr->first)->second == t) {
			storage.erase(itr->first);
			return true;
		}
	}
	return false;
}

template<class T>
bool RepositoryTemplate<T>::update(T& t, const T& tNou){
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		if (storage.find(itr->first)->second == t) {
			storage[itr->first] = tNou;
			return true;
		}
	}
	return false;
}

template<class T>
bool RepositoryTemplate<T>::find(const T& t){
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		if (storage.find(itr->first)->second == t) {
			return true;
		}
	}
	return false;
}

template<class T>
int RepositoryTemplate<T>::size(){
	return storage.size();
}

template<class T>
std::map<int, T> RepositoryTemplate<T>::getAll(){
	/*std::map<int, T> _storage;
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		_storage[itr->first] = itr->second;
	}
	return _storage;*/
	return this->storage;
}
