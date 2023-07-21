#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

#include "Saida.h"
#include "Programa.h"
#include "stringutils.h"


using namespace std;
using namespace base;
using namespace IO;

auto priorityComparator1 = [](const std::string& s1, const std::string& s2) {
        std::string valor1 = s1.substr(s1.find(';') + 1); // Prioridade 1
        std::string valor2 = s2.substr(s2.find(';') + 1);
        return valor1 < valor2;
};


struct PrioridadeComparator2 {
    int operator()(const std::string& s1, const std::string& s2) const {
        std::vector<std::string> parts1, parts2;
        size_t pos1 = 0, pos2 = 0;
        while (pos1 != std::string::npos) {
            size_t end_pos = s1.find(";", pos1);
            parts1.push_back(s1.substr(pos1, end_pos - pos1));
            pos1 = (end_pos == std::string::npos) ? end_pos : end_pos + 1;
        }
        while (pos2 != std::string::npos) {
            size_t end_pos = s2.find(";", pos2);
            parts2.push_back(s2.substr(pos2, end_pos - pos2));
            pos2 = (end_pos == std::string::npos) ? end_pos : end_pos + 1;
        }

        // Obtém os valores de acordo com a ordem de prioridade
        std::string valor1 = parts1[0]; // Prioridade 1
        std::string valor2 = parts2[0];

        std::string valor3 = parts1[3]; // Prioridade 2
        std::string valor4 = parts2[3];

        std::string valor5 = parts1[2]; // Prioridade 3
        std::string valor6 = parts2[2];

        // Compara os valores de acordo com a ordem de prioridade
        int comparacao = valor1.compare(valor2);
        if (comparacao != 0) {
            return comparacao;
        }

        comparacao = valor4.compare(valor3);
        if (comparacao != 0) {
            return comparacao;
        }

        return valor5.compare(valor6);
    }
};

struct PrioridadeComparator3 {
    int operator()(const std::string& s1, const std::string& s2) const {
        std::vector<std::string> parts1, parts2;
        size_t pos1 = 0, pos2 = 0;
        while (pos1 != std::string::npos) {
            size_t end_pos = s1.find(";", pos1);
            parts1.push_back(s1.substr(pos1, end_pos - pos1));
            pos1 = (end_pos == std::string::npos) ? end_pos : end_pos + 1;
        }
        while (pos2 != std::string::npos) {
            size_t end_pos = s2.find(";", pos2);
            parts2.push_back(s2.substr(pos2, end_pos - pos2));
            pos2 = (end_pos == std::string::npos) ? end_pos : end_pos + 1;
        }

        // Obtém os valores de acordo com a ordem de prioridade
        std::string valor1 = parts1[0]; // Prioridade 1
        std::string valor2 = parts2[0];

        // Compara os valores de acordo com a ordem de prioridade
        int comparacao = valor1.compare(valor2);
        if (comparacao != 0) {
            return comparacao;
        }

        // Comparando as datas como strings
        std::string valor3 = parts1[3]; // Prioridade 2
        std::string valor4 = parts2[3];

        comparacao = valor3.compare(valor4);
        if (comparacao != 0) {
            return comparacao;
        }

        return 0; // Se os valores de prioridade 1 e 2 forem iguais, não é necessário comparar a prioridade 3
    }
};


void Saida::relatorio1(Programa* programa)
{
    // variaveis inicializadas
    Disciplina* disciplina;
    Aluno* aluno;
    Avaliacao*ava;
    float notap = 0, notaf = 0, media = 0, peso = 0, div = 0;
    ostringstream stream;
    string stringC = "";
    int aux = 0;
    for (auto dis : programa->getDisciplinas())
    {
        disciplina = dis.second;
        programa->geraNotas(disciplina);
        stringC = "";
        ofstream out("1-pauta-" + disciplina->getCodigo() + ".csv");
        
        // abre e cria o arquivo e o buffer de escrita
        // escrevendo o cabeçalho
        out<<"Matrícula;Aluno;";

        if (!disciplina->getAvaliacoes().empty())
        { // escreve as provas
            for (auto p : disciplina->getAvaliacoes())
            {   
                ava=p.second;
                out<<ava->getCodigo()<<";";
            }
        }
        
        out<<"Média Parcial;Prova Final;Média Final"<<endl; // resto do cabeçalho

        for (auto me : disciplina->getAlunos())
        {                                           // acessa os alunos presentes na disciplina
            aluno = me.second;                  // associa o aluno a uma variavel
            notap = notaf = 0;// zera as variaveis
            notap = disciplina->getNotap(aluno->getMat());
            notaf = disciplina->getNotaf(aluno->getMat()); // zera as variaveis
            stream<<aluno->getMat();
            stringC+= stream.str() +";"+ aluno->getNome()+";"; // coloca as informações dos alunos a uma unica string string
            stream.str("");
            if (!disciplina->getAvaliacoes().empty())
            {
                for (auto p : disciplina->getAvaliacoes())
                {
                    ava=p.second;
                    stream<<fixed<<setprecision(2)<<ava->getNota(aluno->getMat());
                    stringC +=stream.str()+";"; // coloca as provas na string
                    stream.str("");
                    // pega as informaçoes para  calcular a media
                }
            }
            stream<<fixed<<setprecision(2)<<notap;
            stringC +=stream.str()+";"; // adiciona a media parcial na string
            stream.str("");
            if (notap < 7)
            { // verifica se o aluno passou direto
                if (disciplina->getProvaF()->getListAluno().count(aluno->getMat())>0)
                {       
                    stream<<fixed<<setprecision(2)<<disciplina->getProvaF()->getNota(aluno->getMat());
                    
                    stringC += stream.str()+";"; 
                    stream.str("");
                    
                    stream<<fixed<<setprecision(2)<<notaf;   
                    
                    
                    stringC += stream.str();          
                    stream.str("");                                
                    }
                else
                {
                    stringC += 0 + ";"; // adiciona na string
                    stream<<fixed<<setprecision(2)<<notaf;   
                    
                    
                    stringC += stream.str();          
                    stream.str("");            
                }
                
            }
            else
            {

                stringC += "-;"; // caso tenha passado direto a nota da final não existe
                stream<<fixed<<setprecision(2)<<notaf;   
                stringC += stream.str();          
                stream.str("");            
            }
            stringC += "&"; // separação de linha
        }
        
        vector<string> alunos = StringUtils::splitString(stringC,'&'); // adiciona um token no final de cada aluno para que seja separada em um vetor de strings
        aux = alunos.size(); // pega o tamanho das strings

        sort(alunos.begin(),alunos.end(),priorityComparator1); // organiza o vetor em ordem alfabetica

        for (int i = 0; i < aux; i++)
        {                        // adiciona os alunos de acordo com o nome
            out<<alunos[i]; // adiciona o aluno no arquivo
            out<<endl;        // salta uma linha
        }
    }
}





