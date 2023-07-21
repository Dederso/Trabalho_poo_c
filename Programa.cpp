#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

#include "Programa.h"

using namespace base;
using namespace std;






//adiciona na lista geral
void Programa::adicionaCurso(Curso* curso){//curso
    this->cursos[curso->getCodigo()]=curso;
};
void Programa::adicionaAluno(Aluno* aluno){//aluno
    this->alunos[aluno->getMat()]=aluno;
};
void Programa::adicionaDisciplina(Disciplina* disciplina){//disciplina
    this->disciplinas[disciplina->getCodigo()]=disciplina;
};
void Programa::adicionaAvaliacao(Avaliacao* ava){//avaliacao
    this->avaliacoes[ava->getCodigo()]=ava;
};


//getters das lista geral
Curso* Programa::getCurso(int cod){
    return cursos[cod];
};
Aluno* Programa::getAluno(long mat){
    return alunos[mat];
};
Avaliacao* Programa::getAvaliacao(string cod){
    return avaliacoes[cod];
};
Disciplina* Programa::getDisciplina(string cod){
    return disciplinas[cod];
};
map<int,Curso*> Programa::getCursos(){
    return this->cursos;
};
map<long,Aluno*> Programa::getAlunos(){
    return this->alunos;
};
map<string,Avaliacao*> Programa::getAvaliacoes(){
    return this->avaliacoes;
};
map<string,Disciplina*> Programa::getDisciplinas(){
    return this->disciplinas;
};




void Programa::registraNota(Aluno* aluno, Avaliacao* prova, float nota){
    prova->addAluno(aluno);
    prova->addNota(aluno->getMat(),nota);
};
void Programa::matricular(Aluno* aluno, Disciplina* disciplina){
    disciplina->addAluno(aluno);
};

void Programa::cadastrarCurso(int numCurso,string nomeCurso){
    // Cadastrar curso
    CursoGrad* curso = new CursoGrad(numCurso, nomeCurso);
    this->adicionaCurso(curso);//adiciona o curso no mapa geral de cursos   
}

void Programa::cadastrarDisciplina(string codDis,string nome){
    Disciplina* disciplina = new Disciplina(codDis, nome);//cria um objeto Disciplina e atribuia a uma variavel
    this->adicionaDisciplina(disciplina);
};

void Programa::cadastrarAvaliacao(string codDis,string nome, string codAva,string tipo,float peso,int max,string data){//por data
     string P("P"),F("F"),T("T");
     
     if (tipo==P) {
                    //sequencia de entradas do usuario e onde sao armazenadas

                    Disciplina* disciplina = this->getDisciplina(codDis);//atribui a um objeto para melhor leitura

                    Prova* prova = new Prova(disciplina, codAva, nome, peso,data);//controi um novo objeto prova
                    this->adicionaAvaliacao(prova);//adiciona a prova no mapa geral de provas
                    disciplina->addAvaliacao(prova);// adiciona a prova na lista de provas dentro da disciplina
        }

        //Cadastrar Prova Final
        else if (tipo==F) {
            //mesmo procedimento para cadastrar provas, em caso de duvida, veja acima

                    Disciplina* disciplina = this->getDisciplina(codDis);
                    ProvaF* provaf = new ProvaF(disciplina, codAva, nome,peso,data);
                    this->adicionaAvaliacao(provaf);
                    disciplina->addprovaF(provaf);
            
           
        }

        //Cadastrar Trabalho
        else if (tipo==T) {
                    Disciplina* disciplina = this->getDisciplina(codDis);
                    Trabalho* trabalho = new Trabalho(disciplina, codAva, nome, peso, max,data);
                    this->adicionaAvaliacao(trabalho);
                    disciplina->addAvaliacao(trabalho);
        }  
};


void Programa::cadastrarAluno(long codMat,string cursoAluno,string nome,string tipo){
    string G("G"),P("P"),D("D"),M("M");
    Curso* curso;


    if(tipo==G){
        int codcurso=stoi(cursoAluno);
        curso=this->getCurso(codcurso);

        AlunoGrad* aluno= new AlunoGrad(codMat,nome,curso);
            
        this->adicionaAluno(aluno);
        curso->addAlunos(aluno);
    }

    else if(tipo==P){
        if(cursoAluno==D){
            curso=this->getCurso(numDoutorado);
            AlunoPos* aluno= new AlunoPos(codMat,nome,curso);
                    
            this->adicionaAluno(aluno);
            curso->addAlunos(aluno);
        }
        else if(cursoAluno==M){
            curso=this->getCurso(numMestrado);
            AlunoPos* aluno= new AlunoPos(codMat,nome,curso);
                    
            this->adicionaAluno(aluno);
            curso->addAlunos(aluno);
        }
    }
};

void Programa::iniciaPos(){
    CursoPos* mestrado = new CursoPos(numMestrado,"Mestrado");
    CursoPos* doutorado= new CursoPos(numDoutorado,"Doutorado");

    this->adicionaCurso(mestrado);
    this->adicionaCurso(doutorado);
};


void Programa::geraNotas(Disciplina* disciplina){
        Aluno* aluno;
        Avaliacao* ava;
        ProvaF* prova;
        float media,div,fim;
        media=div=fim=0;
        for(const auto& al: disciplina->getAlunos()){
            aluno=al.second;
            for(const auto& av: disciplina->getAvaliacoes()){
                ava=av.second;
                if (ava->getListAluno().count(aluno->getMat())>0){//verifica se o aluno fez a prova
                    media+=(ava->getNota(aluno->getMat()) * ava->getPeso());//adiciona a nota do aluno
                    div+=ava->getPeso();//adiciona o peso da prova para divisão
                }
                else{
                    div+=ava->getPeso();//adiciona o peso da prova para a divisão mesmo o aluno não participando da prova, sua nota será igual a 0
                }
            }
            fim=media/div; //media parcial  
            disciplina->addNotap(aluno->getMat(),fim);
            
                if(fim<7.0){//verifica se passou direto
                    prova=disciplina->getProvaF();
                    if(prova->getListAluno().count(aluno->getMat())>0){//verifica se fez a prova final
                        fim+=prova->getNota(aluno->getMat());//adiciona a nota do aluno
                        fim/=2;//divide a soma das notas por 2
                        disciplina->addNotaf(aluno->getMat(),fim);//adiciona a nota do aluno
                    }
                    else{
                        fim/=2;//caso nao tenha feito a prova final, é considerado como 0
                        disciplina->addNotaf(aluno->getMat(),fim);// adiciona a nota do aluno
                    }
                }
                else{
                    disciplina->addNotaf(aluno->getMat(),fim);//adiciona a nota, sem necessidade de prova final
                }
                
        }
    };

Programa::~Programa(){
    Curso* curso;
    Aluno* aluno;
    Disciplina* disciplina;
    Avaliacao* avaliacao;
    for(const auto& al: this->getCursos()){
        curso=al.second;
        delete(curso);
    }

    for(const auto& al: this->getAlunos()){
        aluno=al.second;
        delete(aluno);
    }
    for(const auto& al: this->getAvaliacoes()){
        avaliacao=al.second;
        
        delete(avaliacao);
    }
    for(const auto& al: this->getDisciplinas()){
        disciplina=al.second;
        delete(disciplina);
    }
    
};
