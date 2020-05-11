#include "ValidareShopping.h"
#include "MyException.h"

ValidareShopping::ValidareShopping(const Shopping& s){
	Shopping sp = s;
	validare(sp);
}

ValidareShopping::~ValidareShopping(){
}

void ValidareShopping::validare(Shopping& s){
	if (s.getNumeClient().size() > 30) {
		throw MyException(" Numele trebuie sa fie mai mic de 30 caractere! ");
	}
	else if (s.getAdresaClient().size() > 30) {
		throw MyException(" Adresa trebuie sa fie mai mica de 30 caractere! ");
	}
	else if (s.getPretTotal() < 0) {
		throw MyException(" Pretul trebuie sa fie stric pozitiv ( > 0) ! ");
	}
	else if (s.getNumeMagazin().size() > 30) {
		throw MyException(" Numele de magazin trebuie sa fie mai mic de 30 caractere! ");
	}
	else if (s.getListaCumparaturi().size() == 1) {
		throw MyException(" Lista trebuie sa contina cel putin un preparat! ");
	}
}
