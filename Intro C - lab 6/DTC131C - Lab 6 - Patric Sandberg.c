#include <stdio.h>
#include <string.h>
#include <time.h>

/*
 * Lab 6 -instruction (C)
Data Structures and File I/O
Objectives
This lab is to provide you practice data structures and file input and output. The objectives of this lab include
designing efficient data structures, application of pointers, and file input/output.

Task 1 – Design an Efficient Data Structure
Electronic Health Record (EHR) is nowadays widely used to manage patient health information.
 Keeping track of personal health information is key to getting the right care. The patient health profile
 allows patients or caregivers to keep track of important health information. If you want to know more about it,
 read it at Wikipedia (Links to an external site.).

Some pieces of a patient’s health information are given below:

First Name
Last Name
Date of birth
Gender
Height in cm
Weight in kg to the nearest tenth
BMI accurate to 2 decimal places. (Set it to 0.0 initially)
Address consists of:
- City,

- Street name,

- Street number,

- Postcode (such as 29188)

Vaccination History: Each of the following (Yes or No)
- Yellow Fever

- Hepatitis

- Malaria

- Bird Flue

- Polio

Additionally, the following information is stored depending on the patient type
- Sodium level (normal range 135-145) for adult man

- Potassium level (normal range 2.5 - 3.5) for adult woman

- School (preschool, preschool class, comprehensive school) for a child (A child is anyone below the age of 16)

In this task, you need to complete the followings:

The efficiency of the storage is very important in resource limited systems. Design a storage efficient structure
 named healthRecord to store patient health profile data. Make sure that your design makes your data structure
 readable and understandable to others.
Count by hand the number of bytes used to represent one healthRecord. Then compare it with the result found by C
 program using sizeof( ) operator. Discuss on the difference and your understanding.
Task 2 – Design an Efficient Data Input and Output Functions
After the data structure is designed, it is time to design and implement functions to get data from the user
 (via keyboard input), show the patient profile data (on screen) and read/save the data from/to disk files.
 The functions should be designed to be efficient in execution time.

In this task, complete the following functions:

Write a support function called calculateBMI() to calculate the body mass index (BMI) for given weight and height.
 You can find the formula for BMI on the Internet at https://en.wikipedia.org/wiki/Body_mass_index
Design and implement an input function named getPatientProfile() to read a patient profile data from the standard
 input file (keyboard by default).
Design and implement an output function named savePatientProfile( ) to store the data in a disk file.
Design and implement an output function named showPatientProfile( ) to display the data in the standard output file
 (screen by default).
Design and implement an input function named readPatientProfile( ) to read data from a disk file.

Task 3 – Test and Evaluation
Write a driver program to test the functions you have implemented in the last task:

Get input of patient health records of 3 adult men, 3 adult women, and 4 children from the standard input file
 (keyboard), and save them to a disk file.
Read 10 saved profile data records from the disk file, sort them into increasing order based on their BMI values.
Display the sorted records on the standard output file (screen), one record a time, controlled by pressing Enter key.
 */

#pragma pack(1)
struct healthRecord {
    char fName[20];
    char lName[25];
    int dateOfBirth;
    char gender;
    unsigned char heightInCm;
    float weightInKg;
    char city[25];
    char streetName[25];
    unsigned short int streetNumber;
    int postCode;
    unsigned char vaccinationHistory;
    union additionalInfo {
        unsigned char sodiumLevel;
        float potassiumLevel;
        unsigned char schoolInformation;
    };
    union additionalInfo additionalInformation;
};

void getPatientProfile(struct healthRecord *myEhr);

int *getCurrentAge(struct healthRecord *myEhr);

void savePatientProfile(struct healthRecord *myEhr);

void showPatientProfile(struct healthRecord *myEhr);

double *calculateBMI(struct healthRecord *myEhr);

void readPatientProfile(struct healthRecord *myEhr);

void sortAccordingToBmi(struct healthRecord *myEhr);

