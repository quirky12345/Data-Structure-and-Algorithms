#include<iostream>
using namespace std;
struct Rectangle{
	int width;
	int height;
	Rectangle(int w,int h){
		this->width = w;
		this->height = h;
	}
	void display(){
		cout<<"Area of Rectangle: "<<width*height<<endl;
	}
};
int main(){
	struct Rectangle rec = Rectangle(5,4);
	rec.display();
	return 0;
}