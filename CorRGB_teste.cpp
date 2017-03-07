#include "CorRGB.cpp"
#include <iostream>

using namespace std;

int main() {
	CorRGB corA = CorRGB("branco");
	cout << corA << endl;	//(255, 255, 255)
	CorRGB corB = CorRGB("amarelo");
	cout << corB << endl;	//(255, 255, 0)
	corA.r = -20;
	cout << (corA - corB)*0.5; << endl;	//(0, 0, 127)
	return 0;
}
