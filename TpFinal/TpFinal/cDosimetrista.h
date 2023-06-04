#pragma once
#ifndef _CDOSIMETRISTA_H
#define _CDOSIMETRISTA_H


#include "cEmpleado.h"
#include "eUbicacion.h"
class cDosimetrista : public cEmpleado
{
	cDosimetrista(string nombre, string matricula);

	double calculo_dosis();
	void tipo_terapia_a_recibir();
	~cDosimetrista();

private:
	string nombre;

};

#endif 