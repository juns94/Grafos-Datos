#include "stdafx.h"
#include "NodoAd.h"


NodoAd::NodoAd()
{
	sgt = NULL;
}


NodoAd::~NodoAd()
{
}

NodoAd::NodoAd(int nPeso) {
	peso = nPeso;
	sgt = NULL;
}


int NodoAd::getPeso() {
	return peso;
}

NodoAd * NodoAd::getSgt() {
	return sgt;
}

void NodoAd::setSgt(NodoAd * nSgt) {
	sgt = nSgt;
}