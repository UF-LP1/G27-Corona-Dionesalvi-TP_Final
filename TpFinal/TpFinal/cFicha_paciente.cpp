#include "cFicha_paciente.h"

cFicha_paciente::cFicha_paciente(cOncologo* oncologo, fecha time_t, list <cTumor> tumores, string tipo_tratamiento) {
	this->oncologo = oncologo;
	this->tumores = tumores;

};

void cFicha_paciente::operator+(cTumor* tumor) {

	tumores.push_back(*tumor);

}


list<cTumor> cFicha_paciente::get_tumor() {
	return this->tumores;
};
string cFicha_paciente::get_tipo_tratamiento() {
	return this->tipo_tratamiento;
};

cFicha_paciente::~cFicha_paciente(){};
