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

  void setSiglaPartido(const string &siglaPartido);

  const string &getSiglaPartido();

  void setDestinoVoto(const string &destinoVoto);

  const string &getDestinoVoto();

  void setDataNascimento(const string &dataNascimento);

  void setNome(const string &nome);

  const string &getNome();

  void setNomeUrna(const string &nomeUrna);

  const string &getNomeUrna();

  void setNumero(const unsigned &numero);

  const unsigned &getNumero();

  void setNumeroPartido(const unsigned &numeroPartido);

  const unsigned &getNumeroPartido();

  void setSexo(const char &sexo);

  const char &getSexo();

  void setIdade(const string &dataEleicao);

  const unsigned &getIdade();

  void setSituacao(const string &situacao);

  const string &getSituacao();

  void setVotosNominais(const unsigned &votosNominais);

  const unsigned &getVotosNominais();

  // const Date& getIdade();
  const string &getDataNascimento();

  void imprimeCandidato();

  const unsigned calculaIdadeCandidato(const string &dataEleicao, const string &dataNascimento);

  Candidato(const vector<string> &vetorDadosCandidato, const string &dataEleicao);

  ~Candidato();
};
class ComparaCandidatos
{
public:
  bool operator()(Candidato &candidato1, Candidato &candidato2);
  bool compare(string dataNascimentoCandidato1, string dataNascimentoCandidato2);
};
#endif // CANDIDATO_H
