#ifndef TRABALHO_H_
#define TRABALHO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>

#include "Avaliacao.h"

using namespace std;

namespace base
{
    
    class Trabalho:public Avaliacao{
        private:
            int max;
            int grupos;
            vector<float> notasT;


        public:
            Trabalho();
            Trabalho(Disciplina* disciplina, string codigo, string nome, float peso, int max,string data);// falta data
            
            int getMax();
            int getGrupos();
            float getNotaT(int i);
            vector<float> getListnotasT();

            void addnotasT(float nota) override;
            float mediaAvaliativa() override;

    };
}

#endif