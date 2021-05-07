
#include "eleicao.h"
#include "leitura.h"
using namespace std;

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "pt_BR.utf8");

  if (argc < 4)
  {
    cout << "Problemas ao ler data de entrada, parametros de entrada incompletos" << endl;
    return 0;
  }
  try
  {
    string dataEleicao = argv[3];

    // string linha, palavra;
    // vector<string> vetorDados;
    list<Candidato> listaDeCandidatos;
    list<Partido> listaDePartidos;
    Leitura leitura;

    leitura.inicializaListaCandidatos(argv[1], dataEleicao, listaDeCandidatos);
    leitura.inicializaListaPartidos(argv[2], listaDePartidos, listaDeCandidatos);

    //CRIANDO ELEIÇÃO
    Eleicao eleicao(listaDeCandidatos, listaDePartidos, dataEleicao);

    //relatório 1
    cout << "Número de vagas: " << eleicao.getNumeroTotalEleitos()
         << endl
         << endl;

    //relatório 2
    eleicao.imprimeCandidatosEleitos();

    //relatório 3
    eleicao.imprimeListaCandidatosMaisVotadosPorLimiteVagas();

    //relatório 4
    eleicao.imprimeCandidatosBeneficiadosVotacaoMajoritaria();

    //relatório 5
    eleicao.imprimeCandidatosBeneficiadosVotacaoProporcional();

    //relatório 6
    eleicao.imprimeListaPartidos();

    //relatório 7
    eleicao.ordenaPrimeiroUltimoListaPartido();

    //relatório 8
    eleicao.imprimeCandidatosPorIdade();

    //relatório 9
    eleicao.imprimeCandidatosPorSexo();

    //relatório 10
    eleicao.imprimeVotosTotaisEleicao();
  }
  catch (const exception &e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}