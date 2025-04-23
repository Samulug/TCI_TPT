#include "TAD_DataType.h"

int main (int argc, char *argv[]) {
		/*tdata conjC ,conjA = NULL, conjB = NULL, aux;
		// ===== ConjA = {[1,2,3], [hola], {mundo}} =====
		
		// Conjunto {mundo}
		aux = CreaNodoConjunto(CreaStrDesdeTexto("mundo"));
		aux->sig = conjA;
		conjA = aux;
		
		
		
		// Lista [hola]
		const char* hola[] = { "hola" };
		aux = CreaNodoLista(CreaListaHard(1, hola));
		aux->sig = conjA;
		conjA = aux;
		
		// Lista [1,2,3]
		const char* nums[] = { "1", "2", "3" };
		aux = CreaNodoLista(CreaListaHard(3, nums));
		aux->sig = conjA;
		conjA = aux;
		
		
		printf("\nConjunto A: ");
		MostrarConj(conjA);
		
		
		// ===== ConjB = {{aqui}, [hola,mundo], {no}, [1,2,3]} =====
		conjB = NULL;
		
		// Lista [1,2,3]
		aux = CreaNodoLista(CreaListaHard(3, nums));
		aux->sig = conjB;
		conjB = aux;
		
		// Conjunto {no}
		aux = CreaNodoConjunto(CreaStrDesdeTexto("no"));
		aux->sig = conjB;
		conjB = aux;
		
		// Conjunto {aqui}
		aux = CreaNodoConjunto(CreaStrDesdeTexto("aqui"));
		aux->sig = conjB;
		conjB = aux;
		
		
		// Lista [hola, mundo]
		const char* holaMundo[] = { "hola", "mundo" };
		aux = CreaNodoLista(CreaListaHard(2, holaMundo));
		aux->sig = conjB;
		conjB = aux;
		
		
		printf("\n\nConjunto B: ");
		MostrarConj(conjB);
		
		conjC=Operaciones(conjA,conjB);
		MostrarConj(conjC->dato);
		
		return 0;
	}*/
	
	
	
	
	
	
	
	tdata conjA,conjB,conjC;
	conjA=CreaConj();
	MostrarConj(conjA->dato);
	conjB=CreaConj();
	MostrarConj(conjB->dato);
	conjC=Operaciones(conjA,conjB);
	MostrarConj(conjC->dato);
	return 0;
}
