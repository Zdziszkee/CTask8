#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct RZYM {
    int arab;
    char *rzym;
}  rz[] = { { 1, "I" }, { 4, "IV" }, { 5, "V" }, { 9, "IX" }, { 10, "X" },
            { 40, "XL" }, { 50, "L" }, { 90, "XC" }, { 100, "C" },
            { 400, "CD" }, { 500, "D" }, { 900, "CM" }, { 1000, "M" } };

void convert_to_roman(int num) {
    int i;
    while (num > 0) {
        for (i = 0; i < 13; i++) {
            if (num < rz[i].arab) {
                i--;
                break;
            }
        }
        printf("%s", rz[i].rzym);
        num -= rz[i].arab;
    }
}

int convert_to_arabic(char* num) {
    int i, sum = 0, prev_value = 0;
    for (i = 0; num[i]; i++) {
        int j;
        for (j = 0; j < 13; j++) {
            if (num[i] == *rz[j].rzym) {
                if (prev_value < rz[j].arab) {
                    sum += rz[j].arab - (2 * prev_value);
                }
                else {
                    sum += rz[j].arab;
                }
                prev_value = rz[j].arab;
                break;
            }
        }
    }
    return sum;
}

int main() {
    char input[20];
    printf("Enter a number: ");
    scanf("%s", input);

    if (isdigit(input[0])) {
        int num = atoi(input);
        if (num > 0 && num < 4000) {
            convert_to_roman(num);
        }
        else {
            printf("Invalid input! Number must be between 1 and 3999.");
        }
    }
    else if (isalpha(input[0])) {
        int num = convert_to_arabic(input);
        if (num > 0 && num < 4000) {
            printf("%d", num);
        }
        else {
            printf("Invalid input! Number must be between 1 and 3999.");
        }
    }
    else {
        printf("Invalid input! Please enter a number.");
    }
    return 0;
}