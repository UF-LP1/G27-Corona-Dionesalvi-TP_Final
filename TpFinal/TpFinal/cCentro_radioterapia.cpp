#include "cCentro_radioterapia.h"

cCentro_radioterapia::cCentro_radioterapia(string direccion, list<cPaciente> pacientes, list<cEmpleado> empleados) {

	this->direccion = direccion;
	this->pacientes = &pacientes;
	this->empleados = &empleados;
}

void contactar_paciente();

void buscar_paciente_limite_radiacion();

void buscar_paciente_en_tratamiento();

