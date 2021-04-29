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

bool ordenaPartidoPorVotos(Partido partido1, Partido partido2)
{
  if (partido1.getTotalVotosPartido() > partido2.getTotalVotosPartido())
    return true;
  else if (partido1.getTotalVotosPartido() < partido2.getTotalVotosPartido())
    return false;
  else
  {
    if (partido1.getNumero() < partido2.getNumero())
      return true;
    return false;
  }
}

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
      if (palavra == "\n")
        break;
    }

    Candidato candidato(vetorDados);
    if (candidato.verificaDestinoVoto())
      listaDeCandidatos.push_back(candidato);
    // candidato.imprimeCandidato();

    vetorDados.clear();
  }
  in.close();

  //IMPRIMINDO LISTA DE CANDIDATOS
  // for (auto candidato : listaDeCandidatos)
  // {
  //   candidato.imprimeCandidato();
  // }

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
      if (palavra == "\n")
        break;
    }

    Partido partido(vetorDados, listaDeCandidatos);
    // partido.imprimePartido();

    listaDePartidos.push_back(partido);
    vetorDados.clear();
  }

  // listaDePartidos.sort(ordenaPartidoPorVotos);

  inPartido.close();

  // cout << "IMPRIMINDO LISTA DE PARTIDOS!" << endl;

  // TODO testar assim:for (const auto& para w)
  for (auto partido : listaDePartidos)
  {
    // partido.imprimePartido();
    // cout << partido.getTotalVotosNominais() << endl;
    // break;
    // cout << partido.getNome() << endl;
    // if (partido.getTotalCandidatos() > 0)
    // {
    // Candidato candidato = partido.buscaCandidatoPorPosicao(0);
    // candidato.imprimeCandidato();
    // }
  }

  //CRIANDO ELEIÇÃO
  string data = argv[3];
  Eleicao eleicao(listaDeCandidatos, listaDePartidos, data);
  // cout << "Número de vagas: " << eleicao.getNumeroTotalEleitos() << endl;
}