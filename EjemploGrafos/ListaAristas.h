#pragma once
#include"NodoAd.h"
class ListaAristas
{
public:
	ListaAristas();
	~ListaAristas();
private:
	NodoAd *Cab();

	bool agregar(NodoAd * vertice, int peso);
	bool eliminar(NodoAd * vertice); // elimina un nodo con vert = vertice

};

