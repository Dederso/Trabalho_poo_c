#ifndef CURSO_H_
#define CURSO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

#include "Disciplina.h"


using namespace std;



namespace base{

class Aluno;

class Curso{


private:

    string nome;
    int codigo;

    
    map<string,Disciplina*> disciplinas;
    map<string,float> medias;
    map<string,float> passou;

    map<long,Aluno*> alunos;

public:
    Curso();
    Curso(string nome);
    Curso(int codigo,string nome);

    
    string getNome();
    int getCodigo();
    map<long,Aluno*> getListAlunos();
    map<string,Disciplina*> getListDisciplinas();
    map<string,float> getListMedias();
    map<string,float> getListPassou();

    Aluno* getAluno(long mat);
    Disciplina* getDisciplina(string codDis);
    float getMedia(string codDis);
    float getPassou(string codDis);

    void addAlunos(Aluno* aluno);
    void addDisciplinas(Disciplina *disciplina);
    void addMedias(string codDis,float media);
    void addPassou(string codDis,float passou);

    void calculaMedias(string codDis);
    virtual ~Curso();
};

class CursoPos:public Curso{
    public:
     CursoPos(int codigo,string nome);

};


class CursoGrad:public Curso{
    public:
        CursoGrad(int codigo,string nome);
};



}
#endif