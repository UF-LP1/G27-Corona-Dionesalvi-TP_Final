#pragma once

#include <iostream>
using namespace std;
class cFicha_paciente;

class cPaciente
{
	cPaciente(string nombre, string DNI, string sexo, string tel_contacto, string tipo_sangre, double porcentaje_salud, cFicha_paciente* ficha);

	void tratamiento();

	cFicha_paciente* get_ficha();

	~cPaciente();

private:
	string nombre;
	const string DNI;
	string sexo; 
	string tel_contacto;
	const string tipo_sangre;
	double porcentaje_salud;
	cFicha_paciente *ficha;
};

