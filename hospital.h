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

//patient
extern char patientId[MAX_PATIENTS][20];
extern char patientName[MAX_PATIENTS][NAME_LENGTH];
extern int patientAge[MAX_PATIENTS];
extern int urgencyLevel[MAX_PATIENTS];
extern int specialtyId[MAX_PATIENTS];

//addmission
extern int admitted[MAX_PATIENTS];
extern int wardId[MAX_PATIENTS];
extern int daysAdmitted[MAX_PATIENTS];
extern int assignedBed[MAX_PATIENTS];

//register
extern int registrationOrder[MAX_PATIENTS];

//billing
extern double baseFee[MAX_PATIENTS];
extern double surcharge[MAX_PATIENTS];
extern double wardCost[MAX_PATIENTS];
extern double grossTotal[MAX_PATIENTS];
extern double discount[MAX_PATIENTS];
extern double finalPayable[MAX_PATIENTS];
extern double waitingTime[MAX_PATIENTS];

extern int specialtyQueue[NUM_SPECIALTIES];
extern int patientCount;

//hospital data
void displaySpecialties(void);
void displayWards(void);
void displayBedOccupancy(void);
int findAvailableBed(int ward);

//input
void clearInputBuffer(void);
int getIntInRange(const char *message, int min, int max);
void readLine(char text[], int size);

//billing

double calculateWaitingTime(int specialty, int queueCount);
double calculateEmergencySurcharge(double fee, int urgency);
double calculateWardCost(int ward, int days);
double calculateGrossTotal(double fee, double surcharge, double wardCost);
double calculateAgeDiscount(double gross, int age);
double calculateFinalPayable(double gross, double discount);

//patient
void registerPatient(void);



#endif
