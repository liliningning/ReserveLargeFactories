#include "addressBook.h"
#include <stdio.h>
/*初始化通讯录*/
int addressBookInit(AddressBook **addrBook)
{
}
/*添加联系人*/
int addressBookAddPerson(AddressBook *addrBook, PersonData person)
{
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