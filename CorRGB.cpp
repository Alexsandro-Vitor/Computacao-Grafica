#include "CorRGB.hpp"
#include <iostream>

//--------------- MonoCor ---------------

//Construtor de MonoCor
MonoCor::MonoCor(unsigned char x = 0) : x(x) {}

unsigned char MonoCor::getX() const {
	return x;
}

//Atribuicao de valor para a MonoCor
unsigned char MonoCor::operator=(const unsigned int& I) {
	if (I > 255) x = 255;
	else if (I < 0) x = 0;
	else x = I;
	return I;
}

//Operacoes de adicao e subtracao com numeros
unsigned int MonoCor::operator+(unsigned int i) {
	if ((x + i) > 255) return 255;
	return x + i;
}

unsigned int MonoCor::operator-(unsigned int i) {
	if (i > x) return 0;
	return x - i;
}

unsigned int MonoCor::operator*(double i) {
	if ((x * i) > 255) return 255;
	else if ((x * i) < 0) return 0;
	return (unsigned int)(x * i);
}

//Operacoes entre cores
MonoCor MonoCor::operator+(MonoCor c) {
	if ((x + c.getX()) > 255) return MonoCor(255);
	else return MonoCor(x + c.getX());
}

MonoCor MonoCor::operator-(MonoCor c) {
	if (c.getX() > x) return MonoCor(0);
	else return MonoCor(x - c.getX());
}

//Sobrecarga do operador de saida para MonoCor
std::ostream& operator<<(std::ostream& output, const MonoCor& C) {
	output << (unsigned short)C.getX();
	return output;
}

//--------------- CorRGB ---------------

//Construtor de CorRGB, usando RGB
CorRGB::CorRGB(unsigned char r, unsigned char g, unsigned char b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

//Construtor de CorRGB, usando as MonoCor
CorRGB::CorRGB(MonoCor r, MonoCor g, MonoCor b) : r(r), g(g), b(b) {}

//Construtor de CorRGB, usando o nome da cor
CorRGB::CorRGB(std::string nome) {
	if (nome.compare("branco") == 0) r = g = b = 255;
	else if (nome.compare("cinza") == 0) r = g = b = 127;
	else if (nome.compare("preto") == 0) r = g = b = 0;
	else if (nome.compare("vermelho") == 0) {r = 255; g = b = 0;}
	else if (nome.compare("amarelo") == 0) {r = g = 255; b = 0;}
	else if (nome.compare("verde") == 0) {r = 0; g = 255; b = 0;}
	else if (nome.compare("ciano") == 0) {r = 0; g = b = 255;}
	else if (nome.compare("azul") == 0) {r = g = 0; b = 255;}
	else if (nome.compare("roxo") == 0) {r = 255; g = 0; b = 255;}
}

//Operacoes entre cores
CorRGB CorRGB::operator+(CorRGB cor) {
	return CorRGB(r + cor.r, g + cor.g, b + cor.b);
}

CorRGB CorRGB::operator-(CorRGB cor) {
	return CorRGB(r - cor.r, g - cor.g, b - cor.b);
}

//Operacoes de cores e numeros
CorRGB CorRGB::operator*(double i) {
	return CorRGB(r * i, g * i, b * i);
}

//Sobrecarga do operador de saida para CorRGB
std::ostream& operator<<(std::ostream& output, const CorRGB& C) {
	output << "(" << C.r << ", " << C.g << ", " << C.b << ")";
	return output;
}
