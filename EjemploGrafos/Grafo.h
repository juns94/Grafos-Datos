#pragma once
#include "ListaVert.h"
class Grafo
{

private:
	ListaVert * LV;

public:
	Grafo();
	~Grafo();

	bool borrarGrafo();

	bool agregarVertice(int dato);
	bool borrarVertice(int dato);

	bool unirVertices(int desde, int para, int peso);
	bool borrarArista(int desde, int para);

	bool modificarPeso(int desde, int para, int peso);

	bool esAdyacente(int desde, int para);
	bool existeVertice(int vert);

};


