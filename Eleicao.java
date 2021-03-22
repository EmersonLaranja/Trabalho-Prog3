import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
// import java.util.Collections;
// import java.util.Comparator;

public class Eleicao {
  private int numeroTotalEleitos = 0;
  private int total_votos_nominais = 0;
  private int total_votos_legenda = 0;
  private int total_votos_validos = 0;

  private List<Candidato> listaDeCandidatosValidos;
  private List<Candidato> listaDeCandidatosMaisVotadosEleitos;
  private List<Candidato> listaDeCandidatosMaisVotados;
  private List<Partido> listaDePartidos;
  static public Date dataEleicao;

  Eleicao(List<Candidato> listaDeCandidatosValidos, List<Partido> listaDePartidos, String data) throws ParseException {
    this.listaDeCandidatosValidos = listaDeCandidatosValidos;
    this.listaDePartidos = listaDePartidos;

    setListaMaisVotadosEleitos();
    setNumeroTotalEleitos();
    setTotalVotosLegenda();
    setTotalVotosNominais();
    setTotalVotosValidos();
    setListaMaisVotados();

    SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    this.dataEleicao = sdf.parse(data);
  }

  // --------------Imprimir---------------//

  public void imprimeCandidatosEleitos() {
    System.out.println("\nVereadores eleitos:");
    imprimeListaCandidatos(this.listaDeCandidatosMaisVotadosEleitos);
  }

  public void imprimeListaCandidatosValidos() {
    imprimeListaCandidatos(this.listaDeCandidatosValidos);
  }

