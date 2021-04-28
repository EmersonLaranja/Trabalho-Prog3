#include "eleicao.h"

Eleicao::Eleicao() {}
Eleicao::~Eleicao() {}

Eleicao::Eleicao(list<Candidato> listaDeCandidatosValidos, list<Partido> listaDePartidos, string data)
{
  numeroTotalEleitos = 0;
  totalVotosNominais = 0;
  totalVotosLegenda = 0;
  totalVotosValidos = 0;

  this->listaDeCandidatosValidos = listaDeCandidatosValidos;
  this->listaDePartidos = listaDePartidos;

  setNumeroTotalEleitos();
  setTotalVotosLegenda();
  setTotalVotosNominais();
  setTotalVotosValidos();
  setDataEleicao(data);
  setlistaMaisVotadosEleitos();
  setlistaMaisVotados();
}

string Eleicao::calculaPercentual(unsigned quant, unsigned total)
{
  string aux = "1";
  return aux;
}

// int Eleicao::calculaIdadeCandidato(LocalDate nascimento, LocalDate diaEleicao)
// {
// }

void Eleicao::ordenaPrimeiroUltimolistaPartido(){};

// --------------Imprimir---------------//

void Eleicao::imprimeVotosTotaisEleicao(){};

void Eleicao::imprimeCandidatosEleitos(){};

void Eleicao::imprimelistaCandidatosValidos(){};

void Eleicao::imprimelistaCandidatosMaisVotadosPorLimiteVagas(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoMajoritaria(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoProporcional(){};

void Eleicao::imprimeCandidatosPorIdade(){};

void Eleicao::imprimeCandidatosPorSexo(){};

void Eleicao::imprimelistaPartidos(){};

void Eleicao::imprimelistaCandidatos(list<Candidato> lista){};

void Eleicao::imprimePreservandoPosicaoMaisVotados(list<Candidato> lista){};

void Eleicao::imprimeBeneficiadosPresenteslista1Ausenteslista2(list<Candidato> lista1, list<Candidato> lista2){};

void Eleicao::setNumeroTotalEleitos()
{
  for (Candidato candidato : listaDeCandidatosValidos)
  {
    if (candidato.getSituacao() == "Eleito")
      this->numeroTotalEleitos++;
  }
}

int Eleicao::getNumeroTotalEleitos()
{
  return this->numeroTotalEleitos;
}

void Eleicao::setlistaMaisVotados()
{
  // listaDeCandidatosMaisVotados = new Arraylist<Candidato>();
  // for (int i = 0; i < getNumeroTotalEleitos(); i++)
  // {
  //   Candidato aux = listaDeCandidatosValidos.get(i);
  //   listaDeCandidatosMaisVotados.add(aux);
  // }
}

void Eleicao::setlistaMaisVotadosEleitos()
{
  //   listaDeCandidatosMaisVotadosEleitos = new Arraylist<Candidato>();

  //   for (int i = 0; i < this->listaDeCandidatosValidos.size(); i++)
  //   {
  //     Candidato aux = listaDeCandidatosValidos.get(i);
  //     if (aux.getSituacao().equals("Eleito"))
  //       listaDeCandidatosMaisVotadosEleitos.add(aux);
  //   }
}

string Eleicao::getNomePartidoPorNumero(int numero)
{

  string aux = "1";

  //   for (Partido partido : listaDePartidos)
  //   {
  //     if (partido.getNumero() == numero)
  //       aux = partido.getNome();
  //   }
  return aux;
}

list<Partido> Eleicao::getlistaDePartidos()
{
  return this->listaDePartidos;
}

list<Candidato> Eleicao::getlistaDeCandidatosMaisVotadosEleitos()
{
  return this->listaDeCandidatosMaisVotadosEleitos;
}

list<Candidato> Eleicao::getlistaDeCandidatosMaisVotados()
{
  return this->listaDeCandidatosMaisVotados;
}

void Eleicao::setTotalVotosLegenda()
{
  for (Partido partido : listaDePartidos)
  {
    this->totalVotosLegenda += partido.getVotosLegenda();
  }
}

int Eleicao::getTotalVotosLegenda()
{
  return this->totalVotosLegenda;
}

int Eleicao::getTotalVotosNominais()
{
  return this->totalVotosNominais;
}

void Eleicao::setDataEleicao(string data)
{
  this->dataEleicao = data;
};

void Eleicao::setTotalVotosNominais()
{
  for (Candidato candidato : listaDeCandidatosValidos)
  {
    this->totalVotosNominais += candidato.getVotosNominais();
  }
}

void Eleicao::setTotalVotosValidos()
{
  this->totalVotosValidos = totalVotosLegenda + totalVotosNominais;
}

int Eleicao::getTotalVotosValidos()
{
  return this->totalVotosValidos;
}
