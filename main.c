#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 32
/*个人信息*/
typedef struct PersonData
{
    char name[BUFFER_SIZE];
    char sex;
    unsigned int age;
    char phone[BUFFER_SIZE];
    char addrs[BUFFER_SIZE];
} PersonData;

/*结点信息*/
typedef struct BookNode
{
    PersonData *person;
    struct BookNode *next;
    struct BookNode *prev;
} BookNode;

/*双链表存储信息*/
typedef struct AddressBook
{
    BookNode *head;
    int len;
} AddressBook;

int addressBookModify(AddressBook *addrBook, char *name, PersonData person)
{
    int ret = 0;//默认返回修改
     BookNode *travePoint = addrBook->head;
    while (travePoint != NULL)
    {
        if (strcmp(travePoint->person->name, name) == 0)
        {
            strcpy(travePoint->person->name, person.name);
            travePoint->person->sex = person.sex;
            travePoint->person->age = person.age;
            strcpy(travePoint->person->phone, person.phone);
            strcpy(travePoint->person->addrs, person.addrs);
            return 1; 
        }
        travePoint = travePoint->next;
        
    }
    
    return ret;
    
}

int main() 
{
    // Initialize an address book
    AddressBook myAddressBook;
    myAddressBook.head = NULL;
 
    // Test modifications
    // Create a sample PersonData instance
    PersonData Person = {"John Doe", 'M', 30, "1234567890", "123 Main St"};

    // Call the modify function
    int modificationResult = addressBookModify(&myAddressBook, "Old Name", Person);

    if (modificationResult == 1) 
    {
        printf("Person information modified successfully.\n");
    } 
    else 
    {
        printf("Person not found. No modification performed.\n");
    }



    return 0;
} 
