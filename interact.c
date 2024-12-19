#include "interact.h"

/*
Parameters: None
Function: Saves current program data to file: reminders.txt
Return: None
*/
void save_reminders() {
    FILE *file = fopen(REMINDER_FILE, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }

    struct Node *current = head; //Iterating through list and writing data of nodes to file
    while (current != NULL) {
        struct Reminder *reminder = current->reminders;
        while (reminder != NULL) {
            fprintf(file, "%d %s\n", current->day, reminder->text);
            reminder = reminder->next;
        }
        current = current->next;
    }

    fclose(file);
    printf("\nReminders saved successfully.\n");
}

/*
Parameters: None
Function: Loads data from reminders.txt into program
Return: None
*/
void load_reminders() {
    FILE *file = fopen(REMINDER_FILE, "r");
    if (file == NULL) {
        printf("No reminders file found. Starting with an empty calendar.\n");
        return;
    }

    int day;
    char reminder_text[MAX_STR_LEN];
    while (fscanf(file, "%d %[^\n]", &day, reminder_text) == 2) {
        add_node(day, reminder_text);
    }

    fclose(file);
    printf("Reminders loaded successfully.\n");
}



/*
Parameters: char* str (user input string), int n (size of str)
Function: Processes user input and extracts day number and string text
Return: Int value of the day for reminder
*/
int read_reminder(char *str, int n) {
    int day;
    char reminder_text[MAX_STR_LEN] = "";
    int parsed_items = sscanf(str, "%d %[^\n]", &day, reminder_text);
        //Error checking
        if (parsed_items < 1 || day < 0 || day > month.month_days) {
            printf("Invalid input. Enter a integer for the day (1-%d) and a reminder: ", month.month_days);
            flush_input_buffer();
        }

    if (day > 0 && day <= month.month_days ) insert_to_calendar(day, reminder_text);
    return day; 
}

/*
Parameters: None
Function: Flushes extra input
Return: None
*/
void flush_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

/*
Parameters: int signal: determines signal case
Function: Handles input signals after saving data to reminders.txt
Return: None
*/
void handle_signal(int signal) {
    save_reminders();

    switch (signal) {
        case SIGINT:
            printf("\nSIGINT received. Exiting program gracefully.\n");
            break;
        case SIGTERM:
            printf("\nSIGTERM received. Exiting program gracefully.\n");
            break;
        case SIGSEGV:
            printf("\nSIGSEGV received. Exiting due to segmentation fault.\n");
            break;
        default:
            printf("\nUnknown signal received. Exiting program.\n");
            break;
    }

    // Exit the program
    exit(signal);
}
