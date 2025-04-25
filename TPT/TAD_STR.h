#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef STRING_H
#define STRING_H
typedef struct nodo{
	char car;
	struct nodo *sig;
}RNodo;

typedef RNodo *str;

str create(char);
str load2(const char*);
str load();
void print(str);
str concat(str, str);
str beforetoken(str, char);
str Union(str,str);
str interseccion(str,str);
str diferencia(str,str);
str depuraStr(str,char);
#endif
