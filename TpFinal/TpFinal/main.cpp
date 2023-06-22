#include <string>
#include "cCentro_radioterapia.h"
#include "cOncologo.h"
using namespace std;

int main()
{
	list<cPaciente*> listapacientes;
	list<cEmpleado*> listaempleados;
	list<cTumor*> tumores;
	list<string*> tratamientos;
	
	cOncologo* oncologo = new cOncologo("cabeza","4373");
	cFecha* fecha = new cFecha(2, 4, 2000);

	cFicha_paciente* ficha = new cFicha_paciente(oncologo, fecha, tumores, tratamientos, 20, "4367587654", 3, 2.0, "tratamiento vigente");
	cCentro_radioterapia* centrito = new cCentro_radioterapia("Ecuador 1050", listapacientes, listaempleados, 80);
	
	cTumor* tumor1 = new cTumor(grande, prostata, 4);
	cTumor* tumor2 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor3 = new cTumor(mediano, prostata, 4);
	cTumor* tumor4 = new cTumor(grande, prostata, 4);
	cTumor* tumor5 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor6 = new cTumor(grande, prostata, 4);
	cTumor* tumor7 = new cTumor(pequenio, prostata, 4);
	cTumor* tumor8 = new cTumor(grande, prostata, 4);
	cTumor* tumor9 = new cTumor(mediano, prostata, 4);
	cTumor* tumor10 = new cTumor(pequenio, prostata, 4);

	cPaciente* paciente = new cPaciente("juan", "44637232", "f", "1123435632", "A++", 60, ficha);
	
	delete centrito;
	delete tumor1;
	delete tumor2;
	delete tumor3;
	delete tumor4;
	delete tumor5;
	delete tumor6;
	delete tumor7;
	delete tumor8;
	delete tumor9;
	delete tumor10;
	
	
	
	
	

}
