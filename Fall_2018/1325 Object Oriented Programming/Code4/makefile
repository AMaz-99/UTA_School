#Aamir Mazumdar 1001523593
#makefile for C++ program
SRC1 = Code4_1001523593.cpp
SRC2 = VendingMachine.cpp
SRC3 = CokeLib.cpp
SRC4 = CokeMachine.cpp

OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)

EXE = $(SRC1:.cpp=.e)

HFILES = VendingMachine.h\
 	 CokeMachine.h \
	 CokeLib.h
	 
CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) 
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) -o $(EXE) 

$(OBJ1) : $(SRC1) $(HFILES)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) 

$(OBJ2) : $(SRC2) $(HFILES)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3) : $(SRC3) $(HFILES)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)  

$(OBJ4) : $(SRC4) $(HFILES)
	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4) 
