#include "stdafx.h"
#include "Vertice.h"
//#include "ListaAristas.h";
Vertice::Vertice()
{
}

Vertice::Vertice(int d) {
	la = new ListaAristas();
	dato = d;
}


Vertice::~Vertice()
{
}

int Vertice::getDato() {
	return dato;
}

void Vertice::setDato(int d) {
	dato = d;
}

bool Vertice::unirCon(Vertice * vert, int peso) {	
	return la->agregar(vert, peso);;
}

bool Vertice::romperCon(Vertice * vert) {
	return la->eliminar(vert);;
}

Vertice *Vertice::Adyacente(int d) {
	return la->getVerticeDeterminado(d);
}

ListaAristas *Vertice::getListaAristas() {

	return la;
}

bool Vertice::getVisited() {
	return visited;

}

void Vertice::setVisited() {
	this->visited = true;
}

