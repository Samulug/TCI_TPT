#include "TAD_DataType.h"

#ifndef TAD_AF_H
#define TAD_AF_H

typedef struct{
	tdata Q,E,d,F;
	str q0;
}Af;

Af InicializaAf();
void MuestraXSeleccion(Af);
void MuestraAf(Af);
void DeterminaAf(Af);
void Aceptacion(Af,str);
Af hardAf();
#endif
