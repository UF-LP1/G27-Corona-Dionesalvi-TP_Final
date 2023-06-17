#pragma once
#ifndef _CCENTRO_RADIOTERAPIA_H
#define _CCENTRO_RADIOTERAPIA_H

#include <list>
#include "cPaciente.h"
#include "cDosimetrista.h"


using namespace std;

class cCentro_radioterapia

{
public:
	
	cCentro_radioterapia(string direccion, list<cPaciente*> pacientes,list <cEmpleado*> empleados);
	
	void contactar_paciente();
	void derivar_paciente(cPaciente* paciente);
	void buscar_paciente_limite_radiacion();
	void buscar_paciente_en_tratamiento();
	void sacar_paciente(cPaciente *paciente);
	void agregar_paciente(cPaciente* paciente);
	void operator+(cPaciente* paciente);
	void operator-(cPaciente* paciente);
	~cCentro_radioterapia();

private: 
	string direccion;
	list <cPaciente*> pacientes;
	list <cEmpleado*> empleados;

};

#endif