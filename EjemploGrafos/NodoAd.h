#pragma once
class NodoAd {
private:
	int peso;
	NodoAd *sgt;
//	Vertice* vert;

public:
	NodoAd();
	NodoAd(int nPeso);
	~NodoAd();

	int getPeso();
	NodoAd * getSgt();
	void setSgt(NodoAd *);
};

