#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
extern struct Node *head;

struct Reminder {
    char text[MAX_STR_LEN];
    struct Reminder *next;
};

struct Node {
    int day;
    struct Reminder *reminders;
    struct Node *next;
};


void add_node(int day, const char *reminder);
void delete_node(int day);
void print_list();
void freeList();

#endif