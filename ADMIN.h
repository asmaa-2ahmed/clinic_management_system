#ifndef ADMIN_H
#define ADMIN_H

/** Include Libraries **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "STD_TYPES.h"
#include "HELPER.h"

/** Define Enum  **/
typedef enum {male, female} Gender;

/** Define Struct  **/
typedef struct patient {
    u8 ID;
    u8 name[20];
    int age;
    Gender gender;
    struct patient* next;
} Patient;

typedef struct {
    u8 slotID;
    char time[20];
    u8 isReserved;
    u8 patientID;
} TimeSlot;

/** Function Prototypes **/
u8 Login();
void displayPatients();
void addPatient(u8 IDD, u8 namee[20], int agee, Gender genderr);

void EditPatientName();
void EditPatientAge();
void EditPatientGender();

void reserveSlot();
void cancelReservation();
void AdminMode();

void viewPatientRecord(u8 IDD);
void viewTodaysReservations();

#endif // ADMIN_H
