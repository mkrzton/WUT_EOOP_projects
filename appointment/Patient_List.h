#pragma once
#ifndef PATIENT_LIST_H_INCLUDED
#define PATIENT_LIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Appointment_List.h"
#include "Dentist.h"
#include "Dentist_List.h"
#include "Patient.h"


using namespace std;

class Patient;
class Patient_List{

private:

    Patient *head_P;

public:

    Patient_List();
    Patient* get_head();
    Patient*set_head(Patient* new_head);
    ~Patient_List();
    bool check_if_patient_exist(int id);
    Patient*add_patient(string New_patient_name, string New_surname, int New_patient_id, string new_PESEL,
						string new_patient_address, string New_patient_phone_number);
    void print();

};
#endif // PATIENT_LIST_H_INCLUDED
