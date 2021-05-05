#ifndef DEPARTAMENTO_H_
#define DEPARTAMENTO_H_

#include <string>
#include <vector>
#include "Funcionario.h"
using namespace std;

class Departamento {
	string nome;
	vector<Funcionario*> funcionarios;

public:
	Departamento(const string& nome);
	const string& getNome() const;
	Funcionario* getFuncionario(int idx) const;
	void adicionar(Funcionario* funcionario);
	void darAumento(const double percentual);
	void remover(int idx);
	double calcularCusto() const;
	~Departamento();
};

#endif
