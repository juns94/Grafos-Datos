#include "stdafx.h"
#include "ListaVert.h"

ListaVert::ListaVert(){
	inicio = NULL;
}

ListaVert::~ListaVert(){
}

NodoVertice *ListaVert::dirUltimo(){
	NodoVertice *tmp = inicio;
	if (tmp != NULL){
		while (tmp->getSgt() != NULL){
			tmp = tmp->getSgt();
		}
	}
	return tmp;
}

bool ListaVert::add(Vertice * vert){
	NodoVertice *indx = inicio;
	bool r = false;
	while (indx != NULL && !r) {
		if (indx->getVertice()->getDato() == vert->getDato()) {
			r = true;
		} else {
			indx = indx->getSgt();
		}
	}
	if (!r) {
		NodoVertice *tmp = new NodoVertice(vert);
		 indx->SetSgt(tmp);
		 return true;
	} else {
		return false;
	}


	
}

bool  ListaVert::remove(int dato) {
	NodoVertice *indx = inicio;
	bool r = false;
	if (indx != NULL) {
		if (indx->getVertice()->getDato() == dato) {
			inicio = indx->getSgt();
			delete indx;
			r = true;
		}

		while (indx != NULL && !r) {
			if (indx->getSgt() != NULL) {
				if (indx->getSgt()->getVertice()->getDato() == dato) {
					NodoVertice *tmp = indx->getSgt();
					indx->SetSgt(tmp->getSgt());
					delete tmp;
					r = true;
				}
			}
			indx = indx->getSgt();
		}
	} 
	return r;
}

Vertice *ListaVert::get(int dato) {
	NodoVertice *indx = inicio;
	bool r = false;
	while (indx != NULL && !r) {
		if (indx->getVertice()->getDato() == dato) {
			r = true;
		} else {
			indx = indx->getSgt();
		}
	}
	if (indx != NULL) {
		return indx->getVertice();
	} else {
		return NULL;
	}
}