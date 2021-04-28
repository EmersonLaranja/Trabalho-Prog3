#if !defined(ELEICAO_H)
#define ELEICAO_H

#include "partido.h"
class Eleicao
{

  int numeroTotalEleitos;
  int totalVotosNominais;
  int totalVotosLegenda;
  int totalVotosValidos;

  list<Candidato> listaDeCandidatosValidos;
  list<Candidato> listaDeCandidatosMaisVotadosEleitos;
  list<Candidato> listaDeCandidatosMaisVotados;
  list<Partido> listaDePartidos;
  string dataEleicao; //TODO mudar para locale
  string calculaPercentual(unsigned quant, unsigned total);

public:
  Eleicao();

  Eleicao(list<Candidato> listaDeCandidatosValidos, list<Partido> listaDePartidos, string data);

  ~Eleicao();

  // int calculaIdadeCandidato(LocalDate nascimento, LocalDate diaEleicao); //TODO: Quando usarmos LocaleDate

  void ordenaPrimeiroUltimolistaPartido();
  // --------------Imprimir---------------//
  void imprimeVotosTotaisEleicao();
  void imprimeCandidatosEleitos();
  void imprimelistaCandidatosValidos();
  void imprimelistaCandidatosMaisVotadosPorLimiteVagas();
  void imprimeCandidatosBeneficiadosVotacaoMajoritaria();
  void imprimeCandidatosBeneficiadosVotacaoProporcional();
  void imprimeCandidatosPorIdade();
  void imprimeCandidatosPorSexo();
  void imprimelistaPartidos();
  void imprimelistaCandidatos(list<Candidato> lista);
  void imprimePreservandoPosicaoMaisVotados(list<Candidato> lista);
  void imprimeBeneficiadosPresenteslista1Ausenteslista2(list<Candidato> lista1, list<Candidato> lista2);
  void setNumeroTotalEleitos();
  int getNumeroTotalEleitos();
  void setDataEleicao(string data);
  void setlistaMaisVotados();
  void setlistaMaisVotadosEleitos();
  string getNomePartidoPorNumero(int numero);
  list<Partido> getlistaDePartidos();
  list<Candidato> getlistaDeCandidatosMaisVotadosEleitos();
  list<Candidato> getlistaDeCandidatosMaisVotados();
  void setTotalVotosLegenda();
  int getTotalVotosLegenda();
  int getTotalVotosNominais();
  void setTotalVotosNominais();
  void setTotalVotosValidos();
  int getTotalVotosValidos();
};

#endif // ELEICAO_H
