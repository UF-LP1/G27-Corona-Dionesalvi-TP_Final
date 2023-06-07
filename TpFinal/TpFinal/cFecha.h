#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

class cFecha

{
public:
	cFecha(int dia, int mes, int anio);
	string get_fecha();
	ostream& operator<<(ostream& out, cFecha& fecha);
	~cFecha();

private:
	int dia;
	int mes;
	int anio;
};

