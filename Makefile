all: depth-first_search
	
depth-first_search: main.o depth-first_search.o
	gcc main.o depth-first_search.o -o my_binary

main.o: main.c
	gcc -c main.c

depth-first_search.o: depth-first_search.c
	gcc -c depth-first_search.c

clean:
	rm -rf *.o depth-first_search