#include "addressbook.h"

//Function for creat a contact
void add_contact(struct AddressBook *addressBook)
{
    /*
    Nmae:
    Enter the contact name.
    phone number:
    -> check the string length for phone number must be 10 number.
    -> check the strings are numerical numbers.
    -> check the phone number in unique or not.
    Email:
    -> check the character @ present in the gmail string
    -> check the .com ended in last gmail string
    -> check the characters presented between @ and .com
    -> check the email string is unque or not.
    */

    int number_check ,email_check, Phone_limite = 0,email_limite = 0;
    char contactname[20] , phonenumber[15], Tem_email[30];//This is tempervery variables for name,phone,email

    //read the name by user in tempervery variable
    printf("Enter the contact name : ");
    scanf(" %[^\n]",contactname);

    //This loop for read the phone number by user limite is 5
    do
    {
        //read the phone number by tempervery variable
        printf("Enter the contact phone number : ");
        scanf(" %[^\n]",phonenumber);
        Phone_limite++;   //increase the limite count
        number_check = validate_phonenumber(phonenumber);//calling the validate_phonenumber function to validate

        if(number_check == 1)
        {
            number_check = unique_phone(phonenumber,addressBook);
        }

    }while(number_check != 1 && Phone_limite != 5);
    
    //When the limit is over it will execute
    if(Phone_limite == 5)
    {
         printf("You have reached the limit.please try again later.\n");
         return;
    }

     //This loop for read the email by user limite is 5   
    do
    {
        //read the email by tempervery variable
        printf("Enter the Email : ");
        scanf(" %[^\n]",Tem_email);
        email_limite++; //increase the limite count
        email_check = validate_email(Tem_email);//calling the validate_email function to validation
        if(email_check == 1)
        {
            email_check = unique_email(Tem_email,addressBook);
        }

    }while(email_check != 1 && email_limite != 5);

    //When the limit is over it will execute
    if(email_limite == 5)
    {
        printf("You have reached the limit.please try again later.\n");
        return;
    }

    //Finally the validation is over, storing the tempervery to permanent variables.
    
        strcpy(addressBook->contacts[addressBook->contactCount].name,contactname);
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phonenumber);
        strcpy(addressBook->contacts[addressBook->contactCount].email,Tem_email);

        addressBook->contactCount++;//Finally increase the contactCount
        printf("\n");

    //display_addressbook(addressBook);//Calling the display_addressbook function    
}

//Function for search contacts...
void search_contact(struct AddressBook *addressBook)
{
    int choose,validate,i,j=1,flag_found,output=0;//temperveary varaiables

    char Search[100];

    //Read the seach method
    printf("1. Search by Name.\n");
    printf("2. Search by phonenumber.\n");
    printf("3. Search by Email\n");
    scanf("%d",&choose);
    getchar();

    do
    {
        //using switch loop to searching
        switch(choose)
        {
            case 1:
            printf("Enter the Name : ");
            scanf(" %[^\n]",Search);
            validate=1;
            break;
            case 2:
            printf("Enter the Phonenumber : ");
            scanf(" %[^\n]",Search);
            validate=validate_phonenumber(Search);
            break;
            case 3:
            printf("Enter the Email : ");
            scanf(" %[^\n]",Search);
            validate=validate_email(Search);
            break;
            default:
            printf("Invalid Input.");
        }

    }while(validate != 1);//condition for loop

    //condition for name seach
    if(choose == 1)
    {
        //This loop for finding the contacts using name
        for(i=0 ; i < addressBook->contactCount ; i++)
        {
           if(strcmp(Search,addressBook->contacts[i].name) == 0)
           {
               flag_found = 1;//flag used for storing the index value
               addressBook->contactfound=1;
           }

           //Printing that contact
           if(flag_found == 1)
           {  
              if(j==1)
              printf("S.no   Name                  Phonenumbers             Emails\n\n");

              printf("%d",j++);
              printf("      %-20s",addressBook->contacts[i].name);
              printf("  %s",addressBook->contacts[i].phone);
              printf("               %-30s",addressBook->contacts[i].email);
              printf("\n");
              flag_found=0;
              output=1;

              //This loop for storing the index value in array
              for(int k =addressBook->ir_size; k <= addressBook->ir_size ; k++ )
              {
                   addressBook->index_record[k] = i;
              }

              addressBook->ir_size++;//index sise for storing main index values
           }
        }
        if(output == 0)//not found contact its execute
        {
                printf("Contact not found\n");
                return;
        }

    }
    else if(choose == 2 )//condition for phone search
    {
        //This loop for finding the contacts using phone
        for(i=0 ; i < addressBook->contactCount ; i++)
       {
       if(strcmp(Search,addressBook->contacts[i].phone) == 0)
       {
           flag_found = 1;//flag used for storing the index value
           addressBook->contactfound=1;
       }
       //Printing that contact
       if(flag_found == 1)
       {
          printf("S.no   Name                  Phonenumbers             Emails\n\n");
          printf("%d",j);
          printf("      %-20s",addressBook->contacts[i].name);
          printf("  %s",addressBook->contacts[i].phone);
          printf("               %-30s",addressBook->contacts[i].email);
          printf("\n");
          return;
       }
       else
        printf("Contact not found\n");
       }
    }
    else if(choose == 3)
    {
        //This loop for finding the contacts using email
        for(i=0 ; i < addressBook->contactCount ; i++)
       {
       if(strcmp(Search,addressBook->contacts[i].email) == 0)
       {
           flag_found = 1;//flag used for storing the index value
           addressBook->contactfound=1;
       }

       //Printing that contact
       if(flag_found == 1)
       {
          printf("S.no   Name                  Phonenumbers             Emails\n\n");
          printf("%d",j);
          printf("      %-20s",addressBook->contacts[i].name);
          printf("  %s",addressBook->contacts[i].phone);
          printf("               %-30s",addressBook->contacts[i].email);
          printf("\n");
          return;
       }
       else
       {
            printf("Contact not found\n");
            return;
       }
       }
    }

}

