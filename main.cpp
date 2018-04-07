#include <string>
#include <iostream>
#include "PilaTDA.h"
#include "Simbolo.h"
#include <typeinfo>
#include <vector>
#include <fstream>

using namespace std;

int menu();

void insertarCadena(PilaTDA*, int, string);
double vaciarPila(PilaTDA*, int, char, double, vector<Simbolo*>&);
Simbolo* esVariable(char, vector<Simbolo*>&);
bool cadenaValida(string, vector<Simbolo*>&);


int main(){
	vector<Simbolo*> variables;
	vector<string> operaciones;
	PilaTDA* pila = new PilaTDA();
	string operacion;
	ifstream file("operaciones.txt");
	bool salir = false;
	int op = -1;
	while (!salir){
		switch(menu()){
			case 1:
				cout<<"Ingrese la operacion: "<<endl;
				cin>>operacion;
				if(cadenaValida(operacion, variables)){
					insertarCadena(pila, 0, operacion);
					cout<<"El resultado es: "<<vaciarPila(pila, 0, '?', 0, variables)<<endl;
				}		
				else{
					cout<<"Operacion invalida"<<endl;
				}
				break;
			case 2:
				if(file.is_open()){
					while(getline(file,operacion)){
						if(operacion.length()>3){
							operaciones.push_back(operacion);
						}else{
							file.close();
						}
					}
				}
				for (int i=0; i < operaciones.size(); i++){
					cout<<i<<") "<<operaciones[i]<<endl;
				}
				while (op <0 || op>=operaciones.size()){
					cin>>op;
				}
				if(cadenaValida(operaciones[op], variables)){
					insertarCadena(pila, 0, operaciones[op]);
					cout<<"El resultado es: "<<vaciarPila(pila, 0, '?',0, variables)<<endl;
				}else{
					cout<<"Operacion invalida"<<endl;
				}
				break;
			case 3:
				salir = true;
				break;
		}
	}	
	return 0;
}

bool cadenaValida(string operacion, vector<Simbolo*>& variables){
	//48 a 57
	char caracter_anterior='?';
	for (int i=0; i < operacion.length(); i++){
		if (i == 0){
			if(( (int) operacion[i] < 65 || (int) operacion[i]>122) ){
				if((int)operacion[i] <=96 && (int)operacion[i]>=91){
					return false;
				}
			}
		}else if (i == 1){
			if(operacion[i] != '='){
				return false;
			}		
		}else if (i+1 == operacion.length()){
			if((((int)operacion[i] < 48 || (int)operacion[i] > 57) && operacion[i] != ')') && !esVariable(operacion[i], variables)){
				return false;
			}
		}else{
			if (((int)caracter_anterior >= 48 && (int)caracter_anterior <= 57 && (int)operacion[i] >= 48 &&
					(int)operacion[i] <= 57) && !esVariable(operacion[i], variables)){
				return false;
			}else if(caracter_anterior == '+' || caracter_anterior == '-' || caracter_anterior == '*' || caracter_anterior == '/'
					|| caracter_anterior == '='){
				if(operacion[i]=='+' || operacion[i]=='-' || operacion[i]=='*' || operacion[i]=='/'){
					return false;
				}
			}
		}
		caracter_anterior = operacion[i];
	}
	return true;
}

Simbolo* esVariable(char caracter, vector<Simbolo*>& variables){
	for (int i=0; i < variables.size(); i++){
		if (caracter == variables.at(i)->getCaracter()){
			return variables.at(i);
		}
	}
	return NULL;
}

double vaciarPila(PilaTDA* pila, int i, char operador, double valor, vector<Simbolo*>& variables){
	//cout<<"vaciado "<<i<<endl;
	if(pila->getSimbolo() == NULL){
		return valor;
	}else if(pila->getSimbolo()->getAnterior() != NULL){
		char caracter = pila->pop();
		Simbolo* var_tentativa;
		cout<<"Caracter: "<<caracter<<endl;
		if(caracter != '+' && caracter != '-' && caracter != '*' && caracter != '/'){
			if(caracter != ' ' && caracter != ')' && caracter != '(' && caracter != '='){
				double char_int;
				if( (var_tentativa = esVariable(caracter, variables)) != NULL){
					char_int = var_tentativa->getVariable();
				}else{
					char_int = caracter - '0';
				}
				cout<<char_int<<endl;
				switch(operador){
					case '+':
						valor+=char_int;
						break;
					case '-':
						valor = char_int-valor;
						break;
					case '*':
						valor*=char_int;
						break;
					case '/':
						if (valor != 0){
							valor = char_int/valor;
						}else{
							cout<<"Se trató de llevar a cabo una division entre 0, por lo que el resultado es incorrecto"<<endl;
						}
						break;
					case '?':
						valor = char_int;
						break;
				}
			}
		}else{
			operador = caracter;
			//cout<<caracter<<endl;
		}
		cout<<valor<<endl;
		i++;
		vaciarPila(pila, i, operador, valor, variables);
	}else{
		Simbolo* variable = new Simbolo(pila->getSimbolo()->getCaracter());
		variable->setVariable(valor);
		for (int i=0; i < variables.size(); i++){
			if (variables.at(i)->getCaracter() == variable->getCaracter()){
				variables.erase(variables.begin()+i);
			}
		}
		variables.push_back(variable);
		
		pila->pop();
		vaciarPila(pila, i, operador, valor, variables);
	}
}

void insertarCadena(PilaTDA* pila, int i, string operacion){
	Simbolo* nuevo;
	if(operacion.length() - 1 == i ){
		nuevo = new Simbolo(operacion[i]);
		pila->push(nuevo);
		cout<<pila->getSimbolo()->getCaracter()<<" "<<endl;
	}else{
		nuevo = new Simbolo(operacion[i]);
		pila->push(nuevo);
		i++;
		cout<<pila->getSimbolo()->getCaracter()<<" "<<endl;
		insertarCadena(pila, i, operacion);
	}
	/*string operacion;
	cin>>operacion;
	for (int i=0; i < operacion.length(); i++){
		if(operacion[i] == ' )
		*/
}

int menu(){
	cout<<"¿Qué desea hacer?"<<endl
	    <<"1)Insertar Operación"<<endl
	    <<"2)Cargar de Archivo"<<endl
	    <<"3)Salir"<<endl;
	int op;
	cin>>op;
	return op;
}

