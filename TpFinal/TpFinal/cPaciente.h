#pragma once

#include <iostream>
#include <sstream>
#include "cFicha_paciente.h"

using namespace std;

class cOncologo;
class cPaciente
{
public:
	cPaciente(string nombre, string DNI, string sexo, string tel_contacto, string tipo_sangre, float porcentaje_salud, cFicha_paciente* fichita);
	cPaciente();
	cFicha_paciente* get_ficha();
	const string get_DNI();
	void set_ficha(cFicha_paciente* ficha);
	bool operator==(string DNI_oncologo);
	string to_string();
	~cPaciente();

private:
	string nombre;
	const string DNI;
	string sexo;
	string tel_contacto;
	const string tipo_sangre;
	float porcentaje_salud;
	cFicha_paciente* ficha;
	friend class cOncologo;
};


