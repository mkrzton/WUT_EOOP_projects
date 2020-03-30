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
Dentist_List::Dentist_List(){ head_D =NULL;}
Dentist_List::~Dentist_List(){

    Dentist *tab = NULL;
    while(head_D != NULL){
    tab = head_D;
	head_D = head_D->get_next();
    delete tab;
    }
}
Dentist* Dentist_List::get_head(){return head_D;}
void Dentist_List::set_head(Dentist* new_head){ head_D = new_head;}
//Dentist* Dentist_List::add_dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname){}
bool Dentist_List::check_if_dentist_exist(int Dentist_id){

    Dentist *curr = NULL;
    curr = head_D;

        while(curr != NULL){

            if(curr->get_dentist_id() == Dentist_id){

                return true;

            }else{

            curr = curr->get_next();

            }
        }
    return 0;
}

void Dentist_List::print(){

    Dentist *curr = head_D;

        if(curr == NULL){

            return;
        }

        cout << endl << "List of Dentists : "<< endl << endl;

            while(curr != NULL){

                curr->print();
                curr = curr->get_next();
                cout << endl;
            }
        cout<<endl;
    }

