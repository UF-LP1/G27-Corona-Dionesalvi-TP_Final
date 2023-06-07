#include "cOncologo.h"



cOncologo::cOncologo(string especialidad_cancer,string matricula):cEmpleado(matricula)
{
	this->especialidad_cancer = especialidad_cancer;
}

cOncologo::~cOncologo() {}

void cOncologo::frecuencia_semanal()
{
}

double cOncologo::calculo_dosis() {}

list<cTumor> diagnostico_tumor(){

	cFicha_paciente *ficha;
	cPaciente* p = new cPaciente("Martin", "32134575", "femenino", "1168756578", "A++", 80, ficha);
	list<cTumor> tumores;

	
	srand(time(0));
	int cantidad_tumores = 0 + rand() % (6) + 1;  //Primero calcula cuantos tumores tiene el paciente
	int tamanio = 0;
	int ubicacion = 0;

	for (int i = 0; i < cantidad_tumores; i++) {

		tamanio = 0 + rand() % (3) + 1; //Calcula tantos tamanios dependiendo la cantidad de tumores
		ubicacion = 0 + rand() % (9) + 1;
		cTumor* aux = new cTumor(pequenio, cabeza, 0); //HAY QUE HACER DELETE?



		switch (tamanio)
		{
		case 1:
			aux->set_tamanio(pequenio);
			break;
		case 2:
			aux->set_tamanio(mediano);
			break;
		case 3:
			aux->set_tamanio(grande);
			break;
		default:
			break;
		}

		switch (ubicacion)
		{
		case 1:
			aux->set_ubicacion(cabeza);
			break;
		case 2:
			aux->set_ubicacion(pulmon);
			break;
		case 3:
			aux->set_ubicacion(cuello);
			break;
		case 4:
			aux->set_ubicacion(mama);
			break;
		case 5:
			aux->set_ubicacion(utero);
			break;
		case 6:
			aux->set_ubicacion(ojo);
			break;
		case 7:
			aux->set_ubicacion(tiroides);
			break;
		case 8:
			aux->set_ubicacion(prostata);
			break;
		case 9:
			aux->set_ubicacion(intestino);
			break;

		default:
			break;
		}

		*p->get_ficha() + aux;  //Se guarda el tumor creado con rand en la lista de tumores que tiene c/ paciente en su ficha

		return tumores;
	};



bool asistencia_sesion() {

	int i = 0 + rand() % (2) + 1;

	if (i == 1) return true; // si es 1, asistio
	else
		return false;

};

void actualizar_ficha(cFicha_paciente *f);

bool chequeo_alta();

void reevaluar_tratamiento();