void edit_contact(struct AddressBook *addressBook)
{
    search_contact(addressBook);//calling search contact

    int choose,j=1,tem_index,validate;

    if(addressBook->contactfound == 1)//when contact found its execute
    {
        printf("\nEnter s.no to conform your contact : ");//there is 1 or more contact with same name to confirm that
        scanf("%d",&choose);
        
        if(choose > 0 && choose <= addressBook->ir_size)
        tem_index = addressBook->index_record[choose-1];//its that the give tempervary index value to take main index value
        else
        {
            printf("Invalid Input.\n");
            return;
        }

        //Print the contacts
        printf("%d",j);
        printf("      %-20s",addressBook->contacts[tem_index].name);
        printf("  %s",addressBook->contacts[tem_index].phone);
        printf("               %-30s",addressBook->contacts[tem_index].email);
        printf("\n");

        char tem_variable[50];

        //This loop used for which detials want to edit
        do
        {
            printf("Choose which contect you want to edit : ");
            printf("\n1. Name.\n");
            printf("2. Phonenumber.\n");
            printf("3. Email.\n");
            printf("4. Exit.\n");
            printf("Enter the number : ");
            scanf("%d",&choose);
            getchar();

            //This if elses contions are used for editing the detials
            if(choose == 1)
            {
                printf("Enter the contact name : ");
                scanf(" %[^\n]",tem_variable);

                strcpy(addressBook->contacts[tem_index].name,tem_variable);//stored tem to permanent
                printf("Contact Name edited successfully.\n");
            }
            else if(choose == 2)
            {
                do
                {
                    printf("Enter the contact phonenumber : ");
                    scanf(" %[^\n]",tem_variable);
                    validate = validate_phonenumber(tem_variable);//validate the new tem phone number

                    if(validate == 1)
                    {
                        validate = unique_phone(tem_variable,addressBook);//validate the dupilcate is persented in new tem phone number
                    }

                }while(validate != 1);
            
                strcpy(addressBook->contacts[tem_index].phone,tem_variable);//stor tem to permanent
                printf("Contact phonenumber edited successfully.\n");
            }
            else if(choose == 3)
            {
                do
                {
                    printf("Enter the contact Email : ");
                    scanf(" %[^\n]",tem_variable);
                    validate = validate_email(tem_variable);//validate the new tem email

                    if(validate == 1)
                    {
                        validate = unique_email(tem_variable,addressBook);//validate the dupilcate is persented in new tem email
                    }

               }while(validate != 1);

                strcpy(addressBook->contacts[tem_index].email,tem_variable);//stored tem to permanent
                printf("Contact Email edited successfully.\n");
            }

        }while(choose != 4);
    }

     return;
}

//This function used for detele the contact 
void delete_contact(struct AddressBook *addressBook)
{
    search_contact(addressBook);//calling the search function

    int choose,j=1,i,tem_index;
    char yes_no;

    if(addressBook->contactfound == 1)
    {
        printf("\nEnter s.no to conform your contact : ");
        scanf("%d",&choose);
        getchar();
        
        if(choose > 0 && choose <= addressBook->ir_size)
        {
            tem_index = addressBook->index_record[choose-1];
            printf("%d",j);
            printf("      %-20s",addressBook->contacts[tem_index].name);
            printf("  %s",addressBook->contacts[tem_index].phone);
            printf("               %-30s",addressBook->contacts[tem_index].email);
            printf("\n");

            printf("Are you sure you want to delete this contact?(Y/N) : ");//conform mag for delete the contact

            do
            {
                scanf(" %c",&yes_no);

                if(yes_no == 'Y' || yes_no == 'y')
                {
                    for(i=0 ; i < addressBook->contactCount ; i++)
                    {
                        if(i == tem_index)
                        {
                            for(j=tem_index ; j < addressBook->contactCount ; j++)//shifthing all contacts forword that delete contact index
                            {
                                strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                                strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                                strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                                
                            }
                            addressBook->contactCount--;
                            break;
                        }
                    }

                    printf("contact deleted successfully\n");//finally printing mas for deleted
                    return;
                }
                else if(yes_no == 'N' || yes_no == 'n')
                {
                    printf("Contact deletion aborted.Your contact is safe\n");
                    return;
                }
                else
                {
                    printf("Invaled Input,Enter (Y/N) : ");
                }
            }while(yes_no != 'y' || yes_no != 'Y');
            
        }
        else
        {
            printf("Invalid Input.\n");
            return;
        }
    }
   
    return;
}
void list_contacts(struct AddressBook *addressBook)
{
    if(addressBook->contactCount > 0)
    display_addressbook(addressBook);//Calling the display_addressbook function
    else
    printf(">>> NO PREVIOUS CONTACTS <<<\n");    
}

