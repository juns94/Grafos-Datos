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