int main() {


    /* initializing array of struct and hard coding data into each element */
    struct healthRecord myEhrList[10] = {{"Patric",  "Sandberg",  19830507, 'm', 178, 86, "Hästveda",     "Ringvägen",       35, 28274, 31, .additionalInformation.sodiumLevel = 135},
                                         {"Nils",    "Andersson", 19650306, 'm', 192, 78, "Malmö",        "Storgatan",       12, 24256, 15, .additionalInformation.sodiumLevel =122},
                                         {"Johan",   "Karlsson",  19981209, 'm', 166, 92, "Göteborg",     "Hisingen",        4,  42256, 21, .additionalInformation.sodiumLevel =145},
                                         {"Gunilla", "Västberg",  19550221, 'f', 168, 56, "Umeå",         "Kanalgatan",      38, 85587, 19, .additionalInformation.potassiumLevel = 1.24},
                                         {"Agda",    "Blomberg",  19810928, 'f', 177, 71, "Västerås",     "Tvärstigen",      89, 12272, 7, .additionalInformation.potassiumLevel =1.42},
                                         {"Sofie",   "Klambro",   20021112, 'f', 170, 62, "Kristianstad", "Näsbychaussen",   55, 29137, 27, .additionalInformation.potassiumLevel =1.31},
                                         {"Olle",    "Niklasson", 20080521, 'm', 134, 26, "Hässleholm",   "Götgatan",        71, 28871, 31, .additionalInformation.schoolInformation = '3'},
                                         {"Harry",   "Jönsson",   20101010, 'm', 125, 20, "Osby",         "Tvärflöjtsvägen", 12, 26541, 1, .additionalInformation.schoolInformation ='2'},
                                         {"Evelina", "Aronsson",  20060317, 'f', 152, 48, "Broby",        "Västergatan",     10, 21131, 30, .additionalInformation.schoolInformation ='3'},
                                         {"Lycke",   "Andersson", 20091019, 'f', 138, 35, "Älmhult",      "Ikeavägen",       5,  29973, 28, .additionalInformation.schoolInformation ='1'},
    };



    /* saving array into file */
    savePatientProfile(myEhrList);

    /* declaring a new array of struct */
    struct healthRecord thisNewList[10];

    /* reading data from file into new array */
    readPatientProfile(thisNewList);

    /* sorting elements according to BMI */
    sortAccordingToBmi(thisNewList);

    /* looping through sorted array, presenting each element separated by pressing 'Enter' */
    int i;
    for (i = 0; i < 10; i++) {
        showPatientProfile(thisNewList + i);
        printf("Press enter to continue\n");
        int enter = 0;
        while (enter != '\r' && enter != '\n') { enter = getchar(); }
    }


    /* code for testing purposes  */
    //struct healthRecord myEhr;
    //struct healthRecord *myEhrPointer = &myEhr;
    //getPatientProfile(myEhrPointer);
    //showPatientProfile(myEhrPointer);
    //savePatientProfile(myEhrPointer);
    //readPatientProfile();

    return 0;
}

void sortAccordingToBmi(struct healthRecord *myEhr) {
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 9; j++)
            if (*calculateBMI(myEhr + j) > *calculateBMI(myEhr + (j + 1))) {
                struct healthRecord tmp = *(myEhr + j);
                *(myEhr + j) = *(myEhr + (j + 1));
                *(myEhr + (j + 1)) = tmp;
            }
}


double *calculateBMI(struct healthRecord *myEhr) {
    double bmi = myEhr->weightInKg / (((double) myEhr->heightInCm /100) * ((double) myEhr->heightInCm /100));
    double *pBmi = &bmi;
    return pBmi;
}


void getPatientProfile(struct healthRecord *myEhr) {

    printf("Enter first name:");
    fgets(myEhr->fName, 20, stdin);
    myEhr->fName[strlen(myEhr->fName) - 1] = '\0';
    printf("Enter last name:");
    fgets(myEhr->lName, 25, stdin);
    myEhr->lName[strlen(myEhr->lName) - 1] = '\0';
    printf("Enter date of birth (YYYYMMDD):");
    scanf("%d", &myEhr->dateOfBirth);
    fflush(stdin);
    printf("Enter gender (m/f):");
    scanf("%c", &myEhr->gender);
    fflush(stdin);
    printf("Enter height in cm:");
    scanf("%d", &myEhr->heightInCm);
    fflush(stdin);
    printf("Enter weight in kilogram:");
    scanf("%f", &myEhr->weightInKg);
    fflush(stdin);
    printf("Enter city name:");
    fgets(myEhr->city, 25, stdin);
    myEhr->city[strlen(myEhr->city) - 1] = '\0';
    printf("Enter street name:");
    fgets(myEhr->streetName, 25, stdin);
    myEhr->streetName[strlen(myEhr->streetName) - 1] = '\0';
    printf("Enter street number:");
    scanf("%hd", &myEhr->streetNumber);
    fflush(stdin);
    printf("Enter post code:");
    scanf("%d", &myEhr->postCode);
    fflush(stdin);
    printf("Enter value for vaccination history\n1 = Yellow fever\n2 = Hepatitis\n4 = Malaria\n"
           "8 = Bird Flu\n16 = Polio\nCombine values and enter total:");
    scanf("%d", &myEhr->vaccinationHistory);
    fflush(stdin);

    if ((*getCurrentAge(myEhr) > 15) && (myEhr->gender == 'm')) {
        printf("Patient is male and %d years old.\nPlease enter sodium level:", *getCurrentAge(myEhr));
        scanf("%d", &myEhr->additionalInformation.sodiumLevel);
    } else if ((*getCurrentAge(myEhr) > 15) && (myEhr->gender == 'f')) {
        printf("Patient is female and %d years old.\nPlease enter potassium level:", *getCurrentAge(myEhr));
        scanf("%f", &myEhr->additionalInformation.potassiumLevel);

    } else if ((*getCurrentAge(myEhr) < 16)) {
        printf("Patient is a child that is %d years old.\nPlease enter school information.\n"
               "1. Preschool\n"
               "2. Preschool class\n"
               "3. Comprehensive school\n"
               ":", *getCurrentAge(myEhr));
        scanf("%c", &myEhr->additionalInformation.schoolInformation);
    }

    fflush(stdin);
}

