#include "TAD_STR.h"

#ifndef DATATYPE_H
#define DATATYPE_H
#define STR 1
#define LIST 2
#define SET 3

struct datatype{
	int tipo;
	
	union{
		str cad;
		
		struct{
			
			struct datatype* dato;
			struct datatype* sig;
		};
	};
};

typedef struct datatype* tdata;

tdata Inicializa(int);
void MostrarConj(tdata);
void show(tdata);
tdata CreaConj();
tdata CreaLista(int);
tdata Operaciones(tdata,tdata);
#endif
