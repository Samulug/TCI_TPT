#include "TAD_DataType.h"

tdata unionConj(tdata,tdata);
tdata InterConj(int);


tdata Inicializa(int n){
	tdata nvo;
	int subtipo,cant;
	fflush(stdin);
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
		if(Cj->tipo==1){
			aux=Cj;
		}
		else{
			aux=Cj->dato;
		}
		show(aux);
		if(Cj->sig!=NULL)printf(",");
			showlis(Cj->sig);
	}
}

void showconj(tdata Cj){
	tdata aux;
		if(Cj!=NULL){
			if(Cj->tipo==1){
				aux=Cj;
			}
			else{
				aux=Cj->dato;
			}
			show(aux);
			if(Cj->sig!=NULL)printf(","); 
				showconj(Cj->sig);
			
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
			showconj(Cj->dato);
			printf("}");
			break;
		}
	}
	else{
		print(Cj->dato);
	}
}
void MostrarConj(tdata Cj){
	printf("{");
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
	
int ComparaElem(tdata A,tdata B){
	int band;
	band=0;
	tdata aux,pivot;
	if(A->tipo==B->tipo){
		switch(A->tipo){
		case 1:
			band=ComparaStr(A,B);
			if(band==1){
				printf("\nMISMOS STR");
				return 1;
			}
			else{
				printf("\nNO SON MISMOS STR");
				return -1;
			}
			break;
		case 2:
			pivot=A;
			aux=B;
			while(pivot!=NULL&&aux!=NULL&&band!=-1){
				band=ComparaElem(aux->dato,pivot->dato);
				aux=aux->sig;
				pivot=pivot->sig;
			}
			if(pivot==NULL&&aux==NULL&&band==1)return 1;
			else return -1;
			break;
		case 3:
			pivot=A;
			aux=B;
			while(pivot!=NULL&&aux!=NULL&&band!=-1){
				band=ComparaElem(pivot->dato,aux->dato);
				aux=aux->sig;
				pivot=pivot->sig;
			}
			if(pivot==NULL&&aux==NULL&&band==1)return 1;
			else return -1;
			break;
		}
	}else{
		print("No son los mismos tipo, pa q entras");
		return -1;
	}
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
					band=ComparaStr(pivot,aux);
				}
				else{
					band=ComparaElem(pivot->dato,aux->dato);
				}
				if(band==1){
					temp=(tdata)malloc(sizeof(struct datatype));
					temp->tipo=pivot->tipo;
					temp->dato=aux->dato;
					temp->sig=NULL;
					ingresoporcola1(&nvo,temp);
						
				}else printf("\nNO SON");
				printf("bandera: %d\n",band);
			}	
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
	}               //c=copiaconj(a);
	aux=b;
	while(aux!=NULL){
		mov=c;
		while(mov!=NULL && band!=-1){
			if(aux->tipo==mov->tipo){
				if(aux->tipo==1){
					band=ComparaStr(aux,mov);
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
			if(aux->tipo==1){
				band=ComparaElem(aux,nvo);
			}else band=ComparaElem(aux->dato,nvo->dato);
		}
		if(band!=1){
			ant=aux;
			aux=aux->sig;
		}
	}
	if(band==1){
		if(aux==NULL){
			ant->sig=NULL;
		}
		else if (ant==NULL){
			(*A)=aux->sig;
		}
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
			if(ant==NULL)c=aux->sig;
			else ant->sig=aux->sig;
		}
		pivot=pivot->sig;
		band=-1;
	}
	return c;
}
	
	
void opciones(){
	printf("\nMenu\n[1] para mostrar la intersección\n[2] para mostrar la unión\n[3] para mostrar la diferencia\n[4] para mostrar la cardinalidad de A\n[5] para ver la pertenencia en A\n[6] para ver la contención en A\n[7] para eliminar un elemento de A ");
}
void Operaciones(tdata A,tdata B){
	tdata C; int n,cardinal;
	C=(tdata)malloc(sizeof(struct datatype));
	C->tipo=3;
	C->sig=NULL;
	
	opciones();
	printf("\nElige que operacion Hacer;");
	scanf("%d",&n);
	while(n!=0){
		C=(tdata)malloc(sizeof(struct datatype));
		C->tipo=3;
		C->sig=NULL;
		switch(n){
		case 1:
			printf("\ningreso a interseccion");
			C->dato=InterseccionConj(A->dato,B->dato);//ok
			MostrarConj(C->dato);
			break;
		case 2:
			printf("\ningreso a Union");
			C->dato=unionConj(A->dato,B->dato);		//ok
			MostrarConj(C->dato);
			break;
		case 3:
			printf("\ningreso a Diferencia");
			C->dato=diferenciaConj(A->dato,B->dato);//OK
			MostrarConj(C->dato);
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
		opciones();
		printf("\nElige que operacion Hacer;");
		scanf("%d",&n);
	}
}
	
int DetD(tdata d){
	int ban=0;
	tdata aux,nvo;
	aux=d->dato;
	while(aux!=NULL && ban!=3){
		nvo=aux->dato;
		while(nvo!=NULL && ban!=3){
			printf("\n %d", nvo->dato->tipo);
			if(nvo->dato->tipo==3)
				ban=3;
			else
			nvo=nvo->sig;
		}
		aux=aux->sig;
	}
	if(ban==3)
		return -1;
	else
		return 1;
}
	

int comparacys(str cad,char c){
	printf("\n Caracteres que estoy comparando: %c y %c\n",cad->car,c);
	if(cad->car==c){
		return 1;
	}
	else{
		return -1;
	}
}
	
/*str Busca(tdata lis, str q,char c){
	int b;
	str aux=NULL;
	printf("Busca, lista: ");         //(q0,0,q1)
	MostrarConj(lis->sig->sig->dato); //lis->dato =(q0) lis->sig->dato=(0) lis->sig->sig->dato=(q1)
	printf("Muestra antes de comparar\n");
	print(lis);
	print(q);
	b=ComparaStr(lis->dato->dato,q); //lis->dato->dato=q0
	printf("%d\n",b);
	if(b==1){
		printf("IGUALES\n");
		print(lis->sig->sig->dato);
		aux=lis->sig->sig->dato->dato;
		print(aux);
		printf("Tipo de la transision: %d\n",lis->sig->sig->dato->tipo);
		if(comparacys(lis->sig->dato->dato,c)){ //revisar lis->sig->dato->dato=str 0 Hacer otro modulo p comp str y char
			printf("Los caracteres son iguales\n");
			return aux;  //lis->sig->sig->dato->dato=str q1
		}
		else{
			return NULL;
		}
	}
	else{
		printf("No compara str\n");
		return NULL;
	}
}
	
str obtenerq(tdata D, str q, char c){
	str b=NULL;
	printf("Mostrar mi conjunto D:\n");
	MostrarConj(D);
	printf("obtenerq\n");
	while(D!=NULL && b==NULL){
		printf("Ciclo\n");
		b=Busca(D->dato,q,c); //q1
		printf("Valor de b en obtenerq: ");
		print(b);
		D=D->sig;
	}
	if(b!=NULL){
		return b;
	}
	else{
		return NULL;
	}
}
	
	
int pertenencia2(tdata A, str q){
	tdata aux;
	int b=0;
	aux=A;
	while (A!=NULL && b!=1){
		
		b=ComparaStr(A->dato,q);
		A=A->sig;
	}
	if(b==1){
		return 1;
	}
	else 
	   return -1;
}
	
/*void acepta(tdata D,str q, str cad,tdata F){
	int b;
	while(cad!=NULL && q!=NULL){
		q=obtenerq(D,q,cad->car);
		print(q);
		cad=cad->sig;
	}
	
	if(q==NULL){
		printf("No esta definido\n");
	}
	else{
		print(q);
		b=pertenencia2(F,q);
		if(b==1)
			printf("Aceptada\n");
		else
			printf("No aceptada\n");
	}
}*/
	
int pertenencia2(tdata A, str q){
	tdata aux;
	int b=0;
	aux=A;
	while (A!=NULL && b!=1){
		
		b=ComparaStr(A->dato,q);
		A=A->sig;
	}
	if(b==1){
		return 1;
	}
	else 
	   return -1;
}
str Busca(tdata lis,str q,char c){
	int b,B;
	str aux=NULL;
	printf("Busca, lista: ");//(q0,0,q1)...
	MostrarConj(lis);
	printf("Muestra antes de comparar\n");//lis->dato =(q0) lis->sig->dato=(0) lis->sig->sig->dato=(q1)
	print(lis); 
	print(q);
	b=ComparaStr(lis->dato->dato,q); //lis->dato->dato=q0
	printf("%d\n",b);
	if(b==1){
		printf("IGUALES\n");
		aux=lis->sig->sig->dato->dato;
		print(aux);
		B=comparacys(lis->sig->dato->dato,c); //modulo para comparar el char y un str lis->sig->dato->dato=str 0
		printf("\nValor de comp caracteres: %d\n",B);
		if(B==1){ 
			printf("Los caracteres son iguales\n");
			return aux;  //lis->sig->sig->dato->dato=str q1
		}
		else{
			return NULL;
		}
	}
	else{
		printf("No compara str\n");
		return NULL;
	}
}
str obtenerq(tdata D,str q,str cadena){
	str b=q;
	str s; //uso dos str auxiliares
	tdata aux; //tdata auxiliae para moverme en la lista de transiciones
	aux=D;
	while(aux!=NULL && cadena!=NULL){ //ciclo mientras que no consuma la cadena por completo o mi lista llegue a null
		s=b; //guardo el valor de b que es mi estado actual
		b=Busca(aux->dato,b,cadena->car);//"busca" analiza las tranciciones con un caracter y me retorna nulo o el sig estado
		if(b==NULL){ //en caso de nulo significa que no coicide la 1ra transicio 
			aux=aux->sig; //paso a la siguiente ej de (q0,0,q1) a (q0,1,q0) para volver a buscar
			b=s;//como busca retorno nulo en b, le devuelvo el estado anterior que guardo s
		}
		else{ //si me devolvio un estado siguiente
			aux=D; //reinicio mi lista y vuelvo a la primera transicion (q0,0,q1)
			cadena=cadena->sig; //avanzo sobre mi cadena
			printf("\nCadena que queda: ");
			print(cadena);
		}
	}				//Si corto ciclo por aux!=nulo entonces la cadena no estaba definida
	if(aux==NULL){ //Podemos fijarnos antes si toda la cadena tiene el alfabeto correcto
		return NULL;
	}else{
		return b;
	}
	
}
void acepta(tdata D,str q, str cad,tdata F){
	int b;
	q=obtenerq(D,q,cad); //busco el estado final
	printf("\nq obtenido: ");
	print(q);

	if(q==NULL){ //si devuelve nulo es porque la cadena no esta definida para el afd
		printf("No esta definido\n");
	}
	else{
		printf("\nEstado final obtenido: ");
		print(q);
		printf("\nEstado de aceptacion: ");
		print(F);
		b=pertenencia2(F,q);
		if(b==1)
			printf("Aceptada\n");
		else
			printf("No aceptada\n");
	}
}
//------------------------------HARDCODE-----------------------------------

tdata creaStrHard(const char *s){
tdata nodoStr = malloc(sizeof(struct datatype));
nodoStr->tipo = 1;
nodoStr->dato = load2(s);
nodoStr->sig = NULL;
return nodoStr;
}

// 2) array de literales ? tdata tipo=2 (lista de cadenas)
tdata creaListaHard(int n, char *Datos[]) {
	if (n <= 0) return NULL;
	
	tdata nodoLista = malloc(sizeof(struct datatype));
	nodoLista->tipo = 2;
	nodoLista->sig = NULL;
	// Creamos nodo tipo 1 con el str
	tdata nodoStr = malloc(sizeof(struct datatype));
	nodoStr->tipo = 1;
	nodoStr->dato = load2(Datos[0]);  // usamos el primero
	// Asignamos ese nodo tipo 1 como dato del nodo tipo 2
	nodoLista->dato = nodoStr;
	
	// Llamada recursiva para el resto
	nodoLista->sig = creaListaHard(n - 1, Datos + 1);
	
	return nodoLista;
}



// 3) array de tdata ? tdata tipo=3 (conjunto)
tdata creaConjHard(int n, tdata items[]) {
	tdata conj = malloc(sizeof(struct datatype));
	conj->tipo = 3;
	conj->sig = NULL;
	
	tdata primero = NULL;
	tdata ultimo = NULL;
	
	for (int i = 0; i < n; i++) {
		tdata nuevo = malloc(sizeof(struct datatype));
		nuevo->tipo = items[i]->tipo;
		nuevo->dato = items[i]->dato;
		nuevo->sig = NULL;
		
		if (primero == NULL) {
			primero = nuevo;
			ultimo = nuevo;
		} else {
			ultimo->sig = nuevo;
			ultimo = nuevo;
		}
	}
	
	conj->dato = primero;
	return conj;
}
