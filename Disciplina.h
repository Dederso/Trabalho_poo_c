#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cassert>
#include <map>

#include "Avaliacao.h"

using namespace std;
namespace base
{
class Curso;


class ProvaF;
class Disciplina{


private:
    string codigo;
    string nome;
    ProvaF* provaF;
    map<long,Aluno*> alunosd;
    map<string,Avaliacao*> avaliacoes;
    map<long,float> notasf;
    map<long,float> notasp;

public:
    Disciplina();
    Disciplina(string codigo,string nome);
    
    string getCodigo();
    string getNome();
    float getNotaf(long mat);
    float getNotap(long mat);
    Aluno* getAluno(long mat);
    ProvaF* getProvaF();

    map<long,Aluno*> getAlunos();
    map<string,Avaliacao*> getAvaliacoes();

    void addAvaliacao(Avaliacao* ava);
    void addAluno(Aluno *aluno);
    void addNotaf(long mat,float nota);
    void addNotap(long mat,float nota);
    void addprovaF(ProvaF* provaF);
    
};

} // namespace base



#endif