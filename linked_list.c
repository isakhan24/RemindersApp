#include "linked_list.h"
#include "reminder.h"

struct Node *head = NULL;

const char *d[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

/*
Parameters: int day (number of day), char reminder (text of reminder)
Function: Adds a node with new reminder information to the linked list, sorts based by day
Return: None
*/
void add_node(int day, const char *reminder) {
    struct Node *current = head, *prev = NULL;

    while (current != NULL && current->day < day) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->day == day) { 
        struct Reminder *new_reminder = (struct Reminder *)malloc(sizeof(struct Reminder));
        if (new_reminder == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }
        strncpy(new_reminder->text, reminder, MAX_STR_LEN - 1);
        new_reminder->text[MAX_STR_LEN - 1] = '\0';
        new_reminder->next = current->reminders;
        current->reminders = new_reminder;
    } else {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }
        new_node->day = day;
        new_node->reminders = NULL;

        struct Reminder *new_reminder = (struct Reminder *)malloc(sizeof(struct Reminder));
        if (new_reminder == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(new_node);
            return;
        }
        strncpy(new_reminder->text, reminder, MAX_STR_LEN - 1);
        new_reminder->text[MAX_STR_LEN - 1] = '\0';
        new_reminder->next = NULL;

        new_node->reminders = new_reminder;
        new_node->next = current;

        if (prev == NULL) {
            head = new_node;
        } else {
            prev->next = new_node;
        }
    }
}

/*
Parameters: None
Function: Deletes node for a specific day
Return: None
*/
void delete_node(int day) {
    if (head == NULL) {
        printf("No reminders to delete\n");
        return;
    }

    if (head->day == day) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *current = head;
    while (current->next != NULL && current->next->day != day) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Reminder for day %d not found\n", day);
    } else {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

/*
Parameters: None
Function: Prints list of reminders sorted by day and time of addition
Return: None
*/
void print_list() {
    if (head == NULL) {
        printf("No reminders set\n");
        return;
    }

    struct Node *current = head;
    while (current != NULL) {
        int day_of_week = (month.start_day + (current->day - 1)) % 7;
        printf("%s %d::", d[day_of_week], current->day);

        struct Reminder *reminder = current->reminders;
        int count = 1;
        while (reminder != NULL) {
            if (count != 1) printf("\t");
            if (current->day <= 9) printf("  (%d) %s\n", count, reminder->text);
            else printf(" (%d) %s\n", count, reminder->text);
            reminder = reminder->next;
            count++;
        }

        current = current->next;
    }
}



void freeList() { //Free's allocated memory of list
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}