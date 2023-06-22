#pragma once

#include <iostream>
#include "cFicha_paciente.h"
using namespace std;


class cPaciente
{
public:
	cPaciente(string nombre, string DNI, string sexo, string tel_contacto, string tipo_sangre, double porcentaje_salud, cFicha_paciente* ficha);

	void tratamiento();

	cFicha_paciente* get_ficha();
	const string get_DNI();


	~cPaciente();

private:
	string nombre;
	const string DNI;
	string sexo;
	string tel_contacto;
	const string tipo_sangre;
	double porcentaje_salud;
	cFicha_paciente* ficha;
};

