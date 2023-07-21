#ifndef SAIDA_H_
#define SAIDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>

#include "Programa.h"
#include "stringutils.h"

using namespace std;
using namespace base;

namespace IO
{

    class Saida
    {

    public:
        void relatorio1(Programa* programa);
        void relatorio2(Programa* programa);
        void relatorio3(Programa* programa);
    };
}
#endif