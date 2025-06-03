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
void Operaciones(tdata,tdata);
int DetD(tdata);
void acepta(tdata,str,str,tdata);
tdata creaStrHard(const char *s);// Crea un tdata tipo=1 a partir de un literal C
tdata creaListaHard(int,  char *items[]);// Crea un tdata tipo=2 (lista) a partir de un array de literales
tdata creaConjHard(int n, tdata items[]);// Crea un tdata tipo=3 (conjunto) a partir de un array de tdata
#endif
