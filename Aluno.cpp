#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "Aluno.h"

using namespace std;

using namespace base;



    Aluno::Aluno(){};
    Aluno::Aluno(long matricula, string nome){
        this->matricula=matricula;
        this->nome=nome;
    };
    Aluno::Aluno(long matricula, string nome, Curso *curso){
        this->matricula=matricula;
        this->nome=nome;
        this->curso=curso;
    };

    long Aluno::getMat(){
        return this->matricula;
    };
    string Aluno::getNome(){
        return this->nome;
    }
    Curso* Aluno::getCurso(){
        return this->curso;
    };


    Aluno::~Aluno(){};







    AlunoGrad::AlunoGrad(long matricula, string nome, Curso *curso):Aluno(matricula,nome,curso){
    };

    AlunoPos::AlunoPos(long matricula, string nome, Curso *curso):Aluno(matricula,nome,curso){    
    };

