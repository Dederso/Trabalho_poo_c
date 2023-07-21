#ifndef LEITURA_H_
#define LEITURA_H_


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>

#include "Programa.h"

using namespace std;
using namespace base;

namespace IO
{
    

    class Leitura{

        public:
        
            void lerCurso(string path, Programa* programa);

            void lerDisciplinas(string path, Programa *programa);

            void lerAlunos(string path, Programa* programa);

            void lerAvaliacoes(string path, Programa* programa);// tem que por data
            
            void lerNotas(string path, Programa* programa);

    };
}

#endif