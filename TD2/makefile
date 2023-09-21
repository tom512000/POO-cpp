a.out : Personne.o principal.o
	g++ Personne.o principal.o

principal.o : Personne.h principal.cc
	g++ -c principal.cc

Personne.o : Personne.h Personne.cc
	g++ -c Personne.cc
