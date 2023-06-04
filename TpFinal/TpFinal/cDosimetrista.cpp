#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(string nombre, string matricula): cEmpleado(matricula) 
{
	this->nombre = nombre;
}

double calculo_dosis();

void tipo_terapia_a_recibir(){
	enum tipo_de_tratamiento {radioterapia_de_hoz,braquiterapia,radioterapia_sistemica};
	cPaciente* p;
	int b = oncologo->diagnostico_tumor(); //Guardo cantidad de tumores que tiene (entre 1 y 7)
	eUbicacion a = p -> get_ficha()->get_tumor()->get_ubicacion(); //Accedemos a la ubicacion del tumor

	for (int i = 0; i < b; i++) {
		switch (a)
		{
			case 1:
				p.get_ficha()->get_tipo_tratamiento()->braquiterapia;
			case 2:
				p.get_ficha()->get_tipo_tratamiento()->radioterapia_de_hoz;
			case 3:
				p.get_ficha()->get_tipo_tratamiento()->braquiterapia;
			case 4:
				p.get_ficha()->get_tipo_tratamiento()->braquiterapia;
			case 5:
				p.get_ficha()->get_tipo_tratamiento()->braquiterapia;
			case 6:
				p.get_ficha()->get_tipo_tratamiento()->braquiterapia;
			case 7:
				p.get_ficha()->get_tipo_tratamiento()->radioterapia_sistemica;
			case 8:
				p.get_ficha()->get_tipo_tratamiento()->radioterapia_sistemica;
			case 9:
				p.get_ficha()->get_tipo_tratamiento()->radioterapia_de_hoz;

		default:
			break;
		}
	}
		

};
