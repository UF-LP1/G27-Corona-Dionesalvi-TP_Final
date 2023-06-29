#pragma once
#ifndef _CCENTRO_RADIOTERAPIA_H
#define _CCENTRO_RADIOTERAPIA_H


#include "cPaciente.h"
#include "cDosimetrista.h"


using namespace std;
class cOncologo;
class cCentro_radioterapia

{
public:

	cCentro_radioterapia(string direccion, list<cPaciente*> pacientes, list <cEmpleado*> empleados, int cantidad_empleados);

	void contactar_paciente(cOncologo* o, cPaciente* z);
	void derivar_paciente(cPaciente* paciente);
	list<cPaciente*> buscar_paciente_limite_radiacion();
	cPaciente* buscar_paciente_en_tratamiento(cPaciente* paciente, eUbicacion ubitumor, string* tipotrat);
	void sacar_paciente(cPaciente* paciente);
	void agregar_paciente(cPaciente* paciente);
	list<cPaciente*> get_pacientes();
	void operator+(cPaciente* paciente);
	void operator-(cPaciente* paciente);
	ostream& operator <<(ostream& out);
	~cCentro_radioterapia();

private:
	string direccion;
	list <cPaciente*> pacientes;
	list <cEmpleado*> empleados;
	static int cantidad_empleados;

};

#endif