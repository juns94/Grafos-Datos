#pragma once
#include "NodoAd.h"

class ListaDeAd
{
public:
	ListaDeAd();
	~ListaDeAd();
	bool agregar();
	bool eliminar();
private:
	Nodo * vertice;
	
	bool vacia();

};

