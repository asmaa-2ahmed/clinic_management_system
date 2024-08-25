/** Include Library **/
#include "ADMIN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Global Variables **/
Patient* head = NULL;

TimeSlot slots[5] = {
    {1, "2pm to 2:30pm", 0, 0},
    {2, "2:30pm to 3pm", 0, 0},
    {3, "3pm to 3:30pm", 0, 0},
    {4, "4pm to 4:30pm", 0, 0},
    {5, "4:30pm to 5pm", 0, 0}
};

                        /***************************** Functions For Admin Mode *****************************/
                                                    /****** Login ******/
u8 Login() {
    u16 password;
    u8 attempts = 3, counter = 0;
    const u16 actualPassword = 1234;

    while (counter < attempts) {
        printf("Please enter your password: ");
        scanf("%hu", &password);
        if (password == actualPassword) {
            printf("Welcome Admin Mode\n");
            printf("*****************\n");
            return 1;
        } else {
            printf("Wrong Password!!\n");
            counter++;
        }
    }
    printf("SORRY, you are not allowed to enter\n");
    printf("*********************************\n");
    return 0;
}
                                                    /****** Display Patients ******/
void displayPatients() {
    Patient* temp = head;
    if (temp) {
        while (temp) {
            printf("ID: %d\n", temp->ID);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Gender: %s\n", temp->gender == female ? "Female" : "Male");
            printf("\n");
            temp = temp->next;
            printf("***********\n");
        }

    } else {
        printf("There are no patients yet...\n");

    }
    printf("*********************************\n");
}
                                                    /****** Add Patient ******/
void addPatient(u8 IDD, u8 namee[20], int agee, Gender genderr) { // Use u16 for age in tenths
    Patient* ptr = head;
    while (ptr) {
        if (ptr->ID == IDD) {
            printf("Error: Patient with ID %d already exists.\n", IDD);
            printf("*********************************\n");
            return;
        }
        ptr = ptr->next;
    }

    Patient* temp = (Patient*)malloc(sizeof(Patient));
    if (temp) {
        temp->ID = IDD;
        strncpy(temp->name, namee, sizeof(temp->name) - 1);
        temp->name[sizeof(temp->name) - 1] = '\0'; // Ensure null termination
        temp->age = agee;
        temp->gender = genderr;
        temp->next = NULL;

        if (!head) {
            head = temp;
        } else {
            ptr = head;
            while (ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        printf("Patient added successfully.\n");
        printf("*********************************\n");
    } else {
        printf("Memory allocation failed.\n");
        printf("*********************************\n");
    }
}



                                                    /****** Edit Patient ******/
void EditPatientName() {
    u8 IDD;
    printf("Enter Patient ID to edit: ");
                if (scanf("%hhu", &IDD) != 1) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    return;
                }

    Patient* temp = head;
    char namee[20];

    printf("Enter new name: ");
    scanf("%19s", namee); // Limiting input to prevent buffer overflow

    while (temp) {
        if (temp->ID == IDD) {
            strncpy(temp->name, namee, sizeof(temp->name) - 1);
            temp->name[sizeof(temp->name) - 1] = '\0'; // Ensure null termination
            printf("Patient name updated successfully.\n");
            printf("*********************************\n");
            return;
        }
        temp = temp->next;
    }

    printf("Error: Patient with ID %d not found.\n", IDD);
    printf("*********************************\n");
}

void EditPatientAge() {
    u8 IDD;
    printf("Enter Patient ID to edit: ");
                if (scanf("%hhu", &IDD) != 1) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    return;
                }
    Patient* temp = head;
    int agee;

    printf("Enter new age: ");
    scanf("%d", &agee);

    while (temp) {
        if (temp->ID == IDD) {
            temp->age = agee;
            printf("Patient age updated successfully.\n");
            printf("*********************************\n");
            return;
        }
        temp = temp->next;
    }

    printf("Error: Patient with ID %d not found.\n", IDD);
    printf("*********************************\n");
}

