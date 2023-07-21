#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>


#include "Avaliacao.h"
using namespace base;
using namespace std;

    Avaliacao::Avaliacao(){};

    Avaliacao::Avaliacao(Disciplina* disciplina, string codigo, string nome,float peso,string data){// adicionar data dps
        this->disciplina=disciplina;
        this->codigo=codigo;
        this->nome=nome;
        this->peso=peso;
        this->data=data;
    };

    Avaliacao::Avaliacao(Disciplina *disciplina){
        this->disciplina=disciplina;
    };

    void Avaliacao::addnotasT(float nota){

    };
    
    Disciplina* Avaliacao::getDisciplina(){
        return this->disciplina;
    };

    string Avaliacao::getCodigo(){
        return this->codigo;
    };


    string Avaliacao::getNome(){
        return this->nome;
    };

    //Date getData();
    



    Aluno* Avaliacao::getAluno(long i){
        return alunosp[i];
    };
    map<long,Aluno*> Avaliacao::getListAluno(){
        return alunosp;
    };



    string Avaliacao::getData(){
        return this->data;
    };
    float Avaliacao::getNota(long i){
        return notas[i];
    };
    map<long,float> Avaliacao::getListNotas(){
        return notas;
    };



    void Avaliacao::addAluno(Aluno *aluno){
        this->alunosp[aluno->getMat()]=aluno;
    };

    void Avaliacao::addNota(long matricula,float nota){
        this->notas[matricula]=nota;
    };


    float Avaliacao::getPeso(){
        return this->peso;
    };



   float Avaliacao::mediaAvaliativa(){
    int i=0;
       float media=0;
       if(!this->getListNotas().empty()){
            for(const auto& me: notas){
                    media+=me.second;
                    i++;
                }
                media/=i;
        }
        else{
            media=0;
        }
        return  media;
    };
   
    Avaliacao::~Avaliacao(){

    };


    Prova::Prova(Disciplina* disciplina, string codigo, string nome,float peso,string data):Avaliacao(disciplina,codigo,nome,peso,data){
    };// adicionar data dps


    
    ProvaF::ProvaF(Disciplina* disciplina, string codigo, string nome,float peso,string data):Avaliacao(disciplina,codigo,nome,peso,data){// adicionar data dps
    };