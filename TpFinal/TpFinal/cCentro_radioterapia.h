#pragma once
#ifndef _CCENTRO_RADIOTERAPIA_H
#define _CCENTRO_RADIOTERAPIA_H

#include <list>
//#include <string>

#include "cPaciente.h"
#include "cEmpleado.h"


using namespace std;

class cCentro_radioterapia

{
public:
	
	cCentro_radioterapia(string direccion, list<cPaciente> *pacientes,list <cEmpleado> *empleados);
	
	void contactar_paciente();
	void buscar_paciente_limite_radiacion();
	void buscar_paciente_en_tratamiento();
	void sacar_paciente();
	void agregar_paciente();

	~cCentro_radioterapia();

private: 
	string direccion;
	list <cPaciente> *pacientes;
	list <cEmpleado> *empleados;

};

#endif