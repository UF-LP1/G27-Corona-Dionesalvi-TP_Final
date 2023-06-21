#include "cOncologo.h"
#include "cPaciente.h"
#include "cFicha_paciente.h"

cOncologo::cOncologo(string especialidad_cancer, string matricula) :cEmpleado(matricula)
{
	this->especialidad_cancer = especialidad_cancer;
}

double cOncologo::calculo_dosis(cFicha_paciente* ficha) { //DOSIS POR SESION

	float a = ficha->get_radiacion_total();
	float b = ficha->get_radiacion_por_sesion();

	if (a >= 1 && a <= 10) { //si varia entre estos nros es radioterapia de haz externo. dosis por sesion entre 1-2
		if (((int)a % 2) == 0) { //si la dosis total es par
			ficha->set_radiacion_por_sesion(2.0); //seteo radiacion por sesion en 2
			ficha->set_frecuencia_semanal_tratamiento(a / b); //la frecuencia con la que va a ir depende de la division a/b
		}
		else {
			ficha->set_radiacion_por_sesion(1.0); //si es impar, le doy 1 Gy por sesion y lo hago ir esas determinadas veces
			ficha->set_frecuencia_semanal_tratamiento(a);
		}
	}

	if (a >= 100 && a <= 160) //si varia entre estos nros es braquiterapia. dosis por sesion entre 6-8
	{



	}

	if (a >= 20 && a <= 40) //si varia entre estos nros es radioterapia sistemica. dosis por sesion entre 2-4
	{

	}
	return 0;
}

list<cTumor> cOncologo::diagnostico_tumor(cPaciente* p) { //Se determinan las caracteristicas por cada tumor 

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
		p->get_ficha()->agregar_fecha(new cFecha()); //actualizamos la fecha de atencion del paciente
		return tumores;
	}
};

bool cOncologo::asistencia_sesion() {

	int i = 0 + rand() % (2) + 1;

	if (i == 1) return true; // si es 1, asistio
	else
		return false;

};

bool cOncologo::chequeo_alta() { return true; };

void cOncologo::reevaluar_tratamiento() {};

cOncologo::~cOncologo() {}


