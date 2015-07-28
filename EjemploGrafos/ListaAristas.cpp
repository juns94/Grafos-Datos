#include "stdafx.h"
#include "ListaAristas.h"


ListaAristas::ListaAristas() {
}


ListaAristas::~ListaAristas() {
}


bool ListaAristas::agregar(Vertice * vert, int peso) {
	NodoAd* ingreso = new NodoAd(vert, peso);
	NodoAd* aux;
	aux = Cab;
	if (Cab == NULL) {
		Cab->setSgt(ingreso);
	} else {
		do {
			if (aux->getSgt() == NULL) {
				aux->setSgt(ingreso);
			}
			aux = aux->getSgt();
		} while (aux->getSgt() != NULL);
	}
	return true;
}


bool ListaAristas::eliminar(Vertice * vert) {
	NodoAd* ingreso = new NodoAd(vert);
	NodoAd* aux;
	aux = Cab;
	if (Cab == NULL) {
		return false;
	} else {
		do {
			if (aux->getSgt()->getVert() == vert) {
				NodoAd * temp = aux->getSgt();
				aux->setSgt(aux->getSgt()->getSgt());
				delete temp;
			}
			aux = aux->getSgt();
		} while (aux->getSgt() != NULL);
	}
	return true;
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