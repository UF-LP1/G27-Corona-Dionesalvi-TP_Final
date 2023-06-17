#pragma once
#include <list>
#include "cEmpleado.h" 
#include "cTumor.h"


using namespace std;

class cOncologo : public cEmpleado
{
public:
	cOncologo(string especialidad_cancer, string matricula);

	void frecuencia_semanal();
	double calculo_dosis(cFicha_paciente * ficha);
	list <cTumor> diagnostico_tumor(cPaciente *p);
	bool asistencia_sesion();
	void actualizar_ficha(cFicha_paciente*f);
	bool chequeo_alta();
	void reevaluar_tratamiento();

	~cOncologo();

private:
	string especialidad_cancer;

};

