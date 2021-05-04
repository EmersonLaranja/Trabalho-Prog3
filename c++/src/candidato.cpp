#include "candidato.h"

Candidato::Candidato(){

};
Candidato::Candidato(vector<string> vetorDadosCandidato, string &dataEleicao)
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
  this->setIdade(dataEleicao);
};

Candidato::~Candidato() {}

bool Candidato::verificaDestinoVoto()
{

  return this->destinoVoto == "Válido";
}

void Candidato::setSiglaPartido(string &siglaPartido)
{
  this->siglaPartido = siglaPartido;
};

const string &Candidato::getSiglaPartido()
{
  return this->siglaPartido;
};

void Candidato::setDestinoVoto(string destinoVoto)
{
  this->destinoVoto = destinoVoto;
};

const string &Candidato::getDestinoVoto()
{
  return this->destinoVoto;
};

void Candidato::setNome(string nome)
{
  this->nome = nome;
};

const string &Candidato::getNome()
{
  return nome;
};

void Candidato::setNomeUrna(string nomeUrna)
{
  this->nomeUrna = nomeUrna;
};

const string &Candidato::getNomeUrna()
{
  return nomeUrna;
};

void Candidato::setNumero(unsigned numero)
{
  this->numero = numero;
};

const unsigned &Candidato::getNumero()
{
  return numero;
};

void Candidato::setNumeroPartido(unsigned numeroPartido)
{
  this->numeroPartido = numeroPartido;
};

const unsigned &Candidato::getNumeroPartido()
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

const char &Candidato::getSexo()
{
  return sexo;
};

void Candidato::setIdade(string &dataEleicao)
{
  this->idade = calculaIdadeCandidato(dataEleicao, this->getDataNascimento());
};

const unsigned &Candidato::getIdade()
{
  return this->idade;
};

void Candidato::setSituacao(string situacao)
{
  this->situacao = situacao;
};

const string &Candidato::getSituacao()
{
  return situacao;
};

void Candidato::setVotosNominais(unsigned votosNominais)
{
  this->votosNominais = votosNominais;
};

const string &Candidato::getDataNascimento()
{
  return dataNascimento;
};

void Candidato::setDataNascimento(string dataNascimento)
{
  this->dataNascimento = dataNascimento;
};

const unsigned &Candidato::getVotosNominais()
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

unsigned Candidato ::calculaIdadeCandidato(string dataEleicao, string dataNascimento)
{
  string data, linha;
  vector<unsigned> vetorDataEleicao;
  vector<unsigned> vetorDataNascimento;

  stringstream s1(dataEleicao);
  while (getline(s1, data, '/')) //Otimiza repetição de while
  {
    unsigned aux = stoi(data);
    vetorDataEleicao.push_back(aux);
  }

  stringstream s2(dataNascimento);
  while (getline(s2, data, '/'))
  {
    unsigned aux = stoi(data);
    vetorDataNascimento.push_back(aux);
  }

  if (vetorDataNascimento[1] < vetorDataEleicao[1])
  {
    return vetorDataEleicao[2] - vetorDataNascimento[2];
  }
  else if (vetorDataNascimento[1] == vetorDataEleicao[1] && vetorDataNascimento[0] <= vetorDataEleicao[0])
  {
    return vetorDataEleicao[2] - vetorDataNascimento[2];
  }
  else
  {
    return ((vetorDataEleicao[2] - vetorDataNascimento[2]) - 1);
  }
}

bool ComparaCandidatos::compare(string dataNascimentoCandidato1, string dataNascimentoCandidato2)
{
  string data, linha;
  vector<unsigned> vetorDataNascimentoCandidato1;
  vector<unsigned> vetorDataNascimentoCandidato2;

  stringstream s1(dataNascimentoCandidato1);
  while (getline(s1, data, '/')) //Otimiza repetição de while
  {
    unsigned aux = stoi(data);
    vetorDataNascimentoCandidato1.push_back(aux);
  }

  stringstream s2(dataNascimentoCandidato2);
  while (getline(s2, data, '/'))
  {
    unsigned aux = stoi(data);
    vetorDataNascimentoCandidato2.push_back(aux);
  }

  if (vetorDataNascimentoCandidato2[2] < vetorDataNascimentoCandidato1[2])
  {
    return false;
  }
  else if (vetorDataNascimentoCandidato2[2] == vetorDataNascimentoCandidato1[2] && vetorDataNascimentoCandidato2[1] < vetorDataNascimentoCandidato1[1])
  {
    return false;
  }
  else if (vetorDataNascimentoCandidato2[2] == vetorDataNascimentoCandidato1[2] && vetorDataNascimentoCandidato2[1] == vetorDataNascimentoCandidato1[1] && vetorDataNascimentoCandidato2[0] < vetorDataNascimentoCandidato1[0])
  {
    return false;
  }
  else
  {
    return true;
    ;
  }
}

bool ComparaCandidatos::operator()(Candidato &candidato1, Candidato &candidato2)
{
  if (candidato1.getVotosNominais() > candidato2.getVotosNominais())
    return true;
  else if (candidato1.getVotosNominais() < candidato2.getVotosNominais())
    return false;
  else
  {
    return compare(candidato1.getDataNascimento(), candidato2.getDataNascimento());
  }
}
//ja volto