#ifndef BOOK_H 
#define BOOK_H // avoid redef

#include <string>
using namespace std;

class Book
{
	private:
		int code;        			//book number
		string name;     			//book
		bool Is_Stock;          	//the value--true:is on the shelf   false: has been lent
		bool Is_Existing;       	//true: exist, false: not exist

	public:
		Book(); 					//constructor: initialization
		Book(int co, string na);  	

		void setcode(int n);   		//set book number
		int getcode();    			//get book number
		void setname(string na);    //set book name
		string getname();  			//get book name

		bool  get_Stock();  		//get the data that if the book is in the base
		void set_Stock(bool is);	//set the data that if the book is in the base
		bool  get_Existing();		//get if the book exists
		void set_Existing(bool is);	//set if the book exists
		void show();	
};

#endif //BOOK_H 