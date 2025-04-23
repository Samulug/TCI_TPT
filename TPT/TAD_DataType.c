#include "TAD_DataType.h"
tdata CreaStrDesdeTexto(const char* palabra) {
	str nodo = NULL;
	for (int i = 0; palabra[i] != '\0'; i++) {
		str nuevo = create(palabra[i]);
		ingresoporcola(&nodo, nuevo);
	}
	tdata dato = (tdata)malloc(sizeof(struct datatype));
	dato->tipo = 1;
	dato->dato = nodo;
	dato->sig = NULL;
	return dato;
}

tdata CreaListaHard(int cant, const char* elementos[]) {
	if (cant == 0) return NULL;
	tdata lista = (tdata)malloc(sizeof(struct datatype));
	lista->tipo = 2;
	lista->dato = CreaStrDesdeTexto(elementos[0]);
	lista->sig = CreaListaHard(cant - 1, &elementos[1]);
	return lista;
}

tdata CreaNodoLista(tdata lista) {
	tdata nodo = (tdata)malloc(sizeof(struct datatype));
	nodo->tipo = 2;
	nodo->dato = lista;
	nodo->sig = NULL;
	return nodo;
}

tdata CreaNodoConjunto(tdata conjunto) {
	tdata nodo = (tdata)malloc(sizeof(struct datatype));
	nodo->tipo = 3;
	nodo->dato = conjunto;
	nodo->sig = NULL;
	return nodo;
}































tdata Inicializa(int n){
	tdata nvo;
	int subtipo,cant;
	if(n!=1){
		switch(n){
		case 2:
			printf("Cuantos elementos tiene tu lista? cant:");
			scanf("%d",&cant);
			fflush(stdin);
			nvo=(tdata)malloc(sizeof(struct datatype));
			nvo->tipo=n;
			nvo->sig=NULL;
			nvo->dato=CreaLista(cant);
			break;
		case 3:
			printf("\n(Conjunto)");
			nvo=(tdata)malloc(sizeof(struct datatype));
			nvo->tipo=n;/*print y scan*/
			printf("\nElegi tipo de dato: ");
			scanf("%d",&subtipo);
			fflush(stdin);
			nvo->sig=NULL;
			nvo->dato=Inicializa(subtipo);
			break;
		}
	}else{
		nvo=(tdata)malloc(sizeof(struct datatype));
		nvo->tipo=n;
		nvo->dato=load();
		fflush(stdin);
		nvo->sig=NULL;
	}
	return nvo;
}
void showlis(tdata Cj){ 
		tdata aux;
		if(Cj!=NULL){
			aux=Cj->dato;
			show(aux);
			if(Cj->sig!=NULL)printf(",");
			showlis(Cj->sig);
		}
}
void show(tdata Cj){
	if(Cj->tipo!=1){
		switch(Cj->tipo){
		case 2:
			printf("[");
			showlis(Cj->dato);
			printf("]");
			break;
		case 3:
			printf("{");
			show(Cj->dato);
			printf("}");
			break;
		}
	}else{
		print(Cj->dato);
	}
}
void MostrarConj(tdata Cj){
	printf("\n{");
	while(Cj!=NULL){
		show(Cj);
		if(Cj->sig!=NULL) printf(",");
		Cj=Cj->sig;
	}
	printf("}");
}
tdata InterConj(int cant) {
	tdata Conj;
	int n;
	if (cant > 0) {
		printf("Tipo de dato del %d conjunto: ", cant);
		scanf("%d", &n);
		fflush(stdin);
		Conj = Inicializa(n);      // crea nodo de tipo correcto (1, 2 o 3)
		Conj->sig = InterConj(cant-1);  // llamada recursiva
		return Conj;               
	} else {
		return NULL;               // caso base para terminar recursión
	}
}
	
tdata CreaConj(){
	tdata Conj;
	int cant;
	Conj=(tdata)malloc(sizeof(struct datatype));
	Conj->tipo=3;
	Conj->sig=NULL;
	printf("Cuantos elementos tiene tu Conjunto? cant:");
	scanf("%d",&cant);
	fflush(stdin);
	Conj->dato=InterConj(cant);
	return Conj;
}
tdata CreaLista(int cant){
	tdata LisN;
	int n;
	LisN=(tdata)malloc(sizeof(struct datatype));
	LisN->tipo=2;
		if(cant!=1){
			printf("Elegi el %d de la Lista: ",cant);
			scanf("%d",&n);
			fflush(stdin);
			LisN->dato=Inicializa(n);
			LisN->sig=CreaLista(cant-1);
		}else{
			printf("Elegi el %d de la Lista: ",cant);
			scanf("%d",&n);
			fflush(stdin);
			LisN->dato=Inicializa(n);
			LisN->sig=NULL;
			return LisN;
		}
}
int ComparaElem(tdata A, tdata B){
	tdata pivot,aux; int band;
	pivot=A;
	aux=B;
	while(pivot!=NULL){
		while(aux!=NULL){
			if(aux->tipo==pivot->tipo){
				printf("\nHAY LISTAS");
				band=ComparaStr(pivot->dato,aux->dato);
				if(band==1){
					if(pivot==NULL){
						return 1;
					}
					printf("\nSON IGUALES LOS STR");
					pivot=pivot->sig;
				}else{
					printf("\nNO SON IGUALES LOS STR");
					return -1;
				}
			}else return -1;
			aux=aux->sig;
		}
		aux=B;
		if(pivot!=NULL)pivot=pivot->sig;
		else return 1;
	}
	return -1;
}
void ingresoporcola1(tdata *lista, tdata nuevo){
	if (*lista == NULL) {
		*lista = nuevo;
	} else {
		tdata aux = *lista;
		while (aux->sig != NULL)
			aux = aux->sig;
		aux->sig = nuevo;
	}
}
tdata InterseccionConj(tdata A, tdata B){
	tdata pivot,aux,nvo,temp;
	int band;
	nvo=NULL;
	pivot=A;
	while(pivot!=NULL){
		aux=B;
		while(aux!=NULL){
			if(aux->tipo==pivot->tipo){
				printf("\nSon iguales");
				band=ComparaElem(pivot->dato,aux->dato);
				if(band==1){
					
				printf("\nsi son");
					
				temp=(tdata)malloc(sizeof(struct datatype));
				
				temp->tipo=pivot->tipo;
				
				temp->dato=aux->dato;
				
				temp->sig=NULL;
				ingresoporcola1(&nvo,temp);
				}else printf("\nNO SON");
			}
			printf("\nIterando B: ");
			show(aux);
			aux=aux->sig;
		}
		pivot=pivot->sig;
	}
	return nvo;
}
tdata Operaciones(tdata A,tdata B){
	tdata C; int n;
	C=(tdata)malloc(sizeof(struct datatype));
	C->tipo=3;
	C->sig=NULL;
	printf("\nElige que operacion Hacer");
	//scanf("%d",&n);
	n=1;
	switch(n){
		case 1:
			printf("\ningreso a interseccion");
			C->dato=InterseccionConj(A->dato,B->dato);
	}
	return C;
}
