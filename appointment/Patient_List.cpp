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

Patient_List::Patient_List(){head_P=NULL;}
Patient* Patient_List:: get_head(){return head_P;}
Patient* Patient_List:: set_head(Patient* new_head){return head_P=new_head;}
//Patient* Patient_List::add_patient(string New_patient_name, string New_surname, int New_patient_id,
//	string new_PESEL, string new_patient_address, string New_patient_phone_number){}// tu visual siê sapie, ¿e funkcja jest typu Patient* a nic nie zwraca
Patient_List::~Patient_List(){

        Patient *tab = NULL;
        while(head_P != NULL){
        tab = head_P;
		head_P = head_P->get_next_patient();
        delete tab;
    }
}
bool Patient_List::check_if_patient_exist(int id){

    Patient *curr = NULL;
    curr = head_P;
    while(curr != NULL){

        if(curr->get_patient_id() == id){
            return true;

        }else curr = curr->get_next_patient();
    }
    return 0;
}

void Patient_List::print(){

    Patient *curr = head_P;

        if(curr == NULL){

            return; //if list is empty returns
        }

        cout << endl << "List of Patients: "<< endl << endl;

        while(curr != NULL){

            curr->print();
            curr = curr->get_next_patient();
            cout << endl;

            }

        cout<< endl;
    }
