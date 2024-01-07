#ifndef __ADDRESS_BOOK_H_
#define __ADDRESS_BOOK_H_

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
/********************************分割线************************************/
/*初始化通讯录*/
int addressBookInit(AddressBook **addrBook);
/*添加联系人*/
int addressBookAddPerson(AddressBook *addrBook, PersonData person);
/*根据名字删除联系人*/
int addressBookDeletePerson(AddressBook *addrBook, char *name);
/*通过名字查找电话号码*/
char *addressBookSeekPhone(AddressBook *addrBook, char *name);
/*修改某人信息*/
int addressBookModify(AddressBook *addrBook, char *name, PersonData person);
/*按照名字给通讯录联系人排序*/
int addressBookSort(AddressBook *addrBook);
/*打印通讯录*/
void addressBookPrint(AddressBook *addrBook);
/*清空通讯录*/
int ruinAddressBook(AddressBook *addrBook);
#endif /*__ADDRESS_BOOK_H_*/