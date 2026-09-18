#include "hospital.h"

//bed
void saveBeds(void)
{
    FILE *file;

    int ward;
    int bed;


    file = fopen("beds_status.txt", "w");

    if (file == NULL)
    {
        printf("Error opening beds_status.txt\n");
        return;
    }


    for (ward = 0; ward < NUM_WARDS; ward++)
    {
        for (bed = 0; bed < wardCapacities[ward]; bed++)
        {
            fprintf(file,"%d %d %d\n",ward + 1,bed + 1,bedOccupancy[ward][bed]);
        }
    }

    fclose(file);
}

void loadBeds(void)
{
    FILE *file;

    int ward;
    int bed;
    int status;

    file = fopen("beds_status.txt", "r");

    if (file == NULL)
    {
        return;
    }

    while (fscanf(file,"%d %d %d",&ward,&bed,&status) == 3)
    {
        if (ward >= 1 &&ward <= NUM_WARDS && bed >= 1 &&bed <= wardCapacities[ward - 1])
        {
            bedOccupancy[ward - 1][bed - 1] = status;
        }
    }

    fclose(file);
}

void savePatientRecord(int index)
{
    FILE *file;

    file = fopen("patient_records.txt", "a");

    if (file == NULL)
    {
        printf("Error opening patient_records.txt\n");
        return;
    }

    fprintf(file,"%s | %s | Age: %d | ""Urgency: %d | Specialty: %s | ""Final Bill: LKR %.2f\n",
            patientId[index],patientName[index],patientAge[index],urgencyLevel[index],
            specialtyNames[patientId[index] ? specialtyId[index] - 1 : 0],finalPayable[index]);

    fclose(file);
}



