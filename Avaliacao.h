#ifndef AVALIACAO_H_
#define AVALIACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>


#include "Aluno.h"

using namespace std;
namespace base{

    class Disciplina;
    
    class Avaliacao{

    private:
        Disciplina *disciplina;
        string codigo;
        string nome;
        string data;
        float peso;
        map<long,Aluno*> alunosp;
        map<long,float> notas;    
        float media;

    public:
        Avaliacao();
        
        Avaliacao(Disciplina* disciplina, string codigo, string nome,float peso,string data);// adicionar data dps

        Avaliacao(Disciplina* disciplina);

        virtual void addnotasT(float nota);
        
        Disciplina* getDisciplina();

        string getCodigo();

        string getNome();

        string getData();
        
        Aluno* getAluno(long i);

        map<long,Aluno*> getListAluno();

        float getNota(long i);


        map<long,float> getListNotas();

        void addAluno(Aluno* aluno);

        void addNota(long matricula,float nota);

        float getPeso();

        virtual float mediaAvaliativa();
        virtual ~Avaliacao();
    };

    class Prova:public Avaliacao{
        public:
            Prova(Disciplina* disciplina, string codigo, string nome,float peso,string data);// adicionar data dps
    };
    class ProvaF:public Avaliacao{
        public:
            ProvaF(Disciplina* disciplina, string codigo, string nome,float peso,string data);// adicionar data dps
    };
    
}
#endif