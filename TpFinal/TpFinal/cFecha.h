#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

class cFecha
{
private:
	tm fecha;

public:
	cFecha();
	cFecha(int dia, int mes, int anio);
	string get_fecha();
	void SetNow();
	~cFecha();
};
