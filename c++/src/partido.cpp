#include "partido.h"

Partido::Partido() {}
Partido::~Partido() {}

Partido::Partido(vector<string> vetorDados, list<Candidato> &listaDeCandidatosValidos)
{
  string sigla = vetorDados[3];
  string nomePartido = vetorDados[2];
  unsigned votosLegenda = stoi(vetorDados[1]);
  unsigned numero = stoi(vetorDados[0]);
  unsigned totalCandidatosEleitos = 0;
  unsigned totalVotosNominais = 0;
  unsigned totalVotosPartido = 0;
  unsigned totalCandidatos = 0;

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

    //------ GAMBIARRA TIME-------- //!Tirar isso aqui, pelo amor de Deus kkk
    for (auto candidato : listaCandidatos)
    {
      aux = candidato;
      break;
    }

    if (aux.getVotosNominais() > 1)
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " votos) / ";
    else
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " voto) / ";

    //------ GAMBIARRA TIME-------- //!Tirar isso aqui, pelo amor de Deus kkk
    unsigned i = 0;
    for (auto candidato : listaCandidatos)
    {
      if (i == listaCandidatos.size() - 1)
      {

        aux = candidato;
        break;
      }
      i++;
    }

    if (aux.getVotosNominais() > 1)
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " votos)";
    else
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " voto)";
  }

  cout << endl;
}

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

  for (Candidato candidato : listaCandidatos)
    if (candidato.getSituacao() == "Eleito")
      contador++;

  this->totalCandidatosEleitos = contador;
}
void Partido::setTotalVotosNominais()
{
  unsigned contador = 0;
  for (Candidato candidato : listaCandidatos)
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
  for (Candidato &candidato : listaDeCandidatosValidos) //Adicionando o "&" vc altera a lista principal
  {
    if (candidato.getNumeroPartido() == this->numero)
    {
      candidato.setSiglaPartido(this->sigla);
      this->listaCandidatos.push_back(candidato);
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
  Candidato aux;
  unsigned i = 0;
  //TODO: corrigir a declaração do candidato
  for (auto candidato : listaCandidatos)
  {
    if (posicao == i)
    {
      aux = candidato;
    }
    i++;
  }
  return aux;
}

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
