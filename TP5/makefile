a.out : Item.o principal.o Description.o Mets.o
	g++ Item.o principal.o Description.o Mets.o

principal.o : Item.h principal.cc
	g++ -c principal.cc

Item.o : Item.h Item.cc Description.h
	g++ -c Item.cc

Description.o : Description.cc Description.h
	g++ -c Description.cc

Mets.o : Mets.cc Mets.h
	g++ -c Mets.cc
