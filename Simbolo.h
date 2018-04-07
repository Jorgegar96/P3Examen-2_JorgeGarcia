#ifndef SIMBOLO_H
#define SIMBOLO_H

class Simbolo{

	private:
		char caracter;
		Simbolo* clase_propia;
		Simbolo* anterior;
		double valor_variable;

	public:
		Simbolo(char);
		Simbolo* getPropia();
		Simbolo* getAnterior();
		void setPropia(Simbolo*);
		void setAnterior(Simbolo*);
		char getCaracter();
		double getVariable();
		void setVariable(double);
};

#endif
