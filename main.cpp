#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

#include "Programa.h"
#include "Leitura.h"
#include "Saida.h"


using namespace std;
using namespace base;
using namespace IO;

int main(int argc, char *argv[])
{   
    Programa* programa= new Programa();
    Leitura* leitura= new Leitura();
    Saida* saida= new Saida();
    programa->iniciaPos();
    string pathAluno;
    string pathCursos;
    string pathAvaliacoes;
    string pathNotas;
    string pathDisciplinas;
    int i = 0; 
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-c") {
            i++;  
            pathCursos = argv[i];
        }
        else if (arg == "-d") {
            i++;          
            pathDisciplinas = argv[i];
           
        } else if (arg == "-p") {
            i++;            
            pathAvaliacoes = argv[i];
           
        } else if (arg == "-a") {
            i++;            
            pathAluno = argv[i];
           
        } else if (arg == "-n") {
            i++;
            pathNotas = argv[i];
        }
    }
    // le os arquivos

    leitura->lerCurso(pathCursos, programa);

    leitura->lerDisciplinas(pathDisciplinas, programa);
    leitura->lerAlunos(pathAluno, programa);
    leitura->lerAvaliacoes(pathAvaliacoes, programa);
    leitura->lerNotas(pathNotas, programa);
    // escreve os arquivos
    saida->relatorio1(programa);
    saida->relatorio2(programa);
    saida->relatorio3(programa);



    delete(programa);
    delete(leitura);
    delete(saida);
    
    return 0;
}
