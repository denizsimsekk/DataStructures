derlecalistir: derle bagla calistir
derle:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I "./include" -c ./src/Liste.cpp -o ./lib/Liste.o
bagla:derle
	g++ ./lib/main.o ./lib/Liste.o -o ./bin/program
calistir:
	./bin/program.exe
