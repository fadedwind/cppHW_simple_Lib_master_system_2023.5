//declare the functions throughout the main running process of the program
//do the muti-file compile: ties all the head files together
#ifndef SETTING_H 
#define SETTING_H // avoid redef
#include "Reader.h"
#include "Book.h"
#include "User.h"
#include "BookManager.h"
#include "ReaderManager.h"
//system, land book
int landbook();
//return book
int returnbook();
// book management
int bookcreate();
int bookdelete();
int bookedit();
int bookfind();
int booklist();
int bookmanage();
// reader management
int readercreate();
int readerdelete();
int readeredit();
int readerfind();
int readerlist();
int readermanage();
// file save and load
int filemanage();
#endif //SETTING_H

