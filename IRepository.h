#pragma once
#include <map>
#include <string>
#include <vector>

using std::string;
using std::map;
using std::vector;

// Tipul entitatii
template<class T>
class IRepository{
private:
	int ID;
protected:
public:
	map<int, T> storage;

	IRepository();
	~IRepository();
	
	void clearStorage();
	void add(const T& t);
	bool remove(const T& t);
	bool update(T& t, const T& tNou);
	bool find(const T& t);
	int size();

	vector<T> getAll();

};

template<class T>
inline IRepository<T>::IRepository(){
	this->ID = 0;
}

template<class T>
inline IRepository<T>::~IRepository(){
	this->ID = 0;
}

template<class T>
inline void IRepository<T>::clearStorage(){
	this->storage.clear();
}

template<class T>
inline void IRepository<T>::add(const T& t){
	this->storage.insert(std::pair<int, T>(this->ID++, t));
}

template<class T>
inline bool IRepository<T>::remove(const T& t){
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		//if(*itr->second == *t){
		if (itr->second->toString(string(" ")) == t->toString(string(" "))) {
			storage.erase(itr->first);
			return true;
		}
	}
	return false;
}

template<class T>
inline bool IRepository<T>::update(T& t, const T& tNou){
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		//if(*itr->second == *t){
		if (itr->second->toString(string(" ")) == t->toString(string(" "))) {
			storage[itr->first] = tNou;
			return true;
		}
	}
	return false;
}

template<class T>
inline bool IRepository<T>::find(const T& t){
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		//if(*itr->second == *t){
		if(itr->second->toString(string(" ")) == t->toString(string(" "))){
			return true;
		}
	}
	return false;
}

template<class T>
inline int IRepository<T>::size(){
	return this->storage.size();
}

template<class T>
inline vector<T> IRepository<T>::getAll(){
	vector<T> all;
	for (auto itr = storage.begin(); itr != storage.end(); itr++) {
		all.push_back(itr->second);
	}
	return all;
}
