#if !defined(ELEICAO_H)
#define ELEICAO_H

#include "partido.h"
#include <iterator>
class Eleicao
{

  int numeroTotalEleitos;
  int totalVotosNominais;
  int totalVotosLegenda;
  int totalVotosValidos;

  list<Candidato> listaDeCandidatosValidos;
  list<Candidato> listaDeCandidatosMaisVotados;
  list<Candidato> listaDeCandidatosMaisVotadosEleitos;
  list<Partido> listaDePartidos;
  string dataEleicao; //TODO mudar para locale
  float calculaPercentual(unsigned quant, unsigned total);

public:
  Eleicao();

  Eleicao(list<Candidato> &listaDeCandidatosValidos, list<Partido> &listaDePartidos, string &data);

  ~Eleicao();

  // int calculaIdadeCandidato(LocalDate nascimento, LocalDate diaEleicao); //TODO: Quando usarmos LocaleDate

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
  int getNumeroTotalEleitos();
  void setDataEleicao(string &data);
  void setListaMaisVotados();
  void setListaMaisVotadosEleitos();
  string getNomePartidoPorNumero(int &numero);
  list<Partido> getListaDePartidos();
  list<Candidato> getListaDeCandidatosMaisVotadosEleitos();
  list<Candidato> getListaDeCandidatosMaisVotados();
  void setTotalVotosLegenda();
  int getTotalVotosLegenda();
  int getTotalVotosNominais();
  void setTotalVotosNominais();
  void setTotalVotosValidos();
  int getTotalVotosValidos();
};

#endif // ELEICAO_H
