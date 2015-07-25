#pragma once
#include"NodoAd.h"
class ListaAristas
{
public:
	ListaAristas();
	~ListaAristas();
private:
	NodoAd *Cab();

	bool agregar(NodoVertice * vertice, int peso);
	bool eliminar(NodoVertice * vertice); // elimina un nodo con vert = vertice

};

