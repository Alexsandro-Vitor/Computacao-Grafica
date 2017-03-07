#include "Luz3D.hpp"

//Construtor de Luz3D
Luz3D::Luz3D(const Ponto3D &pos = Ponto3D(0, 0, 0),
			double kAmbiente = 0, const CorRGB &luzAmbiente = CorRGB(0, 0, 0),
			double kDifuso = 0, double kEspecular = 0, const CorRGB &corLuz = CorRGB(0, 0, 0),
			double n = 0)
	: pos(pos), kAmbiente(kAmbiente), luzAmbiente(luzAmbiente), kDifuso(kDifuso), kEspecular(kEspecular), corLuz(corLuz), n(n) {}

CorRGB Luz3D::iluminar(Ponto3D ponto, Vetor3D normal, Camera3D camera) {
	normal = normal.normalizado();
	Vetor3D l = (pos - ponto).normalizado();
	normal = (normal * l < 0) ? -normal : normal;
	Vetor3D r = normal * 2 * (normal * l) - l;	//Vetor de reflexao
	Vetor3D v = (camera.c - ponto).normalizado();
	return (iluminacaoAmbiente() + iluminacaoDifusa(normal, l) + iluminacaoEspecular(r, v));
}

//Iluminacao ambiente do ponto
CorRGB Luz3D::iluminacaoAmbiente() {
	return luzAmbiente * kAmbiente;
}

//Iluminacao difusa do ponto
CorRGB Luz3D::iluminacaoDifusa(Vetor3D normal, Vetor3D l) {
	return corLuz * kDifuso * (normal * l);
}

//Iluminacao especular do ponto
CorRGB Luz3D::iluminacaoEspecular(Vetor3D r, Vetor3D v) {
	return corLuz * kEspecular * pow(r * v, n);
}
