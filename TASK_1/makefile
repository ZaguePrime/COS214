main:
	g++ -static -c *.cpp -g
	g++ *.o -o main

run: main
	./main

clean:
	rm -f *.o main

all:
	make run && make clean