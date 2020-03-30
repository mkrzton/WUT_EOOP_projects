#include <iostream>
#include <string>

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
Patient::Patient(int New_patient_id, string New_patient_name, string New_surname, string new_patient_address, string New_patient_phone_number){

	Patient_name = New_patient_name;
	Patient_surname = New_surname;
	Patient_address = new_patient_address;
	Patient_phone_number = New_patient_phone_number;
	patient_id = New_patient_id;
        next = NULL;

    }

Patient::~Patient(){}
string Patient::get_Patient_name() const{return Patient_name;}
string Patient::get_Patient_surname()const {return Patient_surname;}
int Patient::get_patient_id() const{return patient_id;}
string Patient::get_Patient_address()const {return Patient_address;}
string Patient::get_Patient_phone_number()const {return Patient_phone_number;}
Patient* Patient:: get_next_patient()const {return next;}
void Patient::set_next_Patient(Patient *another){ next = another; };
void Patient::print(){
	cout<< "Patient: " << Patient_name << " " << Patient_surname << " ID: " <<
	patient_id << " Contact Number: " << Patient_phone_number << " Address: " << Patient_address<< endl;
	}
//ostream& Patient:: operator<< (ostream &output){

//    output << "Patient: " << get_Patient_name() << " " << get_Patient_surname() << " ID: " << get_patient_id() << endl;
   // return output;
//}
