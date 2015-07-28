#include "stdafx.h"
#include "Grafo.h"


Grafo::Grafo() {
	LV = new ListaVert();
}


Grafo::~Grafo() {
}

bool Grafo::agregarVertice(int dato) {
	LV->add(new Vertice(dato));
	return true;
}

bool Grafo::borrarVertice(int dato) {
	LV->remove(dato);
	return true;
}

bool Grafo::unirVertices(int desde, int para, int peso) {
	Vertice * d = LV->get(desde);
	Vertice * p = LV->get(para);
	if (d != NULL && p != NULL) {
		d->unirCon(p, peso);
		return true;
	} else {
		return false;
	}
}


bool Grafo::borrarArista(int desde, int para) {
	Vertice * d = LV->get(desde);
	Vertice * p = LV->get(para);
	if (d != NULL && p != NULL) {
		return LV->get(desde)->romperCon(LV->get(para));
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