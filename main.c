#include "addressBook.h"
#include <stdio.h>
int main()
{
    AddressBook *book = NULL;
    addressBookInit(&book);
    PersonData newPerson = {"anzhenyu", 'm', 18, "12138", "wanjianggongxueyuan"};
    addressBookAddPerson(book, newPerson);
    addressBookPrint(book);
    return 0;
}