#include "book.h"
#include "flush.h"
#include "member.h"
#include <stdio.h>


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
    int k = 0;
    file = fopen("storage/member.txt", "r");
    if(file == NULL)
    {
        puts("Error viewing present member");
        return 1;
    }
    
    while(fscanf(file, "%49[^|]|%19[^|]|\n", replace[k].name, replace[k].id) == 2)
    {
        printf("Member: %sID number: %s", replace[k].name, replace[k].id);
        k++;
    }
    fclose(file);
    return 0;
}