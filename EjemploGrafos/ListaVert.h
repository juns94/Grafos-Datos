#pragma once
#include "NodoVertice.h"
class ListaVert
{

private:
	NodoVertice *inicio;
	NodoVertice *dirUltimo();


public:
	ListaVert();
	~ListaVert();



	bool add(Vertice * vert);
	bool remove(Vertice *vert);


};
