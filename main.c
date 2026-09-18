#include "hospital.h"

void displayMenu(void)
{

    printf(".....................................................\n");
    printf("          SMART HOSPITAL RESOURCE ALLOCATION\n");
    printf(".....................................................\n");

    printf("1. Display Specialty Data\n");
    printf("2. Display Ward Data\n");
    printf("3. Display Bed Occupancy\n");
    printf("4. Register Patient\n");
    printf("5. Display All Patients\n");
    printf("6. Display Patients by Priority\n");
    printf("7. Performance Report\n");
    printf("8. Save Bed Status\n");
    printf("9. Exit\n");

    printf("......................................................\n");
}


int main(void)
{
    int choice;


    loadBeds();

    printf("\n");
    printf("Welcome to Smart Hospital System\n");

    do
    {
        displayMenu();

        choice = getIntInRange("Enter your choice: ", 1, 9);

        switch (choice)
        {
            case 1:
                displaySpecialties();
                break;

            case 2:
                displayWards();
                break;

            case 3:
                displayBedOccupancy();
                break;

            case 4:
                registerPatient();
                break;

            case 5:
                displayAllPatients();
                break;

            case 6:
                displayPatientsByPriority();
                break;

            case 7:
                displayAnalytics();
                break;

            case 8:
                saveBeds();
                printf("Bed status saved successfully.\n");
                break;

            case 9:
                saveBeds();

                printf("Thank you for using Smart Hospital System.\n");
                break;
        }

    } while (choice != 9);

    return 0;
}

