#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <locale.h>
#include <vector>
#include <list>
#include <ctime>
#include "eleicao.h"
#include <algorithm>
using namespace std;

class Excecao
{
  string motivo;

public:
  Excecao(const string &motivo) { this->motivo = motivo; }
  friend ostream &operator<<(ostream &out, const Excecao &excecao);
};
ostream &operator<<(ostream &out, const Excecao &excecao)
{
  return out << excecao.motivo;
}

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "pt_BR.utf8");

  ifstream in(argv[1]); // TODO verificar quando arquivo não abrir

  if (!in.good())
  {
    cout << "Problemas ao ler arquivo de entrada de candidatos" << endl;
    return 0;
  }
  if (argc < 3)
  {
    cout << "Problemas ao ler data de entrada" << endl;
    return 0;
  }
  string dataEleicao = argv[3];

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

    Candidato candidato(vetorDados, dataEleicao);
    if (candidato.verificaDestinoVoto())
      listaDeCandidatos.push_back(candidato);

    vetorDados.clear();
  }
  listaDeCandidatos.sort(ComparaCandidatos());
  in.close();

  //LENDO ARQUIVO DE PARTIDOS
  ifstream inPartido(argv[2]); // TODO verificar quando arquivo não abrir

  if (!inPartido.good())
  {
    cout << "Problemas ao ler arquivo de entrada de partidos" << endl;
    return 0;
  }

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
  Eleicao eleicao(listaDeCandidatos, listaDePartidos, dataEleicao);

  //relatório 1
  cout << "Número de vagas: " << eleicao.getNumeroTotalEleitos()
       << endl
       << endl;

  //relatório 2
  eleicao.imprimeCandidatosEleitos();

  //relatório 3
  eleicao.imprimeListaCandidatosMaisVotadosPorLimiteVagas();

  //relatório 4
  eleicao.imprimeCandidatosBeneficiadosVotacaoMajoritaria();

  //relatório 5
  eleicao.imprimeCandidatosBeneficiadosVotacaoProporcional();

  //relatório 6
  eleicao.imprimeListaPartidos();

  //relatório 7
  eleicao.ordenaPrimeiroUltimoListaPartido();

  //relatório 8
  eleicao.imprimeCandidatosPorIdade();

  //relatório 9
  eleicao.imprimeCandidatosPorSexo();

  //relatório 10
  eleicao.imprimeVotosTotaisEleicao();

  return 0;
}