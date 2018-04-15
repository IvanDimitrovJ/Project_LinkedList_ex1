#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "holiday.h"

int main()
{
    int userChoice, date;
    int longestHoliday;


    holidayList* head=NULL;
    Holiday temp;

    while(1)
    {
        system("cls");
        printf("Operations:\n");
        printf("1. Add New Holiday\n");
        printf("2. Longest Holiday\n");
        printf("3. Print Expired Holidays - enter curr date\n");
        printf("4. Delete Holiday\n");
        printf("5. Display Holidays\n");
        printf("6. Quit.\n");

        printf("Enter your choice: \n");
        scanf("%d", &userChoice);

        switch(userChoice)
        {
            case 1:
                printf("ID: ");
                scanf("%s", temp.ID);
                printf("Date: ");
                scanf("%d", &temp.date);
                printf("Days: ");
                scanf("%d", &temp.days);
                printf("Price: ");
                scanf("%lf", &temp.price);
                if(!addNewHoliday(&head, temp))
                {
                    deleteList(&head);
                    exit(1);
                }
                printf("Done\n");
                break;

                    break;
            case 2: longestHoliday=LongestHoliday(head);
                    printf("Days: %d\n", longestHoliday);
                    break;
            case 3:
                    printf("Year: ");
                    scanf("%d",&date);
                    printExpiredHolidays(head, date);
                    break;
            case 4: deleteHoliday(head);
                    break;
            case 5: displayAllHolidays(head);
                    break;
            case 6: exit(0);
            default: printf("Invalid input!");
                    break;
        }
        fflush(stdin);
        system("PAUSE");
    }
    return 0;
}

int addNewHoliday(holidayList** head, Holiday data)
{
    holidayList *temp = malloc(sizeof(holidayList));

    if(temp == NULL)
    {
        printf("Not enough memory\n");
        return 0;
    }

    strcpy(temp->ID, data.ID);
    temp->date = data.date;
    temp->days = data.days;
    temp->price = data.price;

    if (*head==NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = *head;
    }
    *head = temp;
    return 1;
}

void deleteList(holidayList** head)
{
    holidayList *p, *temp;

    for(p=*head; p!=NULL; )
    {
        temp = p;
        p=p->next;
        free(temp);
    }
    *head = NULL;
}

int LongestHoliday(holidayList* head)
{
    int maxDays;
    holidayList *p = head;

    maxDays = p->days;

    for( ;p!=NULL; p=p->next)
    {
        if(maxDays<p->days)
            maxDays = p->days;
    }
    return maxDays;
}

void printExpiredHolidays(holidayList* head,int date)
{
    holidayList *p = head;

    for( ;p!=NULL; p=p->next)
    {
        if(date > p->date)
        {
            printf("\n%s\t",p->ID);
            printf("%d\t",p->date);
            printf("%d\t", p->days);
            printf("%.2lf\n", p->price);
        }
        else
            printf("There is not an expired holiday\n");
    }
}

int length(holidayList* head)
{
    int count=0;
    holidayList* temp;
    temp = head;

    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void deleteHoliday(holidayList* head)
{
    int location;
    holidayList* temp;
    printf("Enter location to delete: ");
    scanf("%d", &location);

    if(location>length(head))
        printf("Invalid location!\n");
    else if(location == 1)
    {
       temp = head;
       head = temp->next;
       temp->next=NULL;
       free(temp);
    }
    else
    {
        holidayList* p=head, *q;
        int i;
        while(i<location-1)
        {
            p=p->next;
            i++;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        free(q);
    }
}

void displayAllHolidays(holidayList* head)
{
    holidayList *temp = head;

    if(temp == NULL)
    {
        printf("List it empty!\n");
    }
    else
    {
        for(; temp!=NULL; temp=temp->next)
        {
            printf("\n%s\t",temp->ID);
            printf("%d\t",temp->date);
            printf("%d\t", temp->days);
            printf("%.2lf\n", temp->price);
            printf("\n\n");
        }
    }
}
