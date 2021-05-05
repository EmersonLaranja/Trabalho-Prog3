#include <iostream>
#include "Empresa.h"
#include "NumberUtils.h"

Empresa::Empresa(const string& nome, const string& cnpj) {
	this->nome = nome;
	this->cnpj = cnpj;
}

void Empresa::adicionar(Departamento* departamento) {
	departamentos.push_back(departamento);
}

void Empresa::darAumento(const int idx, const double percentual) {
	departamentos[idx]->darAumento(percentual);
}

void Empresa::transferir(const int idxDeptoOrigem, const int idxFunc, const int idxDeptoDestino) {
	Funcionario* f = departamentos[idxDeptoOrigem]->getFuncionario(idxFunc);
	departamentos[idxDeptoDestino]->adicionar(f);
	departamentos[idxDeptoOrigem]->remover(idxFunc);
}

Empresa::~Empresa() {
	for (auto d : departamentos)
		delete d;
}

ostream& operator<<(ostream &out, const Empresa &empresa) {
	for (auto& d : empresa.departamentos)
		out << d->getNome() << " R$ " << formatDoubleCurrency(d->calcularCusto(), LOCALE_PT_BR) << endl;
	return out;
}

