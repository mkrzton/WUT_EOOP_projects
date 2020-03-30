
#include <iostream>
#include <stdlib.h>
#include <string>

#include "Dental_Clinic.h"
#include "Appointment.h"
#include "Appointment_List.h"
#include "Dentist.h"
#include "Dentist_List.h"
#include "Patient.h"
#include "Patient_List.h"

using namespace std;

Dental_Clinic::Dental_Clinic(string new_address, float new_open_hour, float new_close_hour, string new_telephone_number){

        address = new_address;
        open_hour=new_open_hour;
        close_hour=new_close_hour;
        telephone_number= new_telephone_number;
        appointment=new Appointment_List();
        dentist = new Dentist_List();
        patient = new Patient_List();
}
Dental_Clinic::~Dental_Clinic(){cout<<"clinic has been removed"<<endl;}
string Dental_Clinic::get_address(){return address;}
float Dental_Clinic::get_open_hour(){return open_hour;}
float Dental_Clinic::get_close_hour(){return close_hour;}
string Dental_Clinic::get_telephone_number(){return telephone_number;}
void Dental_Clinic::print(){cout<< endl << "Clinic's Address: " << address<< "\tOpening Hours: " << open_hour << "-" << close_hour<<"\tTelephone Number: " <<telephone_number<< endl << endl;}
void Dental_Clinic::print_patient(){patient->print();}
void Dental_Clinic::print_dentist(){dentist->print();}
void Dental_Clinic::print_appointments(){appointment->print();}
Appointment_List * Dental_Clinic:: get_list(){return appointment;}
Patient * Dental_Clinic::add_patient(int New_patient_id, string New_patient_name, string New_surname, string new_patient_address, string New_patient_phone_number){

        if(patient->check_if_patient_exist(New_patient_id)){return NULL;}

        Patient *curr = patient->get_head();
        Patient *tab = new Patient(New_patient_id, New_patient_name, New_surname, new_patient_address, New_patient_phone_number);

            if(patient->get_head() == NULL){
                patient->set_head(tab);
                return tab;

            }else if(New_patient_id < patient->get_head()->get_patient_id()){//if patient is not the first one

                tab->set_next_Patient(patient->get_head());
                patient->set_head(tab);
                return tab;

            }else{

                while(curr != NULL){

                    if(curr->get_patient_id() < New_patient_id && (curr->get_next_patient() == NULL || New_patient_id< curr->get_next_patient()->get_patient_id())){

                        tab->set_next_Patient(curr->get_next_patient());
                        curr->set_next_Patient(tab);
                        return tab;
                    }

                curr = curr->get_next_patient();

            }
        }

    return 0;
}
Dentist* Dental_Clinic::hire_dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname, float new_Dentist_arriving_hour, float new_Dentist_leaving_hour){

    if(dentist->check_if_dentist_exist(new_Dentist_id)){return NULL;}

        Dentist* curr = dentist->get_head();
        Dentist*tab = new Dentist(new_Dentist_id, new_Dentist_name, new_Dentist_surname, new_Dentist_arriving_hour, new_Dentist_leaving_hour);

            if(dentist->get_head() == NULL){
                dentist->set_head(tab);
                return tab;

            }else if(new_Dentist_id < dentist->get_head()->get_dentist_id()){//if dentist is not the first one

                tab->set_next_Dentist(dentist->get_head());
                dentist->set_head(tab);
                return tab;

            }else{

                while(curr != NULL){

                    if(curr->get_dentist_id() < new_Dentist_id && (curr->get_next() == NULL || new_Dentist_id< curr->get_next()->get_dentist_id())){

                        tab->set_next_Dentist(curr->get_next());
                        curr->set_next_Dentist(tab);
                        return tab;
                }

            curr = curr->get_next();
        }
    }
    return 0;
}

void Dental_Clinic::arrange_appointment(float hour,int day, int month, int year, Dentist *dentist, Patient *patient){

     int id=dentist->get_dentist_id();

        if(appointment->check_if_matches_dentist_hours(dentist, hour)==true){

            cout<<"This hour doesn't match this dentist working hours." << endl;
            return;

        }

        if(appointment->check_if_dentist_available(dentist, hour, day, month, year)!=1 || appointment->check_if_patient_does_not_have_appointment(patient,hour, day, month, year)!=1){

              cout<<"Appointment already arranged for this hour"<<endl;
              return;

          }


        Appointment *curr = appointment->get_head1();
        Appointment *tab = new Appointment(hour,day, month, year, dentist, patient);


        if(appointment->get_head1() == NULL){

            appointment->set_head1(tab);

        }else if(id< appointment->get_head1()->get_dentist()->get_dentist_id()){

            tab->set_next_Appointment(appointment->get_head1());
            appointment->set_head1(tab);

        }else{

            while(curr != NULL){
                if(curr->get_dentist()->get_dentist_id() <= id && (curr->get_next_appointment() == NULL || id <curr->get_next_appointment()->get_dentist()->get_dentist_id())){

                    tab->set_next_Appointment(curr->get_next_appointment());
                    curr->set_next_Appointment(tab);
                    return;
                }
            curr = curr->get_next_appointment();
        }
    }

    return;
}
void Dental_Clinic::fire_dentist(int new_Dentist_id) {

	if (!appointment->is_dentist_free(new_Dentist_id)) {

		cout << "Cannot be removed, because dentist has undone job " << endl;
		return;
	}
	{

		Dentist *tab = NULL;
		Dentist *curr = dentist->get_head();

		if (dentist->get_head() == NULL) {

			return;
		}
		else {

			while (curr != NULL) {

				if (dentist->get_head()->get_dentist_id() == new_Dentist_id) {

					dentist->set_head(tab);
					dentist->set_head(dentist->get_head()->get_next());
					delete tab;

				}
				else {

					while (curr->get_next() != NULL) {

						if (curr->get_next()->get_dentist_id() == new_Dentist_id) {

							tab = curr->get_next();
							curr->set_next_Dentist(curr->get_next()->get_next());
							delete tab;

						}
						else {

							curr = curr->get_next();
						}
					}
				}

				curr = curr->get_next();
			}
		}
	}

}

void Dental_Clinic::delete_patient(int patient_id) {

	if (!appointment->does_patient_have_appointment(patient_id)) {

		cout << "Cannot be removed, because patient has arranged appointment " << endl;
		return;
	}
	{

		Patient *tab = NULL;
		Patient *curr = patient->get_head();
		if (patient->get_head() == NULL) {
			return;

		}
		else {

			while (curr != NULL) {

				if (patient->get_head()->get_patient_id() == patient_id) {

					patient->set_head(tab);
					patient->set_head(patient->get_head()->get_next_patient());
					delete tab;

				}
				else {

					while (curr->get_next_patient() != NULL) {

						if (curr->get_next_patient()->get_patient_id() == patient_id) {

							tab = curr->get_next_patient();
							curr->set_next_Patient(curr->get_next_patient()->get_next_patient());
							delete tab;

						}
						else {

							curr = curr->get_next_patient();
						}
					}
				}
				curr = curr->get_next_patient();
			}
		}
	}
}