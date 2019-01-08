#ifndef AGENCIA_H_INCLUDED
#define AGENCIA_H_INCLUDED
#include "agencia.h"
#include "contas.h"


class agencia
{

private:
    contacorrente *contascorrentes[MAX];
    int ndecontas;
    int numproxcont;

public:
    agencia();
    void abreConta(char *);
    bool saca(int , float );
    bool deposita(int , float );
    bool transfere(int, int, float);
    void exibeTodasContas();
    bool encerraConta(int);
    contacorrente *localizaConta(int);
    ~agencia();
};
#endif // AGENCIA_H_INCLUDED
