#include<iostream>
using namespace std;
// Creating Class Employee
class Employee{
	public:
		int id;//data member (also instance variable) 
		string name;//data member (also instance variable) 
		float salary;//data member (also instance variable) 
		// Parameterized Constructor below:
		Employee(int i,string n,float s){
			id = i;
			name = n;
			salary = s;
		}
		void display(){
			cout<<id<<" "<<name<<" "<<salary<<endl;
		}
};
int main(void){ 
	Employee e1 = Employee(1,"Chaitanya",100000.5);   
    Employee e2 = Employee(2,"Parismita",90000.5);
    e1.display();
    e2.display();   
	return 0;
}