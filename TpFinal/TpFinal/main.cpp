#include <string>
#include "cCentro_radioterapia.h"
#include "cOncologo.h"

int main()
{
	list<cPaciente*> listapacientess;
	list<cEmpleado*> listaempleados;
	list<cTumor*> tumores;
	list<string*> tratamientos;

	cDosimetrista* dosimetrista = new cDosimetrista("maria", "1414");
	cDosimetrista* dosimetrista2 = new cDosimetrista("carlos", "0032");

	cOncologo* oncologo = new cOncologo("cabeza", "55666732", "4373");
	cOncologo* oncologo2 = new cOncologo("utero", "87987432", "0055");

	cFecha* fecha = new cFecha(2, 4, 2000);
	cFecha* fecha2 = new cFecha();

	cTumor* tumor1 = new cTumor(grande, prostata, 4);
	cTumor* tumor2 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor3 = new cTumor(mediano, prostata, 4);
	cTumor* tumor4 = new cTumor(grande, prostata, 4);
	cTumor* tumor5 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor6 = new cTumor(grande, ojo, 4);


	cFicha_paciente* ficha = new cFicha_paciente(oncologo, tumores);
	cFicha_paciente* ficha1 = new cFicha_paciente(oncologo, tumores);


	string v = "braquiterapia";
	ficha->agregar_tratamiento("braquiterapia");

	*(ficha)+tumor1;
	*(ficha1)+tumor6;

	cPaciente* paciente1 = new cPaciente("Maca", "43353332", "f", "1127984632", "AB", 44, ficha1);
	cPaciente* paciente2 = new cPaciente("Juan", "44637232", "m", "1123435632", "A+", 60, ficha);
	cPaciente* paciente3 = new cPaciente("Isa", "43357892", "f", "1177665632", "B+", 44, ficha1);
	cPaciente* paciente4 = new cPaciente("Fede", "45587232", "m", "1189976632", "B-", 55, ficha1);
	cPaciente* paciente5 = new cPaciente("Cata", "56787252", "f", "1520000362", "0", 44, ficha);
	cPaciente* paciente6 = new cPaciente("Flor", "44661152", "f", "2326 - 22190362", "B+", 44, ficha);
	cPaciente* paciente7 = new cPaciente("Bato", "44725633", "f", "1522190362", "AB", 44, ficha1);
	cPaciente* paciente8 = new cPaciente("Fran", "23925633", "f", "152000362", "0", 44, ficha);

	//se agregan los pacientes a la lista de pacientes totales

	try {
		listapacientess.push_back(paciente1);
		listapacientess.push_back(paciente2);
		listapacientess.push_back(paciente3);
		listapacientess.push_back(paciente4);
		listapacientess.push_back(paciente5);
		listapacientess.push_back(paciente6);
		listapacientess.push_back(paciente7);
		listapacientess.push_back(paciente8);
	}
	catch (exception* e) {
		cout << e->what() << endl;
		delete e;
	}


	cCentro_radioterapia* centrito = new cCentro_radioterapia("Ecuador 1050", listapacientess, listaempleados, 80);

	cout << "----------------menu---------------" << endl;
	cout << "Ingrese una opcion" << endl;
	cout << "1 - Listar pacientes segun su tratamiento" << endl << "2 - Imprimir listado de pacientes" << endl;
	int opcion;
	cin >> opcion;

	list<cPaciente*>a;
	cPaciente* pacientitoaux;

	string* trat = new string;
	list<cPaciente*> superfiltrados;


	switch (opcion)
	{

	case 1:
		cout << "Ingrese el tipo de tratamiento que desea buscar:" << endl;
		cout << "Tratamiento:" << endl;
		cin >> *trat;


		for (list<cPaciente*>::iterator it_ = listapacientess.begin(); it_ != listapacientess.end(); it_++)
		{
			pacientitoaux = (*it_);
			pacientitoaux = centrito->buscar_paciente_en_tratamiento(pacientitoaux, prostata, trat);
			if (pacientitoaux != nullptr)
			{
				superfiltrados.push_back(pacientitoaux);
			}

		}

		for (list<cPaciente*>::iterator it_ = superfiltrados.begin(); it_ != superfiltrados.end(); it_++) {
			cPaciente* aux = (*it_);
			string imprimir = aux->to_string();
			cout << imprimir << endl;
		}
		break;


	case 2:
		a = centrito->get_pacientes();
		for (list<cPaciente*>::iterator it_ = a.begin(); it_ != a.end(); it_++) {
			cPaciente* aux = (*it_);
			string imprimir = aux->to_string();
			cout << imprimir << endl;
		}
		break;

	default:
		break;
	}

	delete centrito;

	delete fecha;
	delete fecha2;

	delete paciente1;
	delete paciente2;
	delete paciente3;
	delete paciente4;
	delete paciente5;
	delete paciente6;
	delete paciente7;
	delete paciente8;

	delete dosimetrista;
	delete dosimetrista2;

	delete ficha;
	delete ficha1;

	delete oncologo;
	delete oncologo2;

	delete tumor1;
	delete tumor2;
	delete tumor3;
	delete tumor4;
	delete tumor5;
	delete tumor6;

	return 0;
}
