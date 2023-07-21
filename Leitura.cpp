#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

#include "Leitura.h"
#include "Programa.h"
#include "stringutils.h"


using namespace std;
using namespace base;
using namespace IO;






void Leitura::lerCurso(string path, Programa* programa){
    ifstream in(path);
    
    string linha;
    getline(in,linha);
    while (getline(in,linha))
    {

        // pega a linha toda e separa por ";"
        // cada vetor vira uma string diferente
        vector<string> vetor = StringUtils::splitString(linha, ';');

        // tira espaços em branco
        vetor[0] = StringUtils::trim(vetor[0]);
        vetor[1] = StringUtils::trim(vetor[1]);


        int numCurso = StringUtils::string_to_int(vetor[0]);
        string nomeCurso = vetor[1];
       
        //cout<<numCurso<<" "<<nomeCurso<<endl;
       
        programa->cadastrarCurso(numCurso, nomeCurso);
    }
};

void Leitura::lerDisciplinas(string path, Programa *programa){
    ifstream in(path);

    string linha;
    getline(in, linha);
    while (getline(in, linha))
    {

        // pega a linha toda e separa por ";"
        // cada vetor vira uma string diferente
        vector<string> vetor = StringUtils::splitString(linha, ';');

        // tira espaços em branco
        vetor[0] = StringUtils::trim(vetor[0]);
        vetor[1] = StringUtils::trim(vetor[1]);

        string codDis = vetor[0];
        string nomeDis = vetor[1];

        programa->cadastrarDisciplina(codDis, nomeDis);
    }
};

void Leitura::lerAlunos(string path, Programa* programa){
    Disciplina* disciplina;
    Curso* curso;

    ifstream in(path);
    string linha;
    getline(in, linha);
    while (getline(in, linha))
    {
        // pega a linha toda e separa por ";"
        // cada vetor vira uma string diferente
        vector<string> vetor = StringUtils::splitString(linha, ';');

        for(int i=0;i<vetor.size();i++){
            vetor[i]= StringUtils::trim(vetor[i]);
        }
        
        long codMat = StringUtils::string_to_long(vetor[0]);
        string nome = vetor[1];

        vector<string> codDis = StringUtils::splitString(vetor[2], ',');
        string tipo = vetor[3];
        string cursoAluno = vetor[4];

        programa->cadastrarAluno(codMat, cursoAluno, nome, tipo);

        Aluno* aluno = programa->getAluno(codMat);

        int aux = codDis.size();
        while (aux > 0)
        {
            codDis[aux - 1] = StringUtils::trim(codDis[aux - 1]);
            disciplina = programa->getDisciplina(codDis[aux - 1]);      // atribui a disciplina a uma variavel

            curso = aluno->getCurso();                                    // atribui o curso do aluno a uma variavel

            programa->matricular(aluno, disciplina); // matricula o aluno na disciplina


            if (curso->getListDisciplinas().count(disciplina->getCodigo())<=0)
            {                                                      
             curso->addDisciplinas(disciplina); 
                                                 
            }
            aux--;
        }
    }
};

void Leitura::lerAvaliacoes(string path, Programa* programa){
    ifstream in(path);

    int max=0;
    string linha;
    getline(in, linha);
    while (getline(in, linha))
    {

        // pega a linha toda e separa por ";"
        // cada vetor vira uma string diferente
        vector<string> vetor = StringUtils::splitString(linha, ';');

        int aux = vetor.size();
        for (int i = 0; i < aux; i++)
        {
            vetor[i] = StringUtils::trim(vetor[i]);
        }

        string codDis = vetor[0];
        string codAva = vetor[1];
        string nome = vetor[2];
        float peso = stof(vetor[3]);
        
        string tipo = vetor[4];
        string data = vetor[5];
        if (tipo=="T")
        {
            max = StringUtils::string_to_int(vetor[6]);
        }

        programa->cadastrarAvaliacao(codDis, nome, codAva, tipo, peso, max,data);
    }
    in.close();
};// tem que por data
            


void Leitura::lerNotas(string path, Programa* programa){
    ifstream in(path);
    Aluno* aluno;
    Avaliacao* ava;
    string linha;
    getline(in, linha);
    while (getline(in, linha))
    {

        // pega a linha toda e separa por ";"
        // cada vetor vira uma string diferente
        vector<string> vetor = StringUtils::splitString(linha, ';');

        for (int i = 0; i < vetor.size(); i++){
            vetor[i] = StringUtils::trim(vetor[i]);
        }
        // tira espaços em branco
        
        string codAva = vetor[0];
        
        string matriculas= vetor[1];
        
        float notaS = stof(vetor[2]); 
        
        vector<string> matDiv = StringUtils::splitString(matriculas, ',');
        
        for (int i = 0; i < matDiv.size(); i++){
            matDiv[i] = StringUtils::trim(matDiv[i]);
        }
        
        int aux= matDiv.size();
        ava=programa->getAvaliacao(codAva);
        ava->addnotasT(notaS);
        
        while(aux>0){
            long matAluno = StringUtils::string_to_long(matDiv[aux-1]);
            aluno=programa->getAluno(matAluno);
            programa->registraNota(aluno,programa->getAvaliacao(codAva),notaS);
            aux--;
        }
    }
};