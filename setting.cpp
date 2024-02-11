//to define the functions throughout the main running process
#include "setting.h"

#include <iostream>
using namespace std;

BookManager bookManager;
ReaderManager readerManager;

// system land book
int landbook()
{
	string readerName, bookName;
	int readerSubscript, bookSubscript;

	cout << "请输入读者名称" << endl;
	cin >> readerName;
	readerSubscript = readerManager.findreader(readerName);//Check to see if the reader exists
	if (readerSubscript == -1)
	{
		cout << "读者不存在" << endl;
		return 0;
	}

	cout << "请输入书籍名称" << endl;
	cin >> bookName;
	bookSubscript = bookManager.findbook(bookName);//Check to see if the book exists
	if (bookSubscript == -1)
	{
		cout << "书籍不存在" << endl;
		return 0;
	}
	else if (bookSubscript == -2)
	{
		cout << "书籍已借出" << endl;
		return 0;
	}
	//edit borrowing status information for books and readers
	bookManager.editbook(bookSubscript, false);
	readerManager.editreader(readerSubscript, bookManager.getbook(bookSubscript));
	readerManager.editreader(readerSubscript, true);
	cout << "借书成功" << endl;
	return 0;
}

//return book
int returnbook()
{	
	int readerSubscript, bookSubscript;

	cout << "请输入读者名称" << endl;
	string readername;
	cin >> readername;
	readerSubscript = readerManager.findreader(readername);//Check to see if the reader exists
	if (readerSubscript == -1)
	{
		cout << "读者不存在" << endl;
		return 0;
	}
	Reader reader = readerManager.getreader(readerSubscript);
	Book book = reader.getbrbook();
	bookSubscript = bookManager.findbook(book.getname());//Check to see if the book exists
	if (bookSubscript == -1)
	{
		cout << "书并不是本馆的" << endl;
		return 0;
	}
	//edit borrowing status information for books and readers
	bookManager.editbook(bookSubscript, true);
	readerManager.editreader(readerSubscript, false);
	cout << "还书成功" << endl;
	return 0;
}

//book management

//create a new book data
int bookcreate() 
{ 
	Book book;
	int code;
	string name;
	cout << "请输入书号" << endl;
	cin >> code;
	cout << "请输入书名" << endl;
	cin >> name;
	book.setcode(code);
	book.setname(name);
	bookManager.addbook(book);
	cout << "添加成功" << endl;
	return 0; 
}

//delete books
int bookdelete() 
{ 
	cout << "请输入书名" << endl;
	string bookname;
	cin >> bookname;
	int booksubscript = bookManager.findbook(bookname);
	if (booksubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	bookManager.delbook(booksubscript);
	cout << "删除成功" << endl;
	return 0;
}

//edit book info
int bookedit() 
{ 
	cout << "请输入书名" << endl;
	string bookname;
	cin >> bookname;
	int booksubscript = bookManager.findbook(bookname);
	if (booksubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	int newbookcode;
	string newbookname;
	cout << "请输入新书名" << endl;
	cin >> newbookname;
	bookManager.editbook(booksubscript, newbookname);
	cout << "请输入新书号" << endl;
	cin >> newbookcode;
	bookManager.editbook(booksubscript, newbookcode);
	cout << "更改成功" << endl;
	return 0;
}

//find book
int bookfind() 
{ 
	cout << "1.按书名查找" << endl << "2.按书号查找" << "其他退出" << endl;
	int command;
	cin >> command;
	int booksubscript=-1;
	if (command == 1)
	{
		cout << "请输入书名" << endl;
		string bookname;
		cin >> bookname;
		booksubscript = bookManager.findbook(bookname);
	}
	else if (command == 2)
	{
		cout << "请输入书号" << endl;
		int bookcode;
		cin >> bookcode;
		booksubscript = bookManager.findbook(bookcode);
	}
	else
	{
		return 0;
	}
	if (booksubscript == -1)
	{
		cout << "没有这本书" << endl;
		return 0;
	}
	Book book = bookManager.getbook(booksubscript);
	book.show();
	return 0; 
}

//show all the book information
int booklist()
{
	bookManager.listbooks();
	return 0;
}

//book management menu
int bookmanage()
{	
	cout << endl;
	cout << "1.增加图书" << endl;
	cout << "2.删除图书" << endl;
	cout << "3.更改图书" << endl;
	cout << "4.查找图书" << endl;
	cout << "5.显示图书" << endl;
	int command;
	cout << "请输入指令" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		bookcreate();
		break;
	case 2:
		bookdelete();
		break;
	case 3:
		bookedit();
		break;
	case 4:
		bookfind();
		break;
	case 5:
		booklist();
	default:
		return 0;
	}
	return 0;
}


//reader management--

//add readers
int readercreate() 
{
	int code;
	string name;
	Reader reader;
	cout << "请输入编号" << endl;
	cin >> code;
	cout << "请输入姓名" << endl;
	cin >> name;
	reader.setcode(code);
	reader.setname(name);
	readerManager.addreader(reader);
	cout << "添加成功" << endl;
	return 0;
}

//delete readers
int readerdelete() 
{ 
	cout << "请输入读者姓名" << endl;
	string readername;
	cin >> readername;
	int  readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "没有这位读者" << endl;
		return 0;
	}
	readerManager.delreader(readersubscript);
	cout << "删除成功" << endl;
	return 0;
}

