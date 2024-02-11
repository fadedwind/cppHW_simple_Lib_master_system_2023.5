//to define the functions in class"ReaderManager"
#include "ReaderManager.h"

#include <string>
#include <iostream>
//file stream
#include <fstream>
using namespace std;

//get data of readers
Reader ReaderManager::getreader(int subscript)
{
	return rdarr[subscript];
}

//add readers
void ReaderManager::addreader(Reader reader)
{
	rdarr.push_back(reader);
}

//find readers
int ReaderManager::findreader(string name)
{
	for (int i = 0; i < rdarr.size(); i++)
	{
		if (rdarr[i].getname() == name) return i;
	}
	return -1;
}
int ReaderManager::findreader(int code)
{
	for (int i = 0; i < rdarr.size(); i++)
	{
		if (rdarr[i].getcode() == code) return i;
	}
	return -1;
}
int ReaderManager::findreader(Book book)
{
	for (int i = 0; i < rdarr.size(); i++)
	{
		if (rdarr[i].getbrbook().getcode() == book.getcode() && rdarr[i].getbrbook().getname() == book.getname()) return i;
	}
	return -1;
}

//edit reader information
void ReaderManager::editreader(int subscript, Reader reader)
{
	rdarr[subscript] = reader;
}
void ReaderManager::editreader(int subscript, string name)
{
	rdarr[subscript].setname(name);
}
void ReaderManager::editreader(int subscript, int code)
{
	rdarr[subscript].setcode(code);
}
void ReaderManager::editreader(int subscript, Book book)
{
	rdarr[subscript].setbrbook(book);
}
void ReaderManager::editreader(int subscript, bool Is_Borrowing)
{
	rdarr[subscript].set_Borrowing(Is_Borrowing);
}

//delete readers
void ReaderManager::delreader(int subscript)
{
	rdarr[subscript].set_Existing(false);
}

//list all the readers
void ReaderManager::listreaders()
{
	cout << "所有的读者为" << endl;
	for (int i = 0; i < rdarr.size(); i++)
	{
		if (rdarr[i].get_Existing()) rdarr[i].show();
	}
}

//save: use outfile stream
void ReaderManager::save(string filename)
{
	ofstream outfile(filename.c_str(), ios::binary);
	if (!outfile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	int rdsize = rdarr.size();
	outfile.write((char*)(&rdsize), sizeof(rdsize));

	for (int i = 0; i < rdsize; i++)
		outfile.write((char*)(&rdarr[i]), sizeof(Reader));
	outfile.close();
}

//load: use infile stream
void ReaderManager::load(string filename)
{
	ifstream infile(filename.c_str(), ios::binary);
	if (!infile.is_open())
	{
		cout << "Error opening file";
		return;
	}
	rdarr.clear();
	int rdsize;
	infile.read((char*)(&rdsize), sizeof(rdsize));
	rdarr.reserve(rdsize * 2);
	Reader * readerarray = new Reader[rdsize];
	
	for (int i = 0; i < rdsize; i++)
	{
		infile.read((char*)(&readerarray[i]), sizeof(Reader));
		rdarr.push_back(readerarray[i]);
	}
	infile.close();
}
