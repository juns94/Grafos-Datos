#pragma once
#include "NodoVertice.h"
class ListaVert
{

private:
	NodoVertice *inicio;
	NodoVertice *dirUltimo();
	ListaVert *primRec(ListaVert *);

public:
	ListaVert();
	~ListaVert();

	bool add(Vertice * vert);
	bool remove(int dato);
	Vertice *get(int dato); //regresa el vertice con el dato d;
	ListaVert *prim();
	ListaVert *kruskal();
	ListaVert *profundidad();
	ListaVert *djikstra();
	NodoVertice * getInicio();
	void print();

};

