#include "stdafx.h"
#include "Grafo.h"


Grafo::Grafo()
{
}


Grafo::~Grafo()
{
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


	NodoAd *arista = new NodoAd();

	return true;
}


bool Grafo::borrarArista(int desde, int para) {

	return true;
}