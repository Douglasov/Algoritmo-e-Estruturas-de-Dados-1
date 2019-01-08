//Nome:Douglas Santos De Oliveira Venâncio RA:28614 Turma:T1-P1
//Este programa gera um indice remissivo a partir de uma lista de palavras chaves criada através da inserção de palavras pelo usuario.
//Neste programa contém as opções como inserir e deletar palavras chave nesta lista, visualizar as palavras que compõe a lista
//e gerar um indice remissivo lendo um arquivo de texto e utilizando palavras chave da lista, mostrando o indice remissivo na tela e gerando um arquivo de texto contendo o indice remissivo.
//OBS: Utilizar file coding ASCII ou System default caso contrario o tratamento de acento no texto no arquivo de texto não funciona.
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "programa.h"
#include "pavchave.h"
#include "nlinhas.h"

using namespace std;

   int main()
    {

        char nomearq[25],palavra[25];
        int operacao=0;
        programa *indice=new programa();
        while(operacao!=5)
        {
            cout <<"Qual operacao deseja realizar?\n1-Inserir palavra na lista de palavras chave\n2-Deletar palavra da lista de palavras chave\n3-Mostar lista de palavras chaves\n";
            cout<<"4-Gerar Indice remissivel utilizando a lista de palavras chaves a partir \nde um arquivo de texto , mostra-lo na tela e grava-lo em um arquivo de texto\n5-Sair do Programa\n";
            cin>>operacao;
            switch(operacao)
            {
            case 1:
                system("CLS");
                cout<<"digite a palavra chave a ser inserida:\n";
                fflush(stdin);
                gets(palavra);
                indice->inserepchave(palavra);
                system("pause");
                system("CLS");

                break;
            case 2:
                system("CLS");
                cout<<"Digite a palavra chave a ser deletada:\n";
                fflush(stdin);
                gets(palavra);
                indice->deletepchave(palavra);
                system("pause");
                system("CLS");
                break;

            case 3:

                system("CLS");
                if(indice->listacontemelementos())
                {
                cout<<"Lista de palavras chave:\n";
                indice->mostrapchave();
                cout<<"\n\n";
                system("pause");
                system("CLS");
                }
                else
                    {
                        cout<<"A lista de palavras chave esta vazia.\n";
                        system("pause");
                system("CLS");
                    }
                break;

            case 4:
                system("CLS");
                if(indice->listacontemelementos())
                {
                cout<<"Digite o nome do arquivo de texto a ser inserido:\n";
                fflush(stdin);
                gets(nomearq);
                strcat(nomearq,".txt");
                if(indice->arquivoaberto(nomearq))
                {
                system("CLS");
                cout<<"Indice remissivel:\n";
                indice->leecomp(nomearq);
                indice->mostraindice();
                cout<<"\n\n";
                system("pause");
                system("CLS");
                cout<<"Digite o nome arquivo de texto a ser criado:\n";
                fflush(stdin);
                gets(nomearq);
                strcat(nomearq,".txt");
                indice->gravaindice(nomearq);
                }
                else
                {
                   cout << "\nO arquivo " << nomearq << " nao pode ser aberto.\n";
                }
                }
                else
                    {
                        cout<<"A lista de palavras chave esta vazia, nao ha como gerar o indice remissivel.\n";
                    }
                system("pause");
                system("CLS");
                break;

            }
        }
        delete indice;
        return 0;
    }
