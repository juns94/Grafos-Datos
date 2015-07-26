#include "stdafx.h"
#include "NodoVertice.h"


NodoVertice::NodoVertice()
{
	sgt = NULL;
}


NodoVertice::~NodoVertice()
{
}

NodoVertice::NodoVertice(Vertice *nV) {
	V = nV;
	sgt = NULL;
}


Vertice *NodoVertice::getVertice() {
	return V;
}

NodoVertice *NodoVertice::getSgt(){
	return sgt;
}

void NodoVertice::SetSgt(NodoVertice * nSgt){
	sgt = nSgt;
}