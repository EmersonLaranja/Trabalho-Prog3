#include <iostream>
#include "Departamento.h"

Departamento::Departamento(const string& nome) {
	this->nome = nome;
}

// sobre o retorno!
// string Departamento::getNome() // faço cópia no retorno
// string& Departamento::getNome() // PROIBIDO!!!!
// Retorns const string& // é eficiente (não faz cópia) e não deixa
// modificar do lado de fora do objeto
const string& Departamento::getNome() const {
	return nome;
}

Funcionario* Departamento::getFuncionario(int idx) const {
	return funcionarios[idx];
}

void Departamento::adicionar(Funcionario* funcionario) {
	funcionario->departamento = this;
	funcionarios.push_back(funcionario);
}

// dando aumento para todos os funcionários
void Departamento::darAumento(const double percentual) {
	for(auto& f : funcionarios)
		f->darAumento(percentual);
}

// Removendo o funcionário de índice idx da lista de funcionários
void Departamento::remover(int idx) {
	funcionarios.erase(begin(funcionarios) + idx);
}

// Calculando o custo do departamento
double Departamento::calcularCusto() const {
	double soma = 0;
	for (auto& f : funcionarios)
		soma += f->getSalario();
	return soma;
}

Departamento::~Departamento() {
	for (auto f : funcionarios) {
		delete f;
	}
}