
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.lang.Comparable;

public class Partido implements Comparable<Partido> {
  private int numero;
  private int votos_legenda;
  private int total_candidatos_eleitos = 0;
  private int total_votos_nominais = 0;
  private int total_votos_partido = 0;
  private int total_candidatos = 0;
  private String nome_partido;
  private String sigla;
  private List<Candidato> lista_candidatos;

  Partido(String[] vetorDados, List<Candidato> listaDeCandidatosValidos) {
    int numero_partido = Integer.parseInt(vetorDados[0]);
    int votos_legenda = Integer.parseInt(vetorDados[1]);
    String nome_partido = vetorDados[2];
    String sigla_partido = vetorDados[3];

    this.setNumero(numero_partido);
    this.setNome(nome_partido);
    this.setSigla(sigla_partido);
    this.setVotos_legenda(votos_legenda);
    this.setListaCandidatos(listaDeCandidatosValidos);
    this.setTotal_votos_nominais();
    this.setTotal_votos_partido();
    this.setTotal_candidatos_eleitos();
    this.setTotal_candidatos();
  }

  @Override
  public String toString() {
    String s = this.sigla + " - " + this.numero + ", ";
    String aux;

    if (this.total_votos_partido == 0) {
      s = s.concat(+this.total_votos_partido + " voto (" + this.total_votos_nominais + " nominal e ");
    } else {
      s = s.concat(+this.total_votos_partido + " votos (" + this.total_votos_nominais + " nominais e ");
    }

    s = s.concat(+this.votos_legenda + " de legenda), " + this.getTotal_candidatos_eleitos());

    if (this.total_candidatos_eleitos > 1) {
      aux = " candidatos eleitos";
    } else
      aux = " candidato eleito";

    return s + aux;
  }

  @Override
  public int compareTo(Partido partido) {
    if (this.total_votos_partido > partido.getTotal_votos_partido())
      return -1;
    else if (this.total_votos_partido < partido.getTotal_votos_partido())
      return 1;
    else {
      if (this.numero > partido.getNumero())
        return -1;
      return 1;
    }
  }

  public void imprimePrimeiroUltimoPartido() { // Refazer

    System.out.println(this.sigla + " - " + this.numero + ", ");

    Candidato aux = this.lista_candidatos.get(0);
    System.out.print(aux.getNome_urna() + " (" + aux.getNumero() + ", " + aux.getVotos_nominais() + " votos) / ");

    aux = this.lista_candidatos.get(lista_candidatos.size() - 1);

    System.out.print(aux.getNome_urna() + " (" + aux.getNumero() + ", " + aux.getVotos_nominais() + " votos) / ");

    System.out.println();
  }

  public void imprimeListaCandidatosDoPartido() {
    int i = 1;
    for (Candidato candidato : this.lista_candidatos) {
      System.out.println(i + " - " + candidato);
    }

  }

  public void setTotal_candidatos() {
    this.total_candidatos = this.lista_candidatos.size();
  }

  public int getTotal_candidatos() {
    return total_candidatos;
  }

  public Candidato getCandidatoPorPosicao(int posicao) {
    return lista_candidatos.get(posicao);
  }

  public void setTotal_candidatos_eleitos() {
    for (Candidato candidato : lista_candidatos) {
      if (candidato.getSituacao().equals("Eleito")) {
        this.total_candidatos_eleitos++;
      }
    }
  }

  public int getTotal_candidatos_eleitos() {
    return total_candidatos_eleitos;
  }

  public void setTotal_votos_nominais() {
    for (Candidato candidato : lista_candidatos) {
      this.total_votos_nominais += candidato.getVotos_nominais();
    }
  }

  public int getTotalVotosNominais() {
    return total_votos_nominais;
  }

  public void setTotal_votos_partido() {
    this.total_votos_partido = this.total_votos_nominais + this.votos_legenda;
  }

  public int getTotal_votos_partido() {
    return total_votos_partido;
  }

  public void setListaCandidatos(List<Candidato> listaDeCandidatosValidos) {
    this.lista_candidatos = new ArrayList<Candidato>();

    for (Candidato candidato : listaDeCandidatosValidos) {
      if (candidato.getNumero_partido() == this.numero) {
        this.lista_candidatos.add(candidato);
      }
    }

  }

  public List<Candidato> getLista_candidatos() {
    return lista_candidatos;
  }

  public void setNome(String nome) {
    this.nome_partido = nome;
  }

  public String getNome() {
    return nome_partido;
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

  public void setVotos_legenda(int votos_legenda) {
    this.votos_legenda = votos_legenda;
  }

  public int getVotos_legenda() {
    return votos_legenda;
  }

}

class OrdenarPrimeiroUltimoCandidatoPartido implements Comparator<Partido> {
  @Override
  public int compare(Partido partido1, Partido partido2) {
    int i = 0;
    OrdenarPorMaisVotadoComparator comparaVotos = new OrdenarPorMaisVotadoComparator();

    System.out.println(partido1.getCandidatoPorPosicao(0));
    System.out.println();
    i = comparaVotos.compare(partido1.getCandidatoPorPosicao(0), partido2.getCandidatoPorPosicao(0));

    if (i == 0) {
      // compare(partido1.getNumero(), partido2.getNumero());
      return Integer.compare(partido1.getNumero(), partido2.getNumero());

    }
    return i;

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