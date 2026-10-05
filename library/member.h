#ifndef MEMBER_H
#define MEMBER_H

typedef struct
{
    char id[20];
    char name[50];
    char borrowedb[];
} Member;

#endif