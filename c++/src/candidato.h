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

  const string &getSiglaPartido();

  void setDestinoVoto(string destinoVoto);

  const string &getDestinoVoto();

  void setDataNascimento(string dataNascimento);

  void setNome(string nome);

  const string &getNome();

  void setNomeUrna(string nomeUrna);

  const string &getNomeUrna();

  void setNumero(unsigned numero);

  const unsigned &getNumero();

  void setNumeroPartido(unsigned numeroPartido);

  const unsigned &getNumeroPartido();

  void setSexo(char sexo);

  const char &getSexo();

  void setIdade(string &dataEleicao);

  const unsigned &getIdade();

  void setSituacao(string situacao);

  const string &getSituacao();

  void setVotosNominais(unsigned votosNominais);

  const unsigned &getVotosNominais();

  // const Date& getIdade();
  const string &getDataNascimento();

  void imprimeCandidato();

  unsigned calculaIdadeCandidato(string dataEleicao, string dataNascimento);

  Candidato(vector<string> vetorDadosCandidato, string &dataEleicao);

  ~Candidato();
};
class ComparaCandidatos
{
public:
  bool operator()(Candidato &candidato1, Candidato &candidato2);
  bool compare(string dataNascimentoCandidato1, string dataNascimentoCandidato2);
};
#endif // CANDIDATO_H
