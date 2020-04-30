# File name		: Makefile
# Description	: This script tells how to build the code files for the project "Factory_Pattern"
# Creator		: Frederique Hsu
# Creation date	: Wed.	29 April 2020
# Copyright(C)	2020	All rights reserved.
#

OPTIONS = -Wall -g -p
FLAGS = -std=c++17

OBJs = main.o test.o Simple_Factory/Car.o Simple_Factory/CarBase.o Simple_Factory/CarFactory.o \
Factory_Method/CarFactories.o Abstract_Template_Factory/template_factory.o \
Factory_Method/Components.o Factory_Method/AssemblingCar.o Factory_Method/AssemblingCarFactory.o \
Abstract_Template_Factory/Car_Categories.o Abstract_Template_Factory/Abstract_Factory.o \
Abstract_Template_Factory/Extend_Abstract_Factory.o

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

template_factory.o : template_factory.cpp template_factory.h CarBase.h
	g++ $(OPTIONS) $(FLAGS) -c template_factory.cpp

Components.o : Components.cpp Components.h
	g++ $(OPTIONS) $(FLAGS) -c Components.cpp

AssemblingCar.o : AssemblingCar.cpp AssemblingCar.h Components.h CarBase.h
	g++ $(OPTIONS) $(FLAGS) -c AssemblingCar.cpp

AssemblingCarFactory.o : AssemblingCarFactory.cpp AssemblingCarFactory.h CarBase.h AssemblingCar.h Components.h
	g++ $(OPTIONS) $(FLAGS) -c AssemblingCarFactory.cpp

Car_Categories.o : Car_Categories.cpp Car_Categories.h
	g++ $(OPTIONS) $(FLAGS) -c Car_Categories.cpp

Abstract_Factory.o : Abstract_Factory.cpp Abstract_Factory.h
	g++ $(OPTIONS) $(FLAGS) -c Abstract_Factory.cpp

Extend_Abstract_Factory.o : Extend_Abstract_Factory.cpp Extend_Abstract_Factory.h
	g++ $(OPTIONS) $(FLAGS) -c Extend_Abstract_Factory.cpp

.PHONY : clean
clean :
	-rm -frv $(OBJs) Factory_Pattern *.out *.o