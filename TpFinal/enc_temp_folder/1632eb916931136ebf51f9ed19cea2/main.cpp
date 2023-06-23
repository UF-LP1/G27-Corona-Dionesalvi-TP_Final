#include <string>
#include "cCentro_radioterapia.h"
#include "cOncologo.h"
 
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
	cFicha_paciente* ficha = new cFicha_paciente(oncologo,tumores);

	cFicha_paciente* ficha1 = new cFicha_paciente(oncologo,tumores);
	cFicha_paciente* ficha2 = new cFicha_paciente(oncologo2,tumores);
	cFicha_paciente* ficha3 = new cFicha_paciente(oncologo2,tumores);


	cPaciente* paciente1 = new cPaciente();
	cPaciente* paciente2 = new cPaciente("juan", "44637232", "m", "1123435632", "A++", 60,ficha);
	cPaciente* paciente3 = new cPaciente("isa", "43357892", "f", "1177665632", "0", 44,ficha );
	cPaciente* paciente4 = new cPaciente();

	
	/**(ficha) + tumor1;

	*paciente1->get_ficha() + tumor2;
	*paciente2->get_ficha() + tumor3;
	*paciente2->get_ficha() + tumor4; 
	*paciente2->get_ficha() + tumor5;
	*paciente2->get_ficha() + tumor6;
	*paciente3->get_ficha() + tumor7;
	*paciente3->get_ficha() + tumor8;
	*paciente3->get_ficha() + tumor9;
	*paciente4->get_ficha() + tumor10;*/
	
	
	/*paciente1->set_ficha(ficha);
	paciente2->set_ficha(ficha1);
	paciente3->set_ficha(ficha2);
	paciente4->set_ficha(ficha3);*/
	listapacientes.push_back(paciente1);
	listapacientes.push_back(paciente2);
	listapacientes.push_back(paciente3);
	listapacientes.push_back(paciente3);


	cout << "----------------menu---------------" << endl;
	cout << "Ingrese una opcion" << endl;
	cout << "1 - Listar pacientes segun su tratamiento" << endl << "2 - Imprimir listado de pacientes" << endl << "3 - Listar pacientes que esten en su limite de radiacion"<< endl;
	int opcion;
	cin >> opcion;
	
	list<cPaciente*>a;
	string* trat = new string;

switch (opcion)
	{

		case 1:
			cout << "Ingrese el tipo de tratamiento a buscar:" << endl;
			cin >> *trat;

			a = centrito->buscar_paciente_en_tratamiento(listapacientes, cuello, trat);
			
			for (list<cPaciente*>::iterator it_ = a.begin(); it_ != a.end(); it_++) {
				cPaciente* aux = (*it_);
				string imprimir = aux->to_string();
			}
			break;

			break;

		case 2:
			a = centrito->get_pacientes();
			for (list<cPaciente*>::iterator it_ = a.begin(); it_ != a.end(); it_++) {
				cPaciente* aux = (*it_);
				string imprimir = aux->to_string();
			}
			break;

		case 3:
			cout << "Ingrese el tipo de cancer a buscar:" << endl;
			a = centrito->buscar_paciente_limite_radiacion();
			for (list<cPaciente*>::iterator it_ = a.begin(); it_ != a.end(); it_++) {
				cPaciente* aux = (*it_);
				string imprimir = aux->to_string();
			}
			break;

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
