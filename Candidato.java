public class Candidato {
  private int numero;
  private int votos_nominais;
  private String situacao;
  private String destino_voto;
  private String nome;
  private String nome_urna;
  private String nome_partido;
  private char sexo; // 1 feminino e 0 masculino
  private String data_nasc;
  // private boolean destino_voto; //só é usado para verificar se é valido ao
  // criar um candidato
  private int numero_partido;
  // static public int numeroVotosNominais = 0;

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

  public void imprimeCandidato() {
    // System.out.println(getNome() + " / " + getNome_urna() + " (" +
    // getNomePartidoPeloNumeroPartido(this.numero_partido)
    // + ", " + getVotos_nominais() + " votos)");
  };

  public void setDestino_voto(String destino_voto) {
    this.destino_voto = destino_voto;
  }

  public String getDestino_voto() {
    return destino_voto;
  }

  public void setData_nasc(String data_nasc) {
    this.data_nasc = data_nasc;
  }

  public String getData_nasc() {
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
