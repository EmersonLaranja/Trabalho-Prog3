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
  private int votosNominais;
  private int numeroPartido;
  private char sexo; // 1 feminino e 0 masculino
  private LocalDate dataNascimento;
  private String situacao;
  private String destinoVoto;
  private String nome;
  private String nomeUrna;
  private String siglaPartido;
  private Date idade;

  private final char MASCULINO = 'M';
  private final char FEMININO = 'F';

  Candidato(String[] vetorDados) {
    int numero = Integer.parseInt(vetorDados[0]);
    int votosNominais = Integer.parseInt(vetorDados[1]);
    String situacao = vetorDados[2];
    String nome = vetorDados[3];
    String nomeUrna = vetorDados[4];
    char sexo = vetorDados[5].charAt(0);
    String dataNascimento = vetorDados[6];

    String destinoVoto = vetorDados[7];
    int numeroPartido = Integer.parseInt(vetorDados[8]);

    this.setNumero(numero);
    this.setvotosNominais(votosNominais);
    this.setSituacao(situacao);
    this.setNome(nome);
    this.setSexo(sexo);
    this.setnomeUrna(nomeUrna);
    this.setdataNascimento(dataNascimento);
    this.setdestinoVoto(destinoVoto);
    this.setnumeroPartido(numeroPartido);

  }

  public boolean verificaDestinoVoto() {
    return this.destinoVoto.equals("Válido");
  }

  // --------------@Override---------------//

  @Override
  public String toString() {
    return this.nome + " / " + this.nomeUrna + " (" + getSiglaPartido() + " , " + this.votosNominais + " votos)";
  }

  @Override
  public int compareTo(Candidato candidato) {
    if (this.votosNominais > candidato.getvotosNominais())
      return -1;
    else if (this.votosNominais < candidato.getvotosNominais())
      return 1;
    else {
      return this.dataNascimento.compareTo(candidato.getdataNascimento());
    }
  }

  // --------------End of @Override---------------//

  // public void setIdade(Date idade) {
  // LocalDate.Period.between(this.dataNascimento, Eleicao.dataEleicao);
  // System.out.println(this.idade);
  // }

  public void setSiglaPartido(String siglaPartido) {
    this.siglaPartido = siglaPartido;

  }

  public String getSiglaPartido() {
    return siglaPartido;
  }

  public Date getIdade() {
    return idade;
  }

  public void setdestinoVoto(String destinoVoto) {
    this.destinoVoto = destinoVoto;
  }

  public String getdestinoVoto() {
    return destinoVoto;
  }

  public void setdataNascimento(String dataNascimento) {
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
    this.dataNascimento = LocalDate.parse(dataNascimento, formatter);
  }

  public LocalDate getdataNascimento() {
    return dataNascimento;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  public void setnomeUrna(String nomeUrna) {
    this.nomeUrna = nomeUrna;
  }

  public String getnomeUrna() {
    return nomeUrna;
  }

  public void setNumero(int numero) {
    this.numero = numero;
  }

  public int getNumero() {
    return numero;
  }

  public void setnumeroPartido(int numeroPartido) {
    this.numeroPartido = numeroPartido;
  }

  public int getnumeroPartido() {
    return numeroPartido;
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

  public void setvotosNominais(int votosNominais) {
    this.votosNominais = votosNominais;
  }

  public int getvotosNominais() {
    return votosNominais;
  }

}

class OrdenarPorMaisVotadoComparator implements Comparator<Candidato> {
  public int compare(Candidato a, Candidato b) {
    return Integer.compare(a.getvotosNominais(), b.getvotosNominais());
  }
}
