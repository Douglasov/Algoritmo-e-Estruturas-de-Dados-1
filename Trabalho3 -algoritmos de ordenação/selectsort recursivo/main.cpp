#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <direct.h>

using namespace std;


class palavra
{
private:
    char *palav;
public:
    palavra()
    {
        palav=0;
    }
    palavra(char _palav[])
    {
        palav=new char[(strlen(_palav)+1)];
        strcpy(palav,_palav);
    }
    ~palavra()
    {
        if(palav)
            delete [] palav;
    }
    char *getpalav()
    {
        return palav;
    }
    void setpalav(char _palav[])
    {
        if(palav)
        {
            delete [] palav;
        }
        palav=new char[(strlen(_palav)+1)];
        strcpy(palav,_palav);
    }
    void setpointpav(char *_palav)
    {
        palav=_palav;
    }
    char *getpointpav()
    {
        return palav;
    }
};
class programa
{
private:
    palavra *listapav;
    int ult,fimT,iniT;
public:
    programa()
    {
        listapav=0;
        ult=0;
    }

    ~programa()
    {
        delete [] listapav;
    }

    bool conferenpalavras(char *nomearq,int numeropav)
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

    void inserepalavras(char nomearq[],int numeropav)
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

    void gravapalavrasarq(char *nomearq)
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

    void insertionsort()
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


    void selectionsort()
    {
        iniciatimer();
        int menorposicao;
        char *aux;
        for ( int i = 0; i < ult; ++i )
        {
            menorposicao = i;

            for ( int j = i+1; j < ult; ++j )
            {
                if ( strcmp(listapav[j].getpalav(),listapav[menorposicao].getpalav())<=0)
                {
                    menorposicao = j;
                }
            }
            aux = listapav[i].getpointpav();
            listapav[i].setpointpav(listapav[menorposicao].getpointpav());
            listapav[menorposicao].setpointpav(aux);
        }
    }
     //aqui foi inserido no programa
    void iniselectionsortrecursivo()
    {
        iniciatimer();
        selectionsortrecursivo(0);
    }

      void selectionsortrecursivo(int ini)
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
    //ate aqui


    void bubblesort()
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
    void ordenaquicksort()
    {
        iniciatimer();
        quicksort(listapav,0,ult-1);
    }



    int particione(palavra *l,int ini,int fim)
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
    void quicksort(palavra *l,int ini,int fim)
    {
        int piv;
        if(ini<fim)
        {
            piv = particione(l,ini,fim);
            quicksort(l,ini,piv-1);
            quicksort(l,piv+1,fim);
        }
    }

    void ordenamergesort()
    {
        iniciatimer();
        mergeSort(listapav,0,ult);
    }

    void intercala(palavra *l, int ini, int mid, int fim )
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


    void mergeSort(palavra *l, int ini, int fim )
    {
        if ( ini < ( fim - 1 ) )
        {
            int mid = (ini + fim) / 2;
            mergeSort(l, ini, mid);
            mergeSort(l, mid, fim);
            intercala(l, ini, mid, fim);
        }

    }
    void iniciatimer()
    {
        iniT = GetTickCount();
    }
    void tempexefunc()
    {
        int tempexe;
        fimT = GetTickCount();
        tempexe=((fimT-iniT));
        cout<<"\nTempo de Ordenação: "<<tempexe<<" Milisegundos";
    }
};

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
        //aqui foi inserido no programa
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
        //ate aqui

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
        cout<<"\n O tipo de ordenação não existe neste programa.\n";
    }

    }
    else
    {
        cout<<"\n O Comando tem mais ou manos de 4 argumentos.\n";
    }

    delete prog;

    return 0;
}