  public void imprimeListaCandidatosMaisVotadosPorLimiteVagas() {
    System.out.println("\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
    int i;
    for (i = 0; i < numeroTotalEleitos; i++) {
      Candidato aux = listaDeCandidatosMaisVotados.get(i);
      System.out.print((i + 1) + " - " + aux + "\n");
    }
  }

  public void imprimeCandidatosBeneficiadosVotacaoMajoritaria() {

    System.out.println("\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:");
    System.out.println("(com sua posição no ranking de mais votados)");
    imprimeBeneficiadosPresentesLista1AusentesLista2(listaDeCandidatosMaisVotados, listaDeCandidatosMaisVotadosEleitos);

  }

  public void imprimeCandidatosBeneficiadosVotacaoProporcional() {
    System.out.println("\nEleitos, que se beneficiaram do sistema proporcional:");
    System.out.println("(com sua posição no ranking de mais votados)");
    imprimeBeneficiadosPresentesLista1AusentesLista2(listaDeCandidatosMaisVotadosEleitos, listaDeCandidatosMaisVotados);

  }

  // public void imprimeCandidatosPorIdade() {

  // float qntFeminino = 0.0F;
  // float qntMasculino = 0.0F;
  // System.out.println();
  // for (Candidato candidato : listaDeCandidatosValidos) {

  // if (candidato.getSexo() == 'F' && candidato.getSituacao().equals("Eleito"))
  // qntFeminino++;
  // }

  // qntMasculino = getNumeroTotalEleitos() - qntFeminino;
  // System.out.println("Eleitos, por sexo:");
  // float porcentagem = (qntFeminino / numeroTotalEleitos) * 100;

  // System.out.printf("Feminino: %.0f (%.2f%%)\n", qntFeminino, porcentagem);
  // porcentagem = (qntMasculino / numeroTotalEleitos) * 100;
  // System.out.printf("Masculino: %.0f (%.2f%%)\n", qntMasculino, porcentagem);

  // }

  public void imprimeCandidatosPorSexo() {

    float qntFeminino = 0.0F;
    float qntMasculino = 0.0F;
    System.out.println();
    for (Candidato candidato : listaDeCandidatosValidos) {

      if (candidato.getSexo() == 'F' && candidato.getSituacao().equals("Eleito"))
        qntFeminino++;
    }

    qntMasculino = getNumeroTotalEleitos() - qntFeminino;
    System.out.println("Eleitos, por sexo:");
    float porcentagem = (qntFeminino / numeroTotalEleitos) * 100;

    System.out.printf("Feminino: %.0f (%.2f%%)\n", qntFeminino, porcentagem);
    porcentagem = (qntMasculino / numeroTotalEleitos) * 100;
    System.out.printf("Masculino: %.0f (%.2f%%)\n", qntMasculino, porcentagem);

  }

  public void imprimeListaPartidos() {
    int i = 1;
    System.out.println("\nVotação dos partidos e número de candidatos eleitos:");
    for (Partido partido : listaDePartidos) {
      System.out.println(i + " - " + partido);
      i++;
    }
  }

  private void imprimeListaCandidatos(List<Candidato> lista) {
    int i = 1;
    for (Candidato candidato : lista) {
      System.out.print(i + " - " + candidato + "\n");
      i++;
    }
  }

  private void imprimePreservandoPosicaoMaisVotados(List<Candidato> lista) {
    int i, j;
    for (i = 0, j = 0; j < lista.size(); i++) {

      Candidato aux1 = lista.get(j);
      Candidato aux2 = listaDeCandidatosValidos.get(i);

      if (aux1.getNome().equals(aux2.getNome())) {
        System.out.println((i + 1) + " _ " + aux1);
        j++;
      }
    }
  }

  private void imprimeBeneficiadosPresentesLista1AusentesLista2(List<Candidato> lista1, List<Candidato> lista2) {
    List<Candidato> beneficiados = new ArrayList<Candidato>(lista1);
    beneficiados.removeAll(lista2);
    imprimePreservandoPosicaoMaisVotados(beneficiados);

  }

  // ----------End of of Imprimir --------------//

  // public String getNomePartidoPeloNumeroPartido(int numero_partido) {
  // String nome_partido = new String();

  // for (Partido partido : this.listaDePartidos) {
  // if (numero_partido == partido.getNumero()) {
  // nome_partido = partido.getNome();
  // }
  // }
  // return nome_partido;
  // }

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

  public List<Partido> getlistaDePartidos() {
    return listaDePartidos;
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

  public void ordenaPrimeiroUltimoListaPartido() {
    OrdenarPorMaisVotadoComparator comparator = new OrdenarPorMaisVotadoComparator();
    List<Partido> novaLista = new ArrayList<Partido>(this.listaDePartidos);
    int v = 0;

    for (int i = 0; i < this.listaDePartidos.size() - 1; i++) {
      Partido p1 = this.listaDePartidos.get(i);
      for (int j = i + 1; j < this.listaDePartidos.size(); j++) {
        Partido p2 = this.listaDePartidos.get(j);
        v = comparator.compare(p1.getCandidatoPorPosicao(0), p2.getCandidatoPorPosicao(0));
        if (v == 0) {
          if (p1.getNumero() > p2.getNumero()) {
            novaLista.add(p1);
          } else {
            novaLista.add(p2);
          }
        } else if (v == -1) {
          novaLista.add(p1);
        } else
          novaLista.add(p2);

      }
    }

    int i = 1;
    for (Partido partido : novaLista) {
      System.out.print(i + " - ");
      partido.imprimePrimeiroUltimoPartido();
      i++;
    }
  }

  // public void ordenaPrimeiroUltimoListaPartido() {
  // OrdenarPorMaisVotadoComparator comparator = new
  // OrdenarPorMaisVotadoComparator();
  // List<Partido> novaLista = new ArrayList<Partido>(this.listaDePartidos);
  // int v = 0;

  // for (int i = 0; i < this.listaDePartidos.size(); i++) {
  // Partido p1 = this.listaDePartidos.get(i);
  // for (int j = 1; j < this.listaDePartidos.size() - 1; j++) {
  // Partido p2 = this.listaDePartidos.get(j);
  // v = comparator.compare(p1.getCandidatoPorPosicao(0),
  // p2.getCandidatoPorPosicao(0));
  // if(v == 0){
  // if(p1.getNumero() > p2.getNumero()){
  // novaLista.add(p1);
  // }
  // else
  // }
  // }
  // }
  // }
  /**
   * Pegar a lista de partidos que já está ordenada e fazer um laço, onde: cada
   * partido buscamos o candidato da lista de candidatos na posição zero (o mais
   * votado) e atribuimos a um vetor de primeiros
   */

}

// @Override
// public int compareTo(Partido partido) {
// if (th)
// return 0;
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