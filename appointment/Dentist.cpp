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

//class Appointment_List; raczej bez sensu tu deklarowaæ klasy
//class Patient;
//class Dentist;
//class Dentists_List;
//class Patient_List;
//class Appointment;
Dentist::Dentist(int new_Dentist_id, string new_Dentist_name, string new_Dentist_surname, float new_Dentist_arriving_hour, float new_Dentist_leaving_hour){

        Dentist_id = new_Dentist_id;
        Dentist_name = new_Dentist_name;
        Dentist_surname = new_Dentist_surname;
        Dentist_arriving_hour = new_Dentist_arriving_hour;
        Dentist_leaving_hour = new_Dentist_leaving_hour;
        next = NULL;

    }

//Dentist::~Dentist(){} w .h zdefiniowa³eœ ju¿
int Dentist::get_dentist_id()const {return Dentist_id;}
string Dentist::get_Dentist_name() const {return Dentist_name;}
string Dentist::get_Dentist_surname()const {return Dentist_surname;}
float Dentist::get_Dentist_arrive_hour()const {return Dentist_arriving_hour;}
float Dentist::get_Dentist_leaving_hour()const {return Dentist_leaving_hour;}
Dentist* Dentist::get_next()const {return next;}
void Dentist::set_next_Dentist(Dentist* another){next = another;}
void Dentist::print()
{
	cout<< "Dentist: " << Dentist_name << " " << Dentist_surname << " ID: " <<
	Dentist_id<< " Working hours: " << Dentist_arriving_hour << "-"
	<< Dentist_leaving_hour << endl;
}
//ostream& Dentist:: operator<< (ostream &output){

  // output << "Dentist: " << Dentist_name << " " <<get_Dentist_surname() << " ID: " << get_dentist_id() << endl;
 //  return output;
//}

