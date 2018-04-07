#ifndef PILATDA_H
#define PILATDA_H

#include "Simbolo.h"

class PilaTDA{

	private:
		Simbolo* en_pila;

	public:
		PilaTDA();
		void push(Simbolo*);
		char pop();
		Simbolo* top();
		bool isEmpty();
		Simbolo* getSimbolo();

		
};

#endif
