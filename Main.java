import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Main {

  public static void main(String[] args) throws FileNotFoundException {
    List<Candidato> listaDeCandidatosValidos = new ArrayList<Candidato>();
    File ArquivoCandidatos = new File("/home/emerson/Documents/Trabalho-Prog3/vitória-candidatos.csv");
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

    // -------------------------LENDO PARTIDO------------------------------------

    List<Partido> listaDePartidos = new ArrayList<Partido>();
    File ArquivoPartido = new File("/home/emerson/Documents/Trabalho-Prog3/vitória-partidos.csv");
    scanner = new Scanner(ArquivoPartido);
    scanner.nextLine();

    String[] vetorDadosPartido;

    while (scanner.hasNextLine()) {
      auxiliar = scanner.nextLine();
      vetorDadosPartido = auxiliar.split(",");

      Partido partido = new Partido(vetorDadosPartido);

      listaDePartidos.add(partido);
    }

    scanner.close();

    // --------------------------IMPRIMINDO LISTAS---------------------
    Eleicao eleicao = new Eleicao(listaDeCandidatosValidos, listaDePartidos);
    // eleicao.imprimeListaCandidatosValidos();
    // System.out.println(eleicao.getNumeroTotalEleitos());

    // --------------------------IMPRIMINDO LISTAS---------------------
    // System.out.println(eleicao.getTotalVotosNominais());
    // System.out.println(eleicao.getTotalVotosLegenda());
    // System.out.println(eleicao.getTotalVotos());
    for (Candidato candidato : eleicao.getListaDeCandidatosMaisVotadosEleitos()) {
      candidato.imprimeCandidato();
    }

  }
}