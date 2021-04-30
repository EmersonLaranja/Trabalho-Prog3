#include "partido.h"

Partido::Partido() {}
Partido::~Partido() {}

Partido::Partido(vector<string> vetorDados, list<Candidato> &listaDeCandidatosValidos)
{
  string sigla = vetorDados[3];                //leitura Correta
  string nomePartido = vetorDados[2];          //leitura Correta
  unsigned votosLegenda = stoi(vetorDados[1]); //leitura Correta
  unsigned numero = stoi(vetorDados[0]);       //leitura Correta
  unsigned totalCandidatosEleitos = 0;
  unsigned totalVotosNominais = 0;
  unsigned totalVotosPartido = 0;
  unsigned totalCandidatos = 0;

  setSigla(sigla);
  setNome(nomePartido);
  setNumero(numero);
  setListaCandidatos(listaDeCandidatosValidos); //set correto
  setVotosLegenda(votosLegenda);                //set correto
  setTotalCandidatos();                         //set correto
  setTotalCandidatosEleitos();                  //set correto
  setTotalVotosNominais();                      //set correto
  setTotalVotosPartido();                       //set correto
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

bool ComparaPartidos::operator()(Partido partido1, Partido partido2)
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
