a.out : VecteurND.o principal.o
	g++ VecteurND.o principal.o

principal.o : VecteurND.h principal.cc
	g++ -c principal.cc

VecteurND.o : VecteurND.h VecteurND.cc
	g++ -c VecteurND.cc