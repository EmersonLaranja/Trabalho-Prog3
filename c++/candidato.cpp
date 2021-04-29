#include "candidato.h"

Candidato::Candidato(){

};
Candidato::Candidato(vector<string> vetorDadosCandidato)
{
  unsigned numero = stoi(vetorDadosCandidato[0]);
  unsigned votosNominais = stoi(vetorDadosCandidato[1]);
  string situacao = vetorDadosCandidato[2];
  string nome = vetorDadosCandidato[3];
  string nomeUrna = vetorDadosCandidato[4];
  char sexo = vetorDadosCandidato[5].at(0);
  string dataNascimento = vetorDadosCandidato[6];
  string destinoVoto = vetorDadosCandidato[7];
  unsigned numeroPartido = stoi(vetorDadosCandidato[8]);
  // string siglaPartido = vetorDadosCandidato[]; //TODO quando tiver partido, voltar aqui
  this->setNumero(numero);
  this->setVotosNominais(votosNominais);
  this->setSituacao(situacao);
  this->setNome(nome);
  this->setSexo(sexo);
  this->setNomeUrna(nomeUrna);
  this->setDestinoVoto(destinoVoto);
  this->setNumeroPartido(numeroPartido);
  this->setDataNascimento(dataNascimento);
};

Candidato::~Candidato() {}

bool Candidato::verificaDestinoVoto()
{

  return this->destinoVoto == "Válido";
}

void Candidato::setSiglaPartido(string siglaPartido)
{
  this->siglaPartido = siglaPartido;
};

string Candidato::getSiglaPartido()
{
  return this->siglaPartido;
};

void Candidato::setDestinoVoto(string destinoVoto)
{
  this->destinoVoto = destinoVoto;
};

string Candidato::getDestinoVoto()
{
  return this->destinoVoto;
};

void Candidato::setNome(string nome)
{
  this->nome = nome;
};

string Candidato::getNome()
{
  return nome;
};

void Candidato::setNomeUrna(string nomeUrna)
{
  this->nomeUrna = nomeUrna;
};

string Candidato::getNomeUrna()
{
  return nomeUrna;
};

void Candidato::setNumero(unsigned numero)
{
  this->numero = numero;
};

unsigned Candidato::getNumero()
{
  return numero;
};

void Candidato::setNumeroPartido(unsigned numeroPartido)
{
  this->numeroPartido = numeroPartido;
};

unsigned Candidato::getNumeroPartido()
{
  return numeroPartido;
};

void Candidato::setSexo(char sexo)
{
  switch (sexo)
  {
  case 'M':
    this->sexo = MASCULINO;
    break;

  default:
    this->sexo = FEMININO;
    break;
  }
};

char Candidato::getSexo()
{
  return sexo;
};

void Candidato::setSituacao(string situacao)
{
  this->situacao = situacao;
};

string Candidato::getSituacao()
{
  return situacao;
};

void Candidato::setVotosNominais(unsigned votosNominais)
{
  this->votosNominais = votosNominais;
};

string Candidato::getDataNascimento()
{
  return dataNascimento;
};

void Candidato::setDataNascimento(string dataNascimento)
{
  this->dataNascimento = dataNascimento;
};

unsigned Candidato::getVotosNominais()
{
  return votosNominais;
};

void Candidato ::imprimeCandidato()
{
  cout << this->getNome() << " / "
       << this->getNomeUrna() << " ("
       << this->getSiglaPartido() << ", "
       << this->getVotosNominais();

  if (this->getVotosNominais() > 1)
    cout
        << " votos)" << endl;
  else
    cout << " voto)" << endl;
};

// ostream &operator<<(ostream &out, Candidato &candidato)
// {
//   out << candidato.getNumero() << " "
//       << candidato.getVotosNominais() << " "
//       << candidato.getSituacao() << " "
//       << candidato.getNome() << " "
//       << candidato.getNomeUrna() << " "
//       << candidato.getSexo() << " "
//       << candidato.getDataNascimento() << " "
//       << candidato.getDestinoVoto() << " "
//       << candidato.getNumeroPartido() << endl;
//   return out;
// }