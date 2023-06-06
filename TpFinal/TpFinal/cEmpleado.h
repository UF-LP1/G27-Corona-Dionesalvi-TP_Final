#pragma once
#include <string> //preguntar 
#include <ctime> 
#include "cPaciente.h"


using namespace std;

class cEmpleado
{

public:
	cEmpleado(string matricula);

	virtual double calcular_dosis()=0; 

	~cEmpleado();

private:

	const string matricula;
};

