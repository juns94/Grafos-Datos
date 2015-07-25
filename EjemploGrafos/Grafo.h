#pragma once
#include "Nodo.h"
#include "NodoVertice.h"
class Grafo
{
public:
	Grafo();
	~Grafo();

private:
	NodoVertice * inicio;
	bool borrarGrafo();

	bool agregarVertice(int dato);
	bool borrarVertice(int dato);

	bool unirNodos(int desde, int para, int peso);
	bool borrarArista(int desde, int para);



};


