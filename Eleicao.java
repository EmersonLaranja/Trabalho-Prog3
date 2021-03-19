import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Eleicao {
  private int numeroTotalEleitos = 0;
  private int total_votos_nominais = 0;
  private int total_votos_legenda = 0;
  private int total_votos_validos = 0;
  private int quociente_eleitoral = 0; // total_votos_validos/numeroTotalEleitos;
  private List<Candidato> listaDeCandidatosValidos;
  private List<Candidato> listaDeCandidatosMaisVotadosEleitos;
  private List<Candidato> listaDeCandidatosMaisVotados;
  private List<Partido> listaDePartidos;
  private String data;

  Eleicao() {
  }

  Eleicao(List<Candidato> listaDeCandidatosValidos, List<Partido> listaDePartidos) {
    this.listaDeCandidatosValidos = listaDeCandidatosValidos;
    this.listaDePartidos = listaDePartidos;

    Comparator<Candidato> maisVotado = Collections.reverseOrder(new OrdenarPorMaisVotado());
    Collections.sort(listaDeCandidatosValidos, maisVotado);

    setNumeroTotalEleitos();

    setTotalVotosLegenda();
    setTotalVotosValidos();
    setTotalVotosNominais();

    setListaMaisVotados();
    setListaMaisVotadosEleitos();

  }

  public String getNomePartidoPeloNumeroPartido(int numero_partido) {
    String nome_partido = new String();

    for (Partido partido : this.listaDePartidos) {
      if (numero_partido == partido.getNumero()) {
        nome_partido = partido.getNome();
      }
    }
    return nome_partido;
  }

  public void imprimeListaCandidatosValidos() {
    int i = 0;
    for (Candidato candidato : this.listaDeCandidatosValidos) {
      System.out.print(i + " - ");
      candidato.imprimeCandidato();
      System.out.println();
      i++;
    }
  }

  public int getQuociente_eleitoral() {
    return quociente_eleitoral;
  }

  public void setQuociente_eleitoral() {
    this.quociente_eleitoral = (this.total_votos_validos / this.numeroTotalEleitos);
  }

  public void setData(String data) {
    this.data = data;
  }

  public String getData() {
    return data;
  }

  public void setNumeroTotalEleitos() {

    for (Candidato candidato : listaDeCandidatosValidos) {
      if (candidato.getSituacao().equals("Eleito")) // retorna zero se são iguais
        this.numeroTotalEleitos++;

    }
  }

  public int getNumeroTotalEleitos() {
    return this.numeroTotalEleitos;

  }

  public void setListaMaisVotados() {
    listaDeCandidatosMaisVotados = new ArrayList<Candidato>();
    for (int i = 0; i < getNumeroTotalEleitos(); i++) {
      Candidato aux = listaDeCandidatosValidos.get(i);
      listaDeCandidatosMaisVotados.add(aux);
    }
  }

  public void setListaMaisVotadosEleitos() {
    listaDeCandidatosMaisVotadosEleitos = new ArrayList<Candidato>();

    for (int i = 0; i < this.listaDeCandidatosValidos.size(); i++) {
      Candidato aux = listaDeCandidatosValidos.get(i);
      if (aux.getSituacao().equals("Eleito"))
        listaDeCandidatosMaisVotadosEleitos.add(aux);
    }

  }

  public List<Candidato> getListaDeCandidatosMaisVotadosEleitos() {
    return listaDeCandidatosMaisVotadosEleitos;
  }

  public List<Candidato> getListaDeCandidatosMaisVotados() {
    return listaDeCandidatosMaisVotados;
  }

  public void setTotalVotosLegenda() {
    for (Partido partido : listaDePartidos) {
      this.total_votos_legenda += partido.getVotos_legenda();
    }
  }

  public int getTotalVotosLegenda() {
    return total_votos_legenda;
  }

  public int getTotalVotosNominais() {
    return total_votos_nominais;
  }

  public void setTotalVotosNominais() {
    for (Candidato candidato : listaDeCandidatosValidos) {
      this.total_votos_nominais += candidato.getVotos_nominais();
    }

  }

  public void setTotalVotosValidos() {
    this.total_votos_validos = total_votos_legenda + total_votos_nominais;
  }

  public int getTotalVotosValidos() {
    return total_votos_validos;
  }

  // public void imprimeListaPartidos() {
  // for (Partido partido : this.listaDePartidos) {

  // }
  // }

}

class OrdenarPorMaisVotado implements Comparator<Candidato> {
  public int compare(Candidato a, Candidato b) {
    return a.getVotos_nominais() - b.getVotos_nominais();
  }
}
