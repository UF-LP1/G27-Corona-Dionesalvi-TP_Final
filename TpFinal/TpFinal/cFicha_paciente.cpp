#include "cFicha_paciente.h"
#include "cOncologo.h"
#include "cPaciente.h"

cFicha_paciente::cFicha_paciente(cOncologo* oncologo, list<cFecha*> fecha, list <cTumor*> tumores, list<string*> tipo_tratamiento, float radiacion_total, string DNI, int frecuencia_semanal_tratamiento, float radiacion_por_sesion, string estado_tratamiento, int sesiones_cumplidas) : DNI(DNI) {
	this->oncologo = oncologo;
	this->fechas = fecha;
	this->tumores = tumores;
	this->tipo_tratamiento = tipo_tratamiento;
	this->frecuencia_semanal_tratamiento = frecuencia_semanal_tratamiento;
	this->radiacion_total = radiacion_total;
	this->radiacion_por_sesion = radiacion_por_sesion;
	this->estado_tratamiento = estado_tratamiento;
	this->sesiones_cumplidas =sesiones_cumplidas;
	
}

cFicha_paciente::cFicha_paciente(cOncologo* oncologo,list<cTumor*> listilla) //constructor por parametro por defecto
{
	this->oncologo = oncologo;
	this->fechas.push_back(new cFecha());
	this->frecuencia_semanal_tratamiento = 0;
	this->radiacion_por_sesion = 0;
	this->radiacion_total = 0;
	this->tumores = listilla;
	this->sesiones_cumplidas = 0;
};

void cFicha_paciente::operator+(cTumor* tumor) {

	tumores.push_back(tumor); //Sobrecarga del operador + para que agregue un tumor al final de la lista

}

void cFicha_paciente::operator-(cTumor* tumor) {

	tumores.remove(tumor); //Sobrecarga del operador - para que elimine un tumor de la lista

};

list<cTumor*> cFicha_paciente::get_tumor() {
	return this->tumores;
};

void cFicha_paciente::agregar_tratamiento(string tratamiento) {

	this->tipo_tratamiento.push_back(&tratamiento);

}

void cFicha_paciente::agregar_fecha(cFecha* fecha)
{
	this->fechas.push_back(fecha);
};

list<string*> cFicha_paciente::get_tipo_tratamiento()
{
	return this->tipo_tratamiento;
}

void cFicha_paciente::set_radiacion_total(float radiacion) {

	this->radiacion_total;

};

float cFicha_paciente::get_radiacion_total() {
	return this->radiacion_total;
}

float cFicha_paciente::get_radiacion_por_sesion() {
	return this->radiacion_por_sesion;

}

void cFicha_paciente::set_radiacion_por_sesion(float radiacion) {
	 this->radiacion_por_sesion = radiacion;
}

void cFicha_paciente::set_frecuencia_semanal_tratamiento(int frecuencia) {
	 this->frecuencia_semanal_tratamiento = frecuencia;

}

int cFicha_paciente::get_frecuencia_semanal_tratamiento() {

	return this->frecuencia_semanal_tratamiento;
};

list<cFecha*> cFicha_paciente::get_fechas() {

	return this->fechas;
}

void cFicha_paciente::set_estado_tratamiento(string estado){

	this->estado_tratamiento = estado;

};

string cFicha_paciente::get_estado_tratamiento() {
	return this->estado_tratamiento;
}

cOncologo* cFicha_paciente::get_Oncologo()
{
	return this->oncologo;
}

int cFicha_paciente::get_sesiones_cumplidas(){

	return this->sesiones_cumplidas;
};

void cFicha_paciente::set_sesiones_cumplidas(int sesion){
	this->sesiones_cumplidas = sesion;
};


cFicha_paciente::~cFicha_paciente() {

	while (fechas.size() != 0)
	{
		fechas.pop_back();
	}

	while(tumores.size()!= 0)
	{
		tumores.pop_back();
	}
	while (tipo_tratamiento.size() != 0)
	{
		tipo_tratamiento.pop_back();
	}

};
