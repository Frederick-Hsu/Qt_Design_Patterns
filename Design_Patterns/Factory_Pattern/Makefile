# File name		: Makefile
# Description	: This script tells how to build the code files for the project "Factory_Pattern"
# Creator		: Frederique Hsu
# Creation date	: Wed.	29 April 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -Wall -g -p
FLAGS = -std=c++17

OBJs = main.o test.o Simple_Factory/Car.o Simple_Factory/CarBase.o Simple_Factory/CarFactory.o \
Factory_Method/CarFactories.o

Factory_Pattern : $(OBJs)
	g++ $(OPTIONS) $(FLAGS) $(OBJs) -o Factory_Pattern

main.o : main.cpp test.h
	g++ $(OPTIONS) $(FLAGS) -c main.cpp

test.o : test.cpp test.h Simple_Factory/CarBase.h Simple_Factory/CarFactory.h
	g++ $(OPTIONS) $(FLAGS) -c test.cpp

Car.o : Car.cpp Car.h
	g++ $(OPTIONS) $(FLAGS) -c Car.cpp

CarBase.o : CarBase.cpp CarBase.h
	g++ $(OPTIONS) $(FLAGS) -c CarBase.cpp

CarFactory.o : CarFactory.cpp CarFactory.h Car.h CarBase.h
	g++ $(OPTIONS) $(FLAGS) -c CarFactory.cpp

CarFactories.o : CarFactories.cpp CarFactories.h CarBase.h Car.h IFactory.h
	g++ $(OPTIONS) $(FLAGS) -c CarFactories.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJs) Factory_Pattern *.out *.o