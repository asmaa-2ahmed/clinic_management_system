/** Include .h file **/
#include "USER.h"

                                            /****** User Mode ******/
//Function to Manage the User Mode
void UserMode() {
    u8 choice;
    //char input[10];
    do {
        // Display menu options
        printf("User Mode:\n");
        printf("1. View patient record\n");
        printf("2. View today's reservations\n");
        printf("3. Exit\n");

        // Ask the user and scan their choice
        printf("Enter your choice: ");

        choice = getValidU8Input();

        // Handle user choice
        switch (choice) {
            case 1: {
                printf("Enter patient ID: ");
                u8 patientID = getValidU8Input();
                 viewPatientRecord(patientID);
                 printf("*****************************************\n");
                break;
            }
            case 2:
                viewTodaysReservations();
                printf("*****************************************\n");
                break;
            case 3:
                printf("Exiting User Mode.\n");
                printf("*****************************************\n");
                break;
            default:
                printf("Invalid choice. Please enter 1 for displaying patient or 2 for displaying reservations.\n");
                printf("*****************************************\n");
        }
    } while (choice != 3);
}
