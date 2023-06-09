#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(string nombre, string matricula): cEmpleado(matricula) 
{
	this->nombre = nombre;
}

double calculo_dosis();

void tipo_terapia_a_recibir(cPaciente *paciente){
	

	list<cTumor> b = paciente->get_ficha()->get_tumor(); //Guardo la lista de tumores q tiene

	for (list<cTumor>::iterator it_ = b.begin(); it_ != b.end(); it_++) { //va a ir hasta el final de la lista de tumores que tenga
		cTumor aux = *it_; //me creo un auxiliar con el tumor que corresponde segun el for
		eUbicacion a = aux.get_ubicacion();
		switch (a)
		{
			case 1:
				paciente->get_ficha()->set_tipo_tratamiento("braquiterapia");
				break;
			case 2:
				paciente->get_ficha()->set_tipo_tratamiento("radioterapia_de_hoz");
				break;
			case 3:
				paciente->get_ficha()->set_tipo_tratamiento("braquiterapia");
				break;
			case 4:
				paciente->get_ficha()->set_tipo_tratamiento("braquiterapia");
				break;
			case 5:
				paciente->get_ficha()->set_tipo_tratamiento("braquiterapia");
				break;
			case 6:
				paciente->get_ficha()->set_tipo_tratamiento("braquiterapia");
				break;
			case 7:
				paciente->get_ficha()->set_tipo_tratamiento("radioterapia_sistemica");
				break;
			case 8:
				paciente->get_ficha()->set_tipo_tratamiento("radioterapia_sistemica");
				break;
			case 9:
				paciente->get_ficha()->set_tipo_tratamiento("radioterapia_de_hoz");
				break;

		default:
			break;
		}
	}
};
