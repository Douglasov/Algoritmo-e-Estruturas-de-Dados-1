#ifndef NLINHAS_H_INCLUDED
#define NLINHAS_H_INCLUDED


class nlinhas
{
private:
    int poslinhas;
    nlinhas *prox;
public:
    nlinhas();
    nlinhas(int,nlinhas *);
    ~nlinhas();
    int getposlinhas();
    nlinhas *getprox();
    void setposlinhas(int );
    void setprox(nlinhas *);

};

#endif // NLINHAS_H_INCLUDED

