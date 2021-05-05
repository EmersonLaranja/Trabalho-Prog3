#if !defined(ELEICAO_H)
#define ELEICAO_H
#include "partido.h"
#include <iterator>
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
  float calculaPercentual(unsigned &quant, unsigned &total);

public:
  Eleicao();

  Eleicao(list<Candidato> &listaDeCandidatosValidos, list<Partido> &listaDePartidos, string &data);

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
  void imprimeListaCandidatos(list<Candidato> &lista);
  void imprimePreservandoPosicaoMaisVotados(list<Candidato> &lista);
  void imprimeBeneficiadosPresentesLista1AusentesLista2(list<Candidato> &lista1, list<Candidato> &lista2);

  void setNumeroTotalEleitos();
  void setDataEleicao(string &data);
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
  bool compare(unsigned numeroPartidario1, unsigned numeroPartidario2);
};

#endif // ELEICAO_H
