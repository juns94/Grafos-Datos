#include "stdafx.h"
#include "ListaAristas.h"


ListaAristas::ListaAristas() {
}


ListaAristas::~ListaAristas() {
}


bool ListaAristas::agregar(Vertice *& vert, int peso) {
	NodoAd* ingreso = new NodoAd(vert, peso);
	if (Cab == NULL) {
		Cab = ingreso;
	} else {
		NodoAd* aux = Cab;
		while (aux->getSgt() != NULL) {
			aux = aux->getSgt();
		}
		aux->setSgt(ingreso);
	}
	return true;
}


bool ListaAristas::eliminar(Vertice * &vert) {
	NodoAd* aux = Cab;
	bool borrado = false;
	if (aux != NULL) {
		if (aux->getVert()->getDato() == vert->getDato()) {
			Cab = aux->getSgt();
			delete aux;
			return true;
		}
	}
	while (aux != NULL) {
		if (aux->getSgt() != NULL) {
			if (aux->getSgt()->getVert()->getDato() == vert->getDato()) {
				NodoAd * temp = aux->getSgt();
				aux->setSgt(aux->getSgt()->getSgt());
				delete temp;
			}
		}
		aux = aux->getSgt();
	}

	return borrado;
}

Vertice* ListaAristas::getVerticeDeterminado(int d) {
	Vertice* vert = NULL;
	NodoAd* aux = new NodoAd();
	aux = Cab;
	bool encontrado = false;

	if (Cab != NULL) {
		do {
			if (aux->getVert()->getDato() == d) {
				encontrado = true;
				vert = aux->getVert();
			}
			aux = aux->getSgt();
		} while (aux->getSgt() != NULL && encontrado != true);
		return vert;
	}
}

NodoAd *ListaAristas::getCab() {
	return Cab;
}

void ListaAristas::print() {
	NodoAd *tmp = Cab;
	while (tmp != NULL) {
		cout << "(D=> " << tmp->getVert()->getDato() << ", W=> " << tmp->getPeso() << ") ";
		tmp = tmp->getSgt();
	}
}