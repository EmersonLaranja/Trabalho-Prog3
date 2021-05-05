#include "eleicao.h"
#include <iterator>
#include <iostream>

Eleicao::Eleicao() {}
Eleicao::~Eleicao() {}

Eleicao::Eleicao(list<Candidato> &listaDeCandidatosValidos, list<Partido> &listaDePartidos, string &data)
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

float Eleicao::calculaPercentual(unsigned &quant, unsigned &total)
{
  return ((float)quant / total) * 100;
}

void Eleicao::ordenaPrimeiroUltimoListaPartido()
{
  cout << "Primeiro e último colocados de cada partido:" << endl;

  list<Partido> temp;

  for (auto &partido : listaDePartidos)
  {
    if (partido.getTotalVotosNominais() != 0)
    {
      temp.push_back(partido);
    }
  }

  temp.sort(OrdenaPrimeiroUltimoListaPartido());

  unsigned i = 1;
  for (auto &partido : temp)
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
  printf("Total de votos válidos:    %d\n", totalVotosValidos);

  printf("Total de votos nominais:   %d", totalVotosNominais);
  printf(" (%.2f%%)\n", ((float)totalVotosNominais / totalVotosValidos) * 100);

  printf("Total de votos de Legenda: %d", totalVotosLegenda);
  printf(" (%.2f%%)\n\n", ((float)totalVotosLegenda / totalVotosValidos) * 100);
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
  printf("\nEleitos, por faixa etária (na data da eleição):\n");
  printf("      Idade < 30: %d (%.2f%%)\n", menor30, calculaPercentual(menor30, total));
  printf("30 <= Idade < 40: %d (%.2f%%)\n", d30_40, calculaPercentual(d30_40, total));
  printf("40 <= Idade < 50: %d (%.2f%%)\n", d40_50, calculaPercentual(d40_50, total));
  printf("50 <= Idade < 60: %d (%.2f%%)\n", d50_60, calculaPercentual(d50_60, total));
  printf("60 <= Idade     : %d (%.2f%%)\n\n", maior60, calculaPercentual(maior60, total));
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

  cout << "Eleitos, por sexo:" << endl;

  float porcentagem = (qntFeminino / getNumeroTotalEleitos()) * 100;

  printf("Feminino:  %.0f (%.2f%%)\n", qntFeminino, porcentagem);
  porcentagem = (qntMasculino / numeroTotalEleitos) * 100;
  printf("Masculino: %.0f (%.2f%%)\n\n", qntMasculino, porcentagem);
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

void Eleicao::imprimeListaCandidatos(list<Candidato> &lista)
{
  unsigned i = 1;
  for (Candidato &candidato : lista)
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
  for (auto candidato : getListaDeCandidatosMaisVotados())
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
  cout << endl;
}

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

void Eleicao::setDataEleicao(string &data)
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

bool OrdenaPrimeiroUltimoListaPartido::compare(unsigned numeroPartidario1, unsigned numeroPartidario2)
{
  return numeroPartidario1 < numeroPartidario2;
}

bool OrdenaPrimeiroUltimoListaPartido::operator()(Partido &partido1, Partido &partido2)
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
