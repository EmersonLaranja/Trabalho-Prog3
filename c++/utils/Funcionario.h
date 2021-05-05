#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
using namespace std;

class Departamento; // forward declaration
					// permite declarar PONTEIROS para departamentos
					// não permite instâncias diretas para depatartamento

class Funcionario {
	string nome;
	double salario;
	string dataAdmissao;
	Departamento* departamento;

	// significa que objetos da classe departamento pode
	// acessar diretamente os atributos de funcionario 
	// mesmo que sejam privados
	friend class Departamento;

public:
	Funcionario(const string& nome, double salario, const string& dataAdmissao);
	void darAumento(double percentual);
	double getSalario() const;
};

#endif
