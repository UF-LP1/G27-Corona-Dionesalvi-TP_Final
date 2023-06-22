#define _CRT_SECURE_NO_WARNINGS
#include "cFecha.h"


cFecha::cFecha()//si creo la fecha con este constructor lo que sucedera es que se inicializaran los parametros con la fecha estipulada en maquina
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	SetNow();
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

cFecha::cFecha(int dia, int mes, int anio)//si creo la fecho con este constructor sera inicializada en los valores que este recibe
{
	fecha.tm_hour = 0;
	fecha.tm_min = 0;
	fecha.tm_sec = 0;
	fecha.tm_mday = dia;
	fecha.tm_mon = mes - 1;
	fecha.tm_year = anio - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

void cFecha::SetNow()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual dada por el sistema
	fecha.tm_mday = aux->tm_mday;//igualas tu dia a tu dia actual
	fecha.tm_mon = aux->tm_mon;//igualas tu mes a tu mes actual
	fecha.tm_year = aux->tm_year;//igualas tu año a tu año actual
	fecha.tm_min = aux->tm_min;//igualas tus minutos a tus minutos actual
	fecha.tm_sec = aux->tm_sec;//igualas tus segundos a tus segundo actual
}

string cFecha::get_fecha() {

	/* La línea "stringstream ss;" es una declaración de un objeto llamado "ss" de la clase "stringstream" en C++.

	En C++, la clase "stringstream" forma parte de la biblioteca <sstream> y proporciona una forma conveniente de manipular cadenas como si fueran flujos de entrada/salida. Te permite tratar las cadenas como flujos y realizar operaciones como extracción e inserción de datos. 

	Aquí tienes un ejemplo de cómo puedes usar la clase "stringstream":*/
	return to_string(fecha.tm_year + 1900) +
		"/" + to_string(fecha.tm_mon + 1) +
		"/" + to_string(fecha.tm_mday);
}


bool cFecha::operator==(cFecha& otra) { //pasa todo a segundos, la actual y la que recibe. las compara y devuelve si son iguales
	time_t aux_this = mktime(&(this->fecha));
	time_t aux_otra = mktime(&(otra.fecha));
	return aux_this == aux_otra;
}


cFecha::~cFecha() {};