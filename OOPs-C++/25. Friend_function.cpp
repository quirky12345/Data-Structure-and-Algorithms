#include<iostream>
using namespace std;
class B;
class A{
	int x;
public:
	void setdata(int i){
		this->x = i;
	}
	friend void min(A,B);
};
class B{
	int y;
public:
	void setdata(int i){
		this->y = i;
	}
	friend void min(A,B);
};
void min(A a,B b){
    if(a.x <= b.y)cout<<a.x<<endl;
    else cout<<b.y<<endl;
    return;
}
int main(){
	A a;
	a.setdata(5);
	B b;
	b.setdata(4);
	cout<<"Minimum of a and b is: ";
	min(a,b);
	return 0;
}