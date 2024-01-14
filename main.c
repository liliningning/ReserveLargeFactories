#include "addressBook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum STATUS_CODE
{
    EXIT,
    ADD,
    SEEK,
    MODIFY,
    DELETE,
    SORT,
    DERTRUCTION,
    PRINTF,

};
#define BUFFER_SIZE 32

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

    int choice = 0;

    while (1)
    {
        menu();
        printf("请输入你的选项:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case ADD:
        {
            addressBookAddPerson(book);
            break;
        }
        case SEEK:
        {
            char *name1 = calloc(BUFFER_SIZE, sizeof(char));
            printf("input name:\n");
            scanf("%s", name1);
            addressBookSeekPhone(book, name1);
            break;
        }
        case MODIFY:
        {
            char *name2 = calloc(BUFFER_SIZE, sizeof(char));
            printf("请输入要修改人的名字:\n");
            scanf("%s", name2);
            addressBookModify(book, name2);
            break;
        }
        case DELETE:
        {
            addressBookDeletePerson(book);
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
            break;
        }
        case EXIT:
        {
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return 0;
}
