#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED
#include "pavchave.h"


class programa
{
private:
pavchave *inipchave;
public:
programa();
~programa();
void inserepchave(char *);
bool arquivoaberto(char *);
bool listacontemelementos();
void leecomp(char *);
void deletepchave(char *);
void mostrapchave();
void mostraindice();
void gravaindice(char *);
char retiraacentos(char );

};


#endif // PROGRAMA_H_INCLUDED
