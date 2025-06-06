#include "TAD_STR.h"

str create(char c){
	str nvo;
	nvo=(str)malloc(sizeof(RNodo));
	nvo->car=c;
	nvo->sig=NULL;
	return nvo;
}
	
void ingresoporcola(str *Cadena, str nodo){
str temp;
if(*Cadena==NULL){
		*Cadena=nodo;
	}else {
		temp=*Cadena;
		while(temp->sig!=NULL){
			temp=temp->sig;
		}
		temp->sig=nodo;
	}
}
str load(){
	str nodo,cabeza;
	cabeza=NULL;
	char c;
	printf("\nIngresar cadena:");
	fflush(stdin);
	c=getchar();
	while(c!='\n'){
		nodo=create(c);
		ingresoporcola(&cabeza, nodo);
		c=getchar();
	}
	return cabeza;
}
void print(str cab){
	str aux;
	aux=cab;
	if(aux==NULL){
		printf("\nLista Vacia");
	}else{
		while(aux!=NULL){
			printf("%c", aux->car);
			aux=aux->sig;
		}
	}
}
int pertenece(str L,char c){
	while(L!=NULL){
		if(L->car==c){
			return 1;
		}
		L=L->sig;
	}
	return 0;
}
					
str Union(str a, str b){
	str c, aux,nvo;
	int rta;
	c=NULL;
	aux=a;
	while(aux!=NULL){
		rta=pertenece(c,aux->car);
		if(rta==0){
			nvo=create(aux->car);
			ingresoporcola(&c,nvo);
		}
		aux=aux->sig;
	}	
	aux=b;
	
	while(aux!=NULL){
		rta=pertenece(c,aux->car);
		if(rta==0){
			nvo=create(aux->car);
			ingresoporcola(&c,nvo);
		}
		aux=aux->sig;
	}
	return c;
}
	
str interseccion(str a, str b){
	str c,aux,nvo;
	int rta;
	c=NULL;
	aux=a;
	while(aux!=NULL){
		rta=pertenece(b,aux->car);
		if(rta==1){
			nvo=create(aux->car);
			ingresoporcola(&c,nvo);
		}
		aux=aux->sig;
	}
	return c;
}
	
str diferencia(str a, str b){
	str c,aux,nvo;
	int rta;
	c=NULL;
	aux=a;
	while(aux!=NULL){
		rta=pertenece(b,aux->car);
		if(rta!=1){
			nvo=create(aux->car);
			ingresoporcola(&c,nvo);
		}
		aux=aux->sig;
	}
	return c;
}
	
int pertenece2(char L,char c){
	if(L==c){
		return 1;
	}else{
	   return 0;
	}  
}
	
str depuraStr(str a, char tk){
	str nvo,aux,c;
	int rta;
	c=NULL;
	aux=a;
	while(aux!=NULL){
		rta=pertenece2(aux->car,tk);
		if(rta==0){
			nvo=create(aux->car);
			ingresoporcola(&c,nvo);
		}else{
			nvo=create(' ');
			ingresoporcola(&c,nvo);
		}
		aux=aux->sig;
	}
	return c;
}
	
int ComparaStr(str a,str b){
	while (a!=NULL&&b!=NULL){
		printf("Caracter a: %c", a->car);
		printf("Caracter b: %c", b->car);
		if (a->car!=b->car){
			return -1;
		}
		a=a->sig;
		b=b->sig;
	}
	if(a==NULL&&b==NULL)
		   return 1;
	else 
		return -1;
}

// Construye un str a partir de un literal C
str load2(const char *s) {
	str cabeza = NULL, nodo;
	for (int i = 0; s[i] != '\0'; i++) {
		nodo = create(s[i]);
		ingresoporcola(&cabeza, nodo);
	}
	return cabeza;
}

// Clona profundamente un str
str cloneStr(const str original) {
	str cabeza = NULL, tail = NULL;
	for (str p = original; p != NULL; p = p->sig) {
		str nodo = create(p->car);
		if (!cabeza) {
			cabeza = tail = nodo;
		} else {
			tail->sig = nodo;
			tail = nodo;
		}
	}
	return cabeza;
}
