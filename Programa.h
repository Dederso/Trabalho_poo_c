#ifndef PROGRAMA_H_
#define PROGRAMA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

#include "Curso.h"
#include "Disciplina.h"
#include "Trabalho.h"
#include "Aluno.h"

#define numMestrado  800
#define numDoutorado  801

using namespace base;
using namespace std;

    class Programa{

        private:
            map<int,Curso*> cursos;
            map<long,Aluno*> alunos;
            map<string,Avaliacao*> avaliacoes;
            map<string,Disciplina*> disciplinas;
       
        public:
            void adicionaCurso(Curso* curso);
            void adicionaAluno(Aluno* aluno);
            void adicionaAvaliacao(Avaliacao* ava);
            void adicionaDisciplina(Disciplina* disciplina);

            Curso* getCurso(int cod);
            Aluno* getAluno(long mat);
            Avaliacao* getAvaliacao(string cod);
            Disciplina* getDisciplina(string cod);
           
            map<int,Curso*> getCursos();
            map<long,Aluno*> getAlunos();
            map<string,Avaliacao*> getAvaliacoes();
            map<string,Disciplina*> getDisciplinas();



            void iniciaPos();
            
            void registraNota(Aluno* aluno, Avaliacao* prova, float nota);
            void matricular(Aluno* aluno, Disciplina* disciplina);
            void cadastrarCurso(int numCurso,string nomeCurso);
            void cadastrarAluno(long codMat,string cursoAluno,string nome,string tipo);//verificar como sera feita a leitura cursoaluno pode ser int e nao precisar de conversao
            void cadastrarDisciplina(string codDis,string nome);
            void cadastrarAvaliacao(string codDis,string nome, string codAva,string tipo,float peso,int max,string data);//por a data
            void geraNotas(Disciplina* disciplina);

           ~Programa();

    };






#endif