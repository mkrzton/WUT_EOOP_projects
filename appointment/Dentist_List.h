#pragma once
#ifndef DENTIST_LIST_H_INCLUDED
#define DENTIST_LIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Appointment_List.h"
#include "Dentist.h"

#include "Patient.h"
#include "Patient_List.h"

using namespace std;

class Dentist;
class Dentist_List{

private:

    Dentist* head_D;

public:

    Dentist*get_head();
    void set_head(Dentist* new_head);
    Dentist_List();
    ~Dentist_List();
    bool check_if_dentist_exist(int Dentist_id);
    Dentist* add_dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname);
    void print();

};
#endif // DENTIST_LIST_H_INCLUDED
