#include "cOncologo.h"

cOncologo::cOncologo(string especialidad_cancer)
{
	this->especialidad_cancer = especialidad_cancer;
}

double calculo_dosis();

int diagnostico_tumor(){

	cFicha_paciente* ficha;
	cPaciente* p = new cPaciente ("isabella","30997654","fem","1122335679","AB","60",ficha);
	list <cTumor> tumores;

	
	srand(time(0));
	int cantidad_tumores = 0 + rand() % (7) + 1;  //Primero calcula cuantos tumores tiene el paciente
	int tamanio = 0;
	int ubicacion = 0;

	for (int i = 0; i < cantidad_tumores; i++) {
		tamanio = 0 + rand() % (3) + 1; //Calcula tantos tamanios dependiendo la cantidad de tumores
		ubicacion = 0 + rand() % (9) + 1;

		switch (tamanio)
		{
		case 1:
			get_ficha()->get_tumor()->get_tamanio()->pequenio;
		case 2:
			p.get_ficha()->get_tumor()->get_tamanio()->mediano;
		case 3:
			p->get_ficha()->get_tumor()->get_tamanio()->grande;

		default:
			break;
		}

		switch (ubicacion)
		{
		case 1:
			p.get_ficha()->get_tumor()->get_ubicacion()->cabeza;
		case 2:
			p.get_ficha()->get_tumor()->get_ubicacion()->pulmon;
		case 3:
			p.get_ficha()->get_tumor()->get_ubicacion()->cuello;
		case 4:
			p.get_ficha()->get_tumor()->get_ubicacion()->mama;
		case 5:
			p.get_ficha()->get_tumor()->get_ubicacion()->utero;
		case 6:
			p.get_ficha()->get_tumor()->get_ubicacion()->ojo;
		case 7:
			p.get_ficha()->get_tumor()->get_ubicacion()->tiroides;
		case 8:
			p.get_ficha()->get_tumor()->get_ubicacion()->prostata;
		case 9:
			p.get_ficha()->get_tumor()->get_ubicacion()->intestino;

		default:
			break;
		}

		return cantidad_tumores;
	}

		

void frecuencia_semanal();

bool asistencia_sesion() {

	int i = 0 + rand() % (2) + 1;

	if (i == 1 ) return true; // si es 1, asistio
	else
		return false;

};

void actualizar_ficha(cFicha_paciente *f);

bool chequeo_alta();

void reevaluar_tratamiento();

cOncologo::~cOncologo(){}; 
