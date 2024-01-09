#include "addressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATUS_CODE
{
    CALLLOC_ERROR = -4,
    NULL_PTR,
    INVALID_NAME,
    INVALID_POS,
    ON_SUCCESS,
};
/*****************************静态函数声明*************************************/
/* 判空*/
static int checkBook(AddressBook *addrBook);

/* 添加联系人 */
static int addressBookPosAddPerson(AddressBook *addrBook, PersonData person, int pos);
/* 删除结点 */
static int deleteCurrentNode(BookNode *deleteNode);

/*根据名字找到该人所在的节点*/
static BookNode * baseNameSeekPerson (AddressBook *addrBook, char *name);

static void quicksort(AddressBook array, int num1, int num2);

/*****************************静态函数实现*************************************/

/* 判空*/
static int checkBook(AddressBook *addrBook)
{
    if (addrBook == NULL)
    {
        return NULL_PTR;
    }
}

/*  添加联系人 */
static int addressBookPosAddPerson(AddressBook *addrBook, PersonData person, int pos)
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

    strncpy(newNode->person->addrs, person.addrs, sizeof(newNode->person->addrs) - 1);
    // newNode->person->addrs[sizeof(newNode->person->addrs) - 1] = '\0';
    strncpy(newNode->person->name, person.name, sizeof(newNode->person->name) - 1);
    // newNode->person->name[sizeof(newNode->person->name) - 1] = '\0';
    strncpy(newNode->person->phone, person.phone, sizeof(newNode->person->phone) - 1);
    // newNode->person->phone[sizeof(newNode->person->phone) - 1] = '\0';
    newNode->person->sex = person.sex;
    newNode->person->age = person.age;
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
    newNode->next = travelNode->next;
    newNode->prev = travelNode;
    travelNode->next = newNode;
    if (travelNode->next != NULL)
    {
        travelNode->next->prev = newNode;
    }

    /*长度增加*/
    addrBook->len++;
    printf("新增联系人成功！\n");
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


/*根据名字找到该人所在的节点*/
static BookNode * baseNameSeekPerson(AddressBook *addrBook, char *name)
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
int addressBookAddPerson(AddressBook *addrBook, PersonData person)
{
    return addressBookPosAddPerson(addrBook, person, addrBook->len);


}

/*根据名字删除联系人*/
int addressBookDeletePerson(AddressBook *addrBook, char *name)
{
    checkBook(addrBook);
    BookNode *travelNode = addrBook->head->next;
    printf("请输入要删除的人的姓名：\n");
    scanf("%s", name);
    while (travelNode != NULL && strcmp(travelNode->person->name, name) != 0)
    {
        travelNode = travelNode->next;
    }
    /*退出循环，找到了||找完了都没有*/
    if (travelNode == NULL)
    {
        
        printf("联系人不存在 ! \n");
        return INVALID_NAME;
    }
    else
    {
        deleteCurrentNode(travelNode);
    }
    printf("删除联系人成功 ! \n");

    return ON_SUCCESS;
}
/*通过名字查找电话号码*/
int addressBookSeekPhone(AddressBook *addrBook, char *name)
{
       printf("要查找人的姓名：\n");
       scanf("%s",name); 
       BookNode * node = baseNameSeekPerson(addrBook, name);
       if(node == NULL)
       {
            printf("要查找的人不存在 !\n");
       }
       else
       {
            printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "性别","年龄", "电话", "地址");
       }

}
/*修改某人信息*/
int addressBookModify(AddressBook *addrBook, char *name)
{
    printf("输入修改的姓名: \n");
    scanf("%s", name);
    

}
/*按照名字给通讯录联系人排序*/
int addressBookSort(AddressBook *addrBook)
{
    checkBook(addrBook);
    BookNode *newNode = addrBook->head->next;
    BookNode *travelNode = newNode->next;
    int ret = 0;
    while (travelNode->next != NULL)
    {
        /* 比较两个姓名 */
        ret = strcmp(newNode->person->name, travelNode->person->name);
        if (ret <= 0)
        {
            break;
        }
        /*交换结点 */
        else if (ret > 0)
        {
            newNode->prev->next = travelNode;
            travelNode->next->prev = newNode;
            travelNode->prev = newNode->prev;
            newNode->next = travelNode->next;
            travelNode->next = newNode;
            newNode->prev = travelNode;
        }
    }
    /* 结点后移 */
    newNode = newNode->next;
    travelNode = travelNode->next;
    return ON_SUCCESS;
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
    if(addrBook == NULL)
    {
        return NULL_PTR;
    }
    /* 头结点不为空 */
    if(addrBook->head != NULL)
    {
        free(addrBook->head);
        addrBook->head = NULL;
    }
    /* 链表不为空 */
    if(addrBook != NULL)
    {
        free(addrBook);
        addrBook = NULL;
    }
    printf("销毁通讯录成功！\n");
    return ON_SUCCESS;
}