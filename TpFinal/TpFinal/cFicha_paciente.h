#pragma once

#include <list>
#include "cOncologo.h"
#include "cFecha.h"

using namespace std;

class cFicha_paciente
{
public:
	cFicha_paciente(cOncologo *oncologo, fecha cFecha, list <cTumor> tumores, string tipo_tratamiento);

	void operator+(cTumor*tumor);
	void operator-(cTumor* tumor);
	list<cTumor> get_tumor();
	void set_tipo_tratamiento(string tratamiento);
	string get_tipo_tratamiento();

	~cFicha_paciente();

private:
	cOncologo *oncologo;
	cFecha fecha;
	list<cTumor> tumores;
	string tipo_tratamiento;
 
};

