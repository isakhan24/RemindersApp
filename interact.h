#include "reminder.h"   //Including headers and libraries
#include "linked_list.h"
#include <signal.h>

#define REMINDER_FILE "reminders.txt"   //I/O File

//Function declaration
void save_reminders(void);
void load_reminders(void);
int read_reminder(char *str, int n);
void flush_input_buffer();
void handle_signal(int signal);