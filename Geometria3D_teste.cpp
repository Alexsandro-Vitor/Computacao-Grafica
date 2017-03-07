#include "Geometria3D.cpp"
#include <iostream>

using namespace std;

int main() {
	Ponto3D pA = Ponto3D(1, 1, 1);
	Ponto3D pB = Ponto3D(2, 3, 4);
	Vetor3D vA = Vetor3D(1, 2, 3);
	Vetor3D vB = Vetor3D(4, 5, 6);
	Vetor3D vC = Vetor3D(0, 4, 6);
	cout << "pA = " << pA << endl;
	cout << "pB = " << pB << endl;
	cout << "vA = " << vA << endl;
	cout << "vB = " << vB << endl;
	cout << "-vB = " << -vB << endl;									//-vB = (-4, -5, -6)
	cout << "vB * 3 = " << vB * 3 << endl;								//vB * 3 = (12, 15, 18)
	cout << "vA.prodVetorial(vB) = " << vA.prodVetorial(vB) << endl;	//vA.prodVetorial(vB) = (-3, 6, -3)
	cout << "vB / 4 = " << vB / 4 << endl;								//vB / 4 = (1, 1.25, 1.5)
	cout << "pA + vA = " << (pA + vA) << endl;							//pA + vA = (2, 3, 4)
	cout << "vA + pA = " << (vA + pA) << endl;							//vA + pA = (2, 3, 4)
	cout << "pA - vA = " << (pA - vA) << endl;							//pA + vA = (0, -1, -2)
	cout << "pA - pB = " << (pA - pB) << endl;							//pA - pB = (-1, -2, -3)
	cout << "vA + vB = " << (vA + vB) << endl;							//vA + vB = (5, 7, 9)
	cout << "vA - vB = " << (vA - vB) << endl;							//vA - vB = (-3, -3, -3)
	cout << "vC = " << vC << endl;
	cout << "vA >> vC (Projecao) = " << (vA >> vC) << endl;				//vA >> vC = (0, 2, 3)
	cout << "vC.modulo() = " << vC.modulo() << endl;					//vC.modulo() = (4*4 + 6*6)^(1/2) = (52)^(1/2) ~= 7,2111
	cout << "vC.normalizado() = " << vC.normalizado() << endl;			//vC.normalizado() = (0, 0.5547, 0,83205)
	cout << "vB < vC = " << ((vB < vC) ? "true" : "false") << endl;		//vB < vC = false
	cout << "vB > vC = " << ((vB > vC) ? "true" : "false") << endl;		//vB > vC = true
	cout << "vA == vA = " << ((vA == vA) ? "true" : "false") << endl;	//vA == vA = true
	cout << "vA != vA = " << ((vA != vA) ? "true" : "false") << endl;	//vA != vA = false
	return 0;
}
