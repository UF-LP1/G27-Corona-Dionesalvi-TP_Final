#pragma once

#include <list>
#include "cTumor.h"
#include "cFecha.h"

using namespace std;
class cOncologo;
class cPaciente;
class cFicha_paciente

{
public:
	cFicha_paciente(cOncologo* oncologo, list<cFecha*> fechas, list <cTumor*> tumores, list<string*> tipo_tratamiento, float radiacion_total, string DNI, int frecuencia_semanal_tratamiento, float radiacion_por_sesion, string estado_tratamiento, int sesiones_cumplidas);
	cFicha_paciente(cOncologo* oncologo, list<cTumor*> listilla);

	void operator+(cTumor* tumor);
	void operator-(cTumor* tumor);
	list<cTumor*> get_tumor();
	list<string*> get_tipo_tratamiento();
	void set_radiacion_total(float radiacion);
	float get_radiacion_total();
	float get_radiacion_por_sesion();
	void set_radiacion_por_sesion(float radiacion);
	void agregar_tratamiento(string tratamiento);
	void agregar_fecha(cFecha* fecha);
	void set_frecuencia_semanal_tratamiento(int frecuencia);
	int get_frecuencia_semanal_tratamiento();
	list<cFecha*>get_fechas();
	void set_estado_tratamiento(string estado);
	string get_estado_tratamiento();
	cOncologo* get_Oncologo();
	int get_sesiones_cumplidas();
	void set_sesiones_cumplidas(int sesion);
	void recorrotumores();
	~cFicha_paciente();

private:
	cOncologo* oncologo;
	list<cFecha*> fechas;
	list<cTumor*> tumores;
	list<string*> tipo_tratamiento;
	float radiacion_total;
	float radiacion_por_sesion;
	string DNI;
	int frecuencia_semanal_tratamiento;
	string estado_tratamiento;
	int sesiones_cumplidas;
};
