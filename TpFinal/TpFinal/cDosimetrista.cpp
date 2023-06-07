#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(string nombre, string matricula): cEmpleado(matricula) 
{
	this->nombre = nombre;
}

double calculo_dosis();

void tipo_terapia_a_recibir(){
	enum tipo_de_tratamiento {radioterapia_de_hoz,braquiterapia,radioterapia_sistemica};

	cFicha_paciente* ficha;
	cPaciente* p = new cPaciente("Martin", "32134575", "femenino", "1168756578", "A++", 80, ficha);
	cOncologo* oncologo = new cOncologo("cabeza", "43134812");
	list<cTumor> b = oncologo->diagnostico_tumor(); //Guardo la lista de tumores q tiene
	eUbicacion *a =  p->get_ficha()->get_tumor()->get_ubicacion(); //Accedemos a la ubicacion del tumor

	for (list<cTumor>::iterator it_ = b->diagnostico_tumor().begin(); it_ != b->diagnostico_tumor().end(); it_++) { //va a ir hasta el final de la lista de tumores que tenga
		switch (a)
		{
			case 1:
				p.get_ficha()->set_tipo_tratamiento(braquiterapia);
				break;
			case 2:
				p.get_ficha()->set_tipo_tratamiento(radioterapia_de_hoz);
				break;
			case 3:
				p.get_ficha()->set_tipo_tratamiento(braquiterapia);
				break;
			case 4:
				p.get_ficha()->set_tipo_tratamiento(braquiterapia);
				break;
			case 5:
				p.get_ficha()->set_tipo_tratamiento(braquiterapia);
				break;
			case 6:
				p.get_ficha()->set_tipo_tratamiento(braquiterapia);
				break;
			case 7:
				p.get_ficha()->set_tipo_tratamiento(radioterapia_sistemica);
				break;
			case 8:
				p.get_ficha()->set_tipo_tratamiento(radioterapia_sistemica);
				break;
			case 9:
				p.get_ficha()->set_tipo_tratamiento(radioterapia_de_hoz);
				break;

		default:
			break;
		}
	}
		

};
