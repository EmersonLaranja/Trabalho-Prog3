
#include "Partido.h";

using namespace std;

class Partido
{
private:
  unsigned numero;
  unsigned votosLegenda;
  unsigned totalCandidatosEleitos = 0;
  unsigned totalVotosNominais = 0;
  unsigned totalVotosPartido = 0;
  unsigned totalCandidatos = 0;
  string nomePartido;
  string sigla;
  // List<Candidato> listaCandidatos;

  Partido(string vetorDados[], List<Candidato> listaDeCandidatosValidos)
  {
    unsigned numeroPartido = Integer.parseInt(vetorDados[0]);
    unsigned votosLegenda = Integer.parseInt(vetorDados[1]);
    string nomePartido = vetorDados[2];
    string siglaPartido = vetorDados[3];

    this.setNumero(numeroPartido);
    this.setNome(nomePartido);
    this.setSigla(siglaPartido);
    this.setVotosLegenda(votosLegenda);
    this.setListaCandidatos(listaDeCandidatosValidos);
    this.setTotalVotosNominais();
    this.setTotalVotosPartido();
    this.setTotalCandidatosEleitos();
    this.setTotalCandidatos();
  }
  // --------------@Overrides---------------//

  @Override public string tostring()
  {
    string s = this.sigla + " - " + this.numero + ", ";
    string aux;

    if (this.totalVotosPartido > 1)
    {
      if (this.totalVotosNominais > 1)
        s = s.concat(+this.totalVotosPartido + " votos (" + this.totalVotosNominais + " nominais e ");
      else
      {
        s = s.concat(+this.totalVotosPartido + " votos (" + this.totalVotosNominais + " nominal e ");
      }
    }
    else
    {
      if (this.totalVotosNominais > 1)
        s = s.concat(+this.totalVotosPartido + " voto (" + this.totalVotosNominais + " nominais e ");
      else
      {
        s = s.concat(+this.totalVotosPartido + " voto (" + this.totalVotosNominais + " nominal e ");
      }
    }

    s = s.concat(+this.votosLegenda + " de legenda), " + this.getTotalCandidatosEleitos());

    if (this.totalCandidatosEleitos > 1)
    {
      aux = " candidatos eleitos";
    }
    else
      aux = " candidato eleito";

    return s + aux;
  }

  void Partido::imprimePrimeiroUltimoPartido();
  void Partido::imprimeListaCandidatosDoPartido();

  unsigned Partido::verificaListaCandidatosVazia();
  Candidato Partido::buscaCandidatoPorPosicao(unsigned posicao);

  void Partido::setTotalCandidatos();

  unsigned Partido::getTotalCandidatos();
  void Partido::setTotalCandidatosEleitos();
  unsigned Partido::getTotalCandidatosEleitos();

  void Partido::setTotalVotosNominais();

  unsigned Partido::getTotalVotosNominais();
  void Partido::setTotalVotosPartido();
  unsigned Partido::gettotalVotosPartido();

  void Partido::setListaCandidatos(List<Candidato> listaDeCandidatosValidos);

  List<Candidato> Partido::getlistaCandidatos()
  {
    return listaCandidatos;
  }

  void Partido::setNome(string nome)
  {
    this.nomePartido = nome;
  }

  string Partido::getNome()
  {
    return nomePartido;
  }

  void Partido::setNumero(unsigned numero)
  {
    this.numero = numero;
  }

  unsigned Partido::getNumero()
  {
    return numero;
  }

  void Partido::setSigla(string sigla)
  {
    this.sigla = sigla;
  }

  string Partido::getSigla()
  {
    return sigla;
  }

  void Partido::setVotosLegenda(unsigned votosLegenda)
  {
    this.votosLegenda = votosLegenda;
  }

  unsigned Partido::getvotosLegenda()
  {
    return votosLegenda;
  }
}
