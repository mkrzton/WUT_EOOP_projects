#pragma once
#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Dental_Clinic.h"

#include "Appointment_List.h"
#include "Dentist.h"
#include "Dentist_List.h"
#include "Patient.h"
#include "Patient_List.h"

class Dentist;
class Patient;

using namespace std;

class Appointment{

private:

    float hour;
    int day;
    int month;
    int year;
    Dentist *dentist;
	Patient *patient;
    Appointment *next;

public:

    Appointment(float new_hour, int new_day, int new_month, int new_year, Dentist* new_dentist, Patient* new_patient);
    ~Appointment();
    Appointment* get_next_appointment() const;
    void set_next_Appointment(Appointment* another);
    float get_hour();
    int get_day();
    int get_month();
    int get_year();
    Dentist*get_dentist();
    Patient*get_patient();
    void print();
    ostream& operator<< (ostream &output);

};
#endif // APPOINTMENT_H_INCLUDED
