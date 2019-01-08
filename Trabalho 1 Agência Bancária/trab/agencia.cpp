#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "agencia.h"
#include "contas.h"
using namespace std;


agencia::agencia()
{
    ndecontas=0;
    numproxcont=1;
}

//cria uma contacorrete conta corrente se caso não ja sido tenha criado o numero maximo de contas
void agencia::abreConta(char *nomeTitular)
{
    if(ndecontas<5)
    {
        contascorrentes[ndecontas]=new contacorrente(nomeTitular,numproxcont,0);
        numproxcont=numproxcont+1;
        ndecontas++;
    }
    else if(ndecontas==5)
    {
        cout<<"\nNão e possivel criar mais contas numero maximo de contas\n";
    }
}

//saca determinado de determinada conta corrento caso a mesma exista e tenha saldo
bool agencia::saca(int numero, float valor)
{
    for(int i=0; i<ndecontas; i++)
    {
        if(numero==contascorrentes[i]->getNconta())
            return contascorrentes[i]->saca(valor);
    }
    return false;
}

//deposita determinado valor em determinada conta corrente caso ela exista
bool agencia::deposita(int numero, float valor)
{
    for(int i=0; i<ndecontas; i++)
    {
        if(numero==contascorrentes[i]->getNconta())
        {
            contascorrentes[i]->deposita(valor);
            return true;
        }
    }
    return false;
}

//transfere determinado valor entre uma conta de origem e outra de destido, caso as 2 contas existam e a conta de origem tenha saldo suficiente
bool agencia::transfere(int numOrigem, int numDestino, float valor)
{
    for(int i=0; i<ndecontas; i++)
    {
        if(numOrigem==contascorrentes[i]->getNconta())
        {
            for(int e=0; e<ndecontas; e++)
            {
                if(numDestino==contascorrentes[e]->getNconta())
                {
                    if(contascorrentes[i]->saca(valor))
                    {
                        contascorrentes[e]->deposita(valor);
                        return true;
                    }
                }
            }

        }

    }
    return false;
}

//exibe todas as contas na tela
void agencia::exibeTodasContas()
{
    for(int i=0; i<ndecontas; i++)
    {
        contascorrentes[i]->mostraconta();
    }
}

//encerra uma conta caso exista e não tenha saldo, copiando os endereços de memoria dos vetores apartir 1 posição acima dela todos os vetores acima para uma posição abaixo deles
//(mudando os endereços de cada vetor),apos libera a memoria alocada na posição ndecontas.
/*bool agencia::encerraConta(int numero)
{
    for(int e=0; e<ndecontas; e++)
    {
        if((contascorrentes[e]->getNconta()==numero)&&(contascorrentes[e]->getSaldo()==0))
        {
            for(int j=e; j<ndecontas-1; j++)
            {
                *contascorrentes[j]=*contascorrentes[j+1];
            }
            ndecontas--;
            return true;
        }
    }
    return false;
}*/

//encerra a conta especificada caso exista e tenha saldo, copiando todos os seus objetos apartir 1 posição acima dela todos os vetores acima para uma posição abaixo deles
//,apos libera a memoria alocada na posição ndecontas.
bool agencia::encerraConta(int numero)
{
    for(int e=0; e<ndecontas; e++)
    {
        if((contascorrentes[e]->getNconta()==numero)&&(contascorrentes[e]->getSaldo()==0))
        {
            for(int j=e; j<ndecontas-1; j++)
            {

                contascorrentes[j]->setNomedaconta(contascorrentes[j+1]->getNomedaconta());
                contascorrentes[j]->setNconta(contascorrentes[j+1]->getNconta());
                contascorrentes[j]->setSaldo(contascorrentes[j+1]->getSaldo());

            }
            delete contascorrentes[ndecontas-1];
            ndecontas--;
            return true;
        }
    }
    return false;
}

//encontra determinada conta corrente
contacorrente *agencia::localizaConta(int numero)
{
    for(int i=0; i<ndecontas; i++)
    {
        if(numero==contascorrentes[i]->getNconta())
        {
            return contascorrentes[i];
        }
    }
    return 0;
}
//desaloca todas contas correntes
agencia::~agencia()
{
    for(int i=0; i<ndecontas; i++)
    {
        if(contascorrentes[i])
            delete contascorrentes[i];
    }
}
