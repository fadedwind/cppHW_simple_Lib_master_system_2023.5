#ifndef READER_H 
#define READER_H // avoid redef

#include "Book.h"
#include "User.h"
using namespace std;

class Reader: public User
{
	private:
		bool Is_Existing;  			//ture:exist，false: not exist
		bool Is_Borrowing;  		//true:has borrowed a book，false:has not borrowed a book
		Book brbook;     			//show the lent book
	public:
		Reader();               	//constructor
		Reader(int id, string na);  //constructor, with initialization
		bool get_Existing();        //to get delete flag
		void set_Existing(bool);    //to set delete flag
		bool get_Borrowing();       //to obtain reader borrowing
		void set_Borrowing(bool);   //to set the data of book borrowing
		void setbrbook(Book bt);    //to record readers' borrowing information
		Book getbrbook();		    //to get information that borrowing books of readers
		void show();			    //show the basic information of readers and the borrowing status
};

#endif //READER_H 