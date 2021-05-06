#include "partido.h"

Partido::Partido() {}
Partido::~Partido() {}

Partido::Partido(const vector<string> &vetorDadosCandidato, list<Candidato> &listaDeCandidatosValidos)
{
  string sigla = vetorDadosCandidato[3];
  string nomePartido = vetorDadosCandidato[2];
  unsigned votosLegenda = stoi(vetorDadosCandidato[1]);
  unsigned numero = stoi(vetorDadosCandidato[0]);

  setSigla(sigla);
  setNome(nomePartido);
  setNumero(numero);
  setListaCandidatos(listaDeCandidatosValidos);
  setVotosLegenda(votosLegenda);
  setTotalCandidatos();
  setTotalCandidatosEleitos();
  setTotalVotosNominais();
  setTotalVotosPartido();
}

void Partido::imprimePartido()
{
  cout << this->getSigla() << " - "
       << this->getNumero() << ", ";

  if (this->getTotalVotosPartido() > 1)
  {
    cout << this->getTotalVotosPartido() << " votos (";
  }
  else
  {
    cout << this->getTotalVotosPartido() << " voto (";
  }

  if (this->getTotalVotosNominais() > 1)
  {
    cout << this->getTotalVotosNominais() << " nominais e ";
  }
  else
  {
    cout << this->getTotalVotosNominais() << " nominal e ";
  }
  cout
      << this->getVotosLegenda() << " de legenda), ";

  if (this->getTotalCandidatosEleitos() > 1)
  {
    cout << this->getTotalCandidatosEleitos() << " candidatos eleitos" << endl;
  }
  else
  {
    cout << this->getTotalCandidatosEleitos() << " candidato eleito" << endl;
  }
}

void Partido::imprimePrimeiroUltimoPartido()
{
  cout << this->getSigla() << " - " << this->getNumero() << ", ";
  if (this->listaCandidatos.size() > 0)
  {
    Candidato aux;

    // -----------------------PRIMEIRO-----------------------------------
    aux = listaCandidatos.front();

    if (aux.getVotosNominais() > 1)
      cout
          << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " votos) / ";
    else
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " voto) / ";

    // -----------------------ULTIMO-----------------------------------
    aux = listaCandidatos.back();

    if (aux.getVotosNominais() > 1)
      cout
          << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " votos)";
    else
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " voto)";
  }

  cout << endl;
}

void Partido::imprimeListaCandidatosDoPartido()
{
  unsigned i = 1;
  for (Candidato &candidato : listaCandidatos)
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
}

const unsigned &Partido::getTotalCandidatos()
{
  return this->totalCandidatos;
}
const unsigned &Partido::getTotalCandidatosEleitos()
{
  return this->totalCandidatosEleitos;
}
const unsigned &Partido::getTotalVotosNominais()
{
  return this->totalVotosNominais;
}
const unsigned &Partido::getTotalVotosPartido()
{
  return this->totalVotosPartido;
}
const unsigned &Partido::getNumero()
{
  return this->numero;
}
const unsigned &Partido::getVotosLegenda()
{
  return this->votosLegenda;
}

const string &Partido::getNome() { return this->nomePartido; }
const string &Partido::getSigla() { return this->sigla; }
const list<Candidato> &Partido::getListaCandidatos() { return this->listaCandidatos; }

void Partido::setTotalCandidatos()
{
  this->totalCandidatos = 0;
  this->totalCandidatos = this->listaCandidatos.size();
}
void Partido::setTotalCandidatosEleitos()
{
  unsigned contador = 0;

  for (Candidato &candidato : listaCandidatos)
    if (candidato.getSituacao() == "Eleito")
      contador++;

  this->totalCandidatosEleitos = contador;
}
void Partido::setTotalVotosNominais()
{
  unsigned contador = 0;
  for (Candidato &candidato : listaCandidatos)
  {
    contador += candidato.getVotosNominais();
  }
  this->totalVotosNominais = contador;
}
void Partido::setTotalVotosPartido()
{
  this->totalVotosPartido = this->totalVotosNominais + this->votosLegenda;
}

void Partido::setListaCandidatos(list<Candidato> &listaDeCandidatosValidos)
{
  for (Candidato &candidato : listaDeCandidatosValidos)
  {
    if (candidato.getNumeroPartido() == this->numero)
    {
      candidato.setSiglaPartido(this->sigla);
      this->listaCandidatos.push_back(candidato);
    }
  }
}
void Partido::setNumero(const unsigned &numero)
{
  this->numero = numero;
}
void Partido::setSigla(const string &sigla)
{
  this->sigla = sigla;
}
void Partido::setVotosLegenda(const unsigned &votosLegenda)
{
  this->votosLegenda = votosLegenda;
}
void Partido::setNome(const string &nome)
{
  this->nomePartido = nome;
}

//todo static ver
bool Partido::ordenaPartidoPorVotos(const Partido &partido)
{
  if (this->totalVotosPartido > partido.totalVotosPartido)
    return true;
  else if (this->totalVotosPartido < partido.totalVotosPartido)
    return false;
  else
  {
    if (this->numero < partido.numero)
      return true;
    return false;
  }
}
Candidato Partido::buscaCandidatoPorPosicao(const unsigned &posicao)
{
  Candidato aux;
  unsigned i = 0;
  for (Candidato &candidato : listaCandidatos)
  {
    if (posicao == i)
    {
      aux = candidato;
    }
    i++;
  }
  return aux;
}

//! BUG COM CONST
bool ComparaPartidos::operator()(Partido &partido1, Partido &partido2)
{
  if (partido1.getTotalVotosPartido() > partido2.getTotalVotosPartido())
    return true;
  else if (partido1.getTotalVotosPartido() < partido2.getTotalVotosPartido())
    return false;
  else
  {
    if (partido1.getNumero() < partido2.getNumero())
      return true;
    return false;
  }
}
