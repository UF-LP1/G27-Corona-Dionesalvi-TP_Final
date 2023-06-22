#include "cOncologo.h"
#include "cPaciente.h"
#include "cFicha_paciente.h"

cOncologo::cOncologo(string especialidad_cancer, string DNI, string matricula):cEmpleado(matricula)
{
	this->especialidad_cancer = especialidad_cancer;
	this->DNI_ = DNI;
}

double cOncologo::calculo_dosis(cPaciente * paciente) { //DOSIS POR SESION

	float a = paciente->get_ficha()->get_radiacion_total();
	float b = paciente->get_ficha()->get_radiacion_por_sesion();

	if (a >= 1 && a <= 10) { //si varia entre estos nros es radioterapia de haz externo. dosis por sesion entre 1-2
		if (((int)a % 2) == 0) { //si la dosis total es par
			paciente->get_ficha()->set_radiacion_por_sesion(2.0); //seteo radiacion por sesion en 2
			paciente->get_ficha()->set_frecuencia_semanal_tratamiento(a / b); //la frecuencia con la que va a ir depende de la division a/b
		}
		else {
			paciente->get_ficha()->set_radiacion_por_sesion(1.0); //si es impar, le doy 1 Gy por sesion y lo hago ir esas determinadas veces
			paciente->get_ficha()->set_frecuencia_semanal_tratamiento(a);
		}
	}

	if (a >= 100 && a <= 160) //si varia entre estos nros es braquiterapia. dosis por sesion entre 6-8
	{
		if (((int)a % 6) == 0) {
			paciente->get_ficha()->set_radiacion_por_sesion(6.0);
			paciente->get_ficha()->set_frecuencia_semanal_tratamiento(a / b);
		}
		else if (((int)a % 7) == 0) {
			paciente->get_ficha()->set_radiacion_por_sesion(7.0);
			paciente->get_ficha()->set_frecuencia_semanal_tratamiento(a / b);
		}
		else if (((int)a % 8) == 0) {
			paciente->get_ficha()->set_radiacion_por_sesion(8.0);
			paciente->get_ficha()->set_frecuencia_semanal_tratamiento(a / b);

		}
	}

	if (a >= 20 && a <= 40) //si varia entre estos nros es radioterapia sistemica. dosis por sesion entre 2-4
	{
		if (((int)a % 2) == 0) {
			paciente->get_ficha()->set_radiacion_por_sesion(2.0);
			paciente->get_ficha()->set_frecuencia_semanal_tratamiento(a / b);
		}

	}

	return 0;
}

list<cTumor> cOncologo::diagnostico_tumor(cPaciente* p) { //Se determinan las caracteristicas por cada tumor 

	list<cTumor> tumores;

	srand(time(0)); //semilla respecto a la hora de tu computadora. como la hora se actualiza, el random cambia
	int cantidad_tumores = 0 + rand() % (6) + 1;  //Primero calcula cuantos tumores tiene el paciente
	int tamanio = 0;
	int ubicacion = 0;

	for (int i = 0; i < cantidad_tumores; i++) {

		tamanio = 0 + rand() % (3) + 1; //Calcula tantos tamanios dependiendo la cantidad de tumores
		ubicacion = 0 + rand() % (9) + 1;
		cTumor* aux = new cTumor(pequenio, cabeza, 0);

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

bool cOncologo::asistencia_sesion(cFicha_paciente * f, cFecha* e) {

	list<cFecha*> a = f->get_fechas(); //guardo las fechas que el paciente tiene en su ficha
		cFecha b = cFecha(); //me guardo la fecha actual
	for (list<cFecha*>::iterator it = a.begin(); it != a.end(); it++) {
		cFecha* aux2 = (*it);
		if (aux2 == &b) { //utilizo sobrecarga del == en cFecha
			f->set_sesiones_cumplidas(+1);
			int c = f->get_sesiones_cumplidas();
			float d = f->get_radiacion_por_sesion();
			list<cTumor*> g = f->get_tumor();
			for (list<cTumor*>::iterator it = g.begin(); it != g.end(); it++) {
				cTumor* aux = (*it);
				aux->set_radiacion_acum(c * d);
			}
			return true;
		}
		else 
			return false;
	}
};

bool cOncologo::chequeo_alta(cPaciente * p) {
	
	float a = p->get_ficha()->get_radiacion_total();

	for (list<cTumor*>::iterator it = p->get_ficha()->get_tumor().begin(); it != p->get_ficha()->get_tumor().end(); it++) {
		cTumor* aux = (*it);
		if (a == aux->get_radiacion_acum()) {
			p->get_ficha()->set_estado_tratamiento("dado de alta");

			return true;
		}
		else 
			p->get_ficha()->set_estado_tratamiento("siga con el tratamiento");
		return false;
	}
	};

string cOncologo::get_DNI() {

	return this->DNI_;
}

cOncologo::~cOncologo() {}


