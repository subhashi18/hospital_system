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





