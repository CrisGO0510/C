#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year);
int validateDate(Date date);

int main() {
    Date date;
    printf("Ingrese la fecha (dd mm yyyy): ");
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    if (validateDate(date)) {
        printf("La fecha es valida.\n");
    } else {
        printf("La fecha no es valida.\n");
    }

    return 0;
}

int validateDate(Date date) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (date.month < 1 || date.month > 12) {
        return 0;
    }

    if (date.month == 2 && isLeapYear(date.year)) {
        daysInMonth[1] = 29;
    }

    if (date.day < 1 || date.day > daysInMonth[date.month - 1]) {
        return 0;
    }

    return 1;
}

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}
