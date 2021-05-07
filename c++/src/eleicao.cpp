#include "eleicao.h"
#include <iterator>
#include <iostream>

Eleicao::Eleicao() {}
Eleicao::~Eleicao() {}

Eleicao::Eleicao(const list<Candidato> &listaDeCandidatosValidos, const list<Partido> &listaDePartidos, const string &data)
{
  numeroTotalEleitos = 0;
  totalVotosNominais = 0;
  totalVotosLegenda = 0;
  totalVotosValidos = 0;

  this->listaDeCandidatosValidos = listaDeCandidatosValidos;
  this->listaDePartidos = listaDePartidos;

  setNumeroTotalEleitos();
  setListaMaisVotadosEleitos();
  setTotalVotosLegenda();
  setTotalVotosNominais();
  setTotalVotosValidos();
  setListaMaisVotados();
  setDataEleicao(data);
}

const double Eleicao::calculaPercentual(const unsigned &quant, const unsigned &total)
{
  return ((double)quant / total) * 100;
}

void Eleicao::ordenaPrimeiroUltimoListaPartido()
{
  cout << "Primeiro e último colocados de cada partido:" << endl;

  list<Partido> temp;

  for (Partido &partido : listaDePartidos)
  {
    if (partido.getTotalVotosNominais() != 0)
    {
      temp.push_back(partido);
    }
  }

  temp.sort(ordenaPartidoPorVotosNominais);

  unsigned i = 1;
  for (Partido &partido : temp)
  {
    if (!(partido.getTotalVotosNominais() <= 0))
    {
      cout << i << " - ";
      partido.imprimePrimeiroUltimoPartido();
    }
    i++;
  }
};

// --------------Imprimir---------------//

void Eleicao::imprimeVotosTotaisEleicao()
{
  cout << endl;
  cout << "Total de votos válidos:    " << totalVotosValidos << endl;

  cout << "Total de votos nominais:   " << totalVotosNominais << " (";

  float aux = (float)totalVotosNominais / totalVotosValidos * 100;
  cout << formatDoubleCurrency(aux, LOCALE_PT_BR) << "%)" << endl;

  cout << "Total de votos de Legenda: " << totalVotosLegenda << " (";
  aux = ((float)totalVotosLegenda / totalVotosValidos) * 100;
  cout << formatDoubleCurrency(aux, LOCALE_PT_BR) << "%)" << endl;
  cout << endl;
};

void Eleicao::imprimeCandidatosEleitos()
{
  cout << "Vereadores eleitos:" << endl;

  imprimeListaCandidatos(listaDeCandidatosMaisVotadosEleitos);
  cout << endl;
};

void Eleicao::imprimeListaCandidatosValidos(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoMajoritaria()
{
  cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
  cout << "(com sua posição no ranking de mais votados)" << endl;
  imprimeBeneficiadosPresentesLista1AusentesLista2(listaDeCandidatosMaisVotados, listaDeCandidatosMaisVotadosEleitos);
};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoProporcional()
{
  cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
  cout << "(com sua posição no ranking de mais votados)" << endl;
  imprimeBeneficiadosPresentesLista1AusentesLista2(listaDeCandidatosMaisVotadosEleitos, listaDeCandidatosMaisVotados);
};

void Eleicao::imprimeCandidatosPorIdade()
{

  unsigned idade;
  unsigned menor30 = 0;
  unsigned d30_40 = 0;
  unsigned d40_50 = 0;
  unsigned d50_60 = 0;
  unsigned maior60 = 0;
  unsigned total = 0;

  for (Candidato candidato : getListaDeCandidatosMaisVotadosEleitos())
  {
    idade = candidato.getIdade();

    if (idade < 30)
      menor30++;

    else if (idade >= 30 && idade < 40)
      d30_40++;

    else if (idade >= 40 && idade < 50)
      d40_50++;

    else if (idade >= 50 && idade < 60)
      d50_60++;

    else
      maior60++;

    total++;
  }
  cout << "\nEleitos, por faixa etária (na data da eleição):" << endl;

  cout << "      Idade < 30: " << menor30 << " (" << formatDoubleCurrency(calculaPercentual(menor30, total), LOCALE_PT_BR) << "%)" << endl;
  cout << "30 <= Idade < 40: " << d30_40 << " (" << formatDoubleCurrency(calculaPercentual(d30_40, total), LOCALE_PT_BR) << "%)" << endl;
  cout << "40 <= Idade < 50: " << d40_50 << " (" << formatDoubleCurrency(calculaPercentual(d40_50, total), LOCALE_PT_BR) << "%)" << endl;
  cout << "50 <= Idade < 60: " << d50_60 << " (" << formatDoubleCurrency(calculaPercentual(d50_60, total), LOCALE_PT_BR) << "%)" << endl;
  cout << "60 <= Idade     : " << maior60 << " (" << formatDoubleCurrency(calculaPercentual(maior60, total), LOCALE_PT_BR) << "%)" << endl;
};

void Eleicao::imprimeCandidatosPorSexo()
{
  float qntFeminino = 0.0F;
  float qntMasculino = 0.0F;

  for (Candidato &candidato : listaDeCandidatosValidos)
  {
    if (candidato.getSexo() == 'F' && candidato.getSituacao() == "Eleito")
    {
      qntFeminino++;
    }
  }
  qntMasculino = getNumeroTotalEleitos() - qntFeminino;
  cout << endl;
  cout << "Eleitos, por sexo:" << endl;

  float porcentagem = (qntFeminino / getNumeroTotalEleitos()) * 100;

  cout << "Feminino:  " << qntFeminino << " ("
       << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;
  porcentagem = (qntMasculino / numeroTotalEleitos) * 100;

  cout << "Masculino: " << qntMasculino << " ("
       << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%)" << endl;
};

