import java.util.ArrayList;

public class Partido extends Eleicao {
  private int numero;
  private int votos_legenda;
  private int quociente_partidario = 0;
  private String nome_partido;
  private String sigla;
  private ArrayList<Candidato> lista_candidatos;
  // static public int numeroVotosLegenda = 0;

  Partido() {
  }

  Partido(String[] vetorDados) {
    int numero_partido = Integer.parseInt(vetorDados[0]);
    int votos_legenda = Integer.parseInt(vetorDados[1]);
    String nome_partido = vetorDados[2];
    String sigla_partido = vetorDados[3];

    this.setNome(nome_partido);
    this.setNumero(numero_partido);
    this.setSigla(sigla_partido);
    this.setVotos_legenda(votos_legenda);

  }

  public void setListaCandidatos(ArrayList<Candidato> lista_candidatos) {

    for (Candidato candidato : this.lista_candidatos) {
      if (candidato.getNumero() == this.numero) {
        this.lista_candidatos.add(candidato);
      }
    }
  }

  public ArrayList<Candidato> getLista_candidatos() {
    return lista_candidatos;
  }

  public int getQuociente_partidario() {
    return quociente_partidario;
  }

  public void setQuociente_partidario() {
    this.quociente_partidario = quociente_partidario;
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
