#pragma once
#ifndef _CDOSIMETRISTA_H
#define _CDOSIMETRISTA_H


#include "cEmpleado.h"
#include "eUbicacion.h"

class cDosimetrista : public cEmpleado
{
public:
	cDosimetrista(string nombre, string matricula);

	double calculo_dosis(cPaciente* paciente);
	void tipo_terapia_a_recibir(cPaciente *paciente);
	~cDosimetrista();

private:
	string nombre;

};

#endif 