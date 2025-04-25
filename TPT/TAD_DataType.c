#include "TAD_DataType.h"

tdata unionConj(tdata,tdata);
tdata InterConj(int);


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
			printf("Cuantos elementos tiene tu Conjunto? cant:");
			scanf("%d",&subtipo);
			fflush(stdin);
			nvo=(tdata)malloc(sizeof(struct datatype));
			nvo->tipo=n;/*print y scan*/
			nvo->sig=NULL;
			nvo->dato=InterConj(subtipo);
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
	}
	else{
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
	
tdata copiaconj(tdata A){
	tdata C, nvo, aux;
	C=(tdata)malloc(sizeof(struct datatype));
	aux=A;
	while (aux!=NULL){
		nvo=(tdata)malloc(sizeof(struct datatype));
		nvo->tipo=aux->tipo;
		nvo->dato=aux->dato;
		nvo->sig=NULL;
		ingresoporcola1(&C,nvo);
		aux=aux->sig;
	}
	return C;
}
	
int ComparaElem(tdata A, tdata B){
	tdata pivot,aux; int band;
	pivot=A;
	aux=B;
	while(pivot!=NULL){
		while(aux!=NULL){
			if(aux->tipo==pivot->tipo){
	//			printf("\nHAY LISTAS");
				band=ComparaStr(pivot->dato,aux->dato);
				if(band==1){
					if(pivot==NULL){
						return 1;
					}
	//				printf("\nSON IGUALES LOS STR");
					pivot=pivot->sig;
				}else{
	//				printf("\nNO SON IGUALES LOS STR");
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
	int band=0;
	nvo=NULL;
	pivot=A;
	while(pivot!=NULL){
		aux=B;
		while(aux!=NULL && band!=1){
			if(aux->tipo==pivot->tipo){
				
				if(aux->tipo==1){
//					printf("Son str\n");
					band=ComparaStr(pivot,aux);
				}
				else{
	//				printf("\nSon iguales");
					band=ComparaElem(pivot->dato,aux->dato);
				}
				if(band==1){
	//				printf("\nsi son");
					temp=(tdata)malloc(sizeof(struct datatype));
					temp->tipo=pivot->tipo;
					temp->dato=aux->dato;
					temp->sig=NULL;
					ingresoporcola1(&nvo,temp);
						
				}else printf("\nNO SON");
				printf("bandera: %d\n",band);
			}	
//			printf("\nIterando B: ");
			show(aux);
			aux=aux->sig;
		}
		band=-1;
		pivot=pivot->sig;
	}
	return nvo;
	
}
	
	
tdata unionConj(tdata a,tdata b){
	int band;
	band=0;
	tdata c, aux,nvo,mov;
	c=NULL;
	aux=a;
	
	while(aux!=NULL){
		
		nvo=(tdata)malloc(sizeof(struct datatype));
		nvo->tipo = aux->tipo;
		nvo->dato = aux->dato; 
		nvo->sig = NULL; 
		ingresoporcola1(&c, nvo);
		aux=aux->sig; 
	}
	
	//c=copiaconj(a);
	aux=b;
	while(aux!=NULL){
		mov=c;
		while(mov!=NULL && band!=-1){
			if(aux->tipo==mov->tipo){
				if(aux->tipo==1){
					band=ComparaStr(aux->dato,mov->dato);
				}
				else{
					band=ComparaElem(aux->dato,mov->dato);
				}
			}
			mov=mov->sig;
		}
		if(band==-1){
			nvo=(tdata)malloc(sizeof(struct datatype));
			nvo->tipo = aux->tipo;
			nvo->dato = aux->dato; 
			nvo->sig = NULL; 
			ingresoporcola1(&c, nvo);
		}
		aux=aux->sig;
		band=0;;
	}
	return c;
}
	
void pertenencia(tdata A){
	tdata nvo,aux;
	int subtipo,band=0;
	printf("\nElegi tipo de dato: ");
	scanf("%d",&subtipo);
	nvo=Inicializa(subtipo);
	show(nvo);
	aux=A;
	while(aux!=NULL&&band!=1){
		if(aux->tipo==nvo->tipo){
			band=ComparaElem(aux,nvo);
		}
		aux=aux->sig;
	}
	if(band==1){
		printf("\nEl elemento Pertenece al conjunto");
	}else printf("\nEl elemento NO Pertenece al conjunto");
}
	
int cardinalidad(tdata A){
	int cont=0;
	tdata aux=A;
	while(aux!=NULL){
		cont++;
		aux=aux->sig;
	}
	return cont;
}
	
void eliminaElemento(tdata *A){
	tdata nvo,aux,ant;
	int subtipo,band=0;
	printf("\nElegi tipo de dato: ");
	scanf("%d",&subtipo);
	nvo=Inicializa(subtipo);
	show(nvo);
	aux=*A;
	ant=NULL;
	while(aux!=NULL&&band!=1){
		if(aux->tipo==nvo->tipo){
			band=ComparaElem(aux,nvo);
		}
		if(band!=1){
			ant=aux;
			aux=aux->sig;
		}
	}
	if(band==1){
		if(aux==NULL) ant->sig=NULL; 
		else ant->sig=aux->sig;
		printf("\nElemento Eliminado");
	}else printf("\nEl elemento no se encuentra en el Conjunto");
}
	
	
void contencion(tdata A){
	tdata pivot,aux,c;
	c=CreaConj();
	MostrarConj(c->dato);
	int band=1;
	pivot=A;
	while(pivot!=NULL){
		aux=c->dato;
		while(aux!=NULL&&band==1){
			if(pivot->tipo==aux->tipo){
				band=ComparaElem(pivot,aux);
			}
			aux=aux->sig;
		}
		pivot=pivot->sig;
	}
	if(band==1)printf("\nEl el subconjunto esta contenido");
	else printf("\nEl el subconjunto NO esta contenido");
}
	
tdata diferenciaConj(tdata A, tdata B){
	int band;
	band=-1;
	tdata c, pivot,nvo,aux,ant;
	c=NULL;
	aux=A;
	while(aux!=NULL){								//Metemos Todos los elementos de A
		nvo=(tdata)malloc(sizeof(struct datatype));
		nvo->tipo = aux->tipo;
		nvo->dato = aux->dato; 
		nvo->sig = NULL; 
		ingresoporcola1(&c, nvo);
		aux=aux->sig; 
	}
	pivot=B;
	while(pivot!=NULL){
		ant=NULL;
		aux=c;
		while(aux!=NULL && band!=1){
			printf("\nIterando C: ");
			show(aux);
			
			if(pivot->tipo==aux->tipo){
				if(aux->tipo==1){
					band=ComparaStr(aux->dato,pivot->dato);
				}
				else{
					printf("\ntipo:%d",aux->tipo);
					band=ComparaElem(pivot,aux);
				}
				
			}
			if(band!=1){
				ant=aux;
				aux=aux->sig;
			}
		}
		
		if(band==1){
			if(ant==NULL)
				c=aux->sig;
			else 
				ant->sig=aux->sig;
		}
		
		pivot=pivot->sig;
		band=-1;
	}
	return c;
}
	
	
void opciones(){
	printf("Menu\n[1] para mostrar la intersección\n[2] para mostrar la unión\n[3] para mostrar la diferencia\n[4] para mostrar la cardinalidad de A\n[5] para ver la pertenencia en A\n[6] para ver la contención en A\n[7] para eliminar un elemento de A ");
}
	
tdata Operaciones(tdata A,tdata B){
	tdata C; int n,cardinal;
	C=(tdata)malloc(sizeof(struct datatype));
	C->tipo=3;
	C->sig=NULL;
	
	//opciones();
	printf("\nElige que operacion Hacer;");
	scanf("%d",&n);
	switch(n){
		case 1:
			printf("\ningreso a interseccion");
			C->dato=InterseccionConj(A->dato,B->dato); //ok
			break;
		case 2:
			printf("\ningreso a Union");
			C->dato=unionConj(A->dato,B->dato);		//ok
			break;
		case 3:
			printf("\ningreso a Diferencia");
			C->dato=diferenciaConj(A->dato,B->dato);//OK
			break;
		case 4:
			printf("\ningreso a Contar Elementos");
			cardinal=cardinalidad(A->dato);
			printf("Cantidad de elementos de A:%d",cardinal);
			break;
		case 5:
			printf("\ningreso a Pertenencia");
			pertenencia(A->dato);
			break;
		case 6:
			printf("\ningreso a Contención");
			contencion(A->dato);
			break;
		case 7:
			printf("\ningreso a Eliminar Elemento");
			eliminaElemento(&A->dato);
			MostrarConj(A->dato);
			break;
		default:
			printf("opcion invalida\n");
			break;
	}
		
	return C;
}
	
