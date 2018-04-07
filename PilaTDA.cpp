#include "PilaTDA.h"
#include "Simbolo.h"
#include <string>
#include <iostream>

using namespace std;

PilaTDA:: PilaTDA(){
	en_pila = NULL;
}

void PilaTDA:: push(Simbolo* nuevo){
	nuevo->setPropia(nuevo->getPropia());
	nuevo->setAnterior(en_pila);
	en_pila = nuevo;

}

char PilaTDA:: pop(){
	//cout<<"Pop";
	//cout<<en_pila->getCaracter()<<endl;
	char caracter = en_pila->getCaracter();
	Simbolo* temporal = en_pila;
	en_pila = en_pila->getAnterior();
	delete temporal;
	return caracter;
}

Simbolo* PilaTDA:: getSimbolo(){
	return en_pila;
}

bool PilaTDA:: isEmpty(){
	if (en_pila == NULL){
		return true;
	}else{
		return false;
	}
}

Simbolo* PilaTDA:: top(){
	return en_pila;
}

