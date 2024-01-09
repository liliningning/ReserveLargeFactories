#include "addressBook.h"
#include <stdio.h>
#include <string.h>
BookNode *baseNameSeekPerson1(AddressBook *addrBook, char *name)
{
    BookNode *travleNode = addrBook->head->next;
    while (travleNode != NULL && strcmp(travleNode->person->name, name) != 0)
    {
        travleNode = travleNode->next;
    }
    if (travleNode == NULL)
    {
        return NULL;
    }
    return travleNode;
}
#if 1
int swapNode1(AddressBook *addrBook, BookNode *preNode, BookNode *postNode)
{
    if (preNode == NULL || postNode == NULL)
    {
        return -1;
    }
    // 更新前后节点的前后指针
    BookNode *prePrev = preNode->prev;   // head
    BookNode *postNext = postNode->next; // null
    if (prePrev == addrBook->head)
    {
        addrBook->head->next = postNode;
    }
    else
    {
        prePrev->next = postNode;
    }

    preNode->prev = postNode;
    postNode->next = preNode;
    preNode->next = postNext;
    postNode->prev = prePrev;

#if 1

#endif

    if (postNext != NULL)
    {
        postNext->prev = preNode;
    }
    return 1;
}
#endif

int main()
{
    AddressBook *book = NULL;
    addressBookInit(&book);

    printf("add person an\n");
    addressBookAddPerson(book);
    addressBookPrint(book);
    return 0;
}