#ifndef USER_H 
#define USER_H // avoid redef

//set the user info

#include <string>
using namespace std;

class User
{
	protected:
		int code;      				//user code
		string name;				//user name

	public:
		User();   					//constructor
		User(int id, string na);    //constructor and initialization

		void setcode(int n);        //set user code
		int getcode();              //get user code
		void setname(string na);    //set user name
		string  getname();          //get user name

		void show();                //show info of the user
};

#endif //USER_H