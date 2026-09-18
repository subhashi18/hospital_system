#include "hospital.h"

//specialties
const char *specialtyNames[NUM_SPECIALTIES] ={"General Practice (OPD)","Paediatrics","Cardiology","Neurology"};
const double specialtyFees[NUM_SPECIALTIES] ={1500.00,2500.00,4500.00,5000.00};
const int consultationTimes[NUM_SPECIALTIES] ={15,20,30,30};
const int specialtyCaps[NUM_SPECIALTIES] ={30,20,12,10};

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

