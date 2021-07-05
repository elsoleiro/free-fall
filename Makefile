CC = g++
OBJ = main.o
HEADER = include/freeglut.h include/glut.h
CFLAGS = -c -Wall -Iinclude/
LDFLAGS = -lglut -lGL -lGLU

build: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

main.o: src/main.cc $(HEADER)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f *o build


