
#include <iostream>
#include <stdlib.h>
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

Appointment_List::Appointment_List(){head = NULL;}
Appointment_List::~Appointment_List(){

        Appointment *temp = NULL;

            while(head != NULL){

                temp = head;
                head = head->get_next_appointment();
                delete temp;
        }
    }

Appointment* Appointment_List:: get_head1()const {return head;}
void Appointment_List:: set_head1(Appointment *head2){head=head2;}
bool Appointment_List::is_dentist_free(int id){

    Appointment *current = head;

        if(current == NULL){

           return false;
        }

        while(current != NULL){

            if(id==current->get_dentist()->get_dentist_id()){

                return false;
            }

        current = current->get_next_appointment();
        }

    return true;

}

bool Appointment_List::does_patient_have_appointment(int id){

    Appointment *current = head;

    while(current != NULL){

        if(id==current->get_patient()->get_patient_id()){

            return false;
        }

    current = current->get_next_appointment();

        }

    return true;

}
bool Appointment_List::check_if_dentist_available(Dentist *dentist, float hour, int day, int month, int year){

    Appointment *current = head;
    int id=dentist->get_dentist_id();

        while(current != NULL){
            if(id==current->get_dentist()->get_dentist_id()){

                if(hour==current->get_hour() && day==current->get_day() && month==current->get_month() && year==current->get_year()){

                        return false;
                    }
                }

        current = current->get_next_appointment();
    }

    return true;
}

bool Appointment_List::check_if_matches_dentist_hours(Dentist *dentist, float hour){

    float starting = dentist->get_Dentist_arrive_hour();
    float leaving = dentist->get_Dentist_leaving_hour();


    if(starting<=hour && leaving-0.3>hour){return false;}

    return true;
}

bool Appointment_List::check_if_patient_does_not_have_appointment(Patient*patient, float hour, int day, int month, int year){

    Appointment*curr=head;
    int id=patient->get_patient_id();

        while(curr != NULL){

            if(id==curr->get_patient()->get_patient_id()){

           if(hour==curr->get_hour() && day==curr->get_day() && month==curr->get_month() && year==curr->get_year()){

                    return false;
                }
            }

    curr = curr->get_next_appointment();

    }

    return true;
}

void Appointment_List::arrange_appointment(float hour, Dentist *dentist, Patient *patient){}

void Appointment_List::print(){

    Appointment *curr = head;

        if(curr == NULL){

            return;
        }

        cout << endl << "List of Appointments: " << endl << endl;

        while(curr != NULL){

            curr->print();
            curr = curr->get_next_appointment();
            cout  << endl;
        }
}
