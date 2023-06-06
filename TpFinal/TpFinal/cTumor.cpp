#include "cTumor.h"


cTumor::cTumor(eTamanio tamanio, eUbicacion ubicacion, double radiacion_acum) {
	this->tamanio = tamanio;
	this->ubicacion = ubicacion;
	this->radiacion_acum = radiacion_acum;
};

eTamanio cTumor::get_tamanio() {
	return this->tamanio;
};

eUbicacion cTumor::get_ubicacion() {
	return this->ubicacion;
};
void cTumor :: set_tamanio(eTamanio tamanio) {
	this->tamanio = tamanio;
}
void cTumor:: set_ubicacion(eUbicacion ubicacion) {
	this->ubicacion = ubicacion;
}

cTumor::~cTumor() {};