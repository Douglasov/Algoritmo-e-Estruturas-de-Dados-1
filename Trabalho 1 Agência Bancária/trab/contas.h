#ifndef CONTAS_H_INCLUDED
#define CONTAS_H_INCLUDED
#include "agencia.h"
#include "contas.h"

const int MAX=5;

class contacorrente
{
private:
    char *nomedaconta;
    int nconta;
    float saldo;

public:
    contacorrente();
    contacorrente(char*,int,float);
    void setNomedaconta(char*);
    void setNconta(int);
    void setSaldo(float);
    float getSaldo();
    char *getNomedaconta();
    int getNconta();
    void mostraconta();
    void deposita(float);
    bool saca(float);
    ~contacorrente();
};

#endif // CONTAS_H_INCLUDED
