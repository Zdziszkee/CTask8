#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Roman {
    int arabic;
    char *numeral;
};

const struct Roman roman_values[] = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
        {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
        {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
};

int roman_to_arabic(const char *roman) {
    int arabic = 0, i = 0;
    while (roman[i] != '\0') {
        int j = 0;
        while (roman_values[j].numeral[0] != '\0' && roman_values[j].numeral[0] != roman[i]) j++;
        if (roman_values[j].numeral[1] == roman[i + 1]) {
            arabic += roman_values[j].arabic;
            i += 2;
        } else {
            arabic += roman_values[j].arabic;
            i++;
        }
    }
    return arabic;
}
int arabic_to_roman(int arabic) {
    int i = sizeof(roman_values) / sizeof(roman_values[0]) - 1;
    while (arabic > 0) {
        while (arabic >= roman_values[i].arabic) {
            printf("%s", roman_values[i].numeral);
            arabic -= roman_values[i].arabic;
        }
        i--;
    }
    return 0;
}


int main() {
    char input[100];
    printf("Enter an Arabic or Roman number: ");
    scanf("%s", input);

    if (isdigit(input[0])) {
        printf("Roman equivalent: ");
        arabic_to_roman(strtol(input,NULL,10));
    } else if (isalpha(input[0])) {
        printf("Arabic equivalent: %d", roman_to_arabic(input));
    } else {
        printf("Invalid number format");
    }

    return 0;
}