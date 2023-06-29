#include "cCentro_radioterapia.h"
#include "cOncologo.h"

int cCentro_radioterapia::cantidad_empleados = 0;

cCentro_radioterapia::cCentro_radioterapia(string direccion, list<cPaciente*> pacientes, list<cEmpleado*> empleados, int cantidad_empleados) {

	this->direccion = direccion;
	this->pacientes = pacientes;
	this->empleados = empleados;
	this->cantidad_empleados++;
}

void contactar_paciente(cOncologo* o, cPaciente* z) {
	cFicha_paciente* k = z->get_ficha();
	cFecha* a = new cFecha();
	bool b = o->asistencia_sesion(k, a);
	if (b == true) {
		z->get_ficha()->set_estado_tratamiento("tratamiento vigente");
	}
	else
		z->get_ficha()->set_estado_tratamiento("CONTACTARSE");
}

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

list<cPaciente*>cCentro_radioterapia::buscar_paciente_limite_radiacion() { //metodo friend, no requiere operador de ambito
	list<cPaciente*> pacientes_radiacion;
	bool flag = false;
	for (list<cPaciente*>::iterator it_ = pacientes.begin(); it_ != pacientes.end(); it_++) {
		cPaciente* aux2 = (*it_);
		list<cTumor*> tumoroide = aux2->get_ficha()->get_tumor();
		for (auto i = tumoroide.begin(); i != tumoroide.end(); i++) {
			cTumor* aux3 = (*i);
			flag = false;
			if (aux3->get_radiacion_acum() > ((95 * 100) / (aux2->get_ficha()->get_radiacion_total()))) //busco pacientescon tumores cerca de alcanzar limite de raciacion
			{
				pacientes_radiacion.push_back(aux2);
				flag = true; //para que no se repita mi paciente, puede tener mas de un tumor con +95%
			}
			if (flag == true)
				break;
		}
	}
	return pacientes_radiacion;
};

cPaciente* cCentro_radioterapia::buscar_paciente_en_tratamiento(cPaciente* paciente, eUbicacion ubitumor, string* tipotrat) //recibo una lista de pac 
{
	int contadorcito = 0;
	cPaciente* p = paciente;
	list<cTumor*> tumores2 = p->get_ficha()->get_tumor();
	for (list<cTumor*>::iterator it_ = tumores2.begin(); it_ != tumores2.end(); it_++)
	{
		cTumor* aux = (*it_);
		if (aux->get_ubicacion() == ubitumor)
		{
			contadorcito++;
		}
	}

	if (contadorcito == 1)
	{
		return paciente;
	}
	else return nullptr;
};

void cCentro_radioterapia::sacar_paciente(cPaciente* paciente) {

	this->pacientes.remove(paciente);

};

void cCentro_radioterapia::agregar_paciente(cPaciente* paciente) {

	this->pacientes.push_back(paciente);

};

list<cPaciente*> cCentro_radioterapia::get_pacientes() {

	return this->pacientes;
};

void cCentro_radioterapia::operator+(cPaciente* paciente) {

	this->agregar_paciente(paciente);
};

void cCentro_radioterapia::operator-(cPaciente* paciente) {
	this->sacar_paciente(paciente);

}

ostream& cCentro_radioterapia::operator<<(ostream& out)
{
	for (list<cPaciente*>::iterator it_ = this->pacientes.begin(); it_ != this->pacientes.end(); it_++)
	{
		cPaciente* pacientito = (*it_);
		out << pacientito->to_string();
	}
	return out;
}

cCentro_radioterapia::~cCentro_radioterapia() {
	this->cantidad_empleados--;

	while (this->empleados.size() != 0)
	{
		empleados.pop_back();
	}
	while (this->pacientes.size() != 0)
	{
		pacientes.pop_back();
	}

};