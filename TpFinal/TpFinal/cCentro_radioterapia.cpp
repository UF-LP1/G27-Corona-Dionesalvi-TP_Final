#include "cCentro_radioterapia.h"
#include "cOncologo.h"

int cCentro_radioterapia::  cantidad_empleados = 0;

cCentro_radioterapia::cCentro_radioterapia(string direccion, list<cPaciente*> pacientes, list<cEmpleado*> empleados, int cantidad_empleados) {

	this->direccion = direccion;
	this->pacientes = pacientes;
	this->empleados = empleados;
	this->cantidad_empleados++;
}

void contactar_paciente();

void cCentro_radioterapia::derivar_paciente(cPaciente* paciente) {
	cFicha_paciente* p = paciente->get_ficha();
	if (p == NULL) { //si su ficha esta vacia significa que ningun oncologo lo atendio, por eso lo derivo
		for (list<cEmpleado*>::iterator it_ = empleados.begin(); it_ != empleados.end(); it_++) {  //bucle hasta el final de la lista 
			cEmpleado* aux2 = (*it_); //accedo a un elemento tipo cEmpleado, y con el & accedo a la direc de memoria
			cOncologo* aux = dynamic_cast<cOncologo*>(aux2); //si es empleado, chequeo que sea oncologo
			if (aux != nullptr) //chequeo que sea distinto de nullptr pq dynamic cast si no encuentra un empleado oncologo me devuelve un ptr nulo
				aux->diagnostico_tumor(paciente);
		}
	}
	else
		for (list<cEmpleado*>::iterator it_ = empleados.begin(); it_ != empleados.end(); it_++) {
			cEmpleado* aux2 = (*it_);
			cDosimetrista* aux = dynamic_cast<cDosimetrista*>(aux2);
			if (aux != nullptr)
				aux->tipo_terapia_a_recibir(paciente);
		}
}

list<cPaciente*>buscar_paciente_limite_radiacion(list<cPaciente*> paciente) { //metodo friend, no requiere operador de ambito
	list<cPaciente*> pacientes_radiacion;
	bool flag = false;
	for (list<cPaciente*>::iterator it_ = paciente.begin(); it_ != paciente.end(); it_++) {
		cPaciente* aux2 = (*it_);
		for (list<cTumor*>::iterator ti_ = aux2->get_ficha()->get_tumor().begin(); ti_ != aux2->get_ficha()->get_tumor().end(); ti_++) {
			cTumor* aux3 = (*ti_);
			flag = false;
			if (aux3->get_radiacion_acum()>((95*100))/(aux3->get_radiacion_recibir()))
			{
				pacientes_radiacion.push_back(aux2);
				flag = true; //para que no se repita mi paciente, puede tener mas de un tumor con +95%
			}
			if (flag == true) break;
		}
	}
	return pacientes_radiacion;
}; 

list<cPaciente*> cCentro_radioterapia::buscar_paciente_en_tratamiento(list<cPaciente*> paciente,eUbicacion ubitumor,string tipotrat) //recibo una lista de pac 
{	
	list<cPaciente*> pacientesfiltrados;
	for (list<cPaciente*>::iterator it_ = paciente.begin(); it_ != paciente.end(); it_++)
	{
		bool flag = false;
		cPaciente* aux2 = (*it_);
		for (list<cTumor*>::iterator ti_ = aux2->get_ficha()->get_tumor().begin(); ti_ != aux2->get_ficha()->get_tumor().end(); ti_++)
		{
			
			cTumor* tumorcito = (*ti_);
			if ( tumorcito->get_ubicacion() == ubitumor)
			{
				flag = true;
			}
			
		}
		if (flag == true)
		{
			pacientesfiltrados.push_back(aux2);
		}
	}




	list<cPaciente*>pacientesfiltradosfinal;
	for (list<cPaciente*> ::iterator it_ = pacientesfiltrados.begin(); it_ != pacientesfiltrados.end(); it_++)
	{
		cPaciente* aux2 = (*it_);
		bool flag;
		for (list<string*>::iterator ti_ = aux2->get_ficha()->get_tipo_tratamiento().begin(); ti_ != aux2->get_ficha()->get_tipo_tratamiento().end(); ti_++)
		{

			string* ubicacion = (*ti_);
			
			//if (ubicacion == ubitumor) arreglar esta lista no puedo comparar un string con string*
			{
				flag = true;
			}

		}
		if (flag == true)
		{
			pacientesfiltradosfinal.push_back(aux2);
		}
	}

	return pacientesfiltradosfinal;

};

void cCentro_radioterapia::sacar_paciente(cPaciente* paciente) {

	this->pacientes.remove(paciente);
};

void cCentro_radioterapia::agregar_paciente(cPaciente* paciente) {

	this->pacientes.push_back(paciente);

};

void cCentro_radioterapia::operator+(cPaciente* paciente) {

	this->agregar_paciente(paciente);
};

void cCentro_radioterapia::operator-(cPaciente* paciente) {
	this->sacar_paciente(paciente);

};

cCentro_radioterapia::~cCentro_radioterapia() {
	this->cantidad_empleados--;
};