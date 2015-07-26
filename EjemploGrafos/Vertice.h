#pragma once
#include "ListaAristas.h"
class ListaAristas;
class Vertice
{
private:
	int dato;
	ListaAristas *la;

public:
	Vertice();
	Vertice(int d);
	~Vertice();
	

	int getDato();
	void setDato(int d);

};

