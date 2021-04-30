#include "eleicao.h"
#include <iterator>
#include <iostream>
#include <algorithm>

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

  setNumeroTotalEleitos(); //set corretos
  setListaMaisVotadosEleitos();
  setTotalVotosLegenda();  //set corretos
  setTotalVotosNominais(); //set corretos
  setTotalVotosValidos();  //set corretos
  setListaMaisVotados();
  setDataEleicao(data);
}

float Eleicao::calculaPercentual(unsigned quant, unsigned total)
{
  return ((float)quant / total) * 100;
}

// int Eleicao::calculaIdadeCandidato(LocalDate nascimento, LocalDate diaEleicao)
// {
// }

void Eleicao::ordenaPrimeiroUltimolistaPartido(){};

// --------------Imprimir---------------//

void Eleicao::imprimeVotosTotaisEleicao()
{
  printf("Total de votos válidos:    %d\n", totalVotosValidos);

  printf("Total de votos nominais:   %d", totalVotosNominais);
  printf(" (%.2f%%)\n", ((float)totalVotosNominais / totalVotosValidos) * 100);

  printf("Total de votos de Legenda: %d", totalVotosLegenda);
  printf(" (%.2f%%)", ((float)totalVotosLegenda / totalVotosValidos) * 100);
};

void Eleicao::imprimeCandidatosEleitos()
{
  cout << "Vereadores eleitos:" << endl;

  imprimeListaCandidatos(listaDeCandidatosMaisVotadosEleitos);
};

void Eleicao::imprimeListaCandidatosValidos(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoMajoritaria(){};

void Eleicao::imprimeCandidatosBeneficiadosVotacaoProporcional(){};

void Eleicao::imprimeCandidatosPorIdade()
{

  unsigned idade;
  unsigned menor30 = 0;
  unsigned d30_40 = 0;
  unsigned d40_50 = 0;
  unsigned d50_60 = 0;
  unsigned maior60 = 0;
  unsigned total = 0;

  for (Candidato &candidato : getListaDeCandidatosMaisVotados())
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
  printf("60 <= Idade     : %d (%.2f%%)\n", maior60, calculaPercentual(maior60, total));
};

void Eleicao::imprimeCandidatosPorSexo()
{
  float qntFeminino = 0.0F;
  float qntMasculino = 0.0F;

  for (Candidato candidato : listaDeCandidatosValidos)
  {
    if (candidato.getSexo() == 'F' && candidato.getSituacao() == "Eleito")
    {
      qntFeminino++;
    }
  }
  qntMasculino = getNumeroTotalEleitos() - qntFeminino;
  cout << qntFeminino << endl;

  cout << "Eleitos, por sexo:" << endl;

  float porcentagem = (qntFeminino / getNumeroTotalEleitos()) * 100;

  printf("Feminino:  %.0f (%.2f%%)\n", qntFeminino, porcentagem);
  porcentagem = (qntMasculino / numeroTotalEleitos) * 100;
  printf("Masculino: %.0f (%.2f%%)\n", qntMasculino, porcentagem);
};

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

void Eleicao::imprimeListaCandidatosMaisVotadosPorLimiteVagas()
{
  cout << "Candidatos mais votados(em ordem decrescente de votação e respeitando número de vagas) :" << endl;
  int i = 1;
  for (auto candidato : getListaDeCandidatosMaisVotados())
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
}

void Eleicao::imprimePreservandoPosicaoMaisVotados(list<Candidato> lista){

    // int i, j;

    // for (i = 0, j = 0; j < lista.size(); i++)
    // {

    //   Candidato aux1 = lista.get(j);
    //    advance(it, j);
    //   Candidato aux2 = listaDeCandidatosValidos.get(i);

    //   if (aux1.getNome() == (aux2.getNome()))
    //   {
    //     System.out.println((i + 1) + " - " + aux1);
    //     j++;
    //   }
    // }

    /*
#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main()
{
	// Create list with initial value 100
	list<int> li(5, 100);

	// Insert 20 and 30 to the list
	li.push_back(20);
	li.push_back(30);

	// Elements of list are
	// 100, 100, 100, 100, 100, 20, 30

	// Initialize iterator to list
	list<int>::iterator it = li.begin();

	// Move the iterator by 5 elements
	advance(it, 5);

	// Print the element at the it
	cout << *it;

	return 0;
}
*/

};

//tem que ser por cópia
void Eleicao::imprimeBeneficiadosPresenteslista1Ausenteslista2(list<Candidato> lista1, list<Candidato> lista2)
{
  list<Candidato> beneficiados;
  unsigned presente;

  for (Candidato candidatoLista1 : lista1)
  {
    for (Candidato candidatoLista2 : lista2)
    {
      if (candidatoLista1.getNome() == candidatoLista2.getNome())
      {
        presente = 1;
      }
    }
    if (presente)
      beneficiados.push_back(candidatoLista1);
  }
  imprimeListaCandidatos(beneficiados);
}

void Eleicao::setNumeroTotalEleitos()
{
  int contador = 0;
  for (Candidato &candidato : this->listaDeCandidatosValidos)
  {
    if (candidato.getSituacao() == "Eleito")
      contador += 1;
  }
  this->numeroTotalEleitos = contador;
}

int Eleicao::getNumeroTotalEleitos()
{
  return this->numeroTotalEleitos;
}

void Eleicao::setListaMaisVotados()
{
  int i = 0;
  for (Candidato candidato : listaDeCandidatosValidos)
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
  int i = 0;
  for (Candidato candidato : this->listaDeCandidatosValidos)
  {
    if (i == getNumeroTotalEleitos())
      break;

    if (candidato.getSituacao() == "Eleito")
    {
      listaDeCandidatosMaisVotadosEleitos.push_back(candidato);
      i++;
    }
  }
  // for (Candidato candidato : listaDeCandidatosMaisVotadosEleitos)
  // {
  //   candidato.imprimeCandidato();
  // }
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

void Eleicao::setDataEleicao(string &data)
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
