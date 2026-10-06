#include "book.h"
#include "flush.h"
#include "member.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int addMember(Member *replace){
    puts("");
    printf("Enter you membership name: ");
    fgets(replace->name, sizeof(replace->name), stdin);
    printf("Enter your membership ID number: ");
    fgets(replace->id, sizeof(replace->id), stdin);
    
    FILE *file = 0;
    file = fopen("storage/member.txt", "w");
    if(file == NULL)
    {
        puts("Error opening file!");
        return 1;
    }
    fprintf(file, "%s|%s\n", replace->name, replace->id);
    fclose(file);
    puts("Member added successfully");
    return 0;
}

int listMember(Member *replace)
{
    FILE *file = 0;
    int i = 0;
    file = fopen("storage/member.txt", "r");
    if(file == NULL)
    {
        puts("Error viewing present member");
        return 1;
    }
    
    while(fscanf(file, "%49[^|]|%19[^|]|\n", replace[i].name, replace[i].id) == 2)
    {
        printf("Member: %sID number: %s", replace[i].name, replace[i].id);
        i++;
    }
    fclose(file);
    return 0;
}


int borrowBook(Member *replace, Book *replace2)
{
    char find[20];
    int j = 0;
    FILE *file = 0;
            file = fopen("storage/member.txt", "r");
            if(file == NULL)
            {
                puts("Such folder does not exist!");
                return 1;
            }
            puts("");
            
        while(true)
        {
            printf("Enter your membership name: ");
            fgets(find, sizeof(find), stdin);
            
             while(fscanf(file, "%49[^|]|%19[^|]|\n", replace[j].name, replace[j].id) == 2)
             {
                 if(strcmp(replace[j].name, find) == 0)
                 {
                     puts("Member found");
                     break;
                 }
                 
                 else
             }
             puts("No such membership name exist, please try again");
        }
        
        fclose(file);
    printf("How many books do you want to borrow: ");
    scanf("%d", &count);
    flush();
    for(int k = 0; k < count; k++)
    {
        printf("Enter ID number of book");
        fgets(replace2[k].id, sizeof(replace2[k].id), stdin);
    }
    return 0;
}