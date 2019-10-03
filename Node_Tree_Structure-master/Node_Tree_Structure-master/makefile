hepsi: derle calistir oynat
derle:
	g++ -I include/ -o lib/Agac.o -c src/Agac.cpp
	g++ -I include/ -o lib/Dugum.o -c src/Dugum.cpp
calistir:
	g++ -I include/ -o bin/sonuc lib/Dugum.o lib/Agac.o src/Test.cpp
oynat:
	bin/sonuc
	