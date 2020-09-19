SRC = Code6_1001523593.c
OBJ = $(SRC:.c=.o)
EXE = $(SRC:.c=.e)

LSRC = MyLib.c
LOBJ = $(LSRC:.c=.o)
LHDR = $(LSRC:.c=.h)

CFLAGS = -g

LIBOBJ = $(LOBJ)

all : $(EXE)

$(EXE): $(OBJ) $(LIBOBJ)
	gcc $(CFLAGS) $(OBJ) $(LIBOBJ) -o $(EXE) 

$(OBJ) : $(SRC)
	gcc -c $(CFLAGS) $(SRC) -o $(OBJ) 

$(LOBJ): $(LSRC) $(LHDR) 
	gcc -c $(CFLAGS) $(LSRC) -o $(LOBJ)
	
