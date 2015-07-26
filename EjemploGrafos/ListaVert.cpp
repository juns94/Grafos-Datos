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
	NodoVertice *indx = dirUltimo();
	NodoVertice *tmp = new NodoVertice(vert);
	if (indx == NULL) {
		inicio = tmp;
	} else {
		indx->SetSgt(tmp);
	}
	return true;
}

bool  ListaVert::remove(Vertice *vert) {
	NodoVertice *indx = inicio;
	bool r = false;
	if (indx != NULL) {
		if (indx->getVertice() == vert) {
			inicio = indx->getSgt();
			delete indx;
			r = true;
		}

		while (indx != NULL && !r) {
			if (indx->getSgt() != NULL) {
				if (indx->getSgt()->getVertice() == vert) {
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