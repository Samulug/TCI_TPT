#include "TAD_AF.h"

Af InicializaAf(){
	Af A;
	printf("\nIngresa Cojunto de estados\n");
	A.Q=CreaConj();
	printf("\nIngresa Alfabeto\n");
	A.E=CreaConj();
	printf("\nIngresa Estado Inicial\n");
	A.q0=load();
	printf("\nIngresa Estado de Aceptacion\n");
	A.F=CreaConj();
	MostrarConj(A.F->dato);
	printf("\nIngresa Conjunto de Transiciones\n");
	A.d=Inicializa(3);
	MostrarConj(A.d->dato);
	return A;
}
void MuestraAf(Af af){
	printf("\nAF=");
	printf("{");
	MostrarConj(af.Q->dato);
	printf(",");
	MostrarConj(af.E->dato);
	printf(",");
	MostrarConj(af.d->dato);
	printf(",");
	print(af.q0);
	printf(",");
	MostrarConj(af.F->dato);
	printf("}");
}
int opcionesAf(){
	int opc;
	printf("\n(1):Conjunto de Estados\n(2):Conjunto de Alfabeto\n(3):Conjunto de Transiciones\n(4):Estado Inicial\n(5):Conjunto de Estados de Aceptacion");
	printf("\nOpcion:");
	scanf("%d",&opc);
	return opc;
}
void MuestraXSeleccion(Af af){
	int op=opcionesAf();
	switch(op){
	case 1: 
		MostrarConj(af.Q->dato);
		MuestraXSeleccion(af);
		break;
	case 2:
		MostrarConj(af.E->dato);
		MuestraXSeleccion(af);
		break;
	case 3:
		MostrarConj(af.d->dato);
		MuestraXSeleccion(af);
		break;
	case 4: 
		print(af.q0);
		MuestraXSeleccion(af);
		break;
	case 5:
		MostrarConj(af.F->dato);
		MuestraXSeleccion(af);
		break;
	default:
		printf("Opcion incorrecta NV");
		break;
	}
}
void DeterminaAf(Af af){
	int tipoAF=DetD(af.d);
	if(tipoAF==1) printf("Es Determinista");
	else printf("Es NO Determinista");
}

	
void Aceptacion(Af AFD, str cadena){
	acepta(AFD.d->dato,AFD.q0,cadena,AFD.F->dato);
}
	
/*void Aceptacion(Af AFD,str cadena){
	acepta(AFD.d,AFD.q0,cadena,AFD.F);
}*/
	
Af hardAf(){
	Af A;
	
	//-------HarCode ALFABETO-----------
	char *Cepsilon[] = {"0", "1"}; //Conjunto
	tdata epsilon[2];
	for(int i=0;i<2;i++){
		epsilon[i]=creaStrHard(Cepsilon[i]);
	}
	A.E = creaConjHard(2, epsilon);
	//-------HarCode ALFABETO-----------
	
	
	//-------HarCode ESTADOS-----------
	char *CEstados[] = {"q0","q1","q2"};//Conjunto
	tdata ConjEstados[3];
	for(int i=0;i<3;i++){
		ConjEstados[i]=creaStrHard(CEstados[i]);
	}
	A.Q = creaConjHard(3, ConjEstados);
	//-------HarCode ESTADOS-----------
	
	
	//-------HarCode Aceptacion-----------
	char *Aceptado[]= {"q1"};//Conjunto
	tdata ConjAcep[1];
	ConjAcep[0]=creaStrHard(Aceptado[0]);
	A.F = creaConjHard(1, ConjAcep);
	//-------HarCode Aceptacion-----------
	
	//-------HarCode Inicial-----------
	A.q0 = creaStrHard("q0");
	//-------HarCode Inicial-----------
	
	//-------HarCode Transiciones-----------
	
	
	char *t1[] = {"q0","1","q0"};//lista
	char *t2[] = {"q0","0","q1"};//lista
	char *t3[] = {"q1","1","q1"};//lista
	char *t4[] = {"q1","0","q2"};//lista
	char *t5[] = {"q2","1","q2"};//lista
	char *t6[] = {"q2","0","q1"};//lista
	
	tdata lista1 = malloc(sizeof(struct datatype));
	lista1->tipo=2;
	lista1->dato=creaListaHard(3, t1);
	lista1->sig=NULL;
	
	tdata lista2 = malloc(sizeof(struct datatype));
	lista2->tipo=2;
	lista2->dato=creaListaHard(3, t2);
	lista2->sig=NULL;
	
	tdata lista3 = malloc(sizeof(struct datatype));
	lista3->tipo=2;
	lista3->dato=creaListaHard(3, t3);
	lista3->sig=NULL;
	
	tdata lista4 = malloc(sizeof(struct datatype));
	lista4->tipo=2;
	lista4->dato=creaListaHard(3, t4);
	lista4->sig=NULL;
	
	tdata lista5 = malloc(sizeof(struct datatype));
	lista5->tipo=2;
	lista5->dato=creaListaHard(3, t5);
	lista5->sig=NULL;
	
	tdata lista6 = malloc(sizeof(struct datatype));
	lista6->tipo=2;
	lista6->dato=creaListaHard(3, t6);
	lista6->sig=NULL;
	
	tdata transiciones[6] = {lista1, lista2, lista3, lista4, lista5, lista6};
	
	A.d = creaConjHard(6, transiciones);
	
	//-------HarCode Transiciones-----------
	
	return A;
	
}
	
