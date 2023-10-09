main:
	g++ -static -c *.cpp -g
	g++ *.o -o main

run: main
	./main

clean:
	rm -f *.o main

all:
	make clean && clear && make run

valgrind:
	valgrind --leak-check=full --num-callers=5 ./main