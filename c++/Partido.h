#include <string>
#include "Candidato.h"
using namespace std;

class Partido
{
private:
  unsigned numero;
  unsigned votosLegenda;
  unsigned totalCandidatosEleitos = 0;
  unsigned totalVotosNominais = 0;
  unsigned totalVotosPartido = 0;
  unsigned totalCandidatos = 0;
  string nomePartido;
  string sigla;
  // List<Candidato> listaCandidatos;

  Partido(string vetorDados[], List<Candidato> listaDeCandidatosValidos);

  void imprimePrimeiroUltimoPartido();
  void imprimeListaCandidatosDoPartido();

  unsigned verificaListaCandidatosVazia();
  Candidato buscaCandidatoPorPosicao(unsigned posicao);

  void setTotalCandidatos();

  unsigned getTotalCandidatos();
  void setTotalCandidatosEleitos();
  unsigned getTotalCandidatosEleitos();

  void setTotalVotosNominais();

  unsigned getTotalVotosNominais();
  void setTotalVotosPartido();
  unsigned gettotalVotosPartido();

  void setListaCandidatos(List<Candidato> listaDeCandidatosValidos);

  List<Candidato> getlistaCandidatos();

  void setNome(string nome);

  string getNome();
  void setNumero(unsigned numero);
  unsigned getNumero();
  void setSigla(string sigla);
  string getSigla();
  void setVotosLegenda(unsigned votosLegenda);
  unsigned getvotosLegenda();
}
