#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;
class Candidato
{
private:
  unsigned numero;
  unsigned votosNominais;
  unsigned numeroPartido;
  char sexo;
  string situacao;
  string destinoVoto;
  string nome;
  string nomeUrna;
  string siglaPartido;
  string dataNascimento;
  // LocalDate dataNascimento;
  // Date idade;
  const char MASCULINO = 'M';
  const char FEMININO = 'F';

public:
  Candidato(/* args */);

  bool verificaDestinoVoto();

  void setSiglaPartido(string siglaPartido);

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

  void setSituacao(string situacao);

  string getSituacao();

  void setVotosNominais(unsigned votosNominais);

  unsigned getVotosNominais();

  // Date getIdade();
  string getDataNascimento();

  void imprimeCandidato();

  Candidato(vector<string> vetorDadosCandidato);

  ~Candidato();
};

#endif // CANDIDATO_H
