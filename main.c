/**
 * @author: Asmaa Ahmed Ahmed
 * @brief:Clinic Management System
 * @date: 26/7/2024
 */

/** Include Libraries **/
#include "STD_TYPES.h"
#include "HELPER.h"
#include "ADMIN.h"
#include "USER.h"

/** Main **/
int main() {
    while (1) {
        // Display the Menu
        printf("You are :- \t1- Admin \t2- User \t3-Exit\n");

        // Scan the user choice
        printf("Your choice is: ");
        u8 Adm_User = getValidU8Input();

        // Switch on what they want
        switch (Adm_User) {
            case 1:

                AdminMode();
                while (getchar() != '\n');
                break;
            case 2:

                UserMode();
                break;
            case 3:
                printf("Good Bye.....\n");
                return 0;  // Exit the program
            default:
                printf("Invalid input. Please enter 1 for Admin or 2 for User.\n");
                break;
        }
    }

    return 0;
}
