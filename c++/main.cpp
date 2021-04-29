#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "eleicao.h"
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{

  ifstream in(argv[1]); // TODO verificar quando arquivo não abrir

  string linha, palavra;
  vector<string> vetorDados;
  list<Candidato> listaDeCandidatos;

  getline(in, linha); //pulando primeira linha

  //LENDO ARQUIVO DE CANDIDATOS
  while (getline(in, linha))
  {

    stringstream s(linha);

    while (getline(s, palavra, ','))
    {
      vetorDados.push_back(palavra);
    }

    Candidato candidato(vetorDados);
    if (candidato.verificaDestinoVoto())
      listaDeCandidatos.push_back(candidato);

    vetorDados.clear();
  }
  in.close();

  //LENDO ARQUIVO DE PARTIDOS
  ifstream inPartido(argv[2]); // TODO verificar quando arquivo não abrir

  list<Partido> listaDePartidos;
  getline(inPartido, linha); //pulando a primeira linha

  while (getline(inPartido, linha))
  {

    stringstream s(linha);

    while (getline(s, palavra, ','))
    {
      vetorDados.push_back(palavra);
    }

    Partido partido(vetorDados, listaDeCandidatos);

    listaDePartidos.push_back(partido);
    vetorDados.clear();
  }
  inPartido.close();
  listaDePartidos.sort(ComparaPartidos());

  //CRIANDO ELEIÇÃO
  string data = argv[3];
  Eleicao eleicao(listaDeCandidatos, listaDePartidos, data);

  cout << "Número de vagas: " << eleicao.getNumeroTotalEleitos()
       << endl
       << endl;
  // eleicao.imprimelistaPartidos();

  eleicao.imprimeCandidatosEleitos(); //Siglas não estão atualizadas nessa lista
}