#pragma once

#include <list>
#include "cOncologo.h"
#include "cFecha.h"

using namespace std;

class cFicha_paciente
{
public:
	cFicha_paciente(cOncologo *oncologo,  cFecha fecha, list <cTumor*> tumores, list<string*> tipo_tratamiento, float radiacion_total, string DNI, int frecuencia_semanal_tratamiento, float radiacion_por_sesion);

	void operator+(cTumor* tumor);
	void operator-(cTumor* tumor);
	list<cTumor*> get_tumor();
	list<string*> get_tipo_tratamiento();
	void set_radiacion_total(float radiacion);
	float get_radiacion_total();
	float get_radiacion_por_sesion();
	float set_radiacion_por_sesion(float radiacion);
	void agregar_tratamiento(string tratamiento);
	int set_frecuencia_semanal_tratamiento(int frecuencia);
	void get_frecuencia_semanal_tratamiento();


	~cFicha_paciente();

private:
	cOncologo *oncologo;
	cFecha fecha;
	list<cTumor*> tumores;
	list<string*> tipo_tratamiento;
	float radiacion_total;
	float radiacion_por_sesion;
	string DNI;
	int frecuencia_semanal_tratamiento;
	
};

