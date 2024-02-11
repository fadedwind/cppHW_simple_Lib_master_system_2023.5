//this file is to define the functions in class "Book"
#include "Reader.h"
#include "Book.h"
#include <string>
#include <iostream>
using namespace std;
// constructor of class book
Book::Book(){
	code = 0;
	name = "unnamed";
	Is_Stock = true;
	Is_Existing = true;
}
Book::Book(int co, string na){
	code = co;
	name = na;
	Is_Stock = true;
	Is_Existing = true;
}
//number a book
void Book::setcode(int n){
	code = n;
}
//get a book number
int Book::getcode(){
	return code;
}
//name the book
void Book::setname(string na){
	name = na;
}
//get the name of a book
string Book::getname(){
	return name;
}
//load the info that if the book is in the base 
bool Book::get_Stock(){
	return Is_Stock;
}
//set the info that if the book is in the base 
void Book::set_Stock(bool is){
	Is_Stock = is;
}
//get the data "if the book is lent"
bool Book::get_Existing(){
	return Is_Existing;
}
//set the data "if the book is lent"
void Book::set_Existing(bool is){
	Is_Existing = is;
}
// show the data of the book
void Book::show(){
	if (Is_Existing){
		cout << "名称：" << name << " 书号：" << code;
		// check if the book is lent
		if (Is_Stock) cout << " 在架";
		else cout << " 借出";
		cout << endl;
	}
}

