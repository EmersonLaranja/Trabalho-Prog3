#if !defined(ELEICAO_H)
#define ELEICAO_H

#include "NumberUtils.h"
#include "partido.h"
#include <iterator>
using namespace std;

class Eleicao
{

  unsigned numeroTotalEleitos;
  unsigned totalVotosNominais;
  unsigned totalVotosLegenda;
  unsigned totalVotosValidos;

  list<Candidato> listaDeCandidatosValidos;
  list<Candidato> listaDeCandidatosMaisVotados;
  list<Candidato> listaDeCandidatosMaisVotadosEleitos;
  list<Partido> listaDePartidos;
  string dataEleicao;

  const double calculaPercentual(const unsigned &quant, const unsigned &total);

public:
  Eleicao();

  Eleicao(const list<Candidato> &listaDeCandidatosValidos, const list<Partido> &listaDePartidos, const string &data);

  ~Eleicao();

  void ordenaPrimeiroUltimoListaPartido();
  // --------------Imprimir---------------//
  void imprimeVotosTotaisEleicao();
  void imprimeCandidatosEleitos();
  void imprimeListaCandidatosValidos();
  void imprimeListaCandidatosMaisVotadosPorLimiteVagas();
  void imprimeCandidatosBeneficiadosVotacaoMajoritaria();
  void imprimeCandidatosBeneficiadosVotacaoProporcional();
  void imprimeCandidatosPorIdade();
  void imprimeCandidatosPorSexo();
  void imprimeListaPartidos();
  void imprimeListaCandidatos(const list<Candidato> &lista);
  void imprimePreservandoPosicaoMaisVotados(list<Candidato> &lista);

  void imprimeBeneficiadosPresentesLista1AusentesLista2(list<Candidato> &lista1, list<Candidato> &lista2);

  void setNumeroTotalEleitos();
  void setDataEleicao(const string &data);
  void setListaMaisVotados();
  void setListaMaisVotadosEleitos();
  void setTotalVotosLegenda();
  void setTotalVotosNominais();
  void setTotalVotosValidos();

  const unsigned &getNumeroTotalEleitos();
  const list<Partido> &getListaDePartidos();
  const list<Candidato> &getListaDeCandidatosMaisVotadosEleitos();
  const list<Candidato> &getListaDeCandidatosMaisVotados();
  const unsigned &getTotalVotosLegenda();
  const unsigned &getTotalVotosNominais();
  const unsigned &getTotalVotosValidos();
};

class OrdenaPrimeiroUltimoListaPartido
{
public:
  bool operator()(Partido &partido1, Partido &partido2);
  bool compare(const unsigned &numeroPartidario1, const unsigned &numeroPartidario2);
};

#endif // ELEICAO_H
