#pragma once
#include "cEmpleado.h"

class cTumor;
using namespace std;

class cOncologo : public cEmpleado
{
	cOncologo(string especialidad_cancer);

	double calculo_dosis();
	int diagnostico_tumor();
	void frecuencia_semanal();
	bool asistencia_sesion();
	void actualizar_ficha(cFicha_paciente*f);
	bool chequeo_alta();
	void reevaluar_tratamiento();

	~cOncologo();

private:
	string especialidad_cancer;

};

