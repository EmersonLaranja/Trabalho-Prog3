#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <string>
#include "Departamento.h"
using namespace std;

class Empresa {
	string nome;
	string cnpj;
	vector<Departamento*> departamentos;

public:
	Empresa(const string& nome, const string& cnpj);
	void adicionar(Departamento* departamento);
	void darAumento(const int idx, const double percentual);
	void transferir(const int idxDeptoOrigem, const int idxFunc, const int idxDeptoDestino);
	friend ostream& operator<< (ostream &out, const Empresa &empresa);
	~Empresa();
};

#endif
