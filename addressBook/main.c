#include "addressBook.h"
#include <stdio.h>

enum STATUS_CODE
{
    EXIT,
    ADD ,
    SEEK,
    MODIFY,
    DELETE,
    SORT,
    DERTRUCTION,
    PRINTF,

};

void menu()
{
    printf("**************************** \n");
    printf("                        \n");
    printf("    1:添加联系人         \n");
    printf("    2:查找联系人         \n");
    printf("    3:修改联系人         \n");
    printf("    4:删除联系人         \n");
    printf("    5:通过名字将联系人排序\n");
    printf("    6:销毁通讯录         \n");
    printf("    7:打印通讯录         \n");
    printf("    0:退出通讯录         \n");
    printf("                        \n");
    printf("**************************** \n");
}

int main()
{

    /* 初始化 */
    AddressBook *book = NULL;
    addressBookInit(&book);

    char *name = NULL;
    PersonData newpson = {0};
    int choice = 0;

    do
    {

        menu();
        printf("请输入你的选项: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case ADD:
        {
            addressBookAddPerson(book, newpson);
            break;
        }
        case SEEK:
        {
            addressBookSeekPhone(book, name);
            break;
        }
        case MODIFY:
        {
            addressBookModify(book, name);
            break;
        }
        case DELETE:
        {
            addressBookDeletePerson(book, name);
            break;
        }
        case SORT:
        {
                addressBookSort(book);
            break;
        }
        case DERTRUCTION:
        {
            ruinAddressBook(book);
            break;
        }
        case PRINTF:
        {
            addressBookPrint(book);
        }
        case EXIT:
        {

        }
        }
    }while(choice);





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