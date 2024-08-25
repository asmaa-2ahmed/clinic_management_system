#include "HELPER.h"


/* Function to get a valid unsigned 8-bit integer input */

u8 getValidU8Input() {
    u8 input[10]; // Buffer to store input
    while (1) {
        fgets(input, sizeof(input), stdin);
        u8 valid = 1;

        // Check if the input is a valid number
        for (u8 i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            return (u8)atoi(input); // Convert valid input to integer
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }
}

