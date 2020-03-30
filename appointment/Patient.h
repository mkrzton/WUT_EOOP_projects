#pragma once
#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include <iostream>
#include <string.h>

#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Appointment_List.h"
#include "Dentist.h"
#include "Dentist_List.h"

#include "Patient_List.h"


using namespace std;

class Patient{

private:


    int patient_id;
    string Patient_name;
    string Patient_surname;
    string Patient_address;
    string Patient_phone_number;
    Patient*next;

public:

    Patient(int New_patient_id, string New_patient_name, string New_surname, string new_patient_address, string New_patient_phone_number);
	~Patient();
    int get_patient_id() const;
    string get_Patient_name() const;
    string get_Patient_surname()const;
    string get_Patient_address()const;
    string get_Patient_phone_number()const;
    Patient*get_next_patient()const;
    void set_next_Patient(Patient *another);
    void print();
    ostream& operator<< (ostream &output);
};

#endif // PATIENT_H_INCLUDED
