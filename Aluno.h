#ifndef ALUNO_H_
#define ALUNO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>



using namespace std;

namespace base{
    class Curso;

    class Aluno{
    
        long matricula;
        string nome; 
        Curso *curso;
        friend class Curso;

        public:
        Aluno();
        Aluno(long matricula, string nome);
        Aluno(long matricula, string nome, Curso *curso);

        long getMat();
        string getNome(); //implementar
        Curso* getCurso();
        virtual ~Aluno();
    };


    class AlunoPos:public Aluno{
        public:
            AlunoPos(long matricula, string nome, Curso *curso);
    };

    class AlunoGrad:public Aluno{
        public:
            AlunoGrad(long matricula, string nome,Curso *curso);
    };

}




#endif