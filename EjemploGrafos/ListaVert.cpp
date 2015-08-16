#include "stdafx.h"
#include "ListaVert.h"

ListaVert::ListaVert() {
	inicio = NULL;
}

ListaVert::~ListaVert() {
}

NodoVertice *ListaVert::dirUltimo() {
	NodoVertice *tmp = inicio;
	if (tmp != NULL) {
		while (tmp->getSgt() != NULL) {
			tmp = tmp->getSgt();
		}
	}
	return tmp;
}

bool ListaVert::add(Vertice * vert) {
	NodoVertice *indx = inicio;
	bool found = false;
	if (indx == NULL) {
		NodoVertice *tmp = new NodoVertice(vert);
		inicio = tmp;
		return true;
	}
	

	while (indx->getSgt() != NULL && !found){
		if (indx->getVertice()->getDato() == vert->getDato()) {
			found = true;
		} else {
			indx = indx->getSgt();
		}
	}

	if (indx->getVertice()->getDato() == vert->getDato()) {
		return false;
	}

	if (found) {
		return false;
	} else {
		NodoVertice *tmp = new NodoVertice(vert);
		indx->SetSgt(tmp);
		return true;
	}

}

bool  ListaVert::remove(int dato) {
	NodoVertice *indx = inicio;
	Vertice *v = get(dato);
	bool r = false;
	while (indx != NULL) {
		indx->getVertice()->romperCon(v);
		indx = indx->getSgt();
	}

	indx = inicio;
	if (indx != NULL) {
		if (indx->getVertice()->getDato() == dato) {
			if (indx = inicio) {
				inicio = indx->getSgt();
				delete indx;
				r = true;
			}
		}

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

	return r;
}

NodoVertice * ListaVert::getInicio() {
	return inicio;
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

ListaVert *ListaVert::prim() {
	ListaVert *pr = new ListaVert();
	int vs = 0;

	NodoVertice *tmp = inicio;
	if (tmp != NULL) {
		Vertice *v = new Vertice(tmp->getVertice()->getDato());
		pr->add(v);
		pr = primRec(pr);
	}
	return pr;
}

ListaVert *ListaVert::primRec(ListaVert* pr) {
	NodoVertice * tmp = pr->inicio;
	Vertice *va = NULL;
	NodoAd *na = NULL;
	int w = 1000000;

	do {
		Vertice *Vtmp = tmp->getVertice();
		ListaAristas *la = Vtmp->getListaAristas();
		NodoAd *indx = la->getCab();

		while (indx != NULL) {
			if (pr->get(indx->getVert()->getDato()) == NULL && indx->getPeso() < w) {
				w = indx->getPeso();
				na = indx;
				va = Vtmp;
			}
			indx = indx->getSgt();
		}
		tmp = tmp->getSgt();
	} while (tmp != NULL);

	if (na != NULL) {
		Vertice *nuevo = new Vertice(na->getVert()->getDato());
		pr->add(nuevo);
		va->unirCon(nuevo, na->getPeso());
		//	nuevo->unirCon(va, na->getPeso());
		primRec(pr);
	}
	return pr;
}

void ListaVert::print() {
	NodoVertice *tmp = inicio;
	while (tmp != NULL) {
		cout << "V" << tmp->getVertice()->getDato();
		tmp->getVertice()->getListaAristas()->print();
		cout << endl;
		tmp = tmp->getSgt();
	}

}
