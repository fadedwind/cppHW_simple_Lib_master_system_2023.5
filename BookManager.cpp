//the file is to define the functions in the class "Bookmanager"
#include "BookManager.h"

#include <string>
#include <iostream>

#include <fstream>
//Requiment: File stream
using namespace std;

// constructor
BookManager::BookManager()
{
}

// deconstructor
BookManager::~BookManager()
{
}

//add new book
void BookManager::addbook(Book book)
{
	bkarr.push_back(book);
}

//find the data of a book
int BookManager::findbook(string name)
{
	for (int i = 0; i < bkarr.size(); i++)
	{
		if (bkarr[i].getname() == name) return i;
	}
	return -1;
}
int BookManager::findbook(int code)
{
	for (int i = 0; i < bkarr.size(); i++)
	{
		if (bkarr[i].getcode() == code && bkarr[i].get_Existing() == true)
		{
			if (bkarr[i].get_Stock() == true)
				return i;
			else return -2;
		}
	}
	return -1;
}

//load the data of books
Book BookManager::getbook(int subscript)
{
	return bkarr[subscript];
}

//edit the information of books
void BookManager::editbook(int subscript, Book book)
{
	bkarr[subscript] = book;
}
void BookManager::editbook(int subscript, int code)
{
	bkarr[subscript].setcode(code);
}
void BookManager::editbook(int subscript, string name)
{
	bkarr[subscript].setname(name);
}
void BookManager::editbook(int subscript, bool Is_Stock)
{
	bkarr[subscript].set_Stock(Is_Stock);
}

//delete books
void BookManager::delbook(int subscript)
{
	bkarr[subscript].set_Existing(false);
}

//show books
void BookManager::listbooks()
{
	cout << "所有的图书为" << endl;
	for (int i = 0; i < bkarr.size(); i++)
	{
		if (bkarr[i].get_Existing())
			bkarr[i].show();
	}
}

//save data of the books: outfile stream needed
void BookManager::save(string filename)
{
	ofstream outfile(filename.c_str(), ios::binary);//in binary form
	if (!outfile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	int bksize = bkarr.size();
	outfile.write((char*)(&bksize), sizeof(bksize));//Requiment 6： io stream
	for (int i = 0; i <bksize; i++)
		outfile.write((char*)(&bkarr[i]), sizeof(Book)); //write into the file
	outfile.close();
}

//load data of the books:infile stream needed
void BookManager::load(string filename)
{
	ifstream infile(filename.c_str(), ios::binary);//in binary form
	if (!infile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	bkarr.clear();
	int bksize;
	infile.read((char*)(&bksize), sizeof(bksize));
	bkarr.reserve(bksize * 2);
	Book *bookarray = new Book[bksize];//dynamic storage
	for (int i = 0; i < bksize; i++)
	{
		infile.read((char*)(&bookarray[i]), sizeof(Book));
		bkarr.push_back(bookarray[i]);// load from the file
	}
	infile.close();
}
