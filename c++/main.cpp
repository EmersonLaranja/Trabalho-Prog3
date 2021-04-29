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
    // candidato.imprimeCandidato();

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
    // partido.imprimePartido();

    listaDePartidos.push_back(partido);
    vetorDados.clear();
  }
<<<<<<< HEAD

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
=======
  inPartido.close();
  listaDePartidos.sort(ComparaPartidos());
>>>>>>> c891e9aff17cf750766af77d79a2da3b203de238

  //CRIANDO ELEIÇÃO
  string data = argv[3];
  Eleicao eleicao(listaDeCandidatos, listaDePartidos, data);
<<<<<<< HEAD
  // cout << "Número de vagas: " << eleicao.getNumeroTotalEleitos() << endl;
=======

  cout << "Número de vagas: " << eleicao.getNumeroTotalEleitos()
       << endl
       << endl;
  // eleicao.imprimelistaPartidos();

  eleicao.imprimeCandidatosEleitos(); //Siglas não estão atualizadas nessa lista
>>>>>>> c891e9aff17cf750766af77d79a2da3b203de238
}