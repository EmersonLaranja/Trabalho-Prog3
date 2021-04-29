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

  setListaMaisVotadosEleitos();
  setNumeroTotalEleitos(); //set corretos
  setTotalVotosLegenda();  //set corretos
  setTotalVotosNominais(); //set corretos
  setTotalVotosValidos();  //set corretos
  setListaMaisVotados();
  setDataEleicao(data);
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

void Eleicao::imprimeCandidatosEleitos()
{
  cout << "Vereadores eleitos:" << endl;

  imprimeListaCandidatos(listaDeCandidatosMaisVotadosEleitos);
};

void Eleicao::imprimeListaCandidatosValidos(){};

void Eleicao::imprimeListaCandidatosMaisVotadosPorLimiteVagas(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoMajoritaria(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoProporcional(){};

void Eleicao::imprimeCandidatosPorIdade(){};

void Eleicao::imprimeCandidatosPorSexo(){};

void Eleicao::imprimeListaPartidos()
{
  int id = 1;
  for (auto partido : listaDePartidos)
  {
    cout << id << " - ";
    partido.imprimePartido();
    id++;
  }
};

void Eleicao::imprimeListaCandidatos(list<Candidato> lista)
{
  int i = 1;
  for (Candidato candidato : lista)
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
};

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

void Eleicao::setListaMaisVotados()
{
  for (Candidato candidato : listaDeCandidatosValidos)
  {
    listaDeCandidatosMaisVotados.push_back(candidato);
  }
}

void Eleicao::setListaMaisVotadosEleitos()
{
  for (Candidato candidato : listaDeCandidatosValidos)
  {
    if (candidato.getSituacao() == "Eleito")
      listaDeCandidatosMaisVotadosEleitos.push_back(candidato);
  }
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

list<Partido> Eleicao::getListaDePartidos()
{
  return this->listaDePartidos;
}

list<Candidato> Eleicao::getListaDeCandidatosMaisVotadosEleitos()
{
  return this->listaDeCandidatosMaisVotadosEleitos;
}

list<Candidato> Eleicao::getListaDeCandidatosMaisVotados()
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
