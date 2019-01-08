#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "agencia.h"
#include "contas.h"
using namespace std;

//construtor padrão
contacorrente::contacorrente()
{
    nomedaconta= 0;
    nconta= 0;
    saldo = 0;
}

//construtor com parametros
contacorrente::contacorrente(char _nomedaconta[],int _nconta,float _saldo)
{
    nomedaconta=new char[strlen(_nomedaconta)+ 1];
    strcpy(nomedaconta,_nomedaconta);
    nconta=_nconta;
    saldo=_saldo;
}
//modfica o vetor de nomedaconta utilizando o valor de uma varivel fora da classe
void contacorrente::setNomedaconta(char _nomedaconta[])
{
    nomedaconta=new char[strlen(_nomedaconta)+ 1];
    strcpy(nomedaconta,_nomedaconta);
}
//modfica o valor de nconta utilizando o valor de uma varivel fora da classe
void contacorrente::setNconta(int _nconta)
{
    nconta=_nconta;
}
//modfica o valor de Saldo utilizando o valor de uma varivel fora da classe
void contacorrente::setSaldo(float _saldo)
{
    saldo=_saldo;
}

//reotorna o vetor de nomedaconta
char *contacorrente::getNomedaconta()
{
    return nomedaconta;
}
//reotorna o valor de nconta
int contacorrente::getNconta()
{
    return nconta;
}
//reotorna o valor de saldo
float contacorrente::getSaldo()
{
    return saldo;
}

//exibe na tela os valores de nomedaconta,nconta e saldo
void contacorrente::mostraconta()
{
    cout<<"Nome do Cliente: "<<nomedaconta<<"    Numero da conta:"<<nconta<<"    Saldo:"<<saldo<<"\n";
}
//faz com que saldo receba ele mesmo + valor
void contacorrente::deposita(float valor)
{
    saldo=saldo + valor;
}
//verifica se saldo é menor ou igual a valor se for retorna falso, se não saldo recebe ele mesmo - valor e retorna verdadeiro
bool contacorrente::saca(float valor)
{
    if(valor <= saldo)
    {
        saldo=saldo - valor;
        return true;
    }
    return false;
}
//desaloca da memoria nomedaconta
contacorrente::~contacorrente()
{
    if(nomedaconta) delete [] nomedaconta;
}
