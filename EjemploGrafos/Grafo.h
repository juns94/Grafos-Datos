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
	bool agregarNodo();
	bool agregarNodo(int);

	bool unirNodos(int desde ,int para);
	bool agregarNodo(Nodo *nodo, int);
	bool agregarVertice(Nodo *nodo);
	bool borrarVertice(Nodo *nodo);
	bool agregarArista(Nodo *nodo);
	bool agregarArista(int, Nodo *destino);
	bool agregarArista(Nodo *nodo, int peso);
	bool agregarArista(Nodo *fuente, Nodo *destino, int peso);
	bool eliminarArista(Nodo *nodo);
	bool eliminarArista(Nodo *fuente, Nodo *destino);

	char getNombre();
	


};


