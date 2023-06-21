#pragma once
#include <list>
#include "cEmpleado.h" 



using namespace std;

class cPaciente;
class cFicha_paciente;

class cOncologo : public cEmpleado
{
public:
	cOncologo(string especialidad_cancer, string matricula);


	double calculo_dosis(cFicha_paciente* ficha);
	list <cTumor> diagnostico_tumor(cPaciente* p);
	bool asistencia_sesion();

	bool chequeo_alta();
	void reevaluar_tratamiento();

	~cOncologo();

private:
	string especialidad_cancer;

};

