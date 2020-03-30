#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
class Car{


private:

    char* make;
    int licence_plate;
    int owner_id;
    int price;
    Car* next;



public:

    Car(const char* make, int licence_plate, int owner_id, int price);
    ~Car();
    Car(const Car &x);
    void print();

    Car* get_next() const { return next;}
    void set_next(Car* nxt) { next = nxt;}
    char* get_make() const { return make;}
    int get_licence_plate() const { return licence_plate;}
    int get_owner_id() const { return owner_id;}
    int get_price() const { return price;}
    void set_price(int pr) { price=pr;}


};

Car::Car(const char *new_make, int new_licence_plate, int new_owner_id, int new_price){

    make = new char[strlen(new_make)+1];
        if(make == NULL){

            exit(1);
        }

    strcpy(make, new_make);
    licence_plate = new_licence_plate;
    owner_id = new_owner_id;
    price=new_price;
    next = NULL;
}

Car::~Car(){

    delete[] make;
    make = NULL;

}
void Car::print(){
    cout << "make: " << get_make() << "\tlicence plate: " << get_licence_plate() << "\towner id : " << get_owner_id() << "\tprice: " << get_price() << endl;
}


Car::Car(const Car &x){

    make = new char[strlen(x.make)+1];
    if(make == NULL){
        cerr << "error of memory allocation" << endl;
        exit(1);
    }

    strcpy(make, x.make);
    licence_plate=x.licence_plate;
    owner_id = x.owner_id;
    price = x.price;
    next = x.next;
}


class Car_List{

Car *head;

public:
    Car_List();
    ~Car_List();
    Car_List(const Car_List& x);
    Car_List & operator= (const Car_List & x);
    Car_List & operator+ (const Car_List & x);
    friend Car_List operator- (const Car_List &x, const Car_List &y);

    void add_Car(char *make, int licence_plate, int owner_id, int price);
    void remove_owner(int owner_id);
    void print();
    bool check_if_exists(int licence_plate, int owner_id, int price);
    bool check_if_there_are_4_Cars(char* make);

};

Car_List::Car_List(){
   head = NULL;
}
Car_List::~Car_List(){
    Car *temp = NULL;

    while(head != NULL){
        temp = head;
        head = head->get_next();
        delete temp;
    }
}

Car_List::Car_List(const Car_List& x)
{
    head=NULL;
    *this=x;
}

Car_List & Car_List::operator= (const Car_List& x){

        if(this == &x){
            return *this;
        }
        Car *temp = head;
        while(head != NULL){
           // temp = head;
            head = head->get_next();
            delete temp;
        }
        temp = x.head;

        Car *curr = NULL;
        if(temp != NULL){
            head = new Car(*temp);
            if(head == NULL){

                exit(1);
            }

            curr = head;
            temp = temp->get_next();
        }
        while(temp != NULL){
            Car *new_element = new Car(*temp);
            if(new_element == NULL){

                exit(1);
            }
            curr->set_next(new_element);
            curr = new_element;
            temp = temp->get_next();
        }
        return *this;
    }
bool Car_List::check_if_exists(int licence_plate, int owner_id, int price)
{
    Car* car=head;
   while(car !=NULL){

        if(car->get_licence_plate()==licence_plate && car->get_owner_id()==owner_id){

            car->set_price(price);

            return true;
        }

        else if(car->get_licence_plate()==licence_plate) return true;
            car=car->get_next();
    }
    return false;
}

bool Car_List::check_if_there_are_4_Cars(char* make)
{
    Car* current=head;
    if ( head==NULL) return false;
    int count=0;
    while (current != NULL)
    {
        if(strcmp(current->get_make(), make)==0) count++;
        current = current->get_next();
    }
    if (count>3) return true;
    return false;
}

