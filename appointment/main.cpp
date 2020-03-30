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


int main(){

 Dental_Clinic c1("Warszawa Noakowskiego 37", 8.05, 20.15,"666524396");

    Patient* p1 = c1.add_patient(1, "Kasia", "Pagorek", "ul. Czarna 17 Warszawa", "543123451");
    Patient* p2 = c1.add_patient(2, "Ola", "Noz", "ul. 3 Maja 15 Warszawa", "623223151");
    Patient* p3 = c1.add_patient(3, "Maciek", "Gruz", "ul. Czarna 26 Warszawa", "7643123451");
    Patient* p4 = c1.add_patient(4, "Jagoda", "Bratowa", "ul. Slowackiego 37 Warszawa", "231453451");
    Patient* p5 = c1.add_patient(5, "Magda", "Wyga", "ul. Grudzie 28 Warszawa", "235223451");
    Patient* p6 = c1.add_patient(6, "Zofia", "Patria", "ul. Jagiellonska 15 Warszawa", "654423451");
    Patient* p7 = c1.add_patient(6, "Zofia", "Patria", "ul. Jagiellonska 86 Warszawa", "654423451");
    Patient* p8 = c1.add_patient(7, "Zofia", "Buklak", "ul. Daleka 23 Warszawa", "874423451");

    Dentist* d1 = c1.hire_dentist(1,"Marcin","Jusinski", 8.00, 17.00);
    Dentist* d2 = c1.hire_dentist(2,"Pawel","Margul", 8.15, 15.45);
    Dentist* d3 = c1.hire_dentist(3,"Pawel","Chrustny", 8.15, 20.15);
    Dentist* d4 = c1.hire_dentist(4,"Mateusz","Hermanski", 12, 18.30);
    Dentist* d5 = c1.hire_dentist(5,"Wiktor","Piwowar", 14, 20.15);
    Dentist* d6 = c1.hire_dentist(6,"Jan","Panne", 12, 16);
    Dentist* d7 = c1.hire_dentist(6,"Jan","Panne", 12, 20);
    Dentist* d8 = c1.hire_dentist(7,"Jan","Bak", 10, 18);
    Dentist* d9 = c1.hire_dentist(8,"Klaudia","Krawczyk", 10.15, 18.45);


    c1.arrange_appointment(14.00,13,2,2018,d1,p1);
    c1.arrange_appointment(14.00,12,2,2018,d2,p2);
    c1.arrange_appointment(15.00,12,2,2018,d3,p4);
    c1.arrange_appointment(16.00,15,2,2018,d5,p6);
    c1.arrange_appointment(17.00,12,2,2019,d4,p5);
    c1.arrange_appointment(18.00,16,1,2019,d6,p4);
    c1.arrange_appointment(19.00,12,1,2019,d2,p6);
    c1.arrange_appointment(19.00,12,1,2019,d2,p6);
    c1.arrange_appointment(20.00,14,1,2019,d3,p4);
    c1.arrange_appointment(13.00,12,1,2019,d1,p5);
    c1.arrange_appointment(13.00,13,2,2018,d4,p1);
    c1.arrange_appointment(19.00,12,1,2019,d2,p3);// not created because this dentist already has appointment with another patient
    c1.arrange_appointment(19.00,12,1,2019,d3,p6);// not created because patient already has a visit on this hour with another dentist


    c1.print_dentist();
    c1.print_patient();
    c1.fire_dentist(7);
   c1.fire_dentist(3);// will not be removed because has appointment
    c1.fire_dentist(99);//no such dentist, will not be removed
    c1.delete_patient(7);// will not be removed because has an appointment
    c1.delete_patient(98);// no such patient, will not be removed
    c1.delete_patient(4);
    c1.print();
    c1.print_dentist();
    c1.print_patient();

    c1.print_appointments();


    Dental_Clinic* clinic3=new Dental_Clinic("Wroclaw Garncarska Street 33",8.15,20.15, "678901234");// deleting whole clinic

   // clinic3->print();
    //clinic3->print_dentist();
   // clinic3->print_patient();
  //  clinic3->print_appointments();



        delete clinic3;

    return 0;
}
