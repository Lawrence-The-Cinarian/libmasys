#ifndef BOOK_H
#define BOOK_H
#define MAX_BOOKS 1000
#define TITLE 50
#define AUTHOR 50
#define ID 20

static int count = 0;
typedef struct
{
    char id[ID];
    char title[TITLE];
    char author[AUTHOR];
    int tocopies; //Total copies
    int avcopies; //Available copies
} Book;

int addBook(Book *replace);
int listBooks(Book *replace);
int searchByTitle(Book *replace);
int deleteBook(Book *replace);
int availableBooksC(Book *replace);
#endif