#ifndef CORRGB_HPP
#define CORRGB_HPP

#include <string>

class CorRGB;

class MonoCor {
	friend class CorRGB;
	unsigned char x;
public:
	MonoCor(unsigned char x);
	unsigned char getX() const;
	unsigned char operator=(const unsigned int& I);
	unsigned int operator+(unsigned int i);
	unsigned int operator-(unsigned int i);
	unsigned int operator*(double i);
	MonoCor operator+(MonoCor i);
	MonoCor operator-(MonoCor i);
};

class CorRGB {
public:
	MonoCor r, g, b;
	CorRGB(unsigned char r, unsigned char g, unsigned char b);
	CorRGB(MonoCor r, MonoCor g, MonoCor b);
	CorRGB(std::string nome);
	CorRGB operator+(CorRGB cor);
	CorRGB operator-(CorRGB cor);
	CorRGB operator*(double i);
};

#endif
