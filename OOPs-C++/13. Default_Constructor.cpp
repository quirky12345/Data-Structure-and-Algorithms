#include<iostream>
using namespace std;
// Creating Class Employee
class Employee{
	public:
		// Default Constructor below:
		Employee(){
			cout<<"Default Constructor called"<<endl;
		}
};
int main(void){
	Employee e1; //creating an object of Employee   
    Employee e2; //creating an object of Employee  
	// Employee e1 = Employee();   
    // Employee e2 = Employee();   
	return 0;
}