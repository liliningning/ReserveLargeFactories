#include "addressBook.h"
#include <stdio.h>

enum STATUS_CODE
{
    ADD = 1,
    SEEK = 2,
    MODIFY = 3,
    DELETE = 4,
    SAVE = 5,

};

void menu()
{
     printf("                       \n");
    printf("    1:添加联系人         \n");
    printf("    2:查找联系人         \n");
    printf("    3:修改联系人         \n");
    printf("    4:删除联系人         \n");
    printf("    5:保存联系人         \n");
    printf("                        \n");
}


int main()
{
    /* 初始化 */
    AddressBook *book = NULL;
    addressBookInit(&book);

    int choice = 0;
    printf("请输入你的选项: \n");
    scanf("%d", &choice);

    switch(choice)
    {
    case ADD:
    {
        addressBookAddPerson(&book,);
        break;
    }
    case SEEK:
    {
        break;
    }
    case MODIFY:
    {
        break;
    }
    case DELETE:
    {
        break;
    }
    case SAVE:
    {
        break;
    }

    }










    // printf("add person li\n");
    // PersonData newPerson2 = {"lining", 'w', 18, "10086", "伊犁师范大学"};
    // addressBookAddPerson(book, newPerson2);

    // printf("add person an\n");
    // PersonData newPerson1 = {"anzhenyu", 'm', 18, "12138", "皖江工学院"};
    // addressBookAddPerson(book, newPerson1);

    // addressBookSort(book);

    // addressBookPrint(book);

    // // printf("delete person an\n");
    // // addressBookDeletePerson(book, "anzhenyu");
    // // addressBookPrint(book);

    // // char *zhenyuPhone = addressBookSeekPhone(book, "anzhenyu");
    // // printf("zhenyuPhone=%s\n", zhenyuPhone);

    return 0;
}