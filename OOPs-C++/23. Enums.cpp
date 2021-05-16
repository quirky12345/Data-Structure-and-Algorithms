#include<iostream>
using namespace std;
enum Week {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
int main(){
	Week day;
	day = Sunday;
	cout<<"Day: "<<day+1<<endl;
	return 0;
}