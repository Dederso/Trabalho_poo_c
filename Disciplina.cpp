#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cassert>
#include <map>

#include "Disciplina.h"


using namespace std;
using namespace base;

    Disciplina::Disciplina(){

    };
    Disciplina::Disciplina(string codigo,string nome){
        this->codigo=codigo;
        this->nome=nome;
    };
    
    string Disciplina::getCodigo(){
        return this->codigo;
    };
    string Disciplina::getNome(){
        return this->nome;
    };
    
    map<long,Aluno*> Disciplina::getAlunos(){
        return this->alunosd;
    };

    void Disciplina::addAluno(Aluno* aluno) {
        alunosd[aluno->getMat()] = aluno;
    }

    Aluno* Disciplina::getAluno(long mat){
        return alunosd[mat];
    };


    float Disciplina::getNotaf(long mat){
        return notasf[mat];
    };
    float Disciplina::getNotap(long mat){
        return notasp[mat];
    };
    void Disciplina::addNotaf(long mat, float nota){
        this->notasf[mat]=nota;
    };
    void Disciplina::addNotap(long mat, float nota){
        this->notasp[mat]=nota;
    };

    ProvaF* Disciplina::getProvaF(){
        return this->provaF;
    };
    void Disciplina::addprovaF(ProvaF* provaF){
        this->provaF=provaF;
    };






    map<string,Avaliacao*> Disciplina::getAvaliacoes(){
        return this->avaliacoes;
    };

    void Disciplina::addAvaliacao(Avaliacao* ava){
        this->avaliacoes[ava->getCodigo()]=ava;
    };