int *getCurrentAge(struct healthRecord *myEhr) {
    int dob = myEhr->dateOfBirth;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int currDate = ((t->tm_year + 1900) * 10000) + ((t->tm_mon + 1) * 100) + t->tm_mday;
    int currentAge = (currDate - dob) / 10000;
    int *pCurrentAge = &currentAge;
    return pCurrentAge;
}

void showPatientProfile(struct healthRecord *myEhr) {
    printf("===============================================================\nPatient info:\n\n");
    printf("First name       : %s\n", myEhr->fName);
    printf("Last name        : %s\n", (*myEhr).lName);
    printf("Date of birth    : %d\n", myEhr->dateOfBirth);
    printf("Gender           : %c\n", (*myEhr).gender);
    printf("Height (cm)      : %d\n", myEhr->heightInCm);
    printf("Weight (kg)      : %.1f\n", (*myEhr).weightInKg);
    printf("Body Mass Index  : %.2f\n", *calculateBMI(myEhr));
    printf("===============================================================\nContact information:\n\n");
    printf("City name        : %s\n", (*myEhr).city);
    printf("Street name      : %s\n", myEhr->streetName);
    printf("Street number    : %hd\n", (*myEhr).streetNumber);
    printf("Postal code      : %d\n", myEhr->postCode);
    printf("===============================================================\nVaccination information:\n\n");
    printf("Yellow fever     :");
    if ((myEhr->vaccinationHistory & (1 << 0))) {
        printf("YES\n");
    } else { printf("NO\n"); }
    printf("Hepatitis        :");
    if ((myEhr->vaccinationHistory & (1 << 1))) {
        printf("YES\n");
    } else { printf("NO\n"); }
    printf("Malaria          :");
    if ((myEhr->vaccinationHistory & (1 << 2))) {
        printf("YES\n");
    } else { printf("NO\n"); }
    printf("Bird flu         :");
    if ((myEhr->vaccinationHistory & (1 << 3))) {
        printf("YES\n");
    } else { printf("NO\n"); }
    printf("Polio            :");
    if ((myEhr->vaccinationHistory & (1 << 4))) {
        printf("YES\n");
    } else { printf("NO\n"); }
    printf("===============================================================\nAdditional information:\n\n");
    if ((*getCurrentAge(myEhr) > 15) && (myEhr->gender == 'm')) {
        printf("Patient is male and %d years old.\nSodium level: %d\n", *getCurrentAge(myEhr),
               myEhr->additionalInformation.sodiumLevel);

    } else if ((*getCurrentAge(myEhr) > 15) && (myEhr->gender == 'f')) {
        printf("Patient is female and %d years old.\nPotassium level: %.2f\n",
               *getCurrentAge(myEhr), myEhr->additionalInformation.potassiumLevel);

    } else if ((*getCurrentAge(myEhr) < 16)) {
        printf("Patient is a child that is %d years old.\nSchool information:", *getCurrentAge(myEhr));
        if (myEhr->additionalInformation.schoolInformation == '1')
            printf("Preschool\n");
        else if (myEhr->additionalInformation.schoolInformation == '2')
            printf("Preschool class\n");
        else if (myEhr->additionalInformation.schoolInformation == '3')
            printf("Comprehensive school\n");
    }
    printf("===============================================================\n");
}

void savePatientProfile(struct healthRecord *myEhr) {
    FILE *pFileWrite = fopen("HealthRecord.bin", "w");
    fwrite(myEhr, sizeof(struct healthRecord), 10, pFileWrite);
    fclose(pFileWrite);
}

void readPatientProfile(struct healthRecord *myEhr) {
    FILE *pFileOpen = fopen("HealthRecord.bin", "r");
    fread(myEhr, sizeof(struct healthRecord), 10, pFileOpen);
    fclose(pFileOpen);
}