#pragma once
#ifndef DENTIST_H_INCLUDED
#define DENTIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Appointment_List.h"

#include "Dentist_List.h"
#include "Patient.h"
#include "Patient_List.h"



using namespace std;

class Dentist{

private:

    int Dentist_id;
    string Dentist_name;
    string Dentist_surname;
    float Dentist_arriving_hour;
    float Dentist_leaving_hour;
    Dentist*next;

public:
    Dentist*hire_dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname, float new_Dentist_arriving_hour, float new_Dentist_leaving_hour){}
    Dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname, float new_Dentist_arriving_hour, float new_Dentist_leaving_hour);
    ~Dentist(){}
    int get_dentist_id() const;
    string get_Dentist_name()const ;
    string get_Dentist_surname()const;
    float get_Dentist_arrive_hour()const;
    float get_Dentist_leaving_hour()const;
    Dentist*get_next()const;
    void set_next_Dentist(Dentist* another);
    void print();
    ostream& operator<< (ostream &output);

};
#endif // DENTIST_H_INCLUDED