void Saida::relatorio2(Programa* programa)
{
    // variaveis
    Disciplina* disciplina;
    Curso* curso;
    Aluno* aluno;
    ostringstream stream;
    float total = 0, passou = 0, media = 0, div = 0;
    string stringC = "";
                                                               
    ofstream out("2-disciplinas.csv"); // buffer de escrita
    out<<"Código;Disciplina;Curso;Média;% Aprovados"; // escreve o cabeçalho
    for (auto dis : programa->getDisciplinas())
    {                                // pega todas as disciplinas
        disciplina = dis.second; // atribui a uma variavel
        programa->geraNotas(disciplina);   // calcula a nota final
        for (auto me2 : programa->getCursos())
        {                           // pega todos os cursos
            curso = me2.second; // atribui a uma variavel
            if (curso->getListDisciplinas().count(disciplina->getCodigo())>0)
            { // verifica se a disciplina
            // está presente nesse curso
                for (auto me : disciplina->getAlunos())
                { // pega os alunos da
                    // disciplina

                    aluno = me.second; // atribui a uma variavel
                    // PROCURANDO O ALUNO UM A UM DENTRO DO CURSO
                    if (curso->getListAlunos().count(aluno->getMat())>0)
                    {            // verifica se o aluno faz
                                    // parte do curso
                        total++; // total de alunos do curso na disciplina

                        media += disciplina->getNotaf(aluno->getMat()); // pega a media do aluno
                        div++;                                              // auxiliar de divisao
                        if (disciplina->getNotaf(aluno->getMat()) >= 5.0)
                        {             // verifica quem teve uma nota
                                        // final maior que 5
                            passou++; // total de alunos que passaram
                        }
                    }
                }
                media /= div; // dividindo a soma de medias e transformando em media de medias
                passou = (passou * 100) / total;
                
                
                stream<<disciplina->getCodigo()<<";"<<disciplina->getNome()<<";"<<curso->getNome()<<";";
                stringC+=stream.str();
                stream.str("");
                stream<<fixed<<setprecision(2)<<media;
                stringC+=stream.str()+";";
                stream.str("");
                stream<<fixed<<setprecision(1)<<passou;
                stringC+=stream.str()+"%"+"&";
                // zera variaveis
                div = media = 0;
                total = passou = 0;
            }
        }
    }

    vector<string> linhas = StringUtils::splitString(stringC, '&');

    int aux = linhas.size();

    sort(linhas.begin(), linhas.end(), PrioridadeComparator2());

    for (int i = 0; i < aux; i++)
    {
        out<<endl;
        out<<linhas[i];
    }
}


void Saida::relatorio3(Programa* programa)
{ // relatoria de avaliacao
    Avaliacao* ava;
    Disciplina* disciplina;
    string stringC = "";
    ostringstream stream;
    Trabalho* tra;
    ofstream out("3-avaliacoes.csv");                 // buffer de escrita
    out<<"Disciplina;Código;Avaliação;Data;Média\n"; // escreve o cabeçalho

    for (auto me : programa->getDisciplinas())
    {
        disciplina = me.second;
        for (auto me2 : disciplina->getAvaliacoes())
        {
            ava = me2.second; // atribui avaliação
            stream<<disciplina->getCodigo()<<";"<<ava->getCodigo()<<";"<<ava->getNome()<<";"<<ava->getData()<<";";
            stringC+=stream.str();
            stream.str("");
            stream<<fixed<<setprecision(2)<<ava->mediaAvaliativa();
            stringC+=stream.str()+"&";
            stream.str("");
        }
                    
    }
                
        vector<string> strings = StringUtils::splitString(stringC, '&');
        int aux = strings.size(); // pega o tamanho das strings
        
        sort(strings.begin(),strings.end(),PrioridadeComparator3());
        
        for (int i = 0; i < aux - 1; i++)
        { // adiciona a string dos alunos uma a uma no arquivo, e salta para a proxima linha

            out<<(strings[i]); // adiciona
            out<<endl;         // salta
        }

        out<<(strings[aux - 1]); // adiciona o ultimo aluno, sem saltar uma linha a mais
        out<<endl;
}
