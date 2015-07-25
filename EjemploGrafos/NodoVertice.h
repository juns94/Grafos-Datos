#pragma once
#include "Vertice.h"
class NodoVertice
{
public:
	NodoVertice();
	~NodoVertice();

private:
	Vertice *V;
	NodoVertice *sgt;
};

