#include "stdafx.h"
#include "Grafo.h"


Grafo::Grafo() {
	LV = new ListaVert();
}


Grafo::~Grafo() {
}

bool Grafo::agregarVertice(int dato) {
	
	return LV->add(new Vertice(dato));
}

bool Grafo::borrarVertice(int dato) {
	NodoVertice *nv = LV->getInicio();
	Vertice *v = LV->get(dato);
	while (nv != NULL) {
		nv->getVertice()->romperCon(v);
		nv = nv->getSgt();
	}
	return LV->remove(dato);
}

bool Grafo::unirVertices(int desde, int para, int peso) {
	Vertice * d = LV->get(desde);
	Vertice * p = LV->get(para);
	if (d != NULL && p != NULL) {
		d->unirCon(p, peso);
		p->unirCon(d, peso);
		return true;
	} else {
		return false;
	}
}


bool Grafo::borrarArista(int desde, int para) {
	Vertice * d = LV->get(desde);
	Vertice * p = LV->get(para);
	if (d != NULL && p != NULL) {
		return LV->get(desde)->romperCon(LV->get(para)) && LV->get(para)->romperCon(LV->get(desde));
	} else {
		return false;
	}
}


bool Grafo::modificarPeso(int desde, int para, int peso) {
	return true;
}

bool Grafo::esAdyacente(int desde, int para) {
	Vertice * d = LV->get(desde);
	Vertice * p = LV->get(para);
	if (d != NULL && p != NULL) {
		return (d->Adyacente(para) != NULL || p->Adyacente(desde) != NULL);
	} else {
		return false;
	}


}

bool Grafo::existeVertice(int vert) {
	return (LV->get(vert) != NULL);
}


ListaVert* Grafo::prim() {
	return LV->prim();
}

void Grafo::print() {
	LV->print();
}