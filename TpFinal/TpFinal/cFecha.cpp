#include "cFecha.h"

cFecha::cFecha(int dia, int mes, int anio){
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

string cFecha::get_fecha() {
	stringstream ss;
	ss << to_string(this->dia) << " / " << to_string(this->mes) << " / " << to_string(this->anio) << endl;
	return ss.str();

};

ostream& operator<<(ostream& out, cFecha& fecha) {

	out << fecha.get_fecha();
	return out;

};

cFecha::~cFecha(){};