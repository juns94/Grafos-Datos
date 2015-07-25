#pragma once
#include "Grafo.h"
class ListaDeGrafos
{
public:
	ListaDeGrafos();
	~ListaDeGrafos();


private:

	Grafo *root;

	bool crearGrafo(char *);
	bool elimnarGrafo( char *);


};

