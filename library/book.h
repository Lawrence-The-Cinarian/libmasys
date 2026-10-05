#ifndef BOOK_H
#define BOOK_H
#define MAX_BOOKS 1000
#define TITLE 50
#define AUTHOR 50
#define ID 20

typedef struct
{
    char id[ID];
    char title[TITLE];
    char author[AUTHOR];
    int tocopies; //Total copies
    int avcopies; //Available copies
} Book;

int flush();
int addBook(Book *replace);

#endif