#if !defined(LEITURA_H)
#define LEITURA_H
#include "partido.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

class Leitura
{

public:
  const void inicializaListaCandidatos(string nomeArquivoEntrada, string dataEleicao, list<Candidato> &listaDeCandidatos);
  const void inicializaListaPartidos(string nomeArquivoEntrada, list<Partido> &listaPartidos, list<Candidato> &listaDeCandidatos);
};
#endif // LEITURA_H
