#include "cFicha_paciente.h"

cFicha_paciente::cFicha_paciente(cOncologo* oncologo, fecha time_t, list <cTumor> tumor, string tipo_tratamiento) {
	//this->oncologo = oncologo;
	this->tumor = tumor;

};

list<cTumor> cFicha_paciente::get_tumor() {
	return this->tumor;
};
string cFicha_paciente::get_tipo_tratamiento() {
	return this->tipo_tratamiento;
};

cFicha_paciente::~cFicha_paciente(){};
