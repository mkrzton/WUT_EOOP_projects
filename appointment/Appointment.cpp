
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Appointment_List.h"
#include "Dentist.h"
#include "Dentist_List.h"
#include "Patient.h"
#include "Patient_List.h"



using namespace std;

//class Appointment_List;
//class Patient;
//class Dentist;
//class Dentists_List;
//class Patient_List;
//class Appointment;

Appointment::Appointment(float new_hour, int new_day, int new_month, int new_year, Dentist* new_dentist, Patient* new_patient){

        hour = new_hour;
        day = new_day;
        month = new_month;
        year = new_year;
        dentist = new_dentist;
        patient = new_patient;
        next = NULL;
    }

Appointment::~Appointment(){}
Appointment* Appointment:: get_next_appointment() const { return next; }
void Appointment::set_next_Appointment(Appointment* another){ next = another; }
float Appointment::get_hour(){return hour;}
int Appointment::get_day(){return day;}
int Appointment::get_month(){return month;}
int Appointment::get_year(){return year;}
Dentist* Appointment::get_dentist(){return dentist;}
Patient* Appointment::get_patient(){return patient;}
void Appointment::print(){

      patient->print();
      cout<< setprecision(2)<<fixed<< "on hour: " << hour <<", "<< day << "." <<month << "." << year <<" with ";
      dentist->print();

    }

/*ostream& Appointment::operator<< (ostream &output){


    float hour;

    output << "Patient: " << get_name() << " " << get_surname() << " ID: " << get_id() << " on hour: " << setprecision(2)<<fixed<< "on hour: " << get_hour() <<" with "<<"Dentist: " <<get_Dentist_name()<< " " <<get_Dentist_surname() << " ID: " << get_dentist_id();
    Dentist *dentist;
    Patient *patient;
    Appointment *next;
}*/
