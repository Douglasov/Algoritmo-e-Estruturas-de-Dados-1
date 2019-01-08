#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <direct.h>
#include "palavra.h"

using namespace std;

palavra::palavra()
{
    palav=0;
}
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
char* palavra::getpalav()
{
    return palav;
}
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
