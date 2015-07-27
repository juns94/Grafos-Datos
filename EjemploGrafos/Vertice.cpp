#include "stdafx.h"
#include "Vertice.h"
//#include "ListaAristas.h";
Vertice::Vertice()
{
}

Vertice::Vertice(int d) {
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
	la->agregar(vert, peso);
	return true;
}

bool Vertice::romperCon(Vertice * vert) {
	la->eliminar(vert);
	return true;
}