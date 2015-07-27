#pragma once
#include "ListaAristas.h"
//class ListaAristas;
class Vertice {
private:
	int dato;
	ListaAristas *la;

public:
	Vertice();
	Vertice(int d);
	~Vertice();

	bool unirCon(Vertice * vertice, int peso);
	bool romperCon(Vertice * vertice);
	int getDato();
	void setDato(int d);

};

