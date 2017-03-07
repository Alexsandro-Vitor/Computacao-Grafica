#include "Camera3D.hpp"

//Construtor de Camera, talvez mude
Camera3D::Camera3D(Ponto3D c, Vetor3D n, Vetor3D v, double hX, double hY, double d) : c(c), hX(hX/d), hY(hY/d) {
	this->v = v.normalizado();
	this->n = (n - (n >> v)).normalizado();
}

//Metodo para passar um ponto 3D para coordenadas de tela
void Camera3D::verPonto(Ponto3D ponto, CorRGB cor, Tela tela) {
	ponto = transformacaoCamera(ponto);	
	ponto = perspectiva(ponto);
	tela.inserirPonto(ponto, cor);
}

//Metodo para passar um ponto para coordenadas de camera
Ponto3D Camera3D::transformacaoCamera(Ponto3D ponto) {
	
}

//Metodo para projetar um ponto com perspectiva
Ponto3D Camera3D::perspectiva(Ponto3D ponto) {
	return Ponto3D(ponto.x / (ponto.z * hX), ponto.y / (ponto.z * hY), ponto.z);
}
