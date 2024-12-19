#ifndef REMINDER_H
#define REMINDER_H

#include <stdio.h>  //Including libraries
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 100

struct Month{
	int month_days; //Amount of days in the month
    int start_day;  //Day of the week the month starts on (0-6)
    int month_idx;  //Index of the month (0-11)
    char reminder_str[31][MAX_STR_LEN]; 
	bool reminders[31]; 
};

extern struct Month month ; 

//Function decleration
void insert_to_calendar(int day, const char* value) ;
int read_reminder(char *str, int n) ;
void print_calendar() ;
void initializeMonth();

#endif