#include <iostream>
#include <cstring>
using namespace std;

class Bank
{
public:
    char* Bname;
    Bank() {  }
    Bank(char *s)
    {
        Bname=new char[strlen(s)];
        Bname=s;
    }
    Bank(const Bank &bn)
    {
        Bname=new char [strlen(bn.Bname)];
        Bname=bn.Bname;
    }
    ~Bank()
    {
          delete[]Bname;
          cout<<"Destructing Bank"<<endl;
    }

};
class Customer;
class Person
{
    int age;
    char* Pname;
public:

    Person() {  }
    Person(char *p,int a)
    {
         //cout<<"In constructor for Mr. X"<<endl;
        Pname=new char [strlen(p)];
        Pname=p;
        age=a;
    }
    Person(const Person &anm)
    {
         cout<<"In constructor for Mr. X"<<endl;
        Pname=new char[strlen(anm.Pname)+1];
        Pname=anm.Pname;
        age=anm.age;
    }
    ~Person()
    {
        delete [] Pname;
        //cout<<"destructing person"<<endl;
    }
    virtual void show()
    {
         cout<<"Person name: Mr. X" <<endl;
         cout<<"Age: "<<age<<endl;
    }
};

class Employee:public Bank,public Person
{
protected:
    double salary;
    double incr;
public:
    int emp_card;
    Employee() {  }
    Employee(char *s,char *t,int a,double b,double c,int d):Bank(s),Person(t,a)
    {
        cout<<"Constructing Employee 1340 of bank Brac Bank"<<endl;
        salary=b;
        incr=c;
        emp_card=d;
    }
    Employee(Bank &bb,Person &pp,double a,double b,int c)
    {
         cout<<"In constructor for Mr. X"<<endl;
        salary=a;
        incr=b;
        emp_card=c;
    }
    void show()
    {

        cout<<"Employee card:  "<<emp_card<<endl;
        cout<<"Salary:  "<<salary<<endl;
        cout<<"Increment:  "<<incr<<endl;
    }
    ~Employee()
    {
         //cout<<"destruct Employee"<<endl;
    }

    friend void operator+(Employee &a,Customer &b);
};

class Customer:public Bank,public Person
{

protected:
    int purchase;
    double discount;
public:
    int cust_card;
    Customer() {  }
    Customer(char *s,char *t,int a,int b,double c,int d):Bank(s),Person(t,a)
    {
         cout<<"Constructing Customer 3015 of bank Brac Bank"<<endl;
        purchase=b;
        discount=c;
        cust_card=d;
    }
    Customer(Bank &bb,Person &pp,int a,double b,int c)
    {
        cout<<"In constructor for Mr. X"<<endl;
        purchase=a;
        discount=b;
        cust_card=c;
    }
    void show()
    {
        cout<<"customer card: "<<cust_card<<endl;
        cout<<"no of purchase: "<<purchase<<endl;
        cout<<"discount: "<<discount<<endl;
    }
    friend void operator+(Employee &a,Customer &b);
    ~Customer() { }
};

void operator+(Employee &a,Customer &b)
{
    a.salary=a.salary-(b.purchase)*100;
    b.discount=b.discount+(a.incr)*(b.purchase);
}

void display(Employee &emp, Customer &cust)
{
    cout<< "--------------------------------------"<<endl;
    emp.show();
    cout<<endl;
    cust.show();
    cout<< "--------------------------------------\n"<<endl;
}

int main()
{
    Bank bank("World Bank");
    Person person("Mr. X", 35);

    /*
    <bank_name>, <person_name>, <person_age>, <salary>, <increment>, <card_no>
    */
    Employee emp1("Brac Bank", "Mr. Y", 30, 30000, 500.5, 1340);
    /*
    <bank_name>, <person_name>, <person_age>, <no_of_purchase>, <discount>, <card_no>
    */
    Customer cust1("Brac Bank", "Mr. Z", 31, 9, 850.5, 3015);
    cout<< "\nModifying emp1 and cust1:\n";
    display(emp1, cust1);
    emp1 + cust1;
    display(emp1, cust1);

    /*
    <bank>, <person>, <salary>, <increment>, <card_no>
    */
    Employee emp2(bank, person, 44000, 480, 2219);
    /*
    <bank>, <person>, <no_of_purchase>, <discount>, <card_no>
    */
    Customer cust2(bank, person, 12, 370, 2219);
    cout<< "\n\nModifying emp2 and cust2:\n";
    display(emp2, cust2);
    emp2 + cust2;
    display(emp2, cust2);

    Person *p;
    p = &person;
    cout<< "--------------------------------------"<<endl;
    /*
    Implement necessary show() functions
    */
    p->show();
    p = &cust1;
    cout<< "--------------------------------------"<<endl;
    p->show();
    cout<< "--------------------------------------"<<endl;

    return 0;
}
