#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define your structures
typedef struct
 {
    char name[50];
    char phone[20];
    char addrs[100];
    char sex;
    int age;
} PersonData;

typedef struct Node 
{
    PersonData *person;
    struct Node *next;
} BookNode;

typedef struct 
{
    BookNode *head;
} AddressBook;

// Function prototype
int addressBookModify(AddressBook *addrBook, char *name, PersonData person);

int main() 
{
    // Create an example address book
    AddressBook myAddressBook;
    myAddressBook.head = NULL;

    // Populate the address book with some data
    PersonData person1 = {"John Doe", "123-456-7890", "123 Main St", 'M', 25};
    PersonData person2 = {"Jane Smith", "987-654-3210", "456 Oak St", 'F', 30};

    BookNode *node1 = (BookNode *)malloc(sizeof(BookNode));
    node1->person = (PersonData *)malloc(sizeof(PersonData));
    node1->person = &person1;
    node1->next = NULL;

    BookNode *node2 = (BookNode *)malloc(sizeof(BookNode));
    node2->person = (PersonData *)malloc(sizeof(PersonData));
    node2->person = &person2;
    node2->next = NULL;

    myAddressBook.head = node1;
    node1->next = node2;

    // Display the original address book
    printf("Original Address Book:\n");
    BookNode *current = myAddressBook.head;
    while (current != NULL) 
    {
        printf("Name: %s, Phone: %s, Address: %s, Sex: %c, Age: %d\n",
               current->person->name, current->person->phone, current->person->addrs,
               current->person->sex, current->person->age);
        current = current->next;
    }

    // Test the addressBookModify function
    PersonData newPerson = {"John Doe Jr.", "555-123-4567", "789 Elm St", 'M', 30};
    char nameToModify[50];
    printf("Enter the name you want to modify: ");
    scanf("%s", nameToModify);

    int result = addressBookModify(&myAddressBook, nameToModify, newPerson);

    // Display the modified address book
    printf("\nModified Address Book:\n");
    current = myAddressBook.head;
    while (current != NULL) 
    {
        printf("Name: %s, Phone: %s, Address: %s, Sex: %c, Age: %d\n",
               current->person->name, current->person->phone, current->person->addrs,
               current->person->sex, current->person->age);
        current = current->next;
    }

    // Display the result of the modification
    printf("\nModification Result: %s\n", result == 1 ? "Success" : "No matching name found");

    return 0;
}
