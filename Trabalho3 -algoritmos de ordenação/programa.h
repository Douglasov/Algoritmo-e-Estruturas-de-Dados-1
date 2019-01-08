#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED
#include "palavra.h"


class programa
{
private:
    palavra *listapav;
    int ult, fimT, iniT;
public:
    ///***************CONSTRUTORES E DESTRUTOR*********
    programa();
    ~programa();


    ///****************METODOS DE ORDENAÇÃO************
    bool conferenpalavras(char *nomearq,int numeropav);
    void inserepalavras(char nomearq[],int numeropav);
    void gravapalavrasarq(char *nomearq);
    void insertionsort();
    void selectionsort();
    void iniselectionsortrecursivo();
    void selectionsortrecursivo(int ini);
    void bubblesort();
    void ordenaquicksort();
    int particione(palavra *l,int ini,int fim);
    void quicksort(palavra *l,int ini,int fim);
    void ordenamergesort();
    void intercala(palavra *l, int ini, int mid, int fim );
    void mergeSort(palavra *l, int ini, int fim );
    void iniciatimer();
    void tempexefunc();

};

#endif // PROGRAMA_H_INCLUDED
