#pragma once
#include "Vertice.h"
class NodoVertice
{

private:
	Vertice *V;
	NodoVertice *sgt;

public:
	NodoVertice();
	NodoVertice(Vertice *nV);
	~NodoVertice();

	NodoVertice *getSgt();
	void SetSgt(NodoVertice *);
	Vertice *getVertice();
};

