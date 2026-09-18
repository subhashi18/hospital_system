#include "hospital.h"

//specialties
const char *specialtyNames[NUM_SPECIALTIES] ={"General Practice (OPD)","Paediatrics","Cardiology","Neurology"};
const double specialtyFees[NUM_SPECIALTIES] ={1500.00,2500.00,4500.00,5000.00};
const int consultationTimes[NUM_SPECIALTIES] ={15,20,30,30};
const int specialtyCaps[NUM_SPECIALTIES] ={30,20,12,10};

//ward
const char *wardNames[NUM_WARDS] ={"General Ward","Paediatric Ward","Surgical Ward","ICU (Intensive Care Unit)"};
const double wardRates[NUM_WARDS] ={3000.00,6000.00,12000.00,25000.00};
const int wardCapacities[NUM_WARDS] ={20,10,10,5};

//bed
int bedOccupancy[NUM_WARDS][MAX_BEDS] = {0};



//specialties
void displaySpecialties(void)
{
    int i;

    printf("\n-------------------------- DOCTOR SPECIALTIES -------------------------\n");

    printf("%-5s %-30s %-15s %-15s %-10s\n","ID","Specialty","Fee","Time","Daily Cap");

    for (i = 0; i < NUM_SPECIALTIES; i++)
    {
        printf("%-5d %-30s LKR %-10.2f %-10d mins %-10d\n",i + 1,specialtyNames[i],specialtyFees[i],consultationTimes[i],specialtyCaps[i]);
    }
}

//wards
void displayWards(void)
{
    int i;

    printf("\n------------------------- HOSPITAL WARDS -------------------------------\n");
    printf("%-5s %-32s %-15s %-10s\n","ID","Ward","Rate/Day","Capacity");

    for (i = 0; i < NUM_WARDS; i++)
    {
        printf("%-5d %-32s LKR %-10.2f %-10d\n",i + 1,wardNames[i],wardRates[i],wardCapacities[i]);
    }
}

//bed
int findAvailableBed(int ward)
{
    int i;

    for (i = 0; i < wardCapacities[ward]; i++)
    {
        if (bedOccupancy[ward][i] == 0)
        {
            return i;
        }
    }

    return -1;
}

void displayBedOccupancy(void)
{
    int ward;
    int bed;

    printf("\n------------------------- BED OCCUPANCY ---------------------------------\n");

    for (ward = 0; ward < NUM_WARDS; ward++)
    {
        printf("\n%s\n", wardNames[ward]);

        for (bed = 0; bed < wardCapacities[ward]; bed++)
        {
            printf("Bed %02d : ",
                   bed + 1);


            if (bedOccupancy[ward][bed] == 1)
            {
                printf("Occupied\n");
            }
            else
            {
                printf("Available\n");
            }
        }
    }
}




