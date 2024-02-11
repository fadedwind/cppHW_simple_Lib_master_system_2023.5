#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H // avoid redef

#include <vector>
#include <string>

#include "Book.h"
using namespace std;

class BookManager
{
	private:
		vector <Book> bkarr;  //save the data of the book; it is convinient to use vector to express an array
	public:
		BookManager();
		~BookManager();
	
		void addbook(Book book);    				//add book
		int findbook(string name); 					//find book
		int findbook(int code);  					//find book
		Book getbook(int subscript);
		void editbook(int subscript, Book book);	//edit book
		void editbook(int subscript, int code);		//edit book
		void editbook(int subscript, string name);	//edit book
		void editbook(int subscript, bool Is_Stock);//edit book
		void delbook(int subscript);   				//delete book
		void listbooks(); 						 	//show all the books
		void save(string filename = "books.db"); 	//save
		void load(string filename = "books.db");	//load
};

#endif //BOOKMANAGER_H
