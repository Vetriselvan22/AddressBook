# Address Book Management System in C

Project Overview

The Address Book Management System is a console-based application developed using the C programming language. It helps users store and manage contact information easily.

Users can add new contacts, search for existing contacts, update contact details, delete contacts, and display all saved contacts.

The application uses structures, pointers, functions, string handling, and file handling concepts in C.

##Features

- **Add Contact:** Add a new contact with name, phone number, and email address.
- **Search Contact:** Search contacts using name, phone number, or email.
- **Edit Contact:** Update existing contact information.
- **Delete Contact:** Delete unwanted contacts with confirmation.
- **List Contacts:** Display all saved contacts.
- **Data Validation:** Validate phone numbers and email addresses.
- **Duplicate Checking:** Prevent duplicate phone numbers and email addresses.
- **File Handling:** Save and load contact details using a CSV file.

##Technologies Used

- Programming Language: C
- Data Structure: Structures
- Concepts: Pointers, Functions, Arrays, Strings
- File Handling: CSV File
- Compiler: GCC

## Project Structure

AddressBook/
│
├── main.c
├── addressbook.c
├── addressbook.h
├── database.csv
└── README.md

##Validation Rules

**Phone Number**
- Must contain exactly 10 digits.
- Only numerical characters are allowed.
- Duplicate phone numbers are not allowed.

**Email Address**
- Must contain exactly one `@` symbol.
- Must start with a lowercase character.
- Must end with `.com`.
- At least one character must be present between `@` and `.com`.
- Duplicate email addresses are not allowed.

## Data Storage

Contact information is stored in `database.csv` using file handling operations.

The application loads previously saved contacts and saves contact details for future use.

## Learning Outcomes

Through this project, I gained practical experience in:

- Understanding structures and pointers in C.
- Implementing CRUD operations.
- Working with string manipulation functions.
- Applying input validation techniques.
- Handling files using CSV format.
- Managing contact records efficiently.
