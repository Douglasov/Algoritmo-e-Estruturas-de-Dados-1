#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <direct.h>
#include "programa.h"

using namespace std;


 ///***************CONSTRUTORES E DESTRUTOR*********

programa::programa()
{
    listapav=0;
    ult=0;
}

programa::~programa()
{
    delete [] listapav;
}


///****************METODOS DE ORDENAÇÃO************


///METODO PARA VERIFICAR SE O NUMERO DE PALAVRAS NO
///ARQUIVO ESTA DE ACORDO COM O QUE FOI DIGITADO
///E CHECA A INTEGRIDADE DO ARQUVO DE TEXTO
bool programa::conferenpalavras(char *nomearq,int numeropav)
{
    int contapalavras=0;
    char caractere;
    ifstream ifs;
    ifs.open(nomearq);
    if (ifs.is_open())
    {
        while(ifs.good())
        {
            caractere = (char) ifs.get();
            if (caractere == '\n')
            {
                contapalavras++;
            }
        }
        ifs.close();
        if(contapalavras!=numeropav-1)
        {
            cout<<"\nNumero de palavras existentes no arquivo diferente do numero digitado, o comando não sera executado.\n";
            return false;
        }
        return true;
    }
    else
    {
        cout<<"\nNão foi possivel Abrir o Arquivo.\n";
        return false;
    }
}


///CRIA UM VETOR DE PALAVRAS COM AS PALAVRAS "PUXADAS"
///DO ARQUIVO DE TEXTO PARA QUE POSSA DEPOIS SER ORDENADA
void programa::inserepalavras(char nomearq[],int numeropav)
{
    char pav[50];
    char caractere;
    int contacaracteres;
    int contapalavras;
    ifstream ifs;
    ifs.open(nomearq);
    if (ifs.is_open())
    {
        listapav=new palavra[numeropav];
        ult=numeropav;
        contacaracteres = 0;
        contapalavras = 0;
        while(ifs.good())
        {
            caractere = (char) ifs.get();
            pav[contacaracteres]=caractere;
            if (caractere == '\n')
            {
                pav[contacaracteres]='\0';
                strlwr(pav);
                listapav[contapalavras].setpalav(pav);
                contacaracteres = 0;
                contapalavras++;
            }
            else
            {
                contacaracteres++;
            }
        }
        pav[contacaracteres-1]='\0';
        strlwr(pav);
        listapav[contapalavras].setpalav(pav);
        ifs.close();
    }
}


///GRAVA NA PASTA "SAIDA" O ARQUIVO DE TEXTO DE NOME DEFINIDO
///PELO USUARIO COM AS PALAVRAS JA DEVIDAMENTE ORDENADAS
///CONSIDERANDO QUE AS COM ACENTO FICAM NO FINAL
///DA ORDENAÇÃO
void programa::gravapalavrasarq(char *nomearq)
{
    ofstream ofs;
    char caminho[50] = "SAIDA\\";
    strcat(caminho,nomearq);
    char pasta[] = "SAIDA";
    mkdir(pasta);
    ofs.open(caminho);
    if(ofs.is_open())
    {
        for(int i=0; i<ult; i++)
        {
            ofs<<listapav[i].getpalav();
            if(i!=(ult-1))
            {
                ofs<<"\n";
            }
        }
    }
}


///INSERTION SORT
void programa::insertionsort()
{
    iniciatimer();
    char *aux;
    int last;
    for ( int i = 1; i < ult; ++i )
    {

        aux = listapav[i].getpointpav();
        last=i;
        while((last>= 0)&&(strcmp(listapav[last].getpalav(),aux)>=0 ))
        {

            listapav[last].setpointpav(listapav[last-1].getpointpav());
            last--;
        }
        listapav[last+1].setpointpav(aux);
    }
}

///SELECTION SORT
void programa::selectionsort()
{
    iniciatimer();
    int menorposicao;
    char *menorpav,*aux;
    for ( int i = 0; i < ult; ++i )
    {
        menorposicao = i;
        menorpav = listapav[i].getpointpav();
        for ( int j = i+1; j < ult; ++j )
        {
            if ( strcmp(listapav[j].getpalav(),menorpav)<=0)
            {
                menorposicao = j;
                menorpav= listapav[j].getpointpav();
            }
        }
        aux = listapav[i].getpointpav();
        listapav[i].setpointpav(listapav[menorposicao].getpointpav());
        listapav[menorposicao].setpointpav(aux);
    }
}


///SELECTION SORT RECURSIVO
void programa::iniselectionsortrecursivo()
{
    iniciatimer();
    selectionsortrecursivo(0);
}

void programa::selectionsortrecursivo(int ini)
{
    int menorposicao;
    char *aux;
    if(ini<ult)
    {
        menorposicao = ini;
        for ( int i = ini+1; i < ult; ++i )
        {
            if ( strcmp(listapav[i].getpalav(),listapav[menorposicao].getpalav())<=0)
            {
                menorposicao = i;
            }
        }
        aux = listapav[ini].getpointpav();
        listapav[ini].setpointpav(listapav[menorposicao].getpointpav());
        listapav[menorposicao].setpointpav(aux);
        selectionsortrecursivo(ini +1);
    }
}


///BUBBLE SORT
void programa::bubblesort()
{
    iniciatimer();
    char *aux;
    for(int i=0; i<ult-1; i++)
    {
        for(int j=0; j<ult-1; j++)
        {

            if(strcmp(listapav[j].getpalav(),listapav[j+1].getpalav())>=0)
            {
                aux=listapav[j].getpointpav();
                listapav[j].setpointpav(listapav[j+1].getpointpav());
                listapav[j+1].setpointpav(aux);
            }
        }
    }
}


///ORDENAÇÃO FINAL DO QUICKSORT
void programa::ordenaquicksort()
{
    iniciatimer();
    quicksort(listapav,0,ult-1);
}



int programa::particione(palavra *l,int ini,int fim)
{
    char lastword[50], *aux;
    strcpy(lastword,l[fim].getpalav());
    int i=(ini-1);
    for(int j=ini; j<(fim); j++)
    {
        if(strcmp(l[j].getpalav(),lastword)<=0)
        {
            i++;
            aux=l[i].getpointpav();
            l[i].setpointpav(l[j].getpointpav());
            l[j].setpointpav(aux);
        }

    }
    aux=l[i+1].getpointpav();;
    l[i+1].setpointpav(l[fim].getpointpav());
    l[fim].setpointpav(aux);
    return (i+1);

}

///QUICKSORT
void programa::quicksort(palavra *l,int ini,int fim)
{
    int piv;
    if(ini<fim)
    {
        piv = particione(l,ini,fim);
        quicksort(l,ini,piv-1);
        quicksort(l,piv+1,fim);
    }
}


///ORDENAÇÃO FINAL MERGESORT
void programa::ordenamergesort()
{
    iniciatimer();
    mergeSort(listapav,0,ult);
}


///FUNÇÃO INTERCALA DO MERGE
void programa::intercala(palavra *l, int ini, int mid, int fim )
{
    int iniinterc=ini, midinterc=mid, k=0;
    palavra *aux;
    aux = new palavra[(fim-ini)];

    while ( ( iniinterc < mid ) && ( midinterc < fim ))
    {
        if (strcmp(l[iniinterc].getpalav(),l[midinterc].getpalav())<=0)
        {
            aux[k].setpalav(l[iniinterc].getpalav());
            k++;
            iniinterc++;
        }
        else
        {
            aux[k].setpalav(l[midinterc].getpalav());
            k++;
            midinterc++;
        }
    }
    while ( iniinterc < mid )
    {
        aux[k].setpalav(l[iniinterc].getpalav());
        k++;
        iniinterc++;
    }
    while ( midinterc <  fim )
    {
        aux[k].setpalav(l[midinterc].getpalav());
        k++;
        midinterc++;
    }

    for ( iniinterc = ini; iniinterc < fim; ++iniinterc )
    {
        l[iniinterc].setpalav(aux[iniinterc-ini].getpalav());
    }
    delete [] aux;
}

///MERGE SORT
void programa::mergeSort(palavra *l, int ini, int fim )
{
    if ( ini < ( fim - 1 ) )
    {
        int mid = (ini + fim) / 2;
        mergeSort(l, ini, mid);
        mergeSort(l, mid, fim);
        intercala(l, ini, mid, fim);
    }

}

///VALOR INICIAL PARA CONTAR O TEMPO
void programa::iniciatimer()
{
    iniT = GetTickCount();
}

///CALCULO FINAL DO TEMPO TRANSCORRIDO DURANTE A ORDENAÇÃO
void programa::tempexefunc()
{
    int tempexe;
    fimT = GetTickCount();
    tempexe=((fimT-iniT));
    cout<<"Tempo de Ordenacao: "<<tempexe<<" Milisegundos"<<endl;
}
