#include "hospital.h"

void displayPatientsByPriority(void)
{
    int order[MAX_PATIENTS];
    int i;
    int j;
    int temp;

    if (patientCount == 0)
    {
        printf("\n No patients registered.\n");
        return;
    }


    for (i = 0; i < patientCount; i++)
    {
        order[i] = i;
    }

    for (i = 0; i < patientCount - 1; i++)
    {
        for (j = 0; j < patientCount - i - 1; j++)
        {
            int firstPatient = order[j];
            int secondPatient = order[j + 1];

            if (urgencyLevel[firstPatient] <
                urgencyLevel[secondPatient])
            {
                temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }


//check registration order.

            else if (urgencyLevel[firstPatient] ==
                     urgencyLevel[secondPatient])
            {
                if (registrationOrder[firstPatient] >
                    registrationOrder[secondPatient])
                {
                    temp = order[j];
                    order[j] = order[j + 1];
                    order[j + 1] = temp;
                }
            }
        }
    }


   //patient list
    printf("\n------------- PRIORITY QUEUE ----------------\n");

    printf("%-5s %-10s %-20s %-10s %-25s\n","Rank","ID","Name","Urgency","Specialty");

    for (i = 0; i < patientCount; i++)
    {
        int patient = order[i];

        printf("%-5d %-10s %-20s Level %-2d %-25s\n",i + 1,patientId[patient],patientName[patient],urgencyLevel[patient],
               specialtyNames[specialtyId[patient] - 1]);
    }
}



