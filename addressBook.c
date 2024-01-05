#include "addressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATUS_CODE
{
    CALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_POS,
    INVALID_VAL,
    ON_SUCCESS,
};
/*****************************静态函数声明*************************************/
static int checkList(AddressBook *pList);
static int addressBookPosAddPerson(AddressBook *addrBook, PersonData person, int pos);
/*****************************静态函数实现*************************************/
static int checkList(AddressBook *pList)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
}
static int addressBookPosAddPerson(AddressBook *addrBook, PersonData person, int pos)
{
    /*尾插添加联系人，默认在通讯录末尾*/
    checkList(addrBook);
    /*为新节点开辟空间*/
    BookNode *newNode = calloc(1, sizeof(BookNode));
    /*判空*/
    if (newNode == NULL)
    {
        return CALLLOC_ERROR;
    }
    /*维护新节点*/
    newNode->person->addrs = person.addrs;
    newNode->person->age = person.age;
    newNode->person->name = person.name;
    newNode->person->phone = person.phone;
    newNode->person->sex = person.sex;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (pos < 0 || pos > addrBook->len)
    {
        return INVALID_POS;
    }
    BookNode *travelNode = addrBook->head;
    for (int idx = 0; idx < pos; idx++)
    {
        travelNode = travelNode->next;
    }
    /*改变节点指针方向*/
    newNode->next = travelNode->next;
    newNode->prev = travelNode;
    travelNode->next = newNode;
    if (travelNode->next != NULL)
    {
        travelNode->next->prev = newNode;
    }

    /*长度增加*/
    addrBook->len++;
    return ON_SUCCESS;
}
/*****************************分割线*************************************/
/*初始化通讯录*/
int addressBookInit(AddressBook **addrBook)
{
    AddressBook *adBook = calloc(1, sizeof(AddressBook));
    if (adBook == CALLLOC_ERROR)
    {
        return NULL_PTR;
    }
    adBook->head = calloc(1, sizeof(BookNode));
    if (adBook->head == NULL)
    {
        return CALLLOC_ERROR;
    }
    adBook->len = 0;
    adBook->head->next = NULL;
    adBook->head->prev = adBook->head;
    /*解应用*/
    *addrBook = adBook;
}
/*添加联系人*/
int addressBookAddPerson(AddressBook *addrBook, PersonData person)
{
    return addressBookPosAddPerson(addrBook, person, addrBook->len);
}

/*根据名字删除联系人*/
int addressBookDeletePerson(AddressBook *addrBook, char *name)
{
}
/*通过名字查找电话号码*/
int addressBookSeekPhone(AddressBook *addrBook, char *name)
{
}
/*修改某人信息*/
int addressBookModify(AddressBook *addrBook, char *name)
{
}
/*按照名字给通讯录联系人排序*/
int addressBookSort(AddressBook *addrBook)
{
}
/*打印通讯录*/
void addressBookPrint(AddressBook *addrBook)
{
}
/*清空通讯录*/
int ruinAddressBook(AddressBook *addrBook)
{
}