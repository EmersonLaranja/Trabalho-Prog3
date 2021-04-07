#include "Candidato.h";

Candidato::Candidato(string vetorDados[])
{
  this->setNumero(numero);
  this->setVotosNominais(votosNominais);
  this->setSituacao(situacao);
  this->setNome(nome);
  this->setSexo(sexo);
  this->setNomeUrna(nomeUrna);
  this->setDestinoVoto(destinoVoto);
  this->setNumeroPartido(numeroPartido);
  // this->setDataNascimento(dataNascimento);
};

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

string Candidato::getdestinoVoto()
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

string Candidato::getnomeUrna()
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

unsigned Candidato::getnumeroPartido()
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

unsigned Candidato::getvotosNominais()
{
  return votosNominais;
};

// void Candidato::setDataNascimento(string dataNascimento){
// };