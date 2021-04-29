#include "partido.h"

Partido::Partido() {}
Partido::~Partido() {}

Partido::Partido(vector<string> vetorDados, list<Candidato> listaDeCandidatosValidos)
{
  unsigned numero = stoi(vetorDados[0]);
  unsigned votosLegenda = stoi(vetorDados[1]);
  string nomePartido = vetorDados[2];
  string sigla = vetorDados[3];
  this->setNome(nomePartido);
  this->setSigla(sigla);
  this->setListaCandidatos(listaDeCandidatosValidos);
  this->setNumero(numero);
  this->setTotalCandidatos();
  this->setTotalCandidatosEleitos();
  this->setVotosLegenda(votosLegenda);
  this->setTotalVotosPartido();
  this->setTotalVotosNominais();
}

void Partido::imprimePartido()
{
  cout << "Numero: " << this->getNumero() << " "
       << this->getVotosLegenda() << " Total: "
       << this->getTotalVotosPartido() << " "
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
unsigned Partido::getTotalVotosPartido()
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
list<Candidato> Partido::getListaCandidatos() { return this->listaCandidatos; }

void Partido::setTotalCandidatos()
{
  this->totalCandidatos = 0;
  this->totalCandidatos = this->listaCandidatos.size();
}
void Partido::setTotalCandidatosEleitos() //TODO q?
{
  for (Candidato candidato : listaCandidatos)
  {
    candidato.getSituacao();
  }
}
void Partido::setTotalVotosNominais()
{
  this->totalVotosNominais = 0;
  for (Candidato candidato : listaCandidatos)
  {
    // candidato.imprimeCandidato();
    this->totalVotosNominais += candidato.getVotosNominais();
    // cout << candidato.getNome() << " " << candidato.getVotosNominais() << endl;
  }
  // cout << this->getNome() << " " << this->getTotalVotosNominais() << endl;
}
void Partido::setTotalVotosPartido()
{
  this->totalVotosPartido = 0;
  this->totalVotosPartido = this->getTotalVotosNominais() + this->getVotosLegenda();
  // cout << "Nominais " << this->totalVotosNominais << " "
  //  << "Legenda " << this->votosLegenda << endl;
}

void Partido::setListaCandidatos(list<Candidato> listaDeCandidatosValidos)
{
  for (auto candidato : listaDeCandidatosValidos)
  {
    candidato.imprimeCandidato();
    break;
  }
  cout << "OPAAAA" << endl;
  for (Candidato candidato : listaDeCandidatosValidos)
  {
    if (candidato.getNumeroPartido() == this->numero)
    {
      candidato.imprimeCandidato();
      break;
      // cout << candidato.getNome() << " " << candidato.getVotosNominais()
      //      << " NP: " << this->nomePartido << endl;
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
  this->votosLegenda = 0;
  this->votosLegenda = votosLegenda;
}
void Partido::setNome(string nome)
{
  this->nomePartido = nome;
}

bool Partido::ordenaPartidoPorVotos(Partido partido)
{
  if (this->totalVotosPartido > partido.getTotalVotosPartido())
    return true;
  else if (this->totalVotosPartido < partido.getTotalVotosPartido())
    return false;
  else
  {
    if (this->numero < partido.getNumero())
      return true;
    return false;
  }
}

Candidato Partido::buscaCandidatoPorPosicao(unsigned posicao)
{
  // auto aux = listaCandidatos.begin();
  // advance(aux, posicao);
  // return *aux;
  Candidato candidato;
  int i = 0;
  //TODO: corrigir a declaração do candidato
  for (auto candidato : listaCandidatos)
  {
    if (posicao == i)
      return candidato;
    i++;
  }
  cout << "Não encontrou candidato!" << endl;
  return candidato;
}