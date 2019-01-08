#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "pavchave.h"
#include "nlinhas.h"
#include "programa.h"

using namespace std;

    //construtor padrão
    programa::programa()
    {
        inipchave=0;
    }
    //destrutor
    programa::~programa()
    {
        if(inipchave)
            delete inipchave;
    }
    //insere palavras chave na lista de palavras em ordem alfabetica.(insere nós nas lista encadeada de pavchave e coloca uma palavra em seu respectivo vetor de caracteres)
    void programa::inserepchave(char palavra[])
    {
        strlwr(palavra);
        pavchave *aux=inipchave,*aux2;
         //verifica se a palvra recebida ja foi inserida na lista
        if(inipchave!=0)
        {
            while(aux->getprox()!=0)
            {
                if(strcmp(aux->getpchave(),palavra)==0)
                {
                    cout<<"\nA Palavra Chave ja foi inserida, nao e possivel \ninserir uma palavra chave ja inserida.\n";
                    return;
                }
                aux=aux->getprox();
            }
            if(strcmp(aux->getpchave(),palavra)==0)
                {
                    cout<<"\nA Palavra Chave ja foi inserida, nao e possivel \ninserir uma palavra chave ja inserida.\n";
                    return;
                }
        }
        //insere a palavra caso lista esteja vazia
        if(inipchave==0)
        {
            inipchave=new pavchave(palavra,0,0);
            cout<<"\n\nPalavra Inserida com Sucesso\n";
        }
        //compara a palavra ser inserida com o primeiro item da lista e a insere antes do primeiro item caso sua posição na ordenação seja menor que o primeiro.
        else if(strcmp(palavra,inipchave->getpchave())<0)
        {
            inipchave=new pavchave(palavra,0,inipchave);
            cout<<"\n\nPalavra Inserida com Sucesso\n";
        }
        //compara a palavra ser inserida com os itens da lista e a insere antes do item comparado caso sua posição na ordenação seja menor que o item comparado.
        else
        {
            aux=inipchave;
            do
            {
                if(aux->getprox()!=0)
                {
                    aux2=aux;
                    aux=aux->getprox();
                    if(strcmp(palavra,aux->getpchave())<0)
                    {
                        aux=new pavchave(palavra,0,aux);
                        aux2->setprox(aux);
                        cout<<"\n\nPalavra Inserida com Sucesso\n";
                        return;
                    }
                }

            }
            //insere a palvra no final da lista caso sua posição na ordenação seja maior que todos os itens da lista
            while(aux->getprox()!=0);

            aux2=new pavchave(palavra,0,0);
            aux->setprox(aux2);
            cout<<"\n\nPalavra Inserida com Sucesso\n";
        }
    }
    //verifica se a lista encadeada de pavchave contem elementos.
    bool programa::listacontemelementos()
    {
        if(inipchave==0)
            return false;
        return true;
    }
    //verifica se o arquivo de texto a ser lido foi aberto.
    bool programa::arquivoaberto(char nomearq[])
    {
        ifstream ifs;
        ifs.open(nomearq);
        if (ifs.is_open())
        {
            ifs.close();
            return true;
        }
        ifs.close();
        return false;

    }
    //Esta função le o texto contido no arquivo,observa e grava em quais linhas as palavras chave ocorrem.
    void programa::leecomp(char nomearq[])
   {
        char frase[1000];
        char palavramod[50];
        char caractere;
        int contacaracteres=0,contalinhas=1;
        pavchave *aux;
        nlinhas *auxnl,*auxnl1;
        ifstream ifs;
        ifs.open(nomearq);
        if (ifs.is_open())
        {
            //limpa a lista de posições das linhas onde a palavra foi encontrada no texto
            aux=inipchave;
            if(aux!=0)
            {

                while(aux->getprox()!=0)
                {
                    if(aux->getposicoes()!=0)
                    {
                    aux->deletenposicoes();
                    }
                aux=aux->getprox();
                }
                if(aux->getposicoes()!=0)
                    {
                aux->deletenposicoes();
                    }
            }
            //recebe o texto do arquivo de texto.
            while(ifs.good())
            {
                if(contacaracteres==0)
                {
                    caractere=' ';
                    frase[contacaracteres]=caractere;
                    contacaracteres++;
                }
                caractere = retiraacentos( (char) ifs.get());
                //compara linha a linha a ocorencia de cada palavra chave nas linhas.
                if (caractere == '\n')
                {
                    frase[contacaracteres]=' ';
                    frase[contacaracteres+1]='\0';
                    aux=inipchave;
                    if(aux!=0)
                    {
                    while(aux->getprox()!=0)
                    {
                        palavramod[0]=' ';
                        palavramod[1]='\0';
                        strcat(palavramod,aux->getpchave());
                        strcat(palavramod," ");
                        strlwr(palavramod);
                        strlwr(frase);
                        //caso a palavra ocora na linha grava as linhas de ocorencia em ordem crecente na lista nlinhas correspondente a palavra
                        if(strstr(frase,palavramod)!=0)
                        {
                            auxnl1=aux->getposicoes();
                            if(aux->getposicoes()==0)
                            {
                                auxnl=new nlinhas(contalinhas,0);
                                aux->setposicoes(auxnl);
                            }
                            else
                            {
                                while(auxnl1->getprox()!=0)
                                {
                                    auxnl1=auxnl1->getprox();
                                }
                                auxnl=new nlinhas(contalinhas,0);
                                auxnl1->setprox(auxnl);
                            }
                        }

                        aux=aux->getprox();
                    }
                    if(aux!=0)
                    {
                        palavramod[0]=' ';
                        palavramod[1]='\0';
                        strcat(palavramod,aux->getpchave());
                        strcat(palavramod," ");
                        strlwr(palavramod);
                        strlwr(frase);
                        if(strstr(frase,palavramod)!=0)
                        {
                            auxnl1=aux->getposicoes();
                            if(aux->getposicoes()==0)
                            {
                                auxnl=new nlinhas(contalinhas,0);
                                aux->setposicoes(auxnl);
                            }
                            else
                            {
                                while(auxnl1->getprox()!=0)
                                {
                                    auxnl1=auxnl1->getprox();
                                }
                                auxnl=new nlinhas(contalinhas,0);
                                auxnl1->setprox(auxnl);
                            }
                        }
                    }
                }
                    contalinhas++;
                    contacaracteres=0;
                }
                else
                {
                    frase[contacaracteres]=caractere;
                    contacaracteres++;
                }
            }
            //verifica a ocorencia da palavra na ultima linha do texto
            frase[contacaracteres-1]=' ';
            frase[contacaracteres+1]=' ';
            frase[contacaracteres+1]='\0';
            aux=inipchave;
             if(aux!=0)
                    {
            while(aux->getprox()!=0)
            {
                        palavramod[0]=' ';
                        palavramod[1]='\0';
                        strcat(palavramod,aux->getpchave());
                        strcat(palavramod," ");
                        strlwr(palavramod);
                        strlwr(frase);
                if(strstr(frase,palavramod)!=0)
                {
                    auxnl1=aux->getposicoes();
                    if(aux->getposicoes()==0)
                    {
                        auxnl=new nlinhas(contalinhas,0);
                        aux->setposicoes(auxnl);
                    }
                    else
                    {
                        while(auxnl1->getprox()!=0)
                        {
                            auxnl1=auxnl1->getprox();
                        }
                        auxnl=new nlinhas(contalinhas,0);
                        auxnl1->setprox(auxnl);
                    }
                }

                aux=aux->getprox();
            }
            if(aux!=0)
            {
                        palavramod[0]=' ';
                        palavramod[1]='\0';
                        strcat(palavramod,aux->getpchave());
                        strcat(palavramod," ");
                        strlwr(palavramod);
                        strlwr(frase);
                if(strstr(frase,palavramod)!=0)
                {
                    auxnl1=aux->getposicoes();
                    if(aux->getposicoes()==0)
                    {
                        auxnl=new nlinhas(contalinhas,0);
                        aux->setposicoes(auxnl);
                    }
                    else
                    {
                        while(auxnl1->getprox()!=0)
                        {
                            auxnl1=auxnl1->getprox();
                        }
                        auxnl=new nlinhas(contalinhas,0);
                        auxnl1->setprox(auxnl);
                    }
                }
            }
                    }
            ifs.close();
        }
    }
    //função utilizada para deletar um elemento da lista de palavras chave,esta função percorre a lista encadeada de pavchave
    //a procura de uma palvra  igual o vetor de caractere se a encontra utiliza o destrutorcontrolado no nó desta palavra.
    void programa::deletepchave(char palavra[])
    {
        strlwr(palavra);
        pavchave *aux,*aux2;
        aux=inipchave;
        if(inipchave!=0)
        {
            if((strcmp(inipchave->getpchave(),palavra))==0)
            {
                aux=inipchave;
                inipchave=inipchave->getprox();
                aux->destrutorcontrolado();
                cout<<"\n\nPalavra deletada com Sucesso\n";
                return;
            }
            else
            {
                while(aux->getprox()!=0)
                {
                    aux2=aux;
                    aux=aux->getprox();
                    if((strcmp(aux->getpchave(),palavra))==0)
                    {
                        aux2->setprox(aux->getprox());
                        aux->destrutorcontrolado();
                        cout<<"\n\nPalavra deletada com Sucesso\n";
                        return;
                    }
                }
                if((strcmp(aux->getpchave(),palavra))==0)
                {
                    aux2->setprox(aux->getprox());
                    aux->destrutorcontrolado();
                    cout<<"\n\nPalavra deletada com Sucesso\n";
                    return;
                }
            }
            cout<<"\nA palavra chave nao foi inserida, portanto nao pode ser deletada.\n";
        }
        cout<<"\nA palavra chave nao foi inserida, portanto nao pode ser deletada.\n";

    }
    //função utilizada para mostrar a lista de palavras chave na tela.
    void programa::mostrapchave()
        {
            pavchave *aux=inipchave;;
            if(aux!=0)
            {
            while(aux->getprox()!=0&&aux!=0)
            {
                cout<<"\n"<<aux->getpchave();

                aux=aux->getprox();
            }
            cout<<"\n"<<aux->getpchave();
            }
        }
    //função utilizada para mostrar o Indice remissivel na tela.
    void programa::mostraindice()
        {
            pavchave *aux=inipchave;;
            nlinhas *auxnl;
            if(aux!=0)
            {
            while(aux->getprox()!=0&&aux!=0)
            {
                cout<<"\n"<<aux->getpchave();

                auxnl=aux->getposicoes();
                if(auxnl!=0)
                {
                    while(auxnl->getprox()!=0)
                    {
                        cout<<" "<<auxnl->getposlinhas()<<',';
                        auxnl=auxnl->getprox();
                    }
                    cout<<" "<<auxnl->getposlinhas();
                }
                aux=aux->getprox();
            }
            cout<<"\n"<<aux->getpchave();

            auxnl=aux->getposicoes();
            if(auxnl!=0)
            {
                while(auxnl->getprox()!=0)
                {
                    cout<<" "<<auxnl->getposlinhas()<<',';
                    auxnl=auxnl->getprox();
                }
                cout<<" "<<auxnl->getposlinhas();
            }
        }
        }
    //Função utilizada para gravar as palvras chaves e o as linhas de cocorrencias dela no texto em um arquivo de texto.
    void programa::gravaindice(char nomearq[])
    {
            ofstream ofs;
            pavchave *aux=inipchave;;
            nlinhas *auxnl;
            ofs.open(nomearq);
            if(ofs.is_open())
            {
            if(aux!=0)
            {
            while(aux->getprox()!=0&&aux!=0)
            {
                if(aux==inipchave)
                {
                    ofs<<aux->getpchave();
                }
                else
                    {
                ofs<<"\n"<<aux->getpchave();
                    }
                auxnl=aux->getposicoes();
                if(auxnl!=0)
                {
                    while(auxnl->getprox()!=0)
                    {
                        ofs<<" "<<auxnl->getposlinhas()<<',';
                        auxnl=auxnl->getprox();
                    }
                    ofs<<" "<<auxnl->getposlinhas();
                }
                aux=aux->getprox();
            }
            if(inipchave->getprox()!=0)
            {
            ofs<<"\n";
            }
            ofs<<aux->getpchave();
            auxnl=aux->getposicoes();
            if(auxnl!=0)
            {
                while(auxnl->getprox()!=0)
                {
                    ofs<<" "<<auxnl->getposlinhas()<<',';
                    auxnl=auxnl->getprox();
                }
                ofs<<" "<<auxnl->getposlinhas();
            }
        cout<<"\nO arquivo "<<nomearq<<" criado com sucesso.\n";
        }
        ofs.close();

            }
            else
            {
                cout<<"\nO arquivo "<<nomearq<<" nao pode ser criado.\n";
            }
    }
    //Função utilizada para tratar o texto recebido do arquivo de texto lido removendo acentuações,pontos e virgulas.
    char programa::retiraacentos(char c)
 {
       switch (c) {
         case 'Á':
         case 'À':
         case 'Ã':
           c='A';
           break;
         case 'É':
         case 'Ê':
           c='E';
           break;
         case 'Í':
           c='I';
           break;
         case 'Ó':
         case 'Õ':
         case 'Ô':
           c='O';
           break;
         case 'Ú':
           c='U';
           break;
         case 'Ç':
           c='C';

         case 'á':
         case 'à':
         case 'ã':
           c='a';
           break;
         case 'é':
         case 'ê':
           c='e';
           break;
         case 'í':
           c='i';
           break;
         case 'ó':
         case 'õ':
         case 'ô':
           c='o';
           break;
         case 'ú':
           c='u';
           break;
         case 'ç':
           c='c';
           break;
        case'?':
        case'!':
        case':':
        case'.':
        case',':
        case';':
        case'"':
            c=' ';
           break;
       }
       return c;
    }
