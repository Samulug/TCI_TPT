#include "TAD_STR.h"
#ifndef TAD_DATATYPE_H
#define TAD_DATATYPE_H
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
tdata CreaLista(int);
tdata Operaciones(tdata,tdata);
#endif
