#pragma once
#include"NodoAd.h"
#include"NodoVertice.h"

class ListaAristas {
private:
	NodoAd *Cab;

public:
	ListaAristas();
	~ListaAristas();

	bool agregar(Vertice * vertice, int peso);
	bool eliminar(Vertice * vertice); // elimina un nodo con vert = vertice

};

