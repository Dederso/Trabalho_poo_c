#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

#include "Curso.h"

using namespace std;
using namespace base;



 
    Curso::Curso(){

    };
    Curso::Curso(string nome){
        this->nome=nome;
    };
    Curso::Curso(int codigo,string nome){
        this->nome=nome;
        this->codigo=codigo;
    };

    
    
    string Curso::getNome(){
        return nome;
    };
    int Curso::getCodigo(){
        return codigo;
    };

    map<long,Aluno*> Curso::getListAlunos(){
        return alunos;
    };
    map<string,Disciplina*> Curso::getListDisciplinas(){
        return disciplinas;
    };
    map<string,float> Curso::getListMedias(){
        return medias;
    };
    map<string,float> Curso::getListPassou(){
        return passou;
    };


    Aluno* Curso::getAluno(long mat){
        return alunos[mat];
    };
    Disciplina *Curso::getDisciplina(string codDis){
        return disciplinas[codDis];
    };
    float Curso::getMedia(string codDis){
        return medias[codDis];
    };
    float Curso::getPassou(string codDis){
        return passou[codDis];
    };


    void Curso::addAlunos(Aluno* aluno){
        this->alunos[aluno->getMat()]=aluno;
    };

    void Curso::addDisciplinas(Disciplina *disciplina){
        this->disciplinas[disciplina->getCodigo()]=disciplina;
    };
    void Curso::addMedias(string codDis,float media){
        this->medias[codDis]=media;
    };
    void Curso::addPassou(string codDis,float passou){
        this->passou[codDis]=passou;
    };

    void Curso::calculaMedias(string codDis){
        Disciplina* disciplina;
        Aluno* aluno;
        disciplina=this->getDisciplina(codDis);
        float total,media,div,passou;
        total=media=div=passou=0;
        for(const auto& par : alunos){
            aluno=par.second;//atribuindo ao aluno
            if( disciplina->getAlunos().count(aluno->getMat())>0){
                total++;// total de alunos do curso na disciplina

                media += disciplina->getNotaf(aluno->getMat());// pega a media do aluno
                div++;// auxiliar de divisao
                if (disciplina->getNotaf(aluno->getMat()) >= 5.0) {// verifica quem teve uma nota final maior que 5
                    passou++;// total de alunos que passaram
                }
            }
        }
    };


    Curso::~Curso(){

    };



    CursoPos::CursoPos(int codigo,string nome):Curso(codigo,nome){
    };
    
    CursoGrad::CursoGrad(int codigo,string nome):Curso(codigo,nome){
    };