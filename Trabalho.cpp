#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>


#include "Trabalho.h"

using namespace std;
using namespace base;

            Trabalho::Trabalho(){};
            Trabalho::Trabalho(Disciplina* disciplina, string codigo, string nome, float peso, int max,string data):Avaliacao(disciplina,codigo,nome,peso,data){
                this->max=max;
                this->grupos=0;
            };// falta data
            
            int Trabalho::getMax(){
                return max;
            };
            int Trabalho::getGrupos(){
                return grupos;
            };
            float Trabalho::getNotaT(int i){
                return notasT[i];
            };
            vector<float> Trabalho::getListnotasT(){
                return notasT;
            };

            void Trabalho::addnotasT(float nota){
                this->grupos++;
                this->notasT.push_back(nota);
            };

            float Trabalho::mediaAvaliativa(){
                float media=0;
                for(auto me: notasT){
                    media+=me;          
                }
                media/=this->grupos;
                   
                return media;
            };
            