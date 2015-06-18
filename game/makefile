IDIR = ./include
SDIR = ./src
ODIR = ./obj
LDIR = ./lib

CC = g++
OS := $(shell uname)
ifeq ($(OS), Darwin)
CFLAGS = -framework OpenGL -framework GLUT -I$(IDIR) -Wall 
else 
CFLAGS = -lglut -lGL -lGLU -I$(IDIR) -Wall 
endif


_DEPS =  Handle.h Vector3.h
DEPS  = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = GameLoop.o Handle.o Vector3.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

turbosansa.game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f turbosansa.game