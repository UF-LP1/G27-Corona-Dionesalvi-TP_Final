#include "cPaciente.h"

cPaciente::cPaciente(string nombre, string DNI, string sexo, string tel_contacto, string tipo_sangre, double porcentaje_salud, cFicha_paciente* ficha) {
	this->nombre = nombre;
	this->sexo = sexo;
	this->tel_contacto = tel_contacto;
	this->porcentaje_salud = porcentaje_salud;
	this->ficha = ficha;
};

cFicha_paciente* cPaciente::get_ficha() {
	return this->ficha;
}

const string cPaciente::get_DNI()
{
	return this->DNI;
};

cPaciente::~cPaciente() {
};