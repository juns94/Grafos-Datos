#pragma once
#include "Nodo.h"
class NodoAd
{
public:
	NodoAd();
	~NodoAd();
private:
	int peso;
	NodoAd *sgt;
	Nodo* vert;
};

