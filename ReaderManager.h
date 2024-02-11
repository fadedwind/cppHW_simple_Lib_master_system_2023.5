#ifndef READERMANAGER_H 
#define READERMANAGER_H // avoid redef
#include "Reader.h"
#include <vector>//replace the array with vector, convinient
#include <string>//string base used
using namespace std;
class ReaderManager
{
	private:
		vector <Reader> rdarr;//eplace the array with vector, convinient
	public:
		ReaderManager() {};									//onstructor
		~ReaderManager() {};								//deconstructor

		Reader getreader(int subscript);

		void addreader(Reader reader);         				//add readers
		int findreader(string name); 						//find readers
		int findreader(int code); 							//find readers
		int findreader(Book book); 							//find readers
		
		void editreader(int subscript, Reader reader);  	//edit readers
		void editreader(int subscript, string name); 		//edit readers
		void editreader(int subscript, int code); 			//edit readers
		void editreader(int subscript, Book book); 			//edit readers
		void editreader(int subscript, bool Is_Borrowing);	//edit readers
		void delreader(int subscript);  

		void listreaders(); 								//show readers
		//save and load       
		void save(string filename = "readers.db"); 
		void load(string filename = "readers.db"); 
};

#endif //READERMANAGER_H