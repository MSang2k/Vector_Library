TARGET: myvector
myvector: main.o vectorlib.a
	g++ build/main.o -o build/myvector -L . build/vectorlib.a -lm
vectorlib.a: source/my_vector.o
	ar rs build/vectorlib.a source/my_vector.o
my_vector.o: source/my_vector.cpp
	g++ -c -I include  source/my_vector.cpp -o source/my_vector.o
main.o: main.cpp
	g++ -c -I include main.cpp -o build/main.o
clean:
	del source\*.o
	del /q build\*