//Function for the checking the number valid or not 
int validate_phonenumber(char *phone_number)
{
    /*
    phone number:
    -> check the string length for phone number must be 10 number.
    -> check the strings are numerical numbers.
    -> check the phone number in unique or not.
    */

    int phone_no_length ;

    phone_no_length = strlen(phone_number);//it return the length of the string

    //Checking the length the is 10 numbers or not
    if(phone_no_length == 10)
    {
        //This loop for the checking the strings characters are all numericals
        while(*phone_number != '\0')
        {
            if(*phone_number >= '0' && *phone_number <= '9')
            {
                phone_number++;
                continue;
            }
            else
            {
                printf("Invalid number, The contact number must be numerical numbers.\n");
                return 0;
            }
        }
        return 1;//validation is over return 1
    }
    else
    {
        printf("Invalid input, The contact number must be 10 numbers.\n");
        return 0;
    }
}

int validate_email(char *email_tem)
{
    /*
    Email:
    -> check the character @ present in the gmail string
    -> check the .com ended in last gmail string
    -> check the characters presented between @ and .com
    -> check the email string is unque or not.
    */

    int check_at = 0,i,email_length,value_cmp ;

    email_length = strlen(email_tem);//The function return the length of string

    //This loop is checking the @ symble is present or not
    for(i = 0 ; email_tem[i] != '\0' ; i++)
    {
        if(email_tem[i] == '@')
        {
            check_at++;
        }
    }

    //if the @ is present its execute
    if(check_at == 1 && email_tem[0] >= 'a' && email_tem[0] <= 'z')
    {
        //This loop for checking the string characters all are lower case
        while(*email_tem != '\0')
        {
            if(*email_tem >= 'a' && *email_tem <= 'z' || *email_tem == '@'  || *email_tem == '.')
            {
                email_tem++;
                continue;
            }
            else
            {
                printf("The characters must be lower case.\n");
                return 0;
            }
        }

        //This if condition is checking the .com present at string end
        if(*(email_tem-1) == 'm' && *(email_tem-2) == 'o' && *(email_tem-3) =='c' && *(email_tem-4) == '.')
        {
            email_tem = email_tem - email_length;//it become the address 0 index

            char  *address_at;

            address_at = strchr(email_tem,'@');//this function return the address of @

            //This if condtion is character is present between the @ and .com
            if(*++address_at != '.')
            {
                return 1;//Finally validation is over return 1
            }
            else
            {
                printf("At least one character must be present between @ and .com\n");
                return 0;
            }
        }
        else
        {
            printf("The Gmail address must end with .com\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid input,The email address must start with character contain the @ symbol\n");
        return 0;
    }
}

//This function for display the contacts
void display_addressbook(struct AddressBook *display)
{
    printf("S.no   Name                  Phonenumbers             Emails\n\n");

    for(int i = 0; i<display->contactCount;i++)
    {
        printf("%d",i+1);
        printf("      %-20s",display->contacts[i].name);
        printf("  %s",display->contacts[i].phone);
        printf("               %-30s",display->contacts[i].email);
        printf("\n");
    }
}

int unique_phone(char *phone_number,struct AddressBook *contact_count)
{
    //Checking the phone number is unique compare to privious contact numbers 
        for(int i = 0 ; i < contact_count->contactCount ; i++)
        {            
            //its return 0 the strings are equal 
            if(strcmp(phone_number,contact_count->contacts[i].phone) == 0)
            {
                printf("Number already exists.please enter a unique number\n");
                return 0;
            }
        }
        return 1;
}

int unique_email(char *email_tem, struct AddressBook *email_count)
{
    //This loop Checking the email is unique or not
        for(int i = 0 ; i < email_count->contactCount ; i++)
        {
             //its return 0 the strings are equal 
            if(strcmp(email_tem,email_count->contacts[i].email) == 0)
            {
                printf("Email already exists.please enter a unique Email\n");
                return 0;
            }
        }
        return 1;
}

//this function for savving the deatials
void Save_Exit(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv","w");//open the file

    for(int i = 0; i < addressBook->contactCount ; i++)
    {
        //printing the all deatials inside the file
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fp);
}

//This function loading the details when you compile newly
void load_contacts(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv","r");//open file

    if(fp == NULL)
    {
        printf("File is not exit.\n");
        return ;
    }

    int output=1,i=0;

    while(output != -1)
    {
        //scaning the detials 
        output = fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        addressBook->contactCount++;
        i++;
    }
    addressBook->contactCount--;

    fclose(fp);
}
