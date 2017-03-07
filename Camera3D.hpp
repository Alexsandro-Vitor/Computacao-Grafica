#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Geometria3D.cpp"
#include "CorRGB.cpp"
#include "Tela.cpp"

class Camera3D {
	Ponto2D transformacaoCamera(Ponto3D ponto);
	Ponto2D perspectiva(Ponto3D ponto);
public:
	Ponto3D c;
	Vetor3D n, v;
	double hX, hY;
	Camera3D(Ponto3D c, Vetor3D n, Vetor3D v, double hX, double hY, double d = 1);
	Ponto2D verPonto(Ponto3D ponto, CorRGB cor, Tela tela);
};

#endif
