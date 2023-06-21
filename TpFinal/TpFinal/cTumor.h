#pragma once
#include "eTamanio.h"
#include "eUbicacion.h"

class cTumor
{
public:
	cTumor(eTamanio tamanio, eUbicacion ubicacion, double radiacion_acum);

	eTamanio get_tamanio();

	eUbicacion get_ubicacion();

	void set_tamanio(eTamanio tamanio);

	void set_ubicacion(eUbicacion ubicacion);

	~cTumor();

private:
	eTamanio tamanio;
	eUbicacion ubicacion;
	float radiacion_acum;

};
