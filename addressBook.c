#include "addressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATUS_CODE
{
    CALLLOC_ERROR = -5,
    NULL_PTR,
    INVALID_NAME,
    INVALID_POS,
    INVALID_SWAP,
    ON_SUCCESS,
};
/*****************************静态函数声明*************************************/
static int checkBook(AddressBook *addrBook);
/*根据位置找联系人*/
static int addressBookPosAddPerson(AddressBook *addrBook, int pos);
/*删除当前结点*/
static int deleteCurrentNode(BookNode *deleteNode);
/*根据名字找到该人所在的节点*/
static BookNode *baseNameSeekPerson(AddressBook *addrBook, char *name);
/*交换节点*/
static int swapNode(AddressBook *addrBook, BookNode *preNode, BookNode *postNode);
/*****************************静态函数实现*************************************/
static int checkBook(AddressBook *addrBook)
{
    if (addrBook == NULL)
    {
        return NULL_PTR;
    }
}
static int addressBookPosAddPerson(AddressBook *addrBook, int pos)
{
    /*尾插添加联系人，默认在通讯录末尾*/
    checkBook(addrBook);
    /*为新节点开辟空间*/
    BookNode *newNode = calloc(1, sizeof(BookNode));
    /*判空*/
    if (newNode == NULL)
    {
        return CALLLOC_ERROR;
    }
    newNode->person = calloc(1, sizeof(PersonData));
    /*判空*/
    if (newNode->person == NULL)
    {
        return CALLLOC_ERROR;
    }

    /*维护新节点*/
    printf("请输入姓名：\n");
    scanf("%s", newNode->person->name);
    getchar();

    printf("请输入性别：\n");
    scanf("%c", &newNode->person->sex);

    printf("请输入年龄:\n");
    scanf("%d", &newNode->person->age);

    printf("请输入电话号码：\n");
    scanf("%s", newNode->person->phone);

    printf("请输入地址：\n");
    scanf("%s", newNode->person->addrs);

    newNode->next = NULL;
    newNode->prev = NULL;
    if (pos < 0 || pos > addrBook->len)
    {
        return INVALID_POS;
    }
    BookNode *travelNode = addrBook->head;
    for (int idx = 0; idx < pos && travelNode != NULL; idx++)
    {
        travelNode = travelNode->next;
    }
    /*改变节点指针方向*/
    newNode->prev = travelNode;
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if (travelNode->next != NULL)
    {
        travelNode->next->prev = newNode;
    }

    /*长度增加*/
    addrBook->len++;
    printf("添加联系人成功\n");
    return ON_SUCCESS;
}
/*删除当前结点*/
static int deleteCurrentNode(BookNode *deleteNode)
{
    BookNode *preDeleteNode = deleteNode->prev;
    preDeleteNode->next = deleteNode->next;
    if (deleteNode->next != NULL)
    {
        deleteNode->next->prev = preDeleteNode;
    }

    if (deleteNode != NULL)
    {
        free(deleteNode);
        deleteNode = NULL;
    }
}
static BookNode *baseNameSeekPerson(AddressBook *addrBook, char *name)
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
static int swapNode(AddressBook *addrBook, BookNode *preNode, BookNode *postNode)
{
    if (preNode == NULL || postNode == NULL)
    {
        return INVALID_SWAP;
    }
    // 更新前后节点的前后指针
    BookNode *prePrev = preNode->prev;   // head
    BookNode *postNext = postNode->next; // null

    preNode->prev = postNode;
    preNode->next = postNext;
    postNode->next = preNode;
    postNode->prev = prePrev;

    if (prePrev == addrBook->head)
    {
        addrBook->head = postNode;
    }
    if (postNext != NULL)
    {
        postNext->prev = preNode;
    }
    return ON_SUCCESS;
}
#endif
/*****************************分割线*************************************/
/*初始化通讯录*/
int addressBookInit(AddressBook **addrBook)
{
    AddressBook *adBook = calloc(1, sizeof(AddressBook));
    if (adBook == NULL)
    {
        return CALLLOC_ERROR;
    }
    adBook->head = calloc(1, sizeof(BookNode));
    if (adBook->head == NULL)
    {
        return CALLLOC_ERROR;
    }
    adBook->len = 0;
    adBook->head->person = NULL;
    adBook->head->next = NULL;
    adBook->head->prev = adBook->head;
    /*解应用*/
    *addrBook = adBook;
}
/*添加联系人*/
int addressBookAddPerson(AddressBook *addrBook)
{
    return addressBookPosAddPerson(addrBook, addrBook->len);
}

/*根据名字删除联系人*/
int addressBookDeletePerson(AddressBook *addrBook, char *name)
{
    BookNode *personNode = baseNameSeekPerson(addrBook, name);
    deleteCurrentNode(personNode);

    return ON_SUCCESS;
}
/*通过名字查找电话号码*/
char *addressBookSeekPhone(AddressBook *addrBook, char *name)
{
    checkBook(addrBook);
    BookNode *personNode = baseNameSeekPerson(addrBook, name);
    char *ret = calloc(BUFFER_SIZE, sizeof(char));
    strncpy(ret, personNode->person->phone, sizeof(ret) - 1);
    return ret;
}
/*修改某人信息*/
int addressBookModify(AddressBook *addrBook, char *name, PersonData person)
{
}
/*按照名字给通讯录联系人排序*/
int addressBookSort(AddressBook *addrBook)
{
    /*选择排序*/
}
/*打印通讯录*/
void addressBookPrint(AddressBook *addrBook)
{
    checkBook(addrBook);
    BookNode *travelNdoe = addrBook->head->next;
    if (travelNdoe == NULL)
    {
        printf("The address book is empty.\n");
        return;
    }
    while (travelNdoe != NULL)
    {
        printf("name=%s\nsex=%c\nage=%d\nphone=%s\naddrs=%s\n", travelNdoe->person->name, travelNdoe->person->sex, travelNdoe->person->age, travelNdoe->person->phone, travelNdoe->person->addrs);
        travelNdoe = travelNdoe->next;
        printf("\n");
    }
    printf("\n");
}
/*清空通讯录*/
int ruinAddressBook(AddressBook *addrBook)
{
}