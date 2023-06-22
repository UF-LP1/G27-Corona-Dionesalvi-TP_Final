#include <string>
#include "cCentro_radioterapia.h"
#include "cOncologo.h"
using namespace std;

int main()
{
	list<cPaciente*> listapacientes;
	list<cEmpleado*> listaempleados;
	list<cTumor*> tumores;
	list<string*> tratamientos;
	
	cDosimetrista* dosimetrista = new cDosimetrista("maria", "1414");
	cDosimetrista* dosimetrista2 = new cDosimetrista("carlos", "0032");
	cOncologo* oncologo = new cOncologo("cabeza","55666732", "4373");
	cOncologo* oncologo2 = new cOncologo("utero","87987432", "0055");

	cFecha* fecha = new cFecha(2, 4, 2000);
	cFecha* fecha2 = new cFecha();

	cCentro_radioterapia* centrito = new cCentro_radioterapia("Ecuador 1050", listapacientes, listaempleados, 80);
	
	cTumor* tumor1 = new cTumor(grande, prostata, 4);
	cTumor* tumor2 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor3 = new cTumor(mediano, prostata, 4);
	cTumor* tumor4 = new cTumor(grande, prostata, 4);
	cTumor* tumor5 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor6 = new cTumor(grande, prostata, 4);
	cTumor* tumor7 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor8 = new cTumor(grande, prostata, 4);
	cTumor* tumor9 = new cTumor(mediano, prostata, 4);
	cTumor* tumor10 = new cTumor(pequenio, prostata, 4);


	cPaciente* paciente1 = new cPaciente();
	cPaciente* paciente2 = new cPaciente("juan", "44637232", "m", "1123435632", "A++", 60);
	cPaciente* paciente3 = new cPaciente("isa", "43357892", "f", "1177665632", "0", 44);
	cPaciente* paciente4 = new cPaciente();

	
	cFicha_paciente* ficha = new cFicha_paciente(paciente1, oncologo);
	cFicha_paciente* ficha1 = new cFicha_paciente(paciente2, oncologo);
	cFicha_paciente* ficha2 = new cFicha_paciente(paciente3, oncologo2);
	cFicha_paciente* ficha3 = new cFicha_paciente(paciente4, oncologo2);

	paciente1->set_ficha(ficha);
	paciente2->set_ficha(ficha1);
	paciente3->set_ficha(ficha2);
	paciente4->set_ficha(ficha3);

	cout <<"----------------menu---------------" << endl;
	cout << "Ingrese una opcion" << endl;
	cout << "1 - Listar por tratamiento" << endl << "2 - Imprimir listado de pacientes" << endl << "3 - Listar por cancer"<< endl;
	int opcion;
	cin >> opcion;
	
switch (opcion)
	{
	default:
		break;
	}









	delete centrito;

	delete tumor1;
	delete tumor2;
	delete tumor3;
	delete tumor4;
	delete tumor5;
	delete tumor6;
	delete tumor7;
	delete tumor8;
	delete tumor9;
	delete tumor10;
	
	delete dosimetrista;
	delete dosimetrista2;

	delete oncologo;
	delete oncologo2;

	delete fecha;
	delete fecha2;

	delete ficha1;
	delete ficha2;
	delete ficha3;

	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete paciente4;


	return 0;
}
