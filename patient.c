#include "hospital.h"

char patientId[MAX_PATIENTS][20];
char patientName[MAX_PATIENTS][NAME_LENGTH];

int patientAge[MAX_PATIENTS];
int urgencyLevel[MAX_PATIENTS];
int specialtyId[MAX_PATIENTS];

int admitted[MAX_PATIENTS];
int wardId[MAX_PATIENTS];
int daysAdmitted[MAX_PATIENTS];
int assignedBed[MAX_PATIENTS];

int registrationOrder[MAX_PATIENTS];

double baseFee[MAX_PATIENTS];
double surcharge[MAX_PATIENTS];
double wardCost[MAX_PATIENTS];
double grossTotal[MAX_PATIENTS];
double discount[MAX_PATIENTS];
double finalPayable[MAX_PATIENTS];

double waitingTime[MAX_PATIENTS];

int specialtyQueue[NUM_SPECIALTIES] = {0};

int patientCount = 0;

// inputs
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void readLine(char text[], int size)
{
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

int getIntInRange(const char *message, int min, int max)
{
    int value;

    while (1)
    {
        printf("%s", message);
        if (scanf("%d", &value) == 1)
        {
            if (value >= min && value <= max)
            {
                clearInputBuffer();
                return value;
            }
        }

        printf("Invalid input. Please try again.\n");
        clearInputBuffer();
    }
}

//registration
void generatePatientID(int index)
{
    sprintf(patientId[index], "PAT-%04d", 1001 + index);
}

void registerPatient(void)
{
    int i;
    int selectedSpecialty;
    int selectedWard;
    int bed;
    int currentQueue;

    if (patientCount >= MAX_PATIENTS)
    {
        printf("\nMaximum patient limit reached.\n");
        return;
    }

    i = patientCount;

    generatePatientID(i);

    printf("\n------------ PATIENT REGISTRATION --------------\n");

    printf("Patient ID: %s\n", patientId[i]);

    printf("Patient Name: ");
    readLine(patientName[i], NAME_LENGTH);

    while (strlen(patientName[i]) == 0)
    {
        printf("Name cannot be empty.\n");
        printf("Patient Name: ");
        readLine(patientName[i], NAME_LENGTH);
    }
    patientAge[i] = getIntInRange("Age (0-120): ",0,120);

    urgencyLevel[i] = getIntInRange("Urgency (1=Normal, 2=Urgent, 3=Critical): ",1,3);

    displaySpecialties();

    selectedSpecialty = getIntInRange("Select Specialty (1-4): ",1,4);

    specialtyId[i] = selectedSpecialty;


    currentQueue = specialtyQueue[selectedSpecialty - 1];

    waitingTime[i] = calculateWaitingTime(selectedSpecialty - 1,currentQueue);

    specialtyQueue[selectedSpecialty - 1]++;

//ward addmission
    admitted[i] = getIntInRange("Admitted to Ward? (1=Yes, 0=No): ",0,1);

    wardId[i] = 0;
    daysAdmitted[i] = 0;
    assignedBed[i] = -1;


    if (admitted[i] == 1)
    {
        displayWards();

        while (1)
        {
            selectedWard = getIntInRange("Select Ward (1-4): ",1,4);

            bed = findAvailableBed(selectedWard - 1);

            if (bed != -1)
            {
                break;
            }

            printf("This ward is full. Please choose another ward.\n");
        }

        wardId[i] = selectedWard;

        daysAdmitted[i] = getIntInRange("Days Admitted (1-365): ",1,365);

        assignedBed[i] = bed;

        bedOccupancy[selectedWard - 1][bed] = 1;

        saveBeds();
    }

//bill

    baseFee[i] = specialtyFees[selectedSpecialty - 1];


    surcharge[i] = calculateEmergencySurcharge(baseFee[i],urgencyLevel[i]);

    if (admitted[i] == 1)
    {
        wardCost[i] = calculateWardCost(wardId[i] - 1,daysAdmitted[i]);
    }
    else
    {
        wardCost[i] = 0;
    }

    grossTotal[i] = calculateGrossTotal(baseFee[i],surcharge[i],wardCost[i]);

    discount[i] = calculateAgeDiscount(grossTotal[i],patientAge[i]);

    finalPayable[i] = calculateFinalPayable(grossTotal[i],discount[i]);

    registrationOrder[i] = i + 1;

    savePatientRecord(i);

    patientCount++;


    printf("\nPatient registered successfully!\n");

    displayPatientBill(i);
}



void displayPatientBill(int i)
{
    printf("\n=========================================================\n");
    printf("             SMART HOSPITAL ADMISSION & BILL\n");
    printf("\n----------------------------------------------------------\n");

    printf("Patient ID : %s\n", patientId[i]);
    printf("Patient Name : %s\n", patientName[i]);
    printf("Age : %d Years", patientAge[i]);


    if (patientAge[i] < 5 || patientAge[i] > 65)
    {
        printf(" (15%% Subsidy Eligible)");
    }

    printf("\n");


    printf("Specialty : %s\n",
           specialtyNames[specialtyId[i] - 1]);

    //beds
    if (admitted[i] == 1)
    {
        printf("Assigned Ward : %s\n",
               wardNames[wardId[i] - 1]);

        printf("Bed Number : #%02d\n",
               assignedBed[i] + 1);
    }
    else
    {
        printf("Assigned Ward : OPD\n");
    }


    printf("Urgency Level : Level %d\n",urgencyLevel[i]);
    printf("\n-------------------------------------------------\n");

    printf("Base Consultation Fee : LKR %.2f\n",baseFee[i]);
    printf("Emergency Surcharge : LKR %.2f\n",surcharge[i]);
    printf("Ward Stay Cost : LKR %.2f\n",wardCost[i]);
    printf("\n-------------------------------------------------\n");

    printf("Gross Total Bill : LKR %.2f\n",grossTotal[i]);
    printf("Age Subsidy Discount : LKR -%.2f\n",discount[i]);
    printf("\n-------------------------------------------------\n");

    printf("Final Payable Amount : LKR %.2f\n",finalPayable[i]);
    printf("Estimated Waiting Time : %.2f mins\n",waitingTime[i]);
    printf("\n=====================================================\n");
}


//show patients
void displayAllPatients(void)
{
    int i;

    if (patientCount == 0)
    {
        printf("\nNo patients registered.\n");
        return;
    }


    printf("\n*********ALL PATIENTS *************\n");


    printf("%-10s %-20s %-5s %-8s %-15s %-12s\n","ID","Name","Age","Urgency","Specialty","Final Bill");



    for (i = 0; i < patientCount; i++)
    {
        printf("%-10s %-20s %-5d %-8d %-15s %.2f\n",patientId[i],patientName[i],patientAge[i],
               urgencyLevel[i],specialtyNames[specialtyId[i] - 1],finalPayable[i]);
    }
}



