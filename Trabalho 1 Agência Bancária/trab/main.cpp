//Nome:Douglas Santos De Oliveira Venâncio RA:28614 Turma:T1-P1
//Este programa simula uma uma agencia fazendo operações bancarias basicas como criação de contas,tranferencia,depositos,etc.
//OBS:Após tentar de todo modo criar a função encerra conta com utilizando ponteiros e desalocar a memoria da conta encerrada
//,foi apenas possivel deletar er reordenar a conta e não desalocar a memoria, então deixe este metodo em comentarios
//e criei outra função apenas copiando os valores de um para outro e desalocando no final a memoria

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "agencia.h"
#include "contas.h"
using namespace std;


int main()
{
    int numero,numorigem,numdestino;
    float valor;
    char nometitular[60];
    contacorrente *c=new contacorrente();
    agencia *itau=new agencia;
    int operacao=0;
    while(operacao!=8)
    {
        cout <<"Qual operação bancaria deseja realizar?\n1-Inserir contas\n2-Deletar contas\n3-Localizar conta\n4-Fazer deposito\n5-Fazer saque\n6-Fazer transferencia\n7-Listar Contas\n8-Sair do Programa\n";
        cin>>operacao;
        switch(operacao)
        {
        case 1:
            cout<<"\nDigite o nome do titular da conta a ser criada:\n";
            fflush(stdin);
            gets(nometitular);
            itau->abreConta(nometitular);
            break;
        case 2:
            cout<<"\nDigite o numero da conta que deseja encerrar:\n";
            cin>>numero;
            if(itau->encerraConta(numero))
            {
                cout<<"\nConta encerrada com sucesso\n";
            }
            else
            {
                cout<<"\nconta inexistente ou contem saldo\n";
            }
            break;
        case 3:
            cout<<"\nDigite o numero da conta a ser localizada:\n";
            cin>>numero;
            if(itau->localizaConta(numero))
            {
                c=itau->localizaConta(numero);
                c->mostraconta();
            }
            else
            {
                cout<<"\nconta inexistente\n";
            }
            break;
        case 4:
            cout<<"\nDigite o numero da conta a ser depositada:\n";
            cin>>numero;
            cout<<"\nDigite o valor a ser depositado:\n";
            cin>>valor;
            if(itau->deposita(numero,valor))
                cout<<"\nDeposito executado com sucesso\n";
            else
                cout<<"\nconta inexistente\n";
            break;
        case 5:
            cout<<"\nDigite o numero da conta a ser sacada:\n";
            cin>>numero;
            cout<<"\nDigite o valor a ser sacado:\n";
            cin>>valor;
            if(itau->saca(numero,valor))
                cout<<"\nsaque executado com sucesso\n";
            else
                cout<<"\nconta inexistente ou saldo insuficiente\n";
            break;
        case 6:
            cout<<"\nDigite o numero da conta de origem:\n";
            cin>>numorigem;
            cout<<"\nDigite o numero da conta de destino:\n";
            cin>>numdestino;
            cout<<"\nDigite o valor da transferencia:\n";
            cin>>valor;
            if(itau->transfere(numorigem,numdestino,valor))
                cout<<"\ntransferencia executada com sucesso\n";
            else
                cout<<"\nconta inexistente ou saldo insuficiente\n";
            break;
        case 7:
            itau->exibeTodasContas();
            break;


        }
    }
    delete itau;
    delete c;
    return 0;
}
