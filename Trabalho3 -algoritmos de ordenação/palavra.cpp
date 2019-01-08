#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <direct.h>
#include "palavra.h"

using namespace std;


///**********CONTRUTORES DESTRUTORES***********
palavra::palavra()
{
    palav=0;
}

///ALOCA EXATAMENTE O TAMANHO DA PALAVRA
palavra::palavra(char _palav[])
{
    palav=new char[(strlen(_palav)+1)];
    strcpy(palav,_palav);
}
palavra::~palavra()
{
    if(palav)
        delete [] palav;
}


///*********GETTERS E SETTERS*********
char* palavra::getpalav()
{
    return palav;
}

///ALOCA EXATAMENTE O TAMANHO DA PALAVRA
void palavra::setpalav(char _palav[])
{
    if(palav)
    {
        delete [] palav;
    }
    palav=new char[(strlen(_palav)+1)];
    strcpy(palav,_palav);
}

void palavra::setpointpav(char *_palav)
{
    palav=_palav;
}

char* palavra::getpointpav()
{
    return palav;
}
