#include <iostream>
#include "programa.h"

using namespace std;

void MenuOrdenacoes(int tamanho, string v[])
{

    int escolha=1;
    while (escolha!=5)
    {

        printf("\n\n Escolha o metodo de ordenacao - Base de dados %d",tamanho ,"%d palavras");

        printf("\n 1 - Selecao Iterativo");
        printf("\n 2 - Selecao Recursivo ");
        printf("\n 3 - Insercao");
        printf("\n 4 - Bolha");
        printf("\n 5 - Mergesort");
        printf("\n 6 - Quicksort ");
        printf("\n 7 - Sair ");
        printf("\n\n Escolha uma opcao: ");
        scanf("%d",&escolha);


        switch (escolha)
        {
        case 1:
        {
            system("cls");

            float tempo;
            selection_sortIterativo(tamanho, v);

            cout<<tempo<<" Milissegundos";
            GravarArquivo(tamanho,v);
            break;
        }

        case 2:
        {
            system("cls");


            float tempo;
        ;
            selectionSortRecursivo(tamanho, v);


            cout<<tempo<<" Milissegundos";
            GravarArquivo(tamanho,v);
            break;
        }

        case 3:
        {
            system("cls");

            float tempo;

            insertionSort(tamanho, v);

            cout<<tempo<<" Milissegundos";
            GravarArquivo(tamanho,v);
            break;
        }


        }
        case 4:
        {
            system("cls");
            /
            float tempo;

            BubbleSort(tamanho, v);

            cout<<tempo<<" Milissegundos";
            GravarArquivo(tamanho,v);
            break;
        }

        case 5:
        {
            system("cls");

            float tempo;

            mergeSort( v,tamanho);

            cout<<tempo<<" Milissegundos";
            GravarArquivo(tamanho,v);
            break;
        }
        case67:
        {
            system("cls");

            float tempo;

            quickSortIterative(v,0,tamanho-1);

            cout<<tempo<<" Milissegundos";
            GravarArquivo(tamanho,v);
            break;
        }



        default:
        {
            system("cls");
            if( escolha==7)
            {
                continue;
            }
            printf("\n\n Nenhuma opcao foi escolhida ");
            break;
        }

        }

    }

    if( escolha==8)
        printf("\n\n O Programa foi fechado");

    getch();

}




int main()
{
    int escolha=1;

    int tamanho;
    while (escolha!=5)
    {

        printf("\n\n Escolha uma Base de Palavras para ordenacao");

        printf("\n 1 - 1000 palavras ");
        printf("\n 2 - 5000 palavras ");
        printf("\n 3 - 10000 palavras ");
        printf("\n 4 - 15000 palavras ");
        printf("\n 5 - 20000 palavras ");
        printf("\n 6 - 30000 palavras ");
        printf("\n 7 - 40000 palavras ");
        printf("\n 8 - Fechar Programa ");
        printf("\n\n Escolha uma opcao: ");
        scanf("%d",&escolha);


        switch (escolha)
        {
        case 1:
        {
            system("cls");
            arquivo = fopen("aurelio1000.txt", "r");
            tamanho =1000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                count++;
            }
            MenuOrdenacoes(tamanho,s);

            break;
        }

        case 2:
        {
            system("cls");
            arquivo = fopen("aurelio5000.txt", "r");
            tamanho =5000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                //printf("%s", vet1[count]); //Imprime os registros
                count++;
            }
            MenuOrdenacoes(tamanho,s);
            break;
        }

        case 3:
        {
            system("cls");
            arquivo = fopen("aurelio10000.txt", "r");
            char vet [10000][TamanhoString];
            tamanho =10000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                //printf("%s", vet1[count]); //Imprime os registros
                count++;
            }
            MenuOrdenacoes(tamanho,s);
            break;
        }

        case 4:
        {
            system("cls");
            arquivo = fopen("aurelio15000.txt", "r");
            tamanho =15000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                //printf("%s", vet1[count]); //Imprime os registros
                count++;
            }
            MenuOrdenacoes(tamanho,s);
            break;
        }
        case 5:
        {
            system("cls");
            arquivo = fopen("aurelio20000.txt", "r");
            tamanho =20000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                //printf("%s", vet1[count]); //Imprime os registros
                count++;
            }
            MenuOrdenacoes(tamanho,s);
            break;
        }
        case 6:
        {
            system("cls");
            arquivo = fopen("aurelio30000.txt", "r");
            tamanho =30000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                //printf("%s", vet1[count]); //Imprime os registros
                count++;
            }
            MenuOrdenacoes(tamanho,s);
            break;
        }
        case 7:
        {
            system("cls");
            arquivo = fopen("aurelio40000.txt", "r");
            tamanho =40000;

            int count =0;

            while(fgets(vet1[count], TamanhoString, arquivo))
            {
                s[count]=vet1[count];
                //printf("%s", vet1[count]); //Imprime os registros
                count++;
            }
            MenuOrdenacoes(tamanho,s);
            break;
        }
        case 8:
        {
            system("cls");

            continue;
        }


        default:
        {
            system("cls");
            if( escolha==9)
            {
                continue;
            }
            printf("\n\n Nenhuma opcao foi escolhida ");
            break;
        }

        }

    }

    if( escolha==8)
        printf("\n\n O Programa foi fechado");

    getch();
}

