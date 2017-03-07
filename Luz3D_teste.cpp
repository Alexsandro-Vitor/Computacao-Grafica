#include "Luz3D.cpp"

using namespace std;

int main() {
	Luz3D luz = Luz3D();
	Camera3D camera = Camera3D(Ponto3D(0, 0, 0), Vetor3D(0, 1, 0), Vetor3D(1, 0, 0), 1, 1);
	cout << "Posicao: " << luz.pos << endl;
	cout << "kAmbiente: " << luz.kAmbiente << endl;
	cout << "luzAmbiente: " << luz.luzAmbiente << endl;
	cout << "kDifuso: " << luz.kDifuso << endl;
	luz.kEspecular = 1;
	cout << "kEspecular: " << luz.kEspecular << endl;
	luz.corLuz = CorRGB(255, 255, 255);
	cout << "corLuz: " << luz.corLuz << endl;
	luz.n = 10;
	cout << "n: " << luz.n << endl;
	cout << "iluminar(Ponto3D(1, 0, 0), Vetor3D(-1, 0, 0), Camera3D(Ponto3D(0, 0, 0), Vetor3D(0, 1, 0), Vetor3D(1, 0, 0), 1, 1)): "
	<< luz.iluminar(Ponto3D(1, 0, 0), Vetor3D(-1, 0, 0), camera) << endl;
	return 0;
}
