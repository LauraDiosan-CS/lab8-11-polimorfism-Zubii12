#pragma once
#include "RepositoryTemplate.h"
#include <vector>

using std::vector;
// R - Repo
// T - Tipul entitatii
template<class R, class T>
class Service{
private:
	R repo;
public:
	Service();
	Service(const R& repo);
	~Service();

	void setRepo(const R& repo);

	void add(const T& t);
	bool remove(const T& t);
	bool update(T& t, const T& tNou);
	bool find(const T& t);
	int size();

	vector<T> searchByName(const char* name);

	std::map<int, T> getAll();
};

template<class R, class T>
Service<R, T>::Service() {
}

template<class R, class T>
Service<R, T>::Service(const R& repo){
	this->repo = repo;
}

template<class R, class T>
Service<R, T>::~Service(){
}

template<class R, class T>
void Service<R, T>::setRepo(const R& repo){
	this->repo = repo;
}

template<class R, class T>
void Service<R, T>::add(const T& t){
	repo.add(t);
}

template<class R, class T>
bool Service<R, T>::remove(const T& t){
	if (repo.remove(t)) {
		return true;
	}
	return false;
}

template<class R, class T>
bool Service<R, T>::update(T& t, const T& tNou){
	if (repo.update(t, tNou)) {
		return true;
	}
	return false;
}

template<class R, class T>
bool Service<R, T>::find(const T& t){
	if (repo.find(t)) {
		return true;
	}
	return false;
}

template<class R, class T>
int Service<R, T>::size(){
	return repo.size();
}

template<class R, class T>
vector<T> Service<R, T>::searchByName(const char * name){
	std::map<int, T> all = getAll();
	vector<T> allGood;
	for (auto itr = all.begin(); itr != all.end(); itr++) {
		if (strcmp(itr->second.getNumeClient(), name) == 0) {
			allGood.push_back(itr->second);
		}
	}
	return allGood;
}

template<class R, class T>
std::map<int, T> Service<R, T>::getAll(){
	return repo.getAll();
}
