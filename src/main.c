#include "../library/book.h"
#include "../library/member.h"
#include "../library/flush.h"
#include "../library/plaintext.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    Book registerd[MAX_BOOKS];
    Member registers;
    int option = 0;
    char symbol = '\0';
    
    do
    {
        menuForChoosingBetweenMembersAndBooks();
        printf("Enter: ");
        scanf("%d", &option);
        flush();
    
        //For Book Section;
        if(option == 1)
        {
            welcomeMessageForBookSection();
            printf("Enter: ");
            scanf("%d", &option);
            flush();
        
            switch(option)
            {
                case 1:
                addBook(registerd);
                break;
            
                case 2:
                listBooks(registerd);
                break;
            
                case 3:
                searchByTitle(registerd);
                break;
            
                case 4:
                deleteBook(registerd);
                break;
            
                case 5:
                availableBooksC(registerd);
                break;
                
                case 0:
                return 0;
            
                default:
                puts("Invalid option");
            }
        
        }
    
        else if(option == 2)
        {
            welcomeMessageForMemberSection();
            printf("Enter: ");
            scanf("%d", &option);
            flush();
        
            switch(option)
            {
                case 1:
                addMember(&registers);
                break;
            
                case 2:
                listMember(&registers);
                break;
            
                case 3:
                break;
            
                case 4:
                break;
            
                case 5:
                break;
            
                case 0:
                return 0;
            
                default:
                puts("Invalid option");
            }
        }
        
        else break;
        
        printf("Would you like to continue? Y[es] or N[o]]: ");
        scanf(" %c", &symbol);
        if(!(symbol == 'Y' || symbol == 'y')) break;
    }
    while(true);
 
 
    

    return 0;
}