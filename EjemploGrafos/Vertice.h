#pragma once
#include "ListaAristas.h"
class Vertice
{
public:
	Vertice();
	~Vertice();
private:
	int dato;
	ListaAristas *la;
};

