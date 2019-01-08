#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "programa.h"
#include "pavchave.h"
#include "nlinhas.h"

using namespace std;
    //construtor padrão
    nlinhas::nlinhas()
    {
        poslinhas=0;
        prox=0;
    }
    //construtor com parametros
    nlinhas::nlinhas(int _poslinhas,nlinhas *_prox)
    {
        poslinhas=_poslinhas;
        prox=_prox;
    }
    //destrutor
    nlinhas::~nlinhas()
    {
        if(prox)
            delete prox;
        prox=0;
    }
    //metodos get
    //função utilizada para retornar o valor de poslinhas.
    int nlinhas::getposlinhas()
    {
        return poslinhas;
    }
    //função utilizada para retornar o valor de prox que contem 0 ou um endereço para uma variavel nlinhas(ou seja o proximo elemento desta lista encadeada de nlinhas).
    nlinhas *nlinhas::getprox()
    {
        return prox;
    }
    //metodos set
    //função utilizada para modificar o valor de poslinhas.
    void nlinhas::setposlinhas(int _poslinhas)
    {
        poslinhas=_poslinhas;
    }
    //função utilizada para modificar o valor de prox(ou seja o proximo elemento desta lista encadeada de nlinhas).
    void nlinhas::setprox(nlinhas *_prox)
    {
        prox=_prox;
    }
