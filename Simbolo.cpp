#include "Simbolo.h"
#include <iostream>
#include <string>

using namespace std;

Simbolo:: Simbolo(char caracter){
	this->caracter=caracter;
}

Simbolo* Simbolo:: getPropia(){
	return clase_propia;
}

Simbolo* Simbolo:: getAnterior(){
	return anterior;
}

void Simbolo:: setAnterior(Simbolo* anterior){
	this->anterior = anterior;
}	

void Simbolo:: setPropia(Simbolo* clase_propia){
	this->clase_propia = clase_propia;
}

char Simbolo:: getCaracter(){
	return caracter;
}

double Simbolo:: getVariable(){
	return valor_variable;
}

void Simbolo:: setVariable(double valor){
	valor_variable = valor;
}
