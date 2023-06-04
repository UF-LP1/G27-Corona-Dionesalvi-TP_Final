#pragma once
#include <string> //preguntar 
#include <ctime> 

class cPaciente; 
class cFicha_paciente;
using namespace std;

class cEmpleado
{
	cEmpleado(string matricula);

	virtual double calcular_dosis()=0; 

	~cEmpleado();

protected:

	const string matricula;
};

