#include "addressBook.h"
#include <stdio.h>
int main()
{
    AddressBook *book = NULL;
    addressBookInit(&book);

    printf("add person an\n");
    PersonData newPerson1 = {"anzhenyu", 'm', 18, "12138", "皖江工学院"};
    addressBookAddPerson(book, newPerson1);

    printf("add person li\n");
    PersonData newPerson2 = {"lining", 'w', 18, "10086", "伊犁师范大学"};
    addressBookAddPerson(book, newPerson2);
    addressBookPrint(book);

    printf("delete person an\n");
    addressBookDeletePerson(book, "anzhenyu");
    addressBookPrint(book);
    return 0;
}