#ifndef PAVCHAVE_H_INCLUDED
#define PAVCHAVE_H_INCLUDED
#include "nlinhas.h"

class pavchave
{
private:
    char *pchave;
    nlinhas *posicoes;
    pavchave *prox;

public:
    pavchave();
    pavchave(char *,nlinhas *,pavchave *);
    ~pavchave();
    void destrutorcontrolado();
    void deletenposicoes();
    char *getpchave();
    nlinhas *getposicoes();
    pavchave *getprox();
    void setpchave(char *);
    void setprox(pavchave *);
    void setposicoes(nlinhas *);
};

#endif // PAVCHAVE_H_INCLUDED
