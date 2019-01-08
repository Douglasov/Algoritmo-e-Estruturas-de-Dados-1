#ifndef PALAVRA_H_INCLUDED
#define PALAVRA_H_INCLUDED
class palavra
{
private:
    char *palav;
public:
    ///**********CONTRUTORES DESTRUTORES***********
    palavra();
    palavra(char _palav[]);
    ~palavra();

    ///*********GETTERS E SETTERS*********
    char *getpalav();
    char *getpointpav();

    void setpalav(char _palav[]);
    void setpointpav(char *_palav);
};

#endif // PALAVRA_H_INCLUDED
