#pragma once
class Vertice;
#include "NodoAd.h"
class ListaAristas {
private:
	NodoAd *Cab;

public:
	ListaAristas();
	~ListaAristas();

	bool agregar(Vertice * vert, int peso);
	bool eliminar(Vertice * vert); // elimina un nodo con vert = vertice
	Vertice * getVerticeDeterminado(int d);

};