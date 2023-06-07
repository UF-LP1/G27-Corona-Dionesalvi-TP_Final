#include "cCentro_radioterapia.h"

cCentro_radioterapia::cCentro_radioterapia(string direccion, list<cPaciente> *pacientes, list<cEmpleado> *empleados) {

	this->direccion = direccion;
	this->pacientes = pacientes;
	this->empleados = empleados;
}

void contactar_paciente();

void buscar_paciente_limite_radiacion() {


};

void buscar_paciente_en_tratamiento();

void sacar_paciente();

void agregar_paciente();

void cCentro_radioterapia::operator+(cPaciente* paciente) {
	pacientes->push_back(*paciente);

};

void cCentro_radioterapia::operator-(cPaciente* paciente) {
	pacientes->remove(*paciente);
};

cCentro_radioterapia::~cCentro_radioterapia(){};