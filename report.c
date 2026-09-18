#include "hospital.h"

double calculateWardOccupancy(int ward)
{
    int occupied = 0;
    int i;
    double percentage;

    for (i = 0; i < wardCapacities[ward]; i++)
    {
        if (bedOccupancy[ward][i] == 1)
        {
            occupied++;
        }
    }

    percentage = ((double)occupied / wardCapacities[ward]) * 100.0;

    return percentage;
}

void displayAnalytics(void)
{
    int i, bed;

    int normal = 0;
    int urgent = 0;
    int critical = 0;

    double totalRevenue = 0.0;
    double totalDiscount = 0.0;

    int highestPatient = -1;



    if (patientCount == 0)
    {
        printf("\nNo patient data available.\n");
        return;
    }

    for (i = 0; i < patientCount; i++)
    {
        if (urgencyLevel[i] == 1)
        {
            normal++;
        }
        else if (urgencyLevel[i] == 2)
        {
            urgent++;
        }
        else
        {
            critical++;
        }

        totalRevenue = totalRevenue + finalPayable[i];
        totalDiscount = totalDiscount + discount[i];

        if (highestPatient == -1 ||finalPayable[i] > finalPayable[highestPatient])
        {
            highestPatient = i;
        }
    }

    printf("\n--------------------------------------------------\n");
    printf("              PERFORMANCE REPORT\n");
    printf("----------------------------------------------------\n");
    printf("\nTotal Patients : %d\n",patientCount);

    printf("\nUrgency Statistics\n");
    printf("-----------------------------------------------------\n");

    printf("Normal   : %d\n", normal);
    printf("Urgent   : %d\n", urgent);
    printf("Critical : %d\n", critical);

    printf("\nFinancial Statistics\n");
    printf("-----------------------------------------------------\n");
    printf("Total Revenue : LKR %.2f\n",totalRevenue);
    printf("Total Discounts : LKR %.2f\n",totalDiscount);

    printf("\nBed Occupancy\n");
    printf("------------------------------------------------------\n");

    for (i = 0; i < NUM_WARDS; i++)
    {
        int occupied = 0;

        for (bed = 0;
             bed < wardCapacities[i];
             bed++)
        {
            if (bedOccupancy[i][bed] == 1)
            {
                occupied++;
            }
        }

        printf("%-30s %d/%d (%.2f%%)\n",
               wardNames[i],
               occupied,
               wardCapacities[i],
               calculateWardOccupancy(i));
    }


    printf("\nHighest-Paying Patient\n");
    printf("-----------------------------------------------------\n");

    printf("Name : %s\n",
           patientName[highestPatient]);

    printf("Patient ID : %s\n",
           patientId[highestPatient]);

    printf("Total Bill : LKR %.2f\n",
           finalPayable[highestPatient]);


    printf("******************************************************\n");
}



