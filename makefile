temp:	main.o PilaTDA.o Simbolo.o 
		g++ main.o PilaTDA.o Simbolo.o -o temp
main.o:	main.cpp PilaTDA.h Simbolo.h
		g++ -c main.cpp
PilaTDA.o:	PilaTDA.cpp PilaTDA.h Simbolo.cpp
		g++ -c PilaTDA.cpp
Simbolo.o:	Simbolo.cpp Simbolo.h
		g++ -c Simbolo.cpp
