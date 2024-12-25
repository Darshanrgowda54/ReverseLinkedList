#include <stdio.h>
#include <stdlib.h>


typedef struct user{
    int userID;
    struct user *next;
}user;


user *newuser,*temp,*head = NULL;

void creatAccount()
{
    newuser = (user*)malloc(sizeof(user));
    if(newuser == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%d",&newuser->userID);

    newuser->next = NULL;

    if(head == NULL)
    {
        head = newuser;
        temp = newuser;
    }
    else
    {
        temp->next = newuser;
        temp = newuser;
    }
}


void ReverseList()
{
    user *prevuser = NULL,*nextuser;

    nextuser = head;
    temp = head;

    while(nextuser != NULL)
    {
        nextuser = nextuser->next;
        temp->next = prevuser;
        prevuser = temp;
        temp = nextuser;
    }
    head = prevuser;
}


void displayAccount()
{
    temp = head;

    while(temp != NULL)
    {
        printf("Account Details\n");
        printf("User ID: %d\n",temp->userID);
        temp = temp->next;
    }
}


int main()
{
    int choice =1,option;

    while(choice)
    {
        printf("1.Creat Account\n");
        printf("2.Reverse List\n");
        printf("3.Display Account\n");
        printf("4.Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            creatAccount();
            break;
        case 2:
            ReverseList();
            break;
        case 3:
            displayAccount();
            break;
        case 4:
            printf("Exit\n");
            return 0;
        default:
            printf("Please enter valid choice.\n");
            break;
        }
    }
    return 0;
}


