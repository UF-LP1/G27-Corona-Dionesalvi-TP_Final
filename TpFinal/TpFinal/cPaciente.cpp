#include "cPaciente.h"
#include "cOncologo.h"

cPaciente::cPaciente(string nombre, string DNI, string sexo, string tel_contacto, string tipo_sangre, float porcentaje_salud, cFicha_paciente* fichita) {
	this->nombre = nombre;
	this->sexo = sexo;
	this->tel_contacto = tel_contacto;
	this->porcentaje_salud = porcentaje_salud;
	this->ficha = fichita;
	
};

cPaciente::cPaciente() {
	this->nombre = "catalina";
	this->sexo = "femenino";
	this->tel_contacto = "1123456543";
	this->porcentaje_salud = 0.6;

};

cFicha_paciente* cPaciente::get_ficha() {
	return this->ficha;
}

const string cPaciente::get_DNI()
{
	return this->DNI;
};

void cPaciente::set_ficha(cFicha_paciente* ficha)
{
	this->ficha = ficha;
}


bool cPaciente:: operator==(string DNI_oncologo) {

	bool flag2 = false;
	string a = this->get_ficha()->get_Oncologo()->get_DNI();
	if (a == DNI_oncologo)
		flag2 = true;
	else
		flag2 = false;

	return flag2;

}


cPaciente::~cPaciente() {
}

string cPaciente::to_string()
{
	stringstream  ss;
	ss << "Nombre: " << this->nombre << "DNI: " << this->DNI << "Contacto: " << this->tel_contacto << "Tipo de sangre: " << this->tipo_sangre;
	
	return ss.str();
}