void Eleicao::imprimeListaPartidos()
{
  unsigned id = 1;
  cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
  for (Partido &partido : listaDePartidos)
  {
    cout << id << " - ";
    partido.imprimePartido();
    id++;
  }
  cout << endl;
}

void Eleicao::imprimeListaCandidatos(const list<Candidato> &lista)
{
  unsigned i = 1;
  for (Candidato candidato : lista)
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
};

void Eleicao::imprimeListaCandidatosMaisVotadosPorLimiteVagas()
{
  cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
  unsigned i = 1;
  for (Candidato candidato : getListaDeCandidatosMaisVotados())
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
  cout << endl;
}

//!BUG DO CONST
void Eleicao::imprimePreservandoPosicaoMaisVotados(list<Candidato> &lista)
{
  unsigned j = 0, i = 0;
  list<Candidato>::iterator it = lista.begin();
  for (Candidato &candListaValido : listaDeCandidatosValidos)
  {
    if (j == lista.size())
    {
      break;
    }
    advance(it = lista.begin(), j);
    Candidato &aux = *it;

    if (candListaValido.getNome() == aux.getNome())
    {
      cout << i + 1 << " - ";
      aux.imprimeCandidato();
      j++;
    }
    i++;
  }
  cout << endl;
}

void Eleicao::imprimeBeneficiadosPresentesLista1AusentesLista2(list<Candidato> &lista1, list<Candidato> &lista2)
{

  list<Candidato> beneficiados;
  unsigned presente;

  for (Candidato &candidatoLista1 : lista1)
  {
    for (Candidato &candidatoLista2 : lista2)
    {
      if (candidatoLista1.getNome() == candidatoLista2.getNome())
      {
        presente = 1;
      }
    }
    if (!presente)
      beneficiados.push_back(candidatoLista1);
    presente = 0;
  }

  imprimePreservandoPosicaoMaisVotados(beneficiados);
}

void Eleicao::setNumeroTotalEleitos()
{
  unsigned contador = 0;
  for (Candidato &candidato : this->listaDeCandidatosValidos)
  {
    if (candidato.getSituacao() == "Eleito")
      contador += 1;
  }
  this->numeroTotalEleitos = contador;
}

const unsigned &Eleicao::getNumeroTotalEleitos()
{
  return this->numeroTotalEleitos;
}

void Eleicao::setListaMaisVotados()
{
  unsigned i = 0;
  for (Candidato &candidato : listaDeCandidatosValidos)
  {
    if (i == getNumeroTotalEleitos())
    {
      break;
    }
    listaDeCandidatosMaisVotados.push_back(candidato);
    i++;
  }
}

void Eleicao::setListaMaisVotadosEleitos()
{
  unsigned i = 0;
  for (Candidato &candidato : this->listaDeCandidatosValidos)
  {
    if (i == getNumeroTotalEleitos())
      break;

    if (candidato.getSituacao() == "Eleito")
    {
      listaDeCandidatosMaisVotadosEleitos.push_back(candidato);
      i++;
    }
  }
}

const list<Partido> &Eleicao::getListaDePartidos()
{
  return this->listaDePartidos;
}

const list<Candidato> &Eleicao::getListaDeCandidatosMaisVotadosEleitos()
{
  return this->listaDeCandidatosMaisVotadosEleitos;
}

const list<Candidato> &Eleicao::getListaDeCandidatosMaisVotados()
{
  return this->listaDeCandidatosMaisVotados;
}

void Eleicao::setTotalVotosLegenda()
{
  for (Partido &partido : listaDePartidos)
  {
    this->totalVotosLegenda += partido.getVotosLegenda();
  }
}

const unsigned &Eleicao::getTotalVotosLegenda()
{
  return this->totalVotosLegenda;
}

const unsigned &Eleicao::getTotalVotosNominais()
{
  return this->totalVotosNominais;
}

void Eleicao::setDataEleicao(const string &data)
{
  this->dataEleicao = data;
};

void Eleicao::setTotalVotosNominais()
{
  for (Candidato &candidato : listaDeCandidatosValidos)
  {
    this->totalVotosNominais += candidato.getVotosNominais();
  }
}

void Eleicao::setTotalVotosValidos()
{
  this->totalVotosValidos = totalVotosLegenda + totalVotosNominais;
}

const unsigned &Eleicao::getTotalVotosValidos()
{
  return this->totalVotosValidos;
}

bool Eleicao::compare(const unsigned &numeroPartidario1, const unsigned &numeroPartidario2)
{
  return numeroPartidario1 < numeroPartidario2;
}

//Verificar crime
bool Eleicao::ordenaPartidoPorVotosNominais(Partido &partido1, Partido &partido2)
{

  if (partido1.buscaCandidatoPorPosicao(0).getVotosNominais() > partido2.buscaCandidatoPorPosicao(0).getVotosNominais())
    return true;
  else if (partido1.buscaCandidatoPorPosicao(0).getVotosNominais() < partido2.buscaCandidatoPorPosicao(0).getVotosNominais())
    return false;
  else
  {
    return compare(partido1.getNumero(), partido2.getNumero());
  }
}
