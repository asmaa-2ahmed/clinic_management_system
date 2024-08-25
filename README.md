# Clinic Management System

This project is a simple Clinic Management System implemented in C. The system provides two modes of operation: Admin Mode and User Mode, each with its own set of functionalities.

## Features

### Admin Mode
- **Password Protected:** 
  - The default password is `1234`.
  - The system allows 3 attempts to enter the correct password. If the password is incorrect for 3 consecutive attempts, the system will close.
- **Add New Patient Record:** 
  - The admin can add a new patient by entering their name, age, gender, and a unique ID.
  - The ID must be unique; if an ID already exists, the system will reject the entry.
- **Edit Patient Record:** 
  - The admin can edit the information of an existing patient by entering the patient's ID.
  - If the ID does not exist, an "Incorrect ID" message is displayed.
- **Reserve a Slot with the Doctor:** 
  - The system provides 5 available time slots: 
    - 2:00 PM to 2:30 PM
    - 2:30 PM to 3:00 PM
    - 3:00 PM to 3:30 PM
    - 4:00 PM to 4:30 PM
    - 4:30 PM to 5:00 PM
  - The admin can reserve a slot for a patient by entering the patient's ID and the desired slot.
  - Once a slot is reserved, it will no longer be available for other reservations.
- **Cancel Reservation:** 
  - The admin can cancel a reservation by entering the patient's ID.
  - Canceled slots will become available for other patients.

### User Mode
- **View Patient Record:** 
  - The user can view a patient's record by entering the patient ID.
- **View Today's Reservations:** 
  - The system displays all today's reservations, showing the patient ID associated with each time slot.

## How to Use

1. **Compile the Code:**
   - Compile the C code using a C compiler (e.g., `gcc`).
   
2. **Run the Program:**
   - Execute the compiled program.
   
3. **Select Mode:**
   - Choose between Admin Mode and User Mode by following the on-screen instructions.

4. **Admin Mode:**
   - Enter the password to access admin features.
   - Use the options provided to manage patient records and reservations.

5. **User Mode:**
   - Access without a password.
   - View patient records and today's reservations.
