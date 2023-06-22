#pragma once
#ifndef _CCENTRO_RADIOTERAPIA_H
#define _CCENTRO_RADIOTERAPIA_H

#include <list>
#include "cPaciente.h"
#include "cDosimetrista.h"


using namespace std;
class cOncologo;
class cCentro_radioterapia

{
public:

	cCentro_radioterapia(string direccion, list<cPaciente*> pacientes, list <cEmpleado*> empleados /*,static int cantidad_empleados*/);

	void contactar_paciente();
	void derivar_paciente(cPaciente* paciente);
	list<cPaciente*> buscar_paciente_limite_radiacion(list<cPaciente*> paciente);
	list<cPaciente*> buscar_paciente_en_tratamiento(list<cPaciente*> paciente, eUbicacion ubitumor,string tipotrat);
	void sacar_paciente(cPaciente* paciente);
	void agregar_paciente(cPaciente* paciente);
	void operator+(cPaciente* paciente);
	void operator-(cPaciente* paciente);
	~cCentro_radioterapia();

private:
	string direccion;
	list <cPaciente*> pacientes;
	list <cEmpleado*> empleados;
	//static int cantidad_empleados;

};

#endif