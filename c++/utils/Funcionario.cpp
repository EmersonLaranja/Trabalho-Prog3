#include <iostream>
#include "Departamento.h"

Funcionario::Funcionario(const string& nome, double salario, const string& dataAdmissao) {
	this->nome = nome;
	this->salario = salario;
	this->dataAdmissao = dataAdmissao;
	this->departamento = NULL;
}

void Funcionario::darAumento(double percentual) {
	salario += salario * percentual / 100;
}

double Funcionario::getSalario() const {
	return salario;
}
