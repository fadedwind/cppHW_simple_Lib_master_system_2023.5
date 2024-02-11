#include "setting.h"
#include <iostream>
using namespace std;
int main()
{	
	BookManager bookManager;ReaderManager readerManager;
	// show the main windoe of the system
	cout << "~~~欢迎使用图书馆管理系统~~~" << endl;
	bool flag = true;
	while (flag)
	{	
		cout << endl;
		cout << "请输入序号以进行对应操作" << endl;
		cout << "1.借书" << endl;
		cout << "2.还书" << endl;
		cout << "3.图书管理:(增加/删除/更改/查找/显示图书)" << endl;
		cout << "4.读者管理:(增加/删除/更改/查找/显示读者)" << endl;
		cout << "5.文件存储或文件读取" << endl;
		cout << "其他退出" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "请输入指令" << endl;
		int command;cin >> command;
		//use switch...case to achieve the structure
		switch (command)
		{
		case 1:landbook();break;
		case 2:returnbook();break;
		case 3:bookmanage();break;
		case 4:readermanage();break;
		case 5:filemanage();break;
		default:flag = false;// use default command to end the while loop
		}
	}
	return 0;
}