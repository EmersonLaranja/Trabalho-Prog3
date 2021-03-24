import java.text.ParseException;
import java.time.Period;
import java.util.ArrayList;
import java.util.List;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Eleicao {
  private int numeroTotalEleitos = 0;
  private int totalVotosNominais = 0;
  private int totalVotosLegenda = 0;
  private int totalVotosValidos = 0;

  private List<Candidato> listaDeCandidatosValidos;
  private List<Candidato> listaDeCandidatosMaisVotadosEleitos;
  private List<Candidato> listaDeCandidatosMaisVotados;
  private List<Partido> listaDePartidos;
  private LocalDate dataEleicao;

  Eleicao(List<Candidato> listaDeCandidatosValidos, List<Partido> listaDePartidos, String data) throws ParseException {
    this.listaDeCandidatosValidos = listaDeCandidatosValidos;
    this.listaDePartidos = listaDePartidos;

    setListaMaisVotadosEleitos();
    setNumeroTotalEleitos();
    setTotalVotosLegenda();
    setTotalVotosNominais();
    setTotalVotosValidos();
    setListaMaisVotados();
    setDataEleicao(data);

  }

  // --------------Imprimir---------------//

  public void imprimeVotosTotaisEleicao() {
    System.out.printf("Total de votos válidos:    %d\n", totalVotosValidos);

    System.out.printf("Total de votos nominais:   %d", totalVotosNominais);
    System.out.printf(" (%.2f%%)\n", ((float) totalVotosNominais / totalVotosValidos) * 100);

    System.out.printf("Total de votos de Legenda: %d", totalVotosLegenda);
    System.out.printf(" (%.2f%%)\n", ((float) totalVotosLegenda / totalVotosValidos) * 100);

  }

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

  public void imprimeCandidatosPorIdade() {
    int idade;
    int menor30 = 0;
    int d30_40 = 0;
    int d40_50 = 0;
    int d50_60 = 0;
    int maior60 = 0;
    int total = 0;
    for (Candidato candidato : listaDeCandidatosMaisVotadosEleitos) {
      idade = Period.between(candidato.getdataNascimento(), dataEleicao).getYears();
      if (idade < 30)
        menor30++;
      else if (idade >= 30 && idade < 40)
        d30_40++;
      else if (idade >= 40 && idade < 50)
        d40_50++;
      else if (idade >= 50 && idade < 60)
        d50_60++;
      else
        maior60++;
      total++;
    }
    System.out.println("\nEleitos, por faixa etária (na data da eleição):");
    System.out.printf(" Idade < 30: %d (%.2f%%)\n", menor30, ((float) menor30 / total) * 100);
    System.out.printf("30 <= Idade < 40: %d (%.2f%%)\n", d30_40, ((float) d30_40 / total) * 100);
    System.out.printf("40 <= Idade < 50: %d (%.2f%%)\n", d40_50, ((float) d40_50 / total) * 100);
    System.out.printf("50 <= Idade < 60: %d (%.2f%%)\n", d50_60, ((float) d50_60 / total) * 100);
    System.out.printf("60 <= Idade     : %d (%.2f%%)\n", maior60, ((float) maior60 / total) * 100);

  }

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

  public void setDataEleicao(String data) {
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
    this.dataEleicao = LocalDate.parse(data, formatter);
  }

  public LocalDate getDataEleicao() {
    return dataEleicao;
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

  public String getNomePartidoPorNumero(int numero) {
    String aux = new String();

    for (Partido partido : listaDePartidos) {
      if (partido.getNumero() == numero)
        aux = partido.getNome();
    }
    return aux;
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
      this.totalVotosLegenda += partido.getvotosLegenda();
    }
  }

  public int getTotalVotosLegenda() {
    return totalVotosLegenda;
  }

  public int getTotalVotosNominais() {
    return totalVotosNominais;
  }

  public void setTotalVotosNominais() {
    for (Candidato candidato : listaDeCandidatosValidos) {
      this.totalVotosNominais += candidato.getvotosNominais();
    }
  }

  public void setTotalVotosValidos() {
    this.totalVotosValidos = totalVotosLegenda + totalVotosNominais;
  }

  public int getTotalVotosValidos() {
    return totalVotosValidos;
  }

  public void ordenaPrimeiroUltimoListaPartido() {
    OrdenarPrimeiroUltimoCandidatoPartido comparator = new OrdenarPrimeiroUltimoCandidatoPartido();
    List<Partido> novaLista = new ArrayList<Partido>(this.listaDePartidos);

    for (int i = 0; i < novaLista.size(); i++) {
      Partido aux = novaLista.get(i);
      if (aux.getTotalVotosNominais() == 0)
        novaLista.remove(aux);
    }
    novaLista.sort(comparator);

    System.out.println("\nPrimeiro e último colocados de cada partido:");
    int i = 1;
    for (Partido partido : novaLista) {
      System.out.print(i + " - ");
      partido.imprimePrimeiroUltimoPartido();
      i++;
    }
  }
}
