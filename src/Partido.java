
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.lang.Comparable;

public class Partido implements Comparable<Partido> {
  private int numero;
  private int votosLegenda;
  private int totalCandidatosEleitos = 0;
  private int totalVotosNominais = 0;
  private int totalVotosPartido = 0;
  private int totalCandidatos = 0;
  private String nomePartido;
  private String sigla;
  private List<Candidato> listaCandidatos;

  Partido(String[] vetorDados, List<Candidato> listaDeCandidatosValidos) {
    int numeroPartido = Integer.parseInt(vetorDados[0]);
    int votosLegenda = Integer.parseInt(vetorDados[1]);
    String nomePartido = vetorDados[2];
    String siglaPartido = vetorDados[3];

    this.setNumero(numeroPartido);
    this.setNome(nomePartido);
    this.setSigla(siglaPartido);
    this.setvotosLegenda(votosLegenda);
    this.setListaCandidatos(listaDeCandidatosValidos);
    this.settotalVotosNominais();
    this.settotalVotosPartido();
    this.settotalCandidatosEleitos();
    this.settotalCandidatos();
  }

  @Override
  public String toString() {
    String s = this.sigla + " - " + this.numero + ", ";
    String aux;

    if (this.totalVotosPartido == 0) {
      s = s.concat(+this.totalVotosPartido + " voto (" + this.totalVotosNominais + " nominal e ");
    } else {
      s = s.concat(+this.totalVotosPartido + " votos (" + this.totalVotosNominais + " nominais e ");
    }

    s = s.concat(+this.votosLegenda + " de legenda), " + this.gettotalCandidatosEleitos());

    if (this.totalCandidatosEleitos > 1) {
      aux = " candidatos eleitos";
    } else
      aux = " candidato eleito";

    return s + aux;
  }

  @Override
  public int compareTo(Partido partido) {
    if (this.totalVotosPartido > partido.gettotalVotosPartido())
      return -1;
    else if (this.totalVotosPartido < partido.gettotalVotosPartido())
      return 1;
    else {
      if (this.numero > partido.getNumero())
        return -1;
      return 1;
    }
  }

  public void imprimePrimeiroUltimoPartido() { // Refazer

    System.out.print(this.sigla + " - " + this.numero + ", ");
    if (this.listaCandidatos.size() > 0) {
      Candidato aux = this.listaCandidatos.get(0);
      System.out.print(aux.getnomeUrna() + " (" + aux.getNumero() + ", " + aux.getvotosNominais() + " votos) / ");

      aux = this.listaCandidatos.get(listaCandidatos.size() - 1);
      System.out.print(aux.getnomeUrna() + " (" + aux.getNumero() + ", " + aux.getvotosNominais() + " votos)");
    }
    System.out.println();
  }

  public void imprimeListaCandidatosDoPartido() {
    int i = 1;
    for (Candidato candidato : this.listaCandidatos) {
      System.out.println(i + " - " + candidato);
    }

  }

  public void settotalCandidatos() {
    this.totalCandidatos = this.listaCandidatos.size();
  }

  public int gettotalCandidatos() {
    return totalCandidatos;
  }

  public Candidato getCandidatoPorPosicao(int posicao) {
    return listaCandidatos.get(posicao);
  }

  public void settotalCandidatosEleitos() {
    for (Candidato candidato : listaCandidatos) {
      if (candidato.getSituacao().equals("Eleito")) {
        this.totalCandidatosEleitos++;
      }
    }
  }

  public int verificaListaCandidatosVazia() {
    if (this.listaCandidatos.size() == 0) {
      return 1;
    }
    return 0;
  }

  public int gettotalCandidatosEleitos() {
    return totalCandidatosEleitos;
  }

  public void settotalVotosNominais() {
    for (Candidato candidato : listaCandidatos) {
      this.totalVotosNominais += candidato.getvotosNominais();
    }
  }

  public int getTotalVotosNominais() {
    return totalVotosNominais;
  }

  public void settotalVotosPartido() {
    this.totalVotosPartido = this.totalVotosNominais + this.votosLegenda;
  }

  public int gettotalVotosPartido() {
    return totalVotosPartido;
  }

  public void setListaCandidatos(List<Candidato> listaDeCandidatosValidos) {
    this.listaCandidatos = new ArrayList<Candidato>();

    for (Candidato candidato : listaDeCandidatosValidos) {
      if (candidato.getnumeroPartido() == this.numero) {
        this.listaCandidatos.add(candidato);
        candidato.setSiglaPartido(this.sigla);
      }
    }

  }

  public List<Candidato> getlistaCandidatos() {
    return listaCandidatos;
  }

  public void setNome(String nome) {
    this.nomePartido = nome;
  }

  public String getNome() {
    return nomePartido;
  }

  public void setNumero(int numero) {
    this.numero = numero;
  }

  public int getNumero() {
    return numero;
  }

  public void setSigla(String sigla) {
    this.sigla = sigla;
  }

  public String getSigla() {
    return sigla;
  }

  public void setvotosLegenda(int votosLegenda) {
    this.votosLegenda = votosLegenda;
  }

  public int getvotosLegenda() {
    return votosLegenda;
  }

}

class OrdenarPrimeiroUltimoCandidatoPartido implements Comparator<Partido> {
  @Override
  public int compare(Partido p1, Partido p2) {
    int value;
    OrdenarPorMaisVotadoComparator comp = new OrdenarPorMaisVotadoComparator();
    value = comp.compare(p2.getCandidatoPorPosicao(0), p1.getCandidatoPorPosicao(0));

    if (value == -1)
      return -1;
    else if (value == 1)
      return 1;

    else {
      return Integer.compare(p1.getNumero(), p2.getNumero());
    }
  }
}

/*
 * 
 * Compara partido( P1, P2){ int i; i = compara(P1.getPrimCand, P2.getPrimeCand)
 * i = 1; return 1; i = -1; return -1; i = 0; compara(P1.getUltCandm,
 * P2.getUltCand);
 * 
 * 
 * }
 */