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


	while (indx->getSgt() != NULL && !found) {
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
		Vertice *vIndx = tmp->getVertice();
		ListaAristas *la = get(tmp->getVertice()->getDato())->getListaAristas();
		NodoAd *indx = la->getCab();


		while (indx != NULL) {
			if (pr->get(indx->getVert()->getDato()) == NULL && indx->getPeso() < w) {
				va = vIndx;
				w = indx->getPeso();
				na = indx;
			}
			indx = indx->getSgt();
		}
		tmp = tmp->getSgt();
	} while (tmp != NULL);

	if (na != NULL) {
		Vertice *nuevo = new Vertice(na->getVert()->getDato());
		pr->add(nuevo);
		va->unirCon(nuevo, na->getPeso());
		nuevo->unirCon(va, na->getPeso());
		primRec(pr);
	}
	return pr;
}

ListaVert *ListaVert::kruskal() {
	ListaVert *kr = new ListaVert();
	int krSize = 0;
	int lvSize = 0;
	NodoVertice *vIndx;
	NodoAd *aIndex;
	do { //Ciclo kruskal
		vIndx = inicio;
		Vertice *vOrigen = NULL;
		NodoAd *aMenor = NULL;
		lvSize = 0;
		while (vIndx != NULL) {   //ciclo vertices
			
			aIndex = vIndx->getVertice()->getListaAristas()->getCab();
			while (aIndex != NULL) {   //ciclo aristas 
				if ((kr->get(vIndx->getVertice()->getDato()) == NULL) || (kr->get(aIndex->getVert()->getDato() == NULL))) {
					if (aMenor == NULL) {
						vOrigen = vIndx->getVertice();
						aMenor = aIndex;
					} else {
						if (aMenor->getPeso() > aIndex->getPeso()) {
							vOrigen = vIndx->getVertice();
							aMenor = aIndex;
						}
					}
				}
				aIndex = aIndex->getSgt();
			} //fin ciclo aristas
			vIndx = vIndx->getSgt();

			lvSize++;
		}//fin cico vertices
		if (aMenor != NULL) {
			int desde = vOrigen->getDato();
			int para = aMenor->getVert()->getDato();
			int peso = aMenor->getPeso();
			if (kr->add(new Vertice(desde))) {
				krSize++;
			}
			if (kr->add(new Vertice(para))) {
				krSize++;
			}
			kr->get(desde)->unirCon(kr->get(para), peso);
			kr->get(para)->unirCon(kr->get(desde), peso);

		} else {
			ListaVert *lv = new ListaVert();
			lv->add(new Vertice(-1));
			return lv;
		}

	} while (krSize != lvSize);  //fin ciclo kruskal

	return kr;
}


void ListaVert::phelp(ListaVert *lista , Vertice *v){


	if (v->getVisited() == 0){

		lista->add(new Vertice(v->getDato()));
		v->setVisited();

		cout << v->getVisited() << endl;
		phelp(lista, v->getListaAristas()->getCab()->getVert());
	} 


		//system("pause");
		//phelp(lista, v->getListaAristas()->getCab()->getVert());
		

	

		

}
ListaVert *ListaVert::profundidad() {
	ListaVert *pr = new ListaVert();
	int krSize = 0;
	int lvSize = 0;
	NodoVertice *vIndx;
	NodoAd *aIndex;

		vIndx = inicio;
		Vertice *vOrigen = NULL;
		NodoAd *aMenor = NULL;




		phelp( pr , vIndx->getVertice());

		
		while (vIndx != NULL) {
			if (vIndx->getVertice()->getVisited() == 0){


				pr->add(new Vertice(vIndx->getVertice()->getDato()));
				vIndx->getVertice()->setVisited();
			}

			vIndx = vIndx->getSgt();
		
		}
		


		/*
		   //ciclo vertices

		   aIndex = vIndx->getVertice()->getListaAristas()->getCab();
		   while (aIndex != NULL) {   //ciclo aristas
		   if ((pr->get(vIndx->getVertice()->getDato()) == NULL) || (pr->get(aIndex->getVert()->getDato() == NULL))) {
		   if (aMenor == NULL) {
		   vOrigen = vIndx->getVertice();
		   aMenor = aIndex;
		   }
		   else {
		   if (aMenor->getPeso() > aIndex->getPeso()) {
		   vOrigen = vIndx->getVertice();
		   aMenor = aIndex;
		   }
		   }
		   }
		   aIndex = aIndex->getSgt();
		   } //fin ciclo aristas



		   }//fin cico vertices
		   */




		//} while (vIndx != NULL);  //fin ciclo 

		return pr;

	}





ListaVert *ListaVert::djikstra() {


	ListaVert *kr = new ListaVert();
	int krSize = 0;
	int lvSize = 0;
	NodoVertice *vIndx;
	NodoAd *aIndex;
	do { //Ciclo kruskal
		vIndx = inicio;
		Vertice *vOrigen = NULL;
		NodoAd *aMenor = NULL;
		lvSize = 0;
		while (vIndx != NULL) {   //ciclo vertices

			aIndex = vIndx->getVertice()->getListaAristas()->getCab();
			while (aIndex != NULL) {   //ciclo aristas 
				if ((kr->get(vIndx->getVertice()->getDato()) == NULL) || (kr->get(aIndex->getVert()->getDato() == NULL))) {
					if (aMenor == NULL) {
						vOrigen = vIndx->getVertice();
						aMenor = aIndex;
					}
					else {
						if (aMenor->getPeso() > aIndex->getPeso()) {
							vOrigen = vIndx->getVertice();
							aMenor = aIndex;
						}
					}
				}
				aIndex = aIndex->getSgt();
			} //fin ciclo aristas
			vIndx = vIndx->getSgt();

			lvSize++;
		}//fin cico vertices
		if (aMenor != NULL) {
			int desde = vOrigen->getDato();
			int para = aMenor->getVert()->getDato();
			int peso = aMenor->getPeso();
			if (kr->add(new Vertice(desde))) {
				krSize++;
			}
			if (kr->add(new Vertice(para))) {
				krSize++;
			}
			kr->get(desde)->unirCon(kr->get(para), peso);
			kr->get(para)->unirCon(kr->get(desde), peso);

		}
		else {
			ListaVert *lv = new ListaVert();
			lv->add(new Vertice(-1));
			return lv;
		}

	} while (krSize != lvSize);  //fin ciclo kruskal

	return kr;
}


void ListaVert::print() {
	NodoVertice *tmp = inicio;
	while (tmp != NULL) {
		cout << "V" << tmp->getVertice()->getDato() << ">>";
		tmp->getVertice()->getListaAristas()->print();
		cout << endl;
		tmp = tmp->getSgt();
	}

}
