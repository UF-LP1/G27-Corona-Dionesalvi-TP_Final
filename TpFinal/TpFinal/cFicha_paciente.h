#pragma once

#include <list>

class cOncologo;
class cTumor;
using namespace std;

class cFicha_paciente
{
	cFicha_paciente(cOncologo *oncologo, fecha time_t, list <cTumor> tumor, string tipo_tratamiento);

	list<cTumor> get_tumor();
	string get_tipo_tratamiento();

	~cFicha_paciente();

private:
	cOncologo &oncologo;
	time_t fecha;
	list<cTumor> tumor;
	string tipo_tratamiento;
 
};

