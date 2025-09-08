#include <iostream>
#include <string>

using namespace std;

class Person
{
    protected:
        /* data */
        string name;
        int age;
    public:
        Person(string name, int age): name(name), age(age){}

        void setName(string n){
            name = n;
        }
        string getName() const{ return name;}

        virtual void display() const{
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

class Employee: public Person
{
    private:
        double salary;
    public:
    Employee(string n, int a): Person(n, a), salary(0){}
        void work() const{ 
            cout << "Performs tasks!" << endl;
        }

        void display(){
            Person::display();
            cout << ",\t Salary: " << salary << endl;
        }
};

int main(){
    //Example1
    Person employee("Alice", 27);
    employee.display();
    employee.setName("Alicia");
    cout << "Employee's new name is: " << employee.getName() << endl;

    //Example2
    Employee emp1("John Smith", 24);
    emp1.setName("Mark");
    emp1.display();
    return 0;
}