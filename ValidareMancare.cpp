#include "ValidareMancare.h"
ValidareMancare::ValidareMancare(){
}

ValidareMancare::ValidareMancare(const Mancare& mancare){
	Mancare m = mancare;
	validare(m);
}

ValidareMancare::~ValidareMancare(){
}

void ValidareMancare::validare(Mancare& mancare){
	if (mancare.getNumeClient().size() > 30) {
		throw MyException(" Numele trebuie sa fie mai mic de 30 caractere! ");
	}
	else if (mancare.getAdresaClient().size() > 30) {
		throw MyException(" Adresa trebuie sa fie mai mica de 30 caractere! ");
	}
	else if (mancare.getPretTotal() < 0) {
		throw MyException(" Pretul trebuie sa fie stric pozitiv ( > 0) ! ");
	}
	else if (mancare.getListaPreparate().size() == 1) {
		throw MyException(" Lista trebuie sa contina cel putin un preparat! ");
	}
}

