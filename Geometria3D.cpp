#include "Geometria3D.hpp"
#include <cmath>

//Funcao auxiliar
bool doubleEquals(double a, double b) {
	return abs(a - b) < (10e-9);
}

//--------------- Ponto3D ---------------

//Construtor do ponto
Ponto3D::Ponto3D(double x, double y, double z) : x(x), y(y), z(z) {}

//Deslocamento do ponto por um vetor
Ponto3D Ponto3D::operator+(Vetor3D v) {
	return Ponto3D(x + v.x, y + v.y, z + v.z);
}

Ponto3D Ponto3D::operator-(Vetor3D v) {
	return Ponto3D(x - v.x, y - v.y, z - v.z);
}

//Deslocamento de um ponto a outro
Vetor3D Ponto3D::operator-(Ponto3D v) {
	return Vetor3D(x - v.x, y - v.y, z - v.z);
}

//Sobrecarga do operador de saída para Ponto3D
std::ostream& operator<<(std::ostream& output, const Ponto3D& V) {
	output << "(" << V.x << ", " << V.y << ", " << V.z << ")";
	return output;
}

//--------------- Vetor3D ---------------

//Construtor do vetor
Vetor3D::Vetor3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

//Soma de vetores
Vetor3D Vetor3D::operator+(Vetor3D v) {
	return Vetor3D(x + v.x, y + v.y, z + v.z);
}

//Deslocamento de ponto
Ponto3D Vetor3D::operator+(Ponto3D v) {
	return Ponto3D(x + v.x, y + v.y, z + v.z);
}

//Subtracao de vetores
Vetor3D Vetor3D::operator-(Vetor3D v) {
	return Vetor3D(x - v.x, y - v.y, z - v.z);
}

Vetor3D Vetor3D::operator-() {
	return Vetor3D(-x, -y, -z);
}

//Multiplicacao de vetor por escalar
Vetor3D Vetor3D::operator*(double i) {
	return Vetor3D(x * i, y * i, z * i);
}

//Produto vetorial
Vetor3D Vetor3D::prodVetorial(Vetor3D v) {
	return Vetor3D(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

//Multiplicacao de vetores
double Vetor3D::operator*(Vetor3D v) {
	return x * v.x + y * v.y + z * v.z;
}

//Divisao de vetor por escalar
Vetor3D Vetor3D::operator/(double i) {
	return Vetor3D(x / i, y / i, z / i);
}

//Sobrecarga do operador de saída para Vetor3D
std::ostream& operator<<(std::ostream& output, const Vetor3D& V) {
	output << "(" << V.x << ", " << V.y << ", " << V.z << ")";
	return output;
}

//Projecao ortogonal de um vetor sobre outro
Vetor3D Vetor3D::operator>>(Vetor3D v) {
	return v * ((*this * v) / (v * v));
}

//Modulo de um vetor
double Vetor3D::modulo() {
	return sqrt(x * x + y * y + z * z);
}

//Normalizacao do vetor
Vetor3D Vetor3D::normalizado() {
	return doubleEquals(modulo(), 0) ? Vetor3D() : Vetor3D(x / modulo(), y / modulo(), z / modulo());
}

//Comparacao de vetores
bool Vetor3D::operator<(Vetor3D v) {
	return this->modulo() < v.modulo();
}

bool Vetor3D::operator>(Vetor3D v) {
	return this->modulo() > v.modulo();
}

bool Vetor3D::operator==(Vetor3D v) {
	return doubleEquals(x, v.x) && doubleEquals(y, v.y) && doubleEquals(z, v.z);
}

bool Vetor3D::operator!=(Vetor3D v) {
	return !doubleEquals(x, v.x) || !doubleEquals(y, v.y) || !doubleEquals(y, v.y);
}
