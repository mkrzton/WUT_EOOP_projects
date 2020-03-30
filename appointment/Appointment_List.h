#pragma once
#ifndef APPOINTMENT_LIST_H_INCLUDED
#define APPOINTMENT_LIST_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Dentist.h"
#include "Dentist_List.h"
#include "Patient.h"
#include "Patient_List.h"


using namespace std;
class Appointment;

class Appointment_List{

private:

    Appointment* head;

public:

    Appointment_List();
    ~Appointment_List();
    Appointment* get_head1() const;
    void set_head1(Appointment *head2);
    bool is_dentist_free(int id);
    bool does_patient_have_appointment(int id);
    bool check_if_dentist_available(Dentist *dentist, float hour, int day, int month, int year);
    bool check_if_matches_dentist_hours(Dentist *dentist, float hour);
    bool check_if_patient_does_not_have_appointment(Patient*patient, float hour, int day, int month, int year);
    void arrange_appointment(float hour, Dentist *dentist, Patient *patient);
    void print();
};
#endif // APPOINTMENT_LIST_H_INCLUDED
