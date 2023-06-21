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
	float get_radiacion_acum();
	void set_radiacion_acum(int radiacion_sem);
	float get_radiacion_recibir();
	~cTumor();

private:
	eTamanio tamanio;
	eUbicacion ubicacion;
	float radiacion_acum;
	float radiacion_recibir;
};
