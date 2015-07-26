#include "stdafx.h"
#include "Vertice.h"


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

bool Vertice::unirCon(Vertice * vertice, int peso) {
	la->agregar(vertice, peso);
	return true;
}

bool Vertice::romperCon(Vertice * vertice) {
	la->eliminar(vertice);
	return true;
}