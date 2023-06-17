#include "cFicha_paciente.h"

cFicha_paciente::cFicha_paciente(cOncologo* oncologo,  cFecha fecha, list <cTumor*> tumores, list<string*> tipo_tratamiento, float radiacion_total, string DNI, int frecuencia_semanal_tratamiento, float radiacion_por_sesion): DNI(DNI) {
	this->oncologo = oncologo;
	this->fecha = fecha;
	this->tumores = tumores;
	this->tipo_tratamiento = tipo_tratamiento;
	this->frecuencia_semanal_tratamiento = frecuencia_semanal_tratamiento;
	this->radiacion_total = radiacion_total;
	this->radiacion_por_sesion = radiacion_por_sesion;
};

void cFicha_paciente::operator+(cTumor* tumor) {

	this->tumores.push_back(tumor); //Sobrecarga del operador + para que agregue un tumor al final de la lista

}

void cFicha_paciente::operator-(cTumor* tumor) {

	this->tumores.remove(tumor); //Sobrecarga del operador - para que elimine un tumor de la lista
};

list<cTumor*> cFicha_paciente::get_tumor() {
	return this->tumores;

};

void cFicha_paciente::agregar_tratamiento(string tratamiento) {
	 
	this->tipo_tratamiento.push_back(&tratamiento);

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

float cFicha_paciente::set_radiacion_por_sesion(float radiacion) {
	this->radiacion_por_sesion = radiacion;
}

int cFicha_paciente::set_frecuencia_semanal_tratamiento(int frecuencia) {
	this->frecuencia_semanal_tratamiento = frecuencia;

}

void cFicha_paciente::get_frecuencia_semanal_tratamiento() {

	this->frecuencia_semanal_tratamiento;
};

cFicha_paciente::~cFicha_paciente(){};
