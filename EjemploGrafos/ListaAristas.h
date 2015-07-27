#pragma once
class Vertice;
class ListaAristas {
private:
	//NodoAd *Cab;

public:
	ListaAristas();
	~ListaAristas();

	bool agregar(Vertice * vert, int peso);
	bool eliminar(Vertice * vert); // elimina un nodo con vert = vertice

};

