#pragma once
class Vertice;
#include "NodoAd.h"
class ListaAristas {
private:
	NodoAd *Cab;
	int size;

public:
	ListaAristas();
	~ListaAristas();

	bool agregar(Vertice *&vert, int peso);
	bool eliminar(Vertice * &vert); // elimina un nodo con vert = vertice
	Vertice * getVerticeDeterminado(int d); //regresa el vertice con el dato d; null si no lo encuentra
	NodoAd *getCab();
	void print();
	int getSize();
};