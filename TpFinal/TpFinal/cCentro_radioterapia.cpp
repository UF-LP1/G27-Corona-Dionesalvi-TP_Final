#include "cCentro_radioterapia.h"

cCentro_radioterapia::cCentro_radioterapia(string direccion, list<cPaciente*> pacientes, list<cEmpleado*> empleados) {

	this->direccion = direccion;
	this->pacientes = pacientes;
	this->empleados = empleados;
}

void contactar_paciente();

void cCentro_radioterapia::derivar_paciente(cPaciente* paciente) {

	cFicha_paciente *p = paciente->get_ficha();
	if (p == NULL) { //si su ficha esta vacia sigbifica que ningun oncologo lo atendio, por eso lo derivo
		for (list<cEmpleado*>::iterator it_ = empleados.begin(); it_ != empleados.end(); it_++) {  //bucle hasta el final de la lista 
			cEmpleado* aux2 = (*it_); //accedo a un elemento tipo cEmpleado, y con el & accedo a la direc de memoria
			cOncologo* aux = dynamic_cast<cOncologo*>(aux2); //si es empleado, chequeo que sea oncologo
			if (aux != nullptr) 
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
void buscar_paciente_limite_radiacion() {


};


void buscar_paciente_en_tratamiento();

void cCentro_radioterapia::sacar_paciente(cPaciente *paciente) {

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

cCentro_radioterapia::~cCentro_radioterapia(){};