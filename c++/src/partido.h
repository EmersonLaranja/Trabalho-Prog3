#if !defined(PARTIDO_H)
#define PARTIDO_H

#include "candidato.h"

using namespace std;

class Partido
{
  unsigned numero;
  unsigned votosLegenda;
  unsigned totalCandidatosEleitos;
  unsigned totalVotosNominais;
  unsigned totalVotosPartido;
  unsigned totalCandidatos;
  string nomePartido;
  string sigla;
  list<Candidato> listaCandidatos;

public:
  Partido();
  ~Partido();

  Partido(const vector<string> &vetorDadosCandidato, list<Candidato> &listaDeCandidatosValidos);

  void imprimePartido();
  void imprimePrimeiroUltimoPartido();
  void imprimeListaCandidatosDoPartido();

  const unsigned &getTotalCandidatos();
  const unsigned &getTotalCandidatosEleitos();
  const unsigned &getTotalVotosNominais();
  const unsigned &getTotalVotosPartido();
  const unsigned &getNumero();
  const unsigned &getVotosLegenda();
  const string &getNome();
  const string &getSigla();
  const list<Candidato> &getListaCandidatos();

  void setTotalCandidatos();
  void setTotalCandidatosEleitos();
  void setTotalVotosNominais();
  void setTotalVotosPartido();
  void setListaCandidatos(list<Candidato> &listaDeCandidatosValidos);
  void setNumero(const unsigned &numero);
  void setSigla(const string &sigla);
  void setVotosLegenda(const unsigned &votosLegenda);
  void setNome(const string &nome);
  bool ordenaPartidoPorVotos(const Partido &partido);
  Candidato buscaCandidatoPorPosicao(const unsigned &posicao);
};

class ComparaPartidos
{
public:
  bool operator()(Partido &partido1, Partido &partido2);
};

#endif // PARTIDO_H
