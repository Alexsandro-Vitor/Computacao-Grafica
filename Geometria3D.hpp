#ifndef GEOMETRIA3D_HPP
#define GEOMETRIA3D_HPP

#include <iostream>

class Vetor3D;

class Ponto3D {
public:
	double x;
	double y;
	double z;
	Ponto3D(double x, double y, double z);
	Ponto3D operator+(Vetor3D v);
	Ponto3D operator-(Vetor3D v);
	Vetor3D operator-(Ponto3D p);
};

class Vetor3D {
public:
	double x;
	double y;
	double z;
	Vetor3D(double x, double y, double z);
	Vetor3D operator+(Vetor3D v);
	Ponto3D operator+(Ponto3D p);
	Vetor3D operator-(Vetor3D v);
	Vetor3D operator-();
	Vetor3D operator*(double i);
	Vetor3D prodVetorial(Vetor3D v);
	double operator*(Vetor3D v);
	Vetor3D operator/(double i);
	Vetor3D operator>>(Vetor3D v);	//Projecao ortogonal de um vetor sobre outro
	double modulo();
	Vetor3D normalizado();
	bool operator<(Vetor3D v);
	bool operator>(Vetor3D v);
	bool operator==(Vetor3D v);
	bool operator!=(Vetor3D v);
};

#endif
