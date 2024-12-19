#include "reminder.h" //Including header files and libraries
#include "linked_list.h"
#include <time.h>

const char *month_names[] = {   //List of all month names
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const char *day_names[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

/*
Parameters: int day (day of reminder), const char* value (String of reminder)
Function: Adds reminder to the calender by updating number and string value
Return: None
*/
void insert_to_calendar(int day, const char *value) {
    add_node(day, value);
}

/*
Parameters: int day (dat of reminder)
Function: Deletes reminders of selected day
Return: None
*/
void delete_reminder(int day) {
    delete_node(day);
}

/*
Parameters: None
Function: Prints a formatted version of the calender with reminders printted below
Return: None
*/
void print_calendar() {
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < month.start_day; i++) {
        printf("    ");
    }

    for (int i = 1; i <= month.month_days; i++) {
        struct Node *current = head;
        int has_reminder = 0;

        while (current != NULL) {
            if (current->day == i) {
                has_reminder = 1;
                break;
            }
            current = current->next;
        }

        if (has_reminder)
            printf("(%2d)", i);
        else
            printf("%3d ", i);

        if ((i + month.start_day) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n%s Reminders:\n", month_names[month.month_idx]);
    print_list();
    printf("\n---------------------------\n\n");
}

/*
Parameters: None
Function: Determines current month by using time.h library
Return: None
*/
void initializeMonth(void)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    month.month_idx = t->tm_mon;
    t->tm_mday = 1;
    mktime(t);
    month.start_day = t->tm_wday;
    month.month_days = t->tm_mday;
    while (t->tm_mon == month.month_idx)
    {
        month.month_days = t->tm_mday;
        t->tm_mday++;
        mktime(t);
    }
}