//edit reader information
int readeredit() 
{ 
	cout << "请输入读者姓名" << endl;
	string readername;
	cin >> readername;
	int readersubscript = readerManager.findreader(readername);
	if (readersubscript == -1)
	{
		cout << "没有这位读者" << endl;
		return 0;
	}
	int newreadercode;
	string newreadername;
	cout << "请输入新读者姓名" << endl;
	cin >> newreadername;
	readerManager.editreader(readersubscript, newreadername);
	cout << "请输入新读者编号" << endl;
	cin >> newreadercode;
	readerManager.editreader(readersubscript, newreadercode);
	cout << "更改成功" << endl;
	return 0;
}

//find reader information
int readerfind()
{ 
	cout << "1.按读者姓名查找" << endl << "2.按读者编号查找" << "其他退出" << endl;
	int command;
	cin >> command;
	int readersubscript = -1;
	if (command == 1)
	{
		cout << "请输入读者姓名" << endl;
		string readername;
		cin >> readername;
		readersubscript = readerManager.findreader(readername);
	}
	else if (command == 2)
	{
		cout << "请输入读者编号" << endl;
		int readercode;
		cin >> readercode;
		readersubscript = readerManager.findreader(readercode);
	}
	else
	{
		return 0;
	}
	if (readersubscript == -1)
	{
		cout << "没有这位读者" << endl;
		return 0;
	}
	Reader reader = readerManager.getreader(readersubscript);
	reader.show();
	return 0;
}

//show information of all the readers
int readerlist()
{
	readerManager.listreaders();
	return 0;
}

//reader management menu
int readermanage()
{	
	cout << endl;
	cout << "1.增加读者" << endl;
	cout << "2.删除读者" << endl;
	cout << "3.更改读者" << endl;
	cout << "4.查找读者" << endl;
	cout << "5.显示读者" << endl;
	int command;
	cout << "请输入指令" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		readercreate();
		break;
	case 2:
		readerdelete();
		break;
	case 3:
		readeredit();
		break;
	case 4:
		readerfind();
	case 5:
		readerlist();
		break;
	default:
		return 0;
	}
	return 0;
}

// save and load
int filemanage()
{	
	cout << "请输入指令" << endl;
	cout << "1.文件存储" << endl << "2.文件读取" << endl;
	int command;
	cin >> command;
	if (command == 1)
	{
		readerManager.save();
		bookManager.save();
		cout << "已成功存储" << endl;
		return 0;
	}
	else if (command == 2)
	{
		readerManager.load();
		bookManager.load();
		cout << "文件已读取" << endl;
		bookManager.listbooks();
		cout << endl;
		readerManager.listreaders();
		cout << endl;
		return 0;
	}
	else
	{
		cout << "文件未操作" << endl;
		return 1;
	}
	return 0;
}
