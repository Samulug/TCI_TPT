#include "TAD_DataType.h"

int main() {
	tdata conjA,conjB,conjC;
	conjA=CreaConj();
	MostrarConj(conjA->dato);
	conjB=CreaConj();
	MostrarConj(conjB->dato);
	conjC=Operaciones(conjA,conjB);
	MostrarConj(conjC->dato);
	return 0;
}
