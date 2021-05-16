#include<iostream>
using namespace std;
class Demo{
	int a;
	int b;
	int *p;
public:
	// Default Constructor
	Demo(){
		p = new int;
	}
	// setting the value
	void setdata(int x,int y,int z){
		a = x;
		b = y;
		*p = z;
	}
	void showdata(){
		cout<<"value of a: "<<a<<endl;
		cout<<"value of b: "<<b<<endl;
		cout<<"value of *p: "<<*p<<endl;
	}
};
int main(){
	// creating an instance for class Demo
	Demo d1;
	d1.setdata(4,5,6);
	// Shollow copy(without copy constructor) = value will be copied as it is.
	Demo d2 = d1;
	d2.showdata();
	return 0;
}