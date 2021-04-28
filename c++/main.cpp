#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "partido.h"

using namespace std;

int main(int argc, char const *argv[])
{

  ifstream in("candidatos.csv"); // TODO verificar quando arquivo não abrir

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
      if (palavra == "\n")
        break;
    }

    Candidato candidato(vetorDados);
    if (candidato.verificaDestinoVoto())
      listaDeCandidatos.push_back(candidato);

    vetorDados.clear();
  }
  in.close();

  //IMPRIMINDO LISTA DE CANDIDATOS
  // for (auto candidato : listaDeCandidatos)
  // {
  //   candidato.imprimeCandidato();
  // }

  //LENDO ARQUIVO DE PARTIDOS
  ifstream inPartido("partidos.csv"); // TODO verificar quando arquivo não abrir

  list<Partido> listaDePartidos;

  getline(inPartido, linha); //pulando a primeira linha

  while (getline(inPartido, linha))
  {

    stringstream s(linha);

    while (getline(s, palavra, ','))
    {
      vetorDados.push_back(palavra);
      if (palavra == "\n")
        break;
    }

    Partido partido(vetorDados, listaDeCandidatos);
    
    listaDePartidos.push_back(partido);
    vetorDados.clear();
  }

  inPartido.close();

  // cout << "IMPRIMINDO LISTA DE PARTIDOS!" << endl;

  // todo testar assim:    for (const auto& par : w)
  // for (auto partido : listaDePartidos)
  // {
  //   partido.imprimePartido();
  // }
}