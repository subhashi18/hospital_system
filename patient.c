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
}

