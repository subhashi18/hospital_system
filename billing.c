#include "hospital.h"

double calculateWaitingTime(int specialty, int queueCount)
{
    double waitingTime;

    waitingTime = queueCount * consultationTimes[specialty];

    return waitingTime;
}


//emergency
double calculateEmergencySurcharge(double fee, int urgency)
{
    double surcharge;

    if (urgency == 1)
    {
        surcharge = 0.0;
    }
    else if (urgency == 2)
    {
        surcharge = fee * 0.20;
    }
    else
    {

        surcharge = fee * 0.50;
    }

    return surcharge;
}


//ward
double calculateWardCost(int ward, int days)
{
    double cost;

    cost = days * wardRates[ward];

    return cost;
}


//total
double calculateGrossTotal(double fee,double emergencySurcharge,double wardCost)
{
    double total;

    total = fee + emergencySurcharge + wardCost;

    return total;
}


//age discount
double calculateAgeDiscount(double gross, int age)
{
    double discount;

    if (age < 5 || age > 65)
    {

        discount = gross * 0.15;
    }
    else
    {
        discount = 0.0;
    }

    return discount;
}


//final
double calculateFinalPayable(double gross,double discountAmount)
{
    double finalAmount;

    finalAmount = gross - discountAmount;

    return finalAmount;
}
