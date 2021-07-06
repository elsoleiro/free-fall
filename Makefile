CC = g++
OBJ = main.o display.o primitives.o
HEADER = include/GL/freeglut.h include/GL/glut.h include/display.h include/primitives.h
CFLAGS = -c -Wall -Iinclude/
LDFLAGS = -lglut -lGL -lGLU

build: $(OBJ) 
	$(CC) $(LDFLAGS) $(OBJ) -o $@


primitives.o: src/primitives.cc $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

display.o: src/display.cc $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

main.o: src/main.cc $(HEADER) 
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f *o build


