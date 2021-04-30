# comando para compilar o sistema
compile: eleicao.cpp candidato.cpp main.cpp partido.cpp  #TODO Adicionar eleição.cpp
	g++ -std=c++11 -o vereadores *.cpp

run: 
	valgrind ./vereadores candidatos.csv partidos.csv 15/11/2020