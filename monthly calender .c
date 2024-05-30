#include <stdio.h>
#include <stdbool.h>

// Structure to represent a month
struct Month {
    char name[19];
    int days;
};

// Function to check if a given year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

// Function to find the day of the week for January 1st of a given year
int findFirstDay(int year) {
    int day;
    day = (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}

// Function to print the calendar for a given year using structure
void printCalendar(int year) {
    // Define an array of Month structures representing all twelve months
    struct Month months[12] = {
        {"January", 31},
        {"February", 28 + isLeapYear(year)},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31}
    };

    int firstDay = findFirstDay(year);

    // Print calendar header
    printf("Calendar for %d\n", year);

    // Loop through each month
    for (int month = 0; month < 12; month++) {
        printf("\n%s\n", months[month].name);
        printf("  S   M   T   W   Th  F  S\n");

        // Print leading spaces to align the first day of the month
        for (int i = 0; i < firstDay; i++) {
            printf(" ");
        }

        // Print the days of the month
        for (int day = 1; day <= months[month].days; day++) {
            printf("%3d ", day);
            if ((firstDay + day) % 7 == 0) {
                printf("\n"); // Start a new line after Saturday
            }
        }

        // Update firstDay for the next month
        firstDay = (firstDay + months[month].days) % 7;
        printf("\n");
    }
}

int main() {
    int year;

    // Input year from the user
    printf("Enter the year: ");
    scanf("%d", &year);

    // Print the calendar for the given year
    printCalendar(year);

    return 0;
}
