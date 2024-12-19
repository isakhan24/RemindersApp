/*
Isa Akbar Khan
ikhan97@uwo.ca
251337547

CS 2211 - Assingment 5, Calender Reminders
This program accepts user input to add reminders to a calender. The reminders are stored
and displayed for the user to keep track of. This program uses a linked list to dynamically
store data. The program saves/loads data from file: reminders.txt

This program includes other files:
reminder.c
reminder.h
linked_list.c
linked_list.h
interact.c
interact.h
Makefile
reminders.txt
*/
#include "reminder.h" //Including header file
#include "interact.h"

struct Month month; //Creating global Month struct


int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    signal(SIGSEGV, handle_signal);

    initializeMonth(); //Initialize month details
    load_reminders();  //Load reminders from file
    print_calendar();
    int run = 1;
    while (run) {
        int num_in;
        char r[100];
        printf("Enter day and reminder (0 to quit): "); //Grabbing input
        fgets(r, sizeof(r), stdin);

        num_in = read_reminder(r, sizeof(r)); 
        if (num_in == 0) {
            save_reminders(); // Save reminders before exiting
            printf("Exiting program.\n");
            return 0;
        }

        if (num_in > 0) {
            print_calendar(); //Display updated calendar
        }
    }

    return 0;
}
