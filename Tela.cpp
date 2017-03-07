#include "Tela.hpp"

//Construtor de tela
Tela::Tela(int largura, int altura) : largura(largura), altura(altura), zBuffer(new double[largura][altura]), imagem(new CorRGB[largura][altura]) {}

//Inserção de ponto na tela
void Tela::inserirPonto(Ponto3D ponto, CorRGB cor) {
	int x = xTela(ponto), y = yTela(ponto);
	if (x > 0 && x < largura && y > 0 && y < altura) {
		imagem[x][y] = (zBuffer[x][y] > ponto.z) ? imagem[x][y] : cor;
		zBuffer[x][y] = (zBuffer[x][y] > ponto.z) ? zBuffer[x][y] : ponto.z;
	}
}

//Calculo da coordenada x do ponto
int Tela::xTela(Ponto3D ponto) {
	return (int)((ponto.x + 1) * largura / 2);
}

//Calculo da coordenada y do ponto
int Tela::yTela(Ponto3D ponto) {
	return (int)((1 - ponto.y) * altura / 2);
}
