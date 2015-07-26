#pragma once
#include "ListaVert.h"
class Grafo
{
public:
	Grafo();
	~Grafo();

private:
	ListaVert * inicio;
	bool borrarGrafo();

	bool agregarVertice(int dato);
	bool borrarVertice(int dato);

	bool unirNodos(int desde, int para, int peso);
	bool borrarArista(int desde, int para);



};


