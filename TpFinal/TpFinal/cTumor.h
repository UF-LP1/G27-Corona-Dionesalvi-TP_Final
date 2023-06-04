#pragma once
#include "eTamanio.h"
#include "eUbicacion.h"

class cTumor
{
	cTumor(eTamanio tamanio, eUbicacion ubicacion, double radiacion_acum);

	eTamanio get_tamanio();

	eUbicacion get_ubicacion();

	~cTumor();

private:
	eTamanio tamanio;
	eUbicacion ubicacion;
	double radiacion_acum;

};

