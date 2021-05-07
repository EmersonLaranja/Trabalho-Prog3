#if !defined(ELEICAO_H)
#define ELEICAO_H

#include "NumberUtils.h"
#include "Partido.h"

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

  const double calculaPercentual(const unsigned &quant, const unsigned &total) const;
  static bool ordenaPartidosPorVotosNominais(const Partido &partido1, const Partido &partido2);
  static bool comparaNumeroPartidario(const unsigned &numeroPartidario1, const unsigned &numeroPartidario2);

public:
  Eleicao();
  Eleicao(const list<Candidato> &listaDeCandidatosValidos, const list<Partido> &listaDePartidos, const string &data);
  void ordenaPrimeiroUltimoListaPartido();

  // --------------imprimir---------------//
  void imprimeNumeroVagas();
  void imprimeVotosTotaisEleicao();
  void imprimeCandidatosEleitos();
  void imprimeListaCandidatosMaisVotadosPorLimiteVagas();
  void imprimeCandidatosBeneficiadosVotacaoMajoritaria();
  void imprimeCandidatosBeneficiadosVotacaoProporcional();
  void imprimeCandidatosPorIdade();
  void imprimeCandidatosPorSexo();
  void imprimeListaPartidos();
  void imprimeListaCandidatos(const list<Candidato> &lista);
  void imprimePreservandoPosicaoMaisVotados(list<Candidato> &lista);
  void imprimeBeneficiadosPresentesLista1AusentesLista2(const list<Candidato> &lista1, const list<Candidato> &lista2);

  //------------------setters-----------------
  void setNumeroTotalEleitos();
  void setDataEleicao(const string &data);
  void setListaMaisVotados();
  void setListaMaisVotadosEleitos();
  void setTotalVotosLegenda();
  void setTotalVotosNominais();
  void setTotalVotosValidos();

  //-------------getters---------------------
  const unsigned &getNumeroTotalEleitos() const;
  const list<Partido> &getListaDePartidos() const;
  const list<Candidato> &getListaDeCandidatosMaisVotadosEleitos() const;
  const list<Candidato> &getListaDeCandidatosMaisVotados() const;
  const unsigned &getTotalVotosLegenda() const;
  const unsigned &getTotalVotosNominais() const;
  const unsigned &getTotalVotosValidos() const;

  ~Eleicao();
};

#endif // ELEICAO_H