void Car_List::add_Car(char* make, int licence_plate, int owner_id, int price)
{
    Car* car=head;

if (check_if_exists(licence_plate, owner_id, price)) return;

Car* new_car = new Car(make, licence_plate, owner_id, price);



 if (head == NULL) head=new_car;
    else if (licence_plate < head->get_licence_plate()){
        new_car->set_next(head);
        head = new_car;
    } else {
         while (car != NULL)
         {
             if (car->get_licence_plate() < licence_plate && (car -> get_next()==NULL || licence_plate < car->get_next()->get_licence_plate()) ){
                new_car->set_next(car->get_next());
                car->set_next(new_car);
                return;
             }
           car = car->get_next();

         }
         delete[] new_car->get_make();
            delete new_car;
    }
}


void Car_List::remove_owner(int id)
{

    Car *temp = NULL;
    Car *current=head;

    if(head==NULL) {

        return;

    }else{

        while(current !=NULL){

            if(head->get_owner_id()==id){

                temp=head;
                head=head->get_next();
                delete temp;
                return;

            }else{
                    while(current->get_next() != NULL){

                        if(current->get_next()->get_owner_id()==id){

                            temp=current->get_next();
                            current->set_next(current->get_next()->get_next());
                            delete temp;
                            return;

                        }else {

                            current= current->get_next();
                        }
                    }
                }

            current= current->get_next();

        }

    }

}

void Car_List::print()
{

  Car* current= head;
    if(current==NULL){

       cout << endl << "List is empty" << endl;
    }else{
    cout << endl << "List of cars: " << endl << endl;

    while(current != NULL){

        cout<< "Make: " << current->get_make() << "\tLicense number: " << current->get_licence_plate() << "\tOwner id: " << current->get_owner_id() << "\tPrice: " << current->get_price() << " zl"<< endl;
        current=current->get_next();
    }
    }

}
Car_List & Car_List::operator+ (const Car_List &x)
{
    if(this == &x) return *this;
    Car *newb=x.head;
    while(newb)
    {
        add_Car(newb->get_make(),newb->get_licence_plate(),newb->get_owner_id(),newb->get_price());
        newb=newb->get_next();
    }
    return *this;
}

Car_List operator-(const Car_List &x,const Car_List &y){

    Car_List* L1= new Car_List();
    Car* current=x.head;
    Car* current2=y.head;

    int count=0;
    while(current)
    {
        while(current2)
        {
            if(strcmp(current->get_make(),current2->get_make())==0)
            {
                count++;
                break;
            }
            current2=current2->get_next();
        }
        current2=y.head;
        if(count==0)
        {
            L1->add_Car(current->get_make(),current->get_licence_plate(),current->get_owner_id(), current->get_price());
        }
        current=current->get_next();
        count=0;
    }
    return *L1;

}
int main(){

Car_List *List = new Car_List();//dynamic list
Car_List List2;
Car_List List3;//automatic list
Car_List List4;
Car_List Suma;
Car_List Roznica;

cout<<"Dynamic List: "<< endl;
List->add_Car((char*)"Ford", 123, 12, 6000);
List->add_Car((char*)"Volvo", 4321, 11, 8000);
List->add_Car((char*)"Skoda", 21, 23, 3500);
List->add_Car((char*)"BMW", 546, 45, 5050);
List->add_Car((char*)"Opel", 3429, 15, 9000);
List->add_Car((char*)"Opel", 3429, 15, 9000);
List->print();
List->remove_owner(23);
List->print();
List->remove_owner(15);
List->remove_owner(12);
List->print();

cout<<"Automatic List: "<< endl;

List3.add_Car((char*)"Ford", 212, 65, 21213);
List3.add_Car((char*)"Skoda", 13223, 122, 42321);
List3.add_Car((char*)"Dodge", 1223, 1123, 63200);
List3.print();
List3.remove_owner(65);
List3.print();


Car_List l5=*List;
l5.print();
List3.print();
cout<< endl <<"Testing + operator"<< endl;
Suma=l5+List3;
Suma.print();
cout<< endl <<"Testing - operator"<< endl;
Roznica=Suma-List3;
Roznica.print();

List2 = *List;
cout << endl<< "Demonstration of = operator on dynamic list: ";
List2.print();
List4 = List3;
cout << endl<< "Demonstration of = operator on automatic list: ";
List4.print();
return 0;
}
