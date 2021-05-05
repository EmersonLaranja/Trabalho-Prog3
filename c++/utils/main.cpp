#include <iostream>
#include <string>
#include "Empresa.h"
#include "Departamento.h"
#include "Funcionario.h"
using namespace std;

int main() {
	string nome, cnpj, admissao;
	int qtdD, qtdF;
	double salario;

	cin >> nome;
	cin >> cnpj;
	cin >> qtdD;
	
	Empresa* empresa = new Empresa(nome, cnpj);

	for (int i = 0; i < qtdD; i++) {
		cin >> nome;
		cin >> qtdF;
	
		Departamento* depto = new Departamento(nome);
		empresa->adicionar(depto);

		for (int j = 0; j < qtdF; j++) {
			cin >> nome;
			cin >> salario;
			cin >> admissao;

			// O "jeito C++" é esse! (instância diretas)
			// Funcionario func(nome, salario, admissao);

			// Pro trabalho, recomendo usar instâncias indiretas!
			Funcionario* func = new Funcionario(nome, salario, admissao);
			depto->adicionar(func);
		}
	}
	empresa->darAumento(0, 10);
	empresa->transferir(0, 0, 1);
	cout << *empresa;

	delete empresa;
}
