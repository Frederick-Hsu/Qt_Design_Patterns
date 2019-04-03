# File name		: Makefile
# Description	: To build the Polymorphism project.
# Creator		: Frederick Hsu
# Creation date	: Wed.	03 April 2019
# Copyright(C)	2019	All rights reserved.

OBJS = main.o Base.o Derived.o

Polymorphism.o : $(OBJS)
	g++ $(OBJS) -o Polymorphism.o


Base.o : Base.cpp Base.h
	g++ -c Base.cpp

Derived.o : Derived.cpp Derived.h Base.h
	g++ -c Derived.cpp

main.o : main.cpp Base.h Derived.h
	g++ -c main.cpp

.PHONY: clean
clean:
	-rm -frv $(OBJS) Polymorphism.o *.o chain polymorphic