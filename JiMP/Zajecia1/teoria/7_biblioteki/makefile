all : program.exe

main.o : main.c biblioteka.h
	gcc main.c -c -o main.o

biblioteka.o : biblioteka.c biblioteka.h
	gcc biblioteka.c -c -o biblioteka.o

program.exe : biblioteka.o main.o 
	gcc biblioteka.o main.o -o program.exe

clean:
	rm biblioteka.o main.o program.exe

