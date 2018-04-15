typedef struct
{
    char ID[10];
    int date;
    int days;
    double price;

} Holiday;

typedef struct node
{
    char ID[10];
    int date;
    int days;
    double price;
    struct node* next;
} holidayList;



int addNewHoliday(holidayList** head, Holiday data);
void deleteList(holidayList** head);
int LongestHoliday(holidayList* head);
void printExpiredHolidays(holidayList* head,int date);
void deleteHoliday(holidayList* head);
int length(holidayList* head);
void displayAllHolidays(holidayList* head);
