
 /******************************COMO RODAR O ALGORITMO:************************
    ANTES DE RODAR O PROGRAMA, COPIE OS ARQUIVOS A SEREM ORDENADOS PARA A PASTA
    DEBUG DO PROJETO.

    ATRAVES DO COMANDO 'cd' ACESSE A PASTA DEBUG DO PROJETO, ONDE O .exe DO PROJETO
    SE ENCONTRA.
    AO ENCONTRA-LA RODE A LINHA DE COMANDO NO FORMATO DO EXEMPLO A SEGUIR:

    "Trabalho3 bubblesort  15000 aurelio15000.txt aurelio15000_ordenadoBubble.txt"
      <Nome       <Nome     <Tamanho>  <arquivo a ser      <arquivo a ser gravado>
     Projeto>    Metodo>                lido>

    REPITA ESSE PASSO PARA OS METODOS:

MERGESORT:
mergesort


Trabalho3 mergesort  1000 aurelio1000.txt aurelio1000_ordenadoMERGE.txt
Trabalho3 mergesort  5000 aurelio5000.txt aurelio5000_ordenadoMERGE.txt
Trabalho3 mergesort  10000 aurelio10000.txt aurelio10000_ordenadoMERGE.txt
Trabalho3 mergesort  15000 aurelio15000.txt aurelio15000_ordenadoMERGE.txt
Trabalho3 mergesort  20000 aurelio20000.txt aurelio20000_ordenadoMERGE.txt
Trabalho3 mergesort  30000 aurelio30000.txt aurelio30000_ordenadoMERGE.txt
Trabalho3 mergesort  40000 aurelio40000.txt aurelio40000_ordenadoMERGE.txt


INSERTION SORT:
insertionsort


Trabalho3 insertionsort  1000 aurelio1000.txt aurelio1000_ordenadoINSERTION.txt
Trabalho3 insertionsort  5000 aurelio5000.txt aurelio5000_ordenadoINSERTION.txt
Trabalho3 insertionsort  10000 aurelio10000.txt aurelio10000_ordenadoINSERTION.txt
Trabalho3 insertionsort  15000 aurelio15000.txt aurelio15000_ordenadoINSERTION.txt
Trabalho3 insertionsort  20000 aurelio20000.txt aurelio20000_ordenadoINSERTION.txt
Trabalho3 insertionsort  30000 aurelio30000.txt aurelio30000_ordenadoINSERTION.txt
Trabalho3 insertionsort  40000 aurelio40000.txt aurelio40000_ordenadoINSERTION.txt

SELECTION SORT:
selectionsort


Trabalho3 selectionsort  1000 aurelio1000.txt aurelio1000_ordenadoSELECTION.txt
Trabalho3 selectionsort  5000 aurelio5000.txt aurelio5000_ordenadoSELECTION.txt
Trabalho3 selectionsort  10000 aurelio10000.txt aurelio10000_ordenadoSELECTION.txt
Trabalho3 selectionsort  15000 aurelio15000.txt aurelio15000_ordenadoSELECTION.txt
Trabalho3 selectionsort  20000 aurelio20000.txt aurelio20000_ordenadoSELECTION.txt
Trabalho3 selectionsort  30000 aurelio30000.txt aurelio30000_ordenadoSELECTION.txt
Trabalho3 selectionsort  40000 aurelio40000.txt aurelio40000_ordenadoSELECTION.txt

SELECTION RECURSIVO:
selectionsortrecur


Trabalho3 selectionsortrecur 1000 aurelio1000.txt aurelio1000_ordenadoSELECTIONRECURSIVO.txt
Trabalho3 selectionsortrecur 5000 aurelio5000.txt aurelio5000_ordenadoSELECTIONRECURSIVO.txt
Trabalho3 selectionsortrecur 10000 aurelio10000.txt aurelio10000_ordenadoSELECTIONRECURSIVO.txt
Trabalho3 selectionsortrecur 15000 aurelio15000.txt aurelio15000_ordenadoSELECTIONRECURSIVO.txt
Trabalho3 selectionsortrecur 20000 aurelio20000.txt aurelio20000_ordenadoSELECTIONRECURSIVO.txt
Trabalho3 selectionsortrecur 30000 aurelio30000.txt aurelio30000_ordenadoSELECTIONRECURSIVO.txt
Trabalho3 selectionsortrecur 40000 aurelio40000.txt aurelio40000_ordenadoSELECTIONRECURSIVO.txt

BUBBLE SORT:
bubblesort


Trabalho3 bubblesort 1000 aurelio1000.txt aurelio1000_ordenadoBUBBLE.txt
Trabalho3 bubblesort 5000 aurelio5000.txt aurelio5000_ordenadoBUBBLE.txt
Trabalho3 bubblesort 10000 aurelio10000.txt aurelio10000_ordenadoBUBBLE.txt
Trabalho3 bubblesort 15000 aurelio15000.txt aurelio15000_ordenadoBUBBLE.txt
Trabalho3 bubblesort 20000 aurelio20000.txt aurelio20000_ordenadoBUBBLE.txt
Trabalho3 bubblesort 30000 aurelio30000.txt aurelio30000_ordenadoBUBBLE.txt
Trabalho3 bubblesort 40000 aurelio40000.txt aurelio40000_ordenadoBUBBLE.txt

QUICKSORT:
quicksort


Trabalho3 quicksort 1000 aurelio1000.txt aurelio1000_ordenadoQUICK.txt
Trabalho3 quicksort 5000 aurelio5000.txt aurelio5000_ordenadoQUICK.txt
Trabalho3 quicksort 10000 aurelio10000.txt aurelio10000_ordenadoQUICK.txt
Trabalho3 quicksort 15000 aurelio15000.txt aurelio15000_ordenadoQUICK.txt
Trabalho3 quicksort 20000 aurelio20000.txt aurelio20000_ordenadoQUICK.txt
Trabalho3 quicksort 30000 aurelio30000.txt aurelio30000_ordenadoQUICK.txt
Trabalho3 quicksort 40000 aurelio40000.txt aurelio40000_ordenadoQUICK.txt



    ******************************************************************************/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <direct.h>
#include "programa.h"

using namespace std;


int main(int argc,char **argv)
{
    programa *prog=new programa();


    if(argc == 5)
    {
    if(strcmp((argv[1]),"mergesort")==0)
    {
        if(prog->conferenpalavras(argv[3],atoi(argv[2])))
        {
            prog->inserepalavras(argv[3],atoi(argv[2]));
            prog->ordenamergesort();
            prog->tempexefunc();
            prog->gravapalavrasarq(argv[4]);
        }

    }

    else if(strcmp((argv[1]),"insertionsort")==0)
        {
            if(prog->conferenpalavras(argv[3],atoi(argv[2])))
            {
                prog->inserepalavras(argv[3],atoi(argv[2]));
                prog->insertionsort();
                prog->tempexefunc();
                prog->gravapalavrasarq(argv[4]);
            }

        }

         else if(strcmp((argv[1]),"selectionsortrecur")==0)
        {
            if(prog->conferenpalavras(argv[3],atoi(argv[2])))
            {
                prog->inserepalavras(argv[3],atoi(argv[2]));
                prog->iniselectionsortrecursivo();
                prog->tempexefunc();
                prog->gravapalavrasarq(argv[4]);
            }

        }


    else if(strcmp((argv[1]),"bubblesort")==0)
        {
            if(prog->conferenpalavras(argv[3],atoi(argv[2])))
            {
                prog->inserepalavras(argv[3],atoi(argv[2]));
                prog->bubblesort();
                prog->tempexefunc();
                prog->gravapalavrasarq(argv[4]);
            }

        }

    else if(strcmp((argv[1]),"quicksort")==0)
        {
            if(prog->conferenpalavras(argv[3],atoi(argv[2])))
            {
                prog->inserepalavras(argv[3],atoi(argv[2]));
                prog->ordenaquicksort();
                prog->tempexefunc();
                prog->gravapalavrasarq(argv[4]);
            }

        }

    else if(strcmp((argv[1]),"selectionsort")==0)
        {
            if(prog->conferenpalavras(argv[3],atoi(argv[2])))
            {
                prog->inserepalavras(argv[3],atoi(argv[2]));
                prog->selectionsort();
                prog->tempexefunc();
                prog->gravapalavrasarq(argv[4]);

            }

        }
    else
    {
        cout<<"\n O tipo de ordena��o n�o existe neste programa.\n";
    }

    }
    else
    {
        cout<<"\n O Comando tem mais ou manos de 4 argumentos.\n";
    }

    delete prog;

    return 0;
}
