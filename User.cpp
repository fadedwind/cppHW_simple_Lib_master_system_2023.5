//The reader has separate information before corresponding to the book, 
//so it is more convenient for the Reader class to have a User base class
#include "User.h"
#include <string>
#include <iostream>
using namespace std;
//constructor
User::User(){	
	code = 0;
	name = "unnamed";
}
User::User(int id, string na){
	code = id;
	name = na;
}
//set number
void User::setcode(int n){
	code = n;
}
//get number
int User::getcode(){
	return code;
}
//set name
void User::setname(string na){
	name = na;
}
//get name
string User::getname(){
	return name;
}
//show user
void User::show(){
	cout << "姓名：" << name << " 编号：" << code << endl;
}
