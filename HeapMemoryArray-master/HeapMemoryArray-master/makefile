hepsi: derle calistir
Nesneler := ./lib/Top.o

derle:
	g++ -I ./include/ -o ./lib/Top.o -c ./src/Top.cpp
	g++ -I ./include/ -o ./bin/Test $(Nesneler) ./src/Test.cpp
	
calistir:
	./bin/Test