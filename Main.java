import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;

public class Main {

  public static void main(String[] args) throws FileNotFoundException {
    List<Candidato> listaDeCandidatosValidos = new ArrayList<Candidato>();
    File ArquivoCandidatos = new File(
        "/home/gabriel/Documents/UFES/EARTE/2020_2/Prog3/Trabalho/Trabalho-Prog3/vitória-candidatos.csv");
    Scanner scanner = new Scanner(ArquivoCandidatos);
    scanner.nextLine();

    String auxiliar;
    String[] vetorDadosCandidato;

    while (scanner.hasNextLine()) {
      auxiliar = scanner.nextLine();
      vetorDadosCandidato = auxiliar.split(",");

      Candidato candidato = new Candidato(vetorDadosCandidato);

      if (candidato.verificaDestinoVoto()) {

        listaDeCandidatosValidos.add(candidato);
      }
    }
    scanner.close();
    Collections.sort(listaDeCandidatosValidos);

    // -------------------------LENDO PARTIDO------------------------------------

    List<Partido> listaDePartidos = new ArrayList<Partido>();
    File ArquivoPartido = new File(
        "/home/gabriel/Documents/UFES/EARTE/2020_2/Prog3/Trabalho/Trabalho-Prog3/vitória-partidos.csv");
    scanner = new Scanner(ArquivoPartido);
    scanner.nextLine();

    String[] vetorDadosPartido;

    while (scanner.hasNextLine()) {
      auxiliar = scanner.nextLine();
      vetorDadosPartido = auxiliar.split(",");

      Partido partido = new Partido(vetorDadosPartido, listaDeCandidatosValidos);

      listaDePartidos.add(partido);
    }
    Collections.sort(listaDePartidos);
    scanner.close();

    // // --------------------------IMPRIMINDO LISTAS---------------------

    String dataEleicao = args[2];
    System.out.println(dataEleicao);
    try {
      Eleicao eleicao = new Eleicao(listaDeCandidatosValidos, listaDePartidos, dataEleicao);
      System.out.println("Vereadores eleitos: " + eleicao.getNumeroTotalEleitos());
      eleicao.imprimeCandidatosEleitos();
      eleicao.imprimeListaCandidatosMaisVotadosPorLimiteVagas();
      eleicao.imprimeCandidatosBeneficiadosVotacaoMajoritaria();
      eleicao.imprimeCandidatosBeneficiadosVotacaoProporcional();
      eleicao.imprimeListaPartidos();
      eleicao.ordenaPrimeiroUltimoListaPartido();

      System.out.println("\nEleitos, por faixa etária (na data da eleição):");

      eleicao.imprimeCandidatosPorIdade();
      eleicao.imprimeCandidatosPorSexo();
      System.out.println();

    } catch (Exception e) {
      System.out.println(e);

    }
  }
}