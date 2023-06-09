#include "cFicha_paciente.h"

cFicha_paciente::cFicha_paciente(cOncologo* oncologo, fecha cFecha, list <cTumor*> tumores, string tipo_tratamiento, float radiacion_total) {
	this->oncologo = oncologo;
	this->fecha = fecha;
	this->tumores = tumores;
	this->tipo_tratamiento = tipo_tratamiento;
};

void cFicha_paciente::operator+(cTumor* tumor) {

	tumores.push_back(tumor); //Sobrecarga del operador + para que agregue un tumor al final de la lista

}

void cFicha_paciente::operator-(cTumor* tumor) {

	tumores.remove(tumor); //Sobrecarga del operador - para que elimine un tumor de la lista
};

list<cTumor*> cFicha_paciente::get_tumor() {
	return this->tumores;

};

void cFicha_paciente::set_tipo_tratamiento(string tratamiento) {
	this->tipo_tratamiento = tratamiento;
};

string cFicha_paciente::get_tipo_tratamiento()
{
	return this->tipo_tratamiento;
}

void cFicha_paciente::set_radiacion_total(float radiacion) {

	this->radiacion_total;

};



cFicha_paciente::~cFicha_paciente(){};
