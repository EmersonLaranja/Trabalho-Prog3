#include <string>
using namespace std;
class Candidato
{
private:
  unsigned numero;
  unsigned votosNominais;
  unsigned numeroPartido;
  char sexo;
  string situacao;
  string destinoVoto;
  string nome;
  string nomeUrna;
  string siglaPartido;
  // LocalDate dataNascimento;
  // Date idade;
  const char MASCULINO = 'M';
  const char FEMININO = 'F';

public:
  Candidato(/* args */);

  bool verificaDestinoVoto();

  void setSiglaPartido(string siglaPartido);

  string getSiglaPartido();

  void setDestinoVoto(string destinoVoto);

  string getdestinoVoto();

  void setDataNascimento(string dataNascimento);

  void setNome(string nome);

  string getNome();

  void setNomeUrna(string nomeUrna);

  string getnomeUrna();

  void setNumero(unsigned numero);

  unsigned getNumero();

  void setNumeroPartido(unsigned numeroPartido);

  unsigned getnumeroPartido();

  void setSexo(char sexo);

  char getSexo();

  void setSituacao(string situacao);

  string getSituacao();

  void setVotosNominais(unsigned votosNominais);

  unsigned getvotosNominais();

  // Date getIdade();
  // LocalDate getdataNascimento();

  Candidato::Candidato(string vetorDados[])
  {
  }

  Candidato::~Candidato()
  {
  }
};