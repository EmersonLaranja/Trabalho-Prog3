import java.lang.Comparable;
import java.util.Calendar;
import java.util.Comparator;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.Period;
import java.time.Year;
import java.time.YearMonth;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class Candidato implements Comparable<Candidato> {
  private int numero;
  private int votos_nominais;
  private int numero_partido;
  private char sexo; // 1 feminino e 0 masculino
  private Date data_nasc;
  private String situacao;
  private String destino_voto;
  private String nome;
  private String nome_urna;
  private String nome_partido;
  private Date idade;

  private final char MASCULINO = 'M';
  private final char FEMININO = 'F';

  Candidato(String[] vetorDados) {
    int numero = Integer.parseInt(vetorDados[0]);
    int votos_nominais = Integer.parseInt(vetorDados[1]);
    String situacao = vetorDados[2];
    String nome = vetorDados[3];
    String nome_urna = vetorDados[4];
    char sexo = vetorDados[5].charAt(0);
    String data_nasc = vetorDados[6];

    String destino_voto = vetorDados[7];
    int numero_partido = Integer.parseInt(vetorDados[8]);

    this.setNumero(numero);
    this.setVotos_nominais(votos_nominais);
    this.setSituacao(situacao);
    this.setNome(nome);
    this.setSexo(sexo);
    this.setNome_urna(nome_urna);
    this.setData_nasc(data_nasc);
    this.setDestino_voto(destino_voto);
    this.setNumero_partido(numero_partido);

  }

  public boolean verificaDestinoVoto() {
    return this.destino_voto.equals("Válido");
  }

  // --------------@Override---------------//

  @Override
  public String toString() {
    return this.nome + " / " + this.nome_urna + " (PARTIDO, " + this.votos_nominais + " votos)";
  }

  @Override
  public int compareTo(Candidato candidato) {
    if (this.votos_nominais > candidato.getVotos_nominais())
      return -1;
    else if (this.votos_nominais < candidato.getVotos_nominais())
      return 1;
    else {
      return this.data_nasc.compareTo(candidato.getData_nasc());
    }
  }

  // --------------End of @Override---------------//

  // public void setIdade(Date idade) {
  // LocalDate.Period.between(this.data_nasc, Eleicao.dataEleicao);
  // System.out.println(this.idade);
  // }

  public Date getIdade() {
    return idade;
  }

  public void setDestino_voto(String destino_voto) {
    this.destino_voto = destino_voto;
  }

  public String getDestino_voto() {
    return destino_voto;
  }

  public void setData_nasc(String data_nasc) {
    // SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d/MM/yyyy");
    LocalDate localDate = LocalDate.parse(data_nasc, formatter);

  }

  public Date getData_nasc() {
    return data_nasc;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  public void setNome_urna(String nome_urna) {
    this.nome_urna = nome_urna;
  }

  public String getNome_urna() {
    return nome_urna;
  }

  public void setNumero(int numero) {
    this.numero = numero;
  }

  public int getNumero() {
    return numero;
  }

  public void setNumero_partido(int numero_partido) {
    this.numero_partido = numero_partido;
  }

  public int getNumero_partido() {
    return numero_partido;
  }

  public void setSexo(char sexo) {
    switch (sexo) {
    case 'M':
      this.sexo = MASCULINO;
      break;

    default:
      this.sexo = FEMININO;
      break;
    }
  }

  public char getSexo() {
    return sexo;
  }

  public void setSituacao(String situacao) {
    this.situacao = situacao;
  }

  public String getSituacao() {
    return situacao;
  }

  public void setVotos_nominais(int votos_nominais) {
    this.votos_nominais = votos_nominais;
  }

  public int getVotos_nominais() {
    return votos_nominais;
  }

  public String getNome_partido() {
    return nome_partido;
  }

}

class OrdenarPorMaisVotadoComparator implements Comparator<Candidato> {
  public int compare(Candidato a, Candidato b) {
    return Integer.compare(a.getVotos_nominais(), b.getVotos_nominais());
  }
}

// class ComparaPorNumeroCandidato implements Comparator<Candidato> {
// public int compare(Candidato a, Candidato b) {
// if (a.getNumero_partido() > b.getNumero_partido())
// return -1;
// return 1;

// }
// }
/*
 * 
 * Compara partido( P1, P2){ int i; i = compara(P1.getPrimCand, P2.getPrimeCand)
 * i = 1; return 1; i = -1; return -1; i = 0; compara(P1.getUltCandm,
 * P2.getUltCand);
 * 
 * 
 * }
 */