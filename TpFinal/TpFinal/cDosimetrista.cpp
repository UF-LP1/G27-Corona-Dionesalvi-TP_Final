#include "cDosimetrista.h"
#include "eUbicacion.h"

cDosimetrista::cDosimetrista(string nombre, string matricula) : cEmpleado(matricula)
{
	this->nombre = nombre;
}

double calculo_dosis(cPaciente* paciente) { //DOSIS TOTAL
	srand(time(0));
	list<string*> a = paciente->get_ficha()->get_tipo_tratamiento();
	paciente->get_ficha()->agregar_fecha(new cFecha());//actualizamos la fecha de atencion
	for (list<string*>::iterator it = a.begin(); it != a.end(); it++) {

		string* aux = (*it);

		do {
			if (*aux == "radioterapia de haz externo") {
				float a = 0 + rand() % (10) + 1;
				paciente->get_ficha()->set_radiacion_total(a);
			}
			else if (*aux == "braquiterapia") {
				float b = 100 + rand() % (161 - 100) + 1;
				paciente->get_ficha()->set_radiacion_total(b);
			}
			else if (*aux == "radioterapia sistemica") {
				float c = 20 + rand() % (41 - 20) + 1; //calculo dosis total entre 20 - 40 Gy
				paciente->get_ficha()->set_radiacion_total(c);
			}
		} while (a.size() == 1); //mientras que reciba un solo tratamiento

		if (a.size() == 3) { //si tiene 3 tratamientos recibe la dosis de braquiterapia por ser la mayor
			float d = 100 + rand() % (161 - 100) + 1;
			paciente->get_ficha()->set_radiacion_total(d);
		}
		else if (a.size() == 2) //comparo todas las alternativas
		{
			if ((*aux == "radioterapia de haz externo" && *aux == "braquiterapia") || (*aux == "radioterapia sistemica" && *aux == "braquiterapia")) {
				float e = 100 + rand() % (161 - 100) + 1;
				paciente->get_ficha()->set_radiacion_total(e);
			}
			else if (*aux == "radioterapia de haz externo" && *aux == "radioterapia sistemica") {
				float f = 20 + rand() % (41 - 20) + 1; //calculo dosis total entre 20 - 40 Gy
				paciente->get_ficha()->set_radiacion_total(f);
			}
		}
	}
	return 0;
};

void cDosimetrista:: tipo_terapia_a_recibir(cPaciente* paciente) {

	list<cTumor*> b = paciente->get_ficha()->get_tumor(); //Guardo la lista de tumores q tiene

	for (list<cTumor*>::iterator it_ = b.begin(); it_ != b.end(); it_++) { //va a ir hasta el final de la lista de tumores que tenga
		cTumor* aux = *it_; //me creo un auxiliar con el tumor que corresponde segun el for
		eUbicacion a = aux->get_ubicacion();
		switch (a)
		{
		case 1:
			paciente->get_ficha()->agregar_tratamiento("braquiterapia");
			break;
		case 2:
			paciente->get_ficha()->agregar_tratamiento("radioterapia_de_hoz");
			break;
		case 3:
			paciente->get_ficha()->agregar_tratamiento("braquiterapia");
			break;
		case 4:
			paciente->get_ficha()->agregar_tratamiento("braquiterapia");
			break;
		case 5:
			paciente->get_ficha()->agregar_tratamiento("braquiterapia");
			break;
		case 6:
			paciente->get_ficha()->agregar_tratamiento("braquiterapia");
			break;
		case 7:
			paciente->get_ficha()->agregar_tratamiento("radioterapia_sistemica");
			break;
		case 8:
			paciente->get_ficha()->agregar_tratamiento("radioterapia_sistemica");
			break;
		case 9:
			paciente->get_ficha()->agregar_tratamiento("radioterapia_de_hoz");
			break;

		default:
			break;
		}
	}
};

cDosimetrista::~cDosimetrista()
{
}
