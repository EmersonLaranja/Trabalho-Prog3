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

  Partido(vector<string> vetorDadosCandidato, list<Candidato> &listaDeCandidatosValidos);

  void imprimePartido();
  void imprimePrimeiroUltimoPartido();
  void imprimeListaCandidatosDoPartido();

  unsigned verificaListaCandidatosVazia();
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
  void setNumero(unsigned numero);
  void setSigla(string sigla);
  void setVotosLegenda(unsigned votosLegenda);
  void setNome(string nome);
  bool ordenaPartidoPorVotos(Partido partido);

  Candidato buscaCandidatoPorPosicao(unsigned posicao);
};

class ComparaPartidos
{
public:
  bool operator()(Partido &partido1, Partido &partido2);
};

#endif // PARTIDO_H
