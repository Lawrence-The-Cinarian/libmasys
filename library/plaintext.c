#include "plaintext.h"
#include <stdio.h>

void menuForChoosingBetweenMembersAndBooks()
{
    puts("Welcome to the Library Management System (LMS)");
    puts("Please enter in the number of your option below");
    puts("");
    puts("(1) Book Section");
    puts("(2) Member Section");
    puts("(0) Exit");
    puts("");
}


void welcomeMessageForBookSection()
{
    puts("");
    puts("Welcome to the Book Section");
    puts("Please enter in the number of your option below");
    puts("(1) Add books");
    puts("(2) List books");
    puts("(3) Search by title");
    puts("(4) Delete Book");
    puts("(5) View Available books amd its copies");
    puts("(0) Exit");
    puts("");
}


void welcomeMessageForMemberSection()
{
    puts("");
    puts("Welcome to the Member Section");
    puts("Please enter in the number of your option below");
    puts("(1) Add Member");
    puts("(2) View Member");
    puts("(3) Borrow Book");
    puts("(4) Return Book");
    puts("(5) Search Book");
    puts("(6) List Book");
    puts("(0) Exit");
    puts("");
}