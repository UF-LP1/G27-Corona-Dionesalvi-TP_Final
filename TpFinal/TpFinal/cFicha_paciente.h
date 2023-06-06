#pragma once

#include <list>
#include "cOncologo.h"
using namespace std;

class cFicha_paciente
{
public:
	cFicha_paciente(cOncologo *oncologo, fecha time_t, list <cTumor> tumores, string tipo_tratamiento);

	void operator+(cTumor*tumor);
	list<cTumor> get_tumor();
	string get_tipo_tratamiento();

	~cFicha_paciente();

private:
	cOncologo *oncologo;
	time_t fecha;
	list<cTumor> tumores;
	string tipo_tratamiento;
 
};

