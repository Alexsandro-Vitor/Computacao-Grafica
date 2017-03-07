#ifndef LUZ3D_HPP
#define LUZ3D_HPP

#include "CorRGB.cpp"
#include "Camera3D.cpp"

class Luz3D {
	CorRGB iluminacaoAmbiente();
	CorRGB iluminacaoDifusa(Vetor3D normal, Vetor3D l);
	CorRGB iluminacaoEspecular(Vetor3D r, Vetor3D v);
public:
	Ponto3D pos;
	double kAmbiente, kDifuso, kEspecular, n;
	CorRGB luzAmbiente, corLuz;
	Luz3D(const Ponto3D &pos, double kAmbiente, const CorRGB &luzAmbiente, double kDifuso, double kEspecular, const CorRGB &corLuz, double n);
	CorRGB iluminar(Ponto3D ponto, Vetor3D normal, Camera3D camera);
};

#endif
