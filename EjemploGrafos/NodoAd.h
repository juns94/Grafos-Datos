#pragma once
class NodoAd {
private:
	int peso;
	NodoAd *sgt;
	Vertice* vert;

public:
	NodoAd();
	NodoAd(Vertice* nVert);
	NodoAd(Vertice* nVert, int nPeso);
	~NodoAd();


	int getPeso();
	NodoAd * getSgt();
	void setSgt(NodoAd *);
	Vertice *getVert();
};