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

  Partido(vector<string> vetorDadosCandidato, list<Candidato> listaDeCandidatosValidos);

  void imprimePartido();
  void imprimePrimeiroUltimoPartido();
  void imprimeListaCandidatosDoPartido();

  unsigned verificaListaCandidatosVazia();
  unsigned getTotalCandidatos();
  unsigned getTotalCandidatosEleitos();
  unsigned getTotalVotosNominais();
  unsigned getTotalVotosPartido();
  unsigned getNumero();
  unsigned getVotosLegenda();

  string getNome();
  string getSigla();

  void setTotalCandidatos();
  void setTotalCandidatosEleitos();
  void setTotalVotosNominais();
  void setTotalVotosPartido();
  void setListaCandidatos(list<Candidato> listaDeCandidatosValidos);
  void setNumero(unsigned numero);
  void setSigla(string sigla);
  void setVotosLegenda(unsigned votosLegenda);
  void setNome(string nome);
  bool ordenaPartidoPorVotos(Partido partido);

  Candidato buscaCandidatoPorPosicao(unsigned posicao);
  list<Candidato> getListaCandidatos();
};

#endif // PARTIDO_H
