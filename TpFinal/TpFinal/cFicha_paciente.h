#pragma once

#include <list>
#include "cOncologo.h"
#include "cFecha.h"

using namespace std;

class cFicha_paciente
{
public:
	cFicha_paciente(cOncologo *oncologo,  cFecha fecha, list <cTumor*> tumores, list<string*> tipo_tratamiento, float radiacion_total);

	void operator+(cTumor*tumor);
	void operator-(cTumor* tumor);
	list<cTumor*> get_tumor();
	list<string*> get_tipo_tratamiento();
	void set_radiacion_total(float radiacion);
	void agregar_tratamiento(string tratamiento);

	~cFicha_paciente();

private:
	cOncologo *oncologo;
	cFecha fecha;
	list<cTumor*> tumores;
	list<string*> tipo_tratamiento;
	float radiacion_total;

};

