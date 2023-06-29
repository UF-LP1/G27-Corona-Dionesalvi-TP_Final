#pragma once
#include "eTamanio.h"
#include "eUbicacion.h"
class cTumor
{
public:
	cTumor(eTamanio tamanio, eUbicacion ubicacion, float radiacion_acum);

	eTamanio get_tamanio();
	eUbicacion get_ubicacion();
	void set_tamanio(eTamanio tamanio);
	void set_ubicacion(eUbicacion ubicacion);
	float get_radiacion_acum();
	void set_radiacion_acum(float radiacion);
	~cTumor();

private:
	eTamanio tamanio;
	eUbicacion ubicacion;
	float radiacion_acum;
	
};
