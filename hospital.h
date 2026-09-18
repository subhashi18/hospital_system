#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define NAME_LENGTH 100

//specialties
extern const char *specialtyNames[NUM_SPECIALTIES];
extern const double specialtyFees[NUM_SPECIALTIES];
extern const int consultationTimes[NUM_SPECIALTIES];
extern const int specialtyCaps[NUM_SPECIALTIES];

//wards
extern const char *wardNames[NUM_WARDS];
extern const double wardRates[NUM_WARDS];
extern const int wardCapacities[NUM_WARDS];

//bed
extern int bedOccupancy[NUM_WARDS][MAX_BEDS];



//hospital data
void displaySpecialties(void);
void displayWards(void);
void displayBedOccupancy(void);
int findAvailableBed(int ward);

#endif
