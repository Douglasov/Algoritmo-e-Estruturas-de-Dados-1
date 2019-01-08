#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "pavchave.h"
#include "nlinhas.h"
#include "programa.h"

using namespace std;
    //construtor padrão
    pavchave::pavchave()
    {
        pchave=0;
        posicoes=0;
        prox=0;
    }
    //construtor com parametros
    pavchave::pavchave(char _pchave[],nlinhas *_posicoes,pavchave *_prox)
    {
        pchave=new char[strlen(_pchave)+1];
        strcpy(pchave,_pchave);
        posicoes=_posicoes;
        prox=_prox;
    }
     //destrutor
    pavchave::~pavchave()
    {
        if(pchave)
            delete [] pchave;
        if(posicoes)
            delete posicoes;
        posicoes=0;
        if(prox)
            delete prox;
        prox=0;
    }
    //Destrutor controlado utilizado para a exclusão de palavras chave diferente do destrutor comum
    //ele exclui apenas um no da lista encadeada pavchave e toda lista encadeada nlinha referente a esta pavchave.
    void pavchave::destrutorcontrolado()
    {
         if(pchave)
            delete [] pchave;
        if(posicoes)
            delete posicoes;
    }
    //funciona exatamente como o destrutor de nlinhas mas ele ja contem
    //o endereço da lista encadeada nlinha referente a pavchave dessa forma não sendo necesario passaar endereços para auxiliares.
    void pavchave::deletenposicoes()
    {
        if(posicoes)
            delete posicoes;
        posicoes=0;
    }
    //metodos get
    //função utilizada para retornar o vetor de caracteres em pchave.
    char *pavchave::getpchave()
    {
        return pchave;
    }
     //função utilizada para retornar o valor de posicoes que contem 0 ou um endereço para uma variavel nlinhas
     //(ou seja o primeiro endereço da lista encadeada de nlinhas referente a pavchave).
    nlinhas *pavchave::getposicoes()
    {
        return posicoes;
    }
     //função utilizada para retornar o valor de prox que contem 0 ou um endereço para uma variavel pavchave(ou seja o proximo elemento desta lista encadeada de pavchave).
    pavchave *pavchave::getprox()
    {
        return prox;
    }
    //metodos set
    //função utilizada para modificar o vetor de caracteres contido em pchave.
    void pavchave::setpchave(char _pchave[])
    {
        delete [] pchave;
        pchave=new char[strlen(_pchave)+1];
        strcpy(pchave,_pchave);
    }
    //função utilizada para modificar o valor de prox(ou seja o proximo elemento desta lista encadeada de pavchave).
    void pavchave::setprox(pavchave *_prox)
    {
        prox=_prox;
    }
    //função utilizada para modificar o valor de posicoes(ou seja o primeiro endereço da lista encadeada de nlinhas referente a pavchave).
    void pavchave::setposicoes(nlinhas *_posicoes)
    {
        posicoes=_posicoes;
    }
