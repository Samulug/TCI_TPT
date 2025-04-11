#include "TAD_DataType.h"

tdata Inicializa(int n){
	tdata nvo;
	if(n!=1){
		switch(n){
		case 2:
			nvo=(tdata)malloc(sizeof(struct datatype));
			nvo->tipo=n;
			printf("Elegi el dato wachin: ");
			scanf("%d",&n);
			fflush(stdin);
			nvo->sig=NULL;
			nvo->dato=Inicializa(n);
			printf("\nLis");
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
		nvo=(tdata)malloc(sizeof( str));
		nvo->tipo=n;
		nvo->dato=load();
		fflush(stdin);
		nvo->sig=NULL;
		printf("\nStr");
	}
	return nvo;
}
void showlis(tdata Lis){
	printf("[");
	while(Lis!=NULL){
		print(Lis->cad);
		Lis=Lis->sig;
	}
	printf("]");
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
}
void MostrarConj(tdata Cj){
	while(Cj!=NULL){
		printf("\n{");
		show(Cj->dato);
		Cj=Cj->sig;
	}
	printf("}");
}
	
