#include "book.h"
#include "flush.h"
#include <stdio.h>
#include <string.h>

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
        fprintf(file, "%s|%s|%s|%d\n", replace[j].title, replace[j].author, replace[j].id, replace[j].tocopies);
    }
    fclose(file);
    puts("File saved successfully");
    return 0;
}


int listBooks(Book *replace)
{
    FILE *file = 0;
    int k = 0;
    file = fopen("storage/books.txt", "r");
    if(file == NULL)
    {
        puts("Error listing books!");
        return 1;
    }
    
    while(fscanf(file, "%49[^|]|%49[^|]|%19[^|]|%d\n", replace[k].title, replace[k].author, replace[k].id, &replace[k].tocopies) == 4)
    {
        printf("Title: %sAuthor: %sID number: %sTotal Copies inputted: %d\n\n", replace[k].title, replace[k].author, replace[k].id, replace[k].tocopies);
        k++;
    }
    fclose(file);
    return 0;
}


int searchByTitle(Book *replace)
{
    FILE *file = 0;
    int l = 0;
    char find[50];
    file = fopen("storage/books.txt", "r");
    if(file == NULL)
    {
        puts("Error opening the file");
        return 1;
    }
    printf("Enter the title of the book: ");
    fgets(find, sizeof(find), stdin);
    while(fscanf(file, "%49[^|]|%49[^|]|%19[^|]|%d\n", replace[l].title, replace[l].author, replace[l].id, &replace[l].tocopies) == 4)
    {
        if(strcmp(replace[l].title, find) == 0)
        {
            printf("Title: %sAuthor: %sID number: %sTotal Copies inputted: %d\n\n", replace[l].title, replace[l].author, replace[l].id, replace[l].tocopies);
            return 1;
        }
    }
    puts("No such information exist in the database");
    fclose(file);
    return 0;
}


int deleteBook(Book *replace)
{
    FILE *file = 0;
    int m = 0;
    char find[50];
    file = fopen("storage/books.txt", "r+");
    if(file == NULL)
    {
        puts("Error opening the file");
        return 1;
    }
    printf("Enter the title of the book: ");
    fgets(find, sizeof(find), stdin);
    while(fscanf(file, "%49[^|]|%49[^|]|%19[^|]|%d\n", replace[m].title, replace[m].author, replace[m].id, &replace[m].tocopies) == 4)
    {
        if(strcmp(replace[m].title, find) == 0)
        {
            fprintf(file, "");
            return 1;
        }
    }
    puts("No such information exist in the database");
    fclose(file);
}


int availableBooksC(Book *replace)
{
    FILE *file = 0;
    int n = 0;
    int total = 0;
    file = fopen("storage/books.txt", "r");
    if(file == NULL)
    {
        puts("Error opening file!");
        return 1;
    }
    
    while(fscanf(file, "%49[^|]|%49[^|]|%19[^|]|%d\n", replace[n].title, replace[n].author, replace[n].id, &replace[n].tocopies) == 4)
    {
        printf("Name: %sCopies: %d", replace[n].title, replace[n].tocopies);
        puts("");
         total += replace[n].tocopies;
         n++;
    }
    replace->avcopies = total;
    printf("Total number of available books: %d\n", replace->avcopies);
    fclose(file);
    return 0;
}