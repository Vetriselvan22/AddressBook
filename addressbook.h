#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>


struct Contact{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100];
    int contactCount;
    int contactfound;
    int index_record[100];
    int ir_size;
};

//decleration for all functions
void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);
void Save_Exit(struct AddressBook *addressBook);
void load_contacts(struct AddressBook *addressBook);
int validate_phonenumber(char *phone_number);
int validate_email(char *email_tem);
void display_addressbook(struct AddressBook *display);
int unique_email(char *email_tem, struct AddressBook *email_count);
int unique_phone(char *phone_number,struct AddressBook *contact_count);

#endif
