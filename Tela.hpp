#ifndef TELA_HPP
#define TELA_HPP

#include "Geometria3D.cpp"
#include "CorRGB.cpp"

class Tela {
	int largura;
	int altura;
	double **zBuffer;
	CorRGB **imagem;
	int xTela(Ponto3D ponto);
	int yTela(Ponto3D ponto);
public:
	Tela(int largura, int altura);
	void inserirPonto(Ponto3D ponto, CorRGB cor);
};

#endif
