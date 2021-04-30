#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#define MASCULINO 'M'
#define FEMININO 'F'
using namespace std;
class Candidato
{
private:
  unsigned numero;
  unsigned votosNominais;
  unsigned numeroPartido;
  unsigned idade;
  char sexo;
  string situacao;
  string destinoVoto;
  string nome;
  string nomeUrna;
  string siglaPartido;
  string dataNascimento;

public:
  Candidato(/* args */);

  bool verificaDestinoVoto();

  void setSiglaPartido(string &siglaPartido);

  string getSiglaPartido();

  void setDestinoVoto(string destinoVoto);

  string getDestinoVoto();

  void setDataNascimento(string dataNascimento);

  void setNome(string nome);

  string getNome();

  void setNomeUrna(string nomeUrna);

  string getNomeUrna();

  void setNumero(unsigned numero);

  unsigned getNumero();

  void setNumeroPartido(unsigned numeroPartido);

  unsigned getNumeroPartido();

  void setSexo(char sexo);

  char getSexo();

  void setIdade(string &dataEleicao);

  int getIdade();

  void setSituacao(string situacao);

  string getSituacao();

  void setVotosNominais(unsigned votosNominais);

  unsigned getVotosNominais();

  // Date getIdade();
  string getDataNascimento();

  void imprimeCandidato();

  int calculaIdadeCandidato(string dataEleicao, string dataNascimento);

  Candidato(vector<string> vetorDadosCandidato, string &dataEleicao);

  ~Candidato();
};
// class ComparaIdades
// {
// public:
//   bool compare(string dataNascimentoCandidato1, string dataNascimentoCandidato2);
// };

class ComparaCandidatos
{
public:
  bool operator()(Candidato candidato1, Candidato candidato2);
  bool compare(string dataNascimentoCandidato1, string dataNascimentoCandidato2);
};
#endif // CANDIDATO_H
