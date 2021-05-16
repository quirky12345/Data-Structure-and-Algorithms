#include<iostream>
using namespace std;
class Employee{
	int id;
	string name;
	float salary;
public:
	// Parameterized Constructor
	Employee(int i,string n,float s){
		// Here, this pointer is used to refer current class instance valriable.
		this->id = i;
		this->name = n;
		this->salary = s;
	}
	void display(){
		cout<<id<<" "<<name<<" "<<salary<<endl;
	}
};
int main(){
	// creating instance of class: Employee
	Employee e1 = Employee(1,"Chaitanya",45678);
	Employee e2 = Employee(2,"Parismita",78568);
	e1.display();
	e2.display();
	return 0;
}