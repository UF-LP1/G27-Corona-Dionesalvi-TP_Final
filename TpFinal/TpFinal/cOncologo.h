#pragma once
#include "cEmpleado.h"

class cOncologo : public cEmpleado
{
	cOncologo(string especialidad_cancer);

	double calculo_dosis();
	void diagnostico_tumor(cPaciente*p);
	void frecuencia_semanal();
	bool asistencia_sesion();
	void actualizar_ficha(cFicha_paciente*f);
	bool chequeo_alta();
	void reevaluar_tratamiento();

	~cOncologo();

private:
	string especialidad_cancer;

};

