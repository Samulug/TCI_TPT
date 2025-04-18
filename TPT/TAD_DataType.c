#include "TAD_DataType.h"

tdata Inicializa(int n){
	tdata nvo;
	int cant;
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
			/*
			printf("Elegi el dato wachin: ");
			scanf("%d",&n);
			fflush(stdin);
			
			nvo->dato=Inicializa(n);
			printf("\nLis");*/
			
			break;
		case 3:
			nvo=(tdata)malloc(sizeof(struct datatype));
			nvo->tipo=n;/*print y scan*/
			printf("Elegi el dato wachin: ");
			scanf("%d",&n);
			fflush(stdin);
			nvo->sig=NULL;
			nvo->dato=Inicializa(n);
			printf("\nSet");
			break;
		}
	}else{
		nvo=(tdata)malloc(sizeof(struct datatype));
		nvo->tipo=n;
		nvo->dato=load();
		fflush(stdin);
		nvo->sig=NULL;
		printf("\nStr");
	}
	return nvo;
}
void showlis(tdata Cj){ //3->2(3elementos)=(3{(1)hola})
		tdata aux;
		if(Cj!=NULL){
			aux=Cj->dato;
			while(aux->tipo!=1){
				Cj=Cj->dato;
				aux=aux->dato;
			}
			print(aux->dato);
			printf(",");
			showlis(Cj->sig);
		}
}
void show(tdata Cj){
	if(Cj->tipo!=1){
		switch(Cj->tipo){
		case 2:
			printf("[");
			showlis(Cj);
			printf("]");
			break;
		case 3:
			printf("{");
			show(Cj->dato);
			printf("}");
			break;
		}
	}
}
void MostrarConj(tdata Cj){
	while(Cj!=NULL){
		printf("\n{");
		show(Cj->dato);
		Cj=Cj->sig;
	}
	printf("}");
}
	
tdata CreaLista(int cant){
	tdata LisN;
	int n;
	LisN=(tdata)malloc(sizeof(struct datatype));
	LisN->tipo=2;
		if(cant!=1){
			printf("Elegi el dato wachin: ");
			scanf("%d",&n);
			fflush(stdin);
			LisN->dato=Inicializa(n);
			LisN->sig=CreaLista(cant-1);
		}else{
			printf("Elegi el dato wachin: ");
			scanf("%d",&n);
			fflush(stdin);
			LisN->dato=Inicializa(n);
			LisN->sig=NULL;
			return LisN;
		}
}
