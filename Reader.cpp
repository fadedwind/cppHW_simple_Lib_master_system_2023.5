//To define the functions in the class"Reader",interitate from class: User
#include "Reader.h"

#include <iostream>
#include <string>
using namespace std;

//constructor
Reader::Reader()
{
	Is_Borrowing = true;
	Is_Existing = true;
}
Reader::Reader(int id, string na) :User(id, na)// constructor interitance
{
	Is_Borrowing = true;
	Is_Existing = true;
}

//set the data "if the reader is existed"
bool Reader::get_Existing()
{
	return Is_Existing;
}

//set the data "if the reader is existed"
void Reader::set_Existing(bool is)
{
	Is_Existing = is;
}

//Get information that borrowing books of readers
bool Reader::get_Borrowing()
{
	return Is_Borrowing;
}

//set information that borrowing books of readers
void Reader::set_Borrowing(bool is)
{
	Is_Borrowing = is;
}

//set the book if book is lent
void Reader::setbrbook(Book bt)
{
	brbook = bt;
}

//show the lent book of the reader
Book Reader::getbrbook()
{
	return brbook;
}

//Get information that borrowing books of readers
void Reader::show()
{
	User::show();
	if (brbook.get_Stock() == false)
		cout << " 书名是" << brbook.getname() <<" 书号是"<<brbook.getcode()<< endl;
	cout << Is_Existing << endl;
}
