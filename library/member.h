#ifndef MEMBER_H
#define MEMBER_H
#define MEMBER_ID 20
#define MEMBER_NAME 50
#define MEMBER_BORROW_LIMIT 15
#include "book.h"

typedef struct
{
    char id[MEMBER_ID];
    char name[MEMBER_NAME];
} Member;

int addMember(Member *replace);
int listMember(Member*replace);
int borrowBook(Member *replace, Book *replace2);

#endif