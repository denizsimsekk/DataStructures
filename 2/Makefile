derlecalistir: derle bagla calistir
derle:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
	g++ -I "./include" -c ./src/DogruKuyrugu.cpp -o ./lib/DogruKuyrugu.o
	g++ -I "./include" -c ./src/Nokta.cpp -o ./lib/Nokta.o
	g++ -I "./include" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I "./include" -c ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
	g++ -I "./include" -c ./src/OncelikliKuyruk.cpp -o ./lib/OncelikliKuyruk.o
bagla:derle
	g++ ./lib/main.o ./lib/DogruKuyrugu.o ./lib/Nokta.o ./lib/Dugum.o ./lib/AVLAgaci.o ./lib/OncelikliKuyruk.o -o ./bin/program
calistir:
	./bin/program.exe