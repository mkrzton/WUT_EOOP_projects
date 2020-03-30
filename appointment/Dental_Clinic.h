#pragma once
#ifndef DENTAL_CLINIC_H_INCLUDED
#define DENTAL_CLINIC_H_INCLUDED

#include <iostream>
#include <string.h>


#include "Appointment.h"
#include "Appointment_List.h"
#include "Dentist.h"
#include "Dentist_List.h"
#include "Patient.h"
#include "Patient_List.h"

using namespace std;

class Dental_Clinic {

private:

	string address;
	float open_hour;
	float close_hour;
	string telephone_number;
	Appointment_List *appointment;
	Dentist_List *dentist;
	Patient_List *patient;
	Appointment *app;

public:

	Dental_Clinic(string new_address, float new_open_hour, float new_close_hour, string new_telephone_number);
	~Dental_Clinic();
	string get_address();
	float get_open_hour();
	float get_close_hour();
	string get_telephone_number();

	void print();
	void print_patient();
	void print_dentist();
	void print_appointments();
	Appointment_List* get_list();

	Patient*add_patient(int New_patient_id, string New_patient_name, string New_surname, string new_patient_address, string New_patient_phone_number);
	Dentist*hire_dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname, float new_Dentist_arriving_hour, float new_Dentist_leaving_hour);
	void arrange_appointment(float hour, int day, int month, int year, Dentist *dentist, Patient *patient);
	void fire_dentist(int new_Dentist_id);
	void delete_patient(int patient_id);

};
#endif // DENTAL_CLINIC_H_INCLUDED

