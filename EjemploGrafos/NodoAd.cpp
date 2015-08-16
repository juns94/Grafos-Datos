#include "stdafx.h"
#include "NodoAd.h"


NodoAd::NodoAd() {
	sgt = NULL;
}


NodoAd::~NodoAd() {
}

NodoAd::NodoAd(Vertice* &nVert, int nPeso) {
	peso = nPeso;
	vert = nVert;
	sgt = NULL;
}
NodoAd::NodoAd(Vertice* &nVert) {
	vert = nVert;
	sgt = NULL;
}

int NodoAd::getPeso() {
	return peso;
}

NodoAd * NodoAd::getSgt() {
	return sgt;
}
Vertice * NodoAd::getVert() {
	return vert;
}

void NodoAd::setSgt(NodoAd * nSgt) {
	sgt = nSgt;
}