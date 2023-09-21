a.out : Objet.o Carton.o Principal.o
	g++ Objet.o Carton.o Principal.o

Principal.o : Objet.h Carton.h Principal.cc
	g++ -c Principal.cc

Carton.o : Carton.h Carton.cc
	g++ -c Carton.cc

Objet.o : Objet.h Objet.cc
	g++ -c Objet.cc