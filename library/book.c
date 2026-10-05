#include "book.h"
#include "flush.h"
#include <stdio.h>

static int count = 0;

int addBook(Book *replace)
{
    printf("How many types of book are we adding: ");
    scanf("%d", &count);
    flush();
    for(int i = 0; i < count; i++)
    {
        puts("");
        printf("Title of book: ");
        fgets(replace[i].title, sizeof(replace[i].title), stdin);
        printf("Author of book: ");
        fgets(replace[i].author, sizeof(replace[i].author), stdin);
        printf("Please enter your ID number: ");
        fgets(replace[i].id, sizeof(replace[i].id), stdin);
        printf("Total copies that you want to add: ");
        scanf("%d", &replace[i].tocopies);
        flush();
    }
    
    FILE *file = 0;
    file = fopen("storage/books.txt", "a");
    if(file == NULL)
    {
        puts("Error opening file!");
        return 1;
    }
    for(int j = 0; j < count; j++)
    {
        fprintf(file, "%s %s %s %d\n", replace[j].title, replace[j].author, replace[j].id, replace[j].tocopies);
    }
    fclose(file);
    puts("File saved successfully");
    return 0;
}