all: txtfind isort

txtfind: main.o
	gcc -Wall -o txtfind main.o
isort: sort.o
	gcc -Wall -o isort sort.o
main.o: main.c
	gcc -Wall -c -fPIC -c main.c 
sort.o: sort.c
	gcc -Wall -c -fPIC -c sort.c

.PHONY: clean all

clean:
	rm -f *.o txtfind isort a.out