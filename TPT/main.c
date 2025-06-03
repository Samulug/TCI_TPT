#include "TAD_AF.h"

int main() {
/*	tdata conjA,conjB,conjC;*/
/*	conjA=CreaConj();*/
/*	MostrarConj(conjA->dato);*/
/*	conjB=CreaConj();*/
/*	MostrarConj(conjB->dato);*/
/*	Operaciones(conjA,conjB);
	str cadena;
	Af AFD;
	AFD=InicializaAf();
	MuestraAf(AFD);
	DeterminaAf(AFD);
	cadena=load();
	Aceptacion(AFD,cadena);
	printf("Analisis de composicion: \n");
	printf("\nNivel 1\n");
	MostrarConj(AFD.d->dato);
	printf("\nTipo: %d",AFD.d->tipo);
	printf("\nNivel 2\n");
	MostrarConj(AFD.d->dato->dato);
	printf("\nTipo: %d",AFD.d->dato->tipo);
	printf("\nNivel 3\n");
	showlis(AFD.d->dato->dato->dato);
	printf("\nTipo: %d",AFD.d->dato->dato->tipo);
	printf("\nNivel 4\n");
	print(AFD.d->dato->dato->dato->dato);
	printf("\nTipo: %d",AFD.d->dato->dato->dato->tipo);*/
	Af A = hardAf();
	MuestraAf(A);
	DeterminaAf(A);
	return 0;
}
