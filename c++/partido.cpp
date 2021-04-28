#include "partido.h"

Partido::Partido() {}
Partido::~Partido() {}

Partido::Partido(vector<string> vetorDados, list<Candidato> listaDeCandidatosValidos)
{
  unsigned numero = stoi(vetorDados[0]);
  unsigned votosLegenda = stoi(vetorDados[1]);
  string nomePartido = vetorDados[2];
  string sigla = vetorDados[3];
  unsigned totalCandidatosEleitos = 0;
  unsigned totalVotosNominais = 0;
  unsigned totalVotosPartido = 0;
  unsigned totalCandidatos = 0;
  this->setListaCandidatos(listaDeCandidatosValidos);
  this->setNumero(numero);
  this->setVotosLegenda(votosLegenda);
  this->setTotalCandidatosEleitos();
  this->setTotalVotosNominais();
  this->setTotalVotosPartido();
  this->setTotalCandidatos();
  this->setNome(nomePartido);
  this->setSigla(sigla);
}

void Partido::imprimePartido()
{
  cout << this->getNumero() << " "
       << this->getVotosLegenda() << " "
       << this->gettotalVotosPartido() << " "
       << this->getTotalCandidatos() << " "
       << this->getTotalVotosNominais() << " "
       << this->getNome() << " "
       << this->getSigla() << endl;
}

void Partido::imprimePrimeiroUltimoPartido() {}

void Partido::imprimeListaCandidatosDoPartido()
{
  unsigned i = 1;
  for (Candidato candidato : listaCandidatos)
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
}

unsigned Partido::verificaListaCandidatosVazia()
{
  if (listaCandidatos.empty())
    return 1;

  return 0;
}
unsigned Partido::getTotalCandidatos()
{
  return this->totalCandidatos;
}
unsigned Partido::getTotalCandidatosEleitos()
{
  return this->totalCandidatosEleitos;
}
unsigned Partido::getTotalVotosNominais()
{
  return this->totalVotosNominais;
}
unsigned Partido::gettotalVotosPartido()
{
  return this->totalVotosPartido;
}
unsigned Partido::getNumero()
{
  return this->numero;
}
unsigned Partido::getVotosLegenda()
{
  return this->votosLegenda;
}

string Partido::getNome() { return this->nomePartido; }
string Partido::getSigla() { return this->sigla; }
list<Candidato> Partido::getlistaCandidatos() { return this->listaCandidatos; }

void Partido::setTotalCandidatos()
{
  this->totalCandidatos = this->listaCandidatos.size();
}
void Partido::setTotalCandidatosEleitos()
{
  for (Candidato candidato : listaCandidatos)
  {
    candidato.getSituacao();
  }
}
void Partido::setTotalVotosNominais()
{
  for (Candidato candidato : listaCandidatos)
  {
    this->totalVotosNominais += candidato.getVotosNominais();
  }
}
void Partido::setTotalVotosPartido()
{
  this->totalVotosPartido = this->totalVotosNominais + this->votosLegenda;
}

void Partido::setListaCandidatos(list<Candidato> listaDeCandidatosValidos)
{
  for (Candidato candidato : listaDeCandidatosValidos)
  {
    if (candidato.getNumeroPartido() == this->numero)
    {
      this->listaCandidatos.push_back(candidato);
      candidato.setSiglaPartido(this->sigla);
    }
  }
}
void Partido::setNumero(unsigned numero)
{
  this->numero = numero;
}
void Partido::setSigla(string sigla)
{
  this->sigla = sigla;
}
void Partido::setVotosLegenda(unsigned votosLegenda)
{
  this->votosLegenda = votosLegenda;
}
void Partido::setNome(string nome)
{
  this->nomePartido = nome;
}

Candidato Partido::buscaCandidatoPorPosicao(unsigned &posicao)
{
  auto aux = listaCandidatos.begin();
  advance(aux, posicao);
  return *aux;

  // int i = 0;
  // for (auto candidato : listaCandidatos)
  // {
  //   if (posicao == i)
  //     return candidato;

  //   i++;
  // }
}