void EditPatientGender() {
    u8 IDD;
    printf("Enter Patient ID to edit: ");
                if (scanf("%hhu", &IDD) != 1) {
                    printf("Invalid ID input.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    return;
                }
    Patient* temp = head;
    u8 genderInput;
    Gender genderr;

    printf("Enter new gender (0 for male, 1 for female): ");
    scanf("%hhu", &genderInput);

    genderr = (Gender)genderInput;

    while (temp) {
        if (temp->ID == IDD) {
            temp->gender = genderr; // Update gender
            printf("Patient gender updated successfully.\n");
            printf("*********************************\n");
            return;
        }
        temp = temp->next;
    }

    printf("Error: Patient with ID %d not found.\n", IDD);
    printf("*********************************\n");
}


                                                    /****** Resrvation ******/
void reserveSlot() {
    int patientID;
    int slotID;
    printf("Available slots:\n");
    for (int i = 0; i < 5; i++) {
        if (!slots[i].isReserved) {
            printf("%d - %s\n", slots[i].slotID, slots[i].time);
        }
    }

    printf("Enter patient ID: ");
    scanf("%d", &patientID);

    Patient* temp = head;
    while (temp) {
        if (temp->ID == patientID) {
            break;
        }
        temp = temp->next;
    }

    if (!temp) {
        printf("Patient ID not found!\n");
        printf("*********************************\n");
        return;
    }

    printf("Enter slot ID: ");
    scanf("%d", &slotID);

    for (int i = 0; i < 5; i++) {
        if (slots[i].slotID == slotID && !slots[i].isReserved) {
            slots[i].isReserved = 1;
            slots[i].patientID = patientID;
            printf("Slot reserved successfully!\n");
            printf("*********************************\n");
            return;
        }
    }

    printf("Slot not available!\n");
    printf("*********************************\n");
}

void cancelReservation() {
    int patientID;
    printf("Enter patient ID: ");
    scanf("%d", &patientID);

    for (int i = 0; i < 5; i++) {
        if (slots[i].patientID == patientID) {
            slots[i].isReserved = 0;
            slots[i].patientID = 0;
            printf("Reservation cancelled successfully!\n");
            printf("*********************************\n");
            return;
        }
    }

    printf("Patient ID not found!\n");
    printf("*********************************\n");
}


void AdminMode() {
    if (!Login()) {
        return;
    }
    u8 choicee;
    while (1) {
        printf("Please enter your choice:\n");
        printf("1- Display Patients\n");
        printf("2- Add a new Patient\n");
        printf("3- Edit Patient Info\n");
        printf("4- Reserve a slot with the doctor\n");
        printf("5- Cancel reservation\n");
        printf("6- Exit\n");

        scanf("%hhu", &choicee);

        switch (choicee) {
            case 1:
                displayPatients();
                break;

            case 2: {
                u8 IDD;
                u8 namee[20];
                int agee;
                int genderInput;  // Changed from u8 to int
                Gender genderr;

                printf("Enter Patient ID: ");
                scanf("%hhu", &IDD);
                while (getchar() != '\n');  // Clear input buffer

                printf("Enter Patient Name: ");
                scanf("%19s", namee);
                while (getchar() != '\n');  // Clear input buffer

                printf("Enter Patient Age: ");
                scanf("%d", &agee);
                while (getchar() != '\n');  // Clear input buffer

                printf("Enter Patient Gender (0 for male, 1 for female): ");
                scanf("%d", &genderInput);  // Changed %hhu to %d
                while (getchar() != '\n');  // Clear input buffer

                genderr = (Gender)genderInput;

                // Call to addPatient function
                addPatient(IDD, namee, agee, genderr);
                break;
            }

           case 3: {
                u8 editChoice;
                printf("Edit: 1- Name, 2- Age, 3- Gender\n");
                if (scanf("%hhu", &editChoice) != 1) {
                    printf("Invalid choice input.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    continue; // Continue to the next iteration of the loop
                }

                switch (editChoice) {
                    case 1:
                        EditPatientName();
                        break;

                    case 2:
                        EditPatientAge();
                        break;

                    case 3:
                        EditPatientGender();
                        break;

                    default:
                        printf("Invalid edit choice.\n");
                        break;
                }
                break;
            }



            case 4:
                reserveSlot();
                break;

            case 5:
                cancelReservation();
                break;

            case 6:
                return;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}



                        /***************************** Functions For User Mode *****************************/


                                                    /****** View Patient Record ******/
// Function to print the info of a specific patient using its id
void viewPatientRecord(u8 IDD) {
    Patient* temp = head;
    // Search for a Patient
    while (temp) {
            // if the Patient exists?
        if (temp->ID == IDD) {
            // Print his information
            printf("ID: %d\n", temp->ID);
            printf("Name: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Gender: %s\n", temp->gender == female ? "Female" : "Male");
            printf("\n");
            // Terminate the function
            return;
        }
        // Continue Looping
        temp = temp->next;
    } // The patient is not found
    printf("Error: Patient with ID %d not found.\n", IDD);
}


                                                    /****** View Todays Reservations ******/
//Function to loop over the array and return the reserved slots with user id
void viewTodaysReservations() {
    printf("Today's reservations:\n");
    for (u8 i = 0; i < 5; i++) {
        if (slots[i].isReserved) {
            printf("Slot %d (%s) - Patient ID: %d\n", slots[i].slotID, slots[i].time, slots[i].patientID);
        }
    }
}

