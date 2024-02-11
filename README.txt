Functional design ideas---

1. Borrow book function

Realize the requirement to enter the reader's name and book title when borrowing a book, and modify and store the borrowing information. Readers and books should have corresponding status flags to distinguish the status of the book and the status of readers.

2. Return the book function

When returning the book, the reader name and book title are required to be entered for modification and storage. Readers should also modify the corresponding status after changing books.

3. Library management function

Implement the basic operations of book maintenance, including adding, changing, deleting, finding, and displaying books.

4. User management function

Implement basic operations for reader maintenance, including adding, changing, deleting, finding, and displaying readers.

5. File storage function

Store book information, reader information, and administrator information by default or specified name; Update the content of maintenance information.

Functional Architecture ---

1. Borrow a book
2. Return the book function
3. Book management
    1. Add books
    2. Delete books
    3. Edit books
    4. Find books
    5. Display books
4. Reader Management
    1. Increase readership
    2. Delete readers
    3. Edit readers
    4. Find readers
    5. Display readers
5. File management
    1. File storage
    2. File reading


Class build:

1.User

private:
    int code;           	 
    string name;                
public:
    User();                     
    User(int id, string na); 
    void setcode(int n);         
    int getcode();               
    void setname(string na);     
    string  getname();           
    void show();                 


2.Reader 

private:
    bool Is_Existing;           
    bool Is_Borrowing;         
    Book brbook;               
public:
    Reader();                  
    Reader(int id, string na);
    bool get_Existing();        
    void set_Existing(bool);    
    bool get_Borrowing();       
    void set_Borrowing(bool);   
    void setbrbook(Book bt);    
    Book getbrbook();           
    void show();                


3.Book

private:
    int code;                 
    string name;            	
    bool Is_Stock;          	
    bool Is_Existing;       	
public:
    Book();               
    Book(int no,string na); 
    void setcode(int n);    	
    int getcode();          	
    void setname(string na);
    string getname();      
    bool  get_Stock();        
    void set_Stock(bool);     
    bool  get_Existing();     
    void set_Existing(bool);  


4.BookManager

private:
	vector <Book> bkarr;  				
public:
	BookManager();
	~BookManager();
	void addbook(Book book);    			
	int findbook(string name);  			  
	int findbook(int code);  			 
	CBook getbook(int subscript);
	void editbook(int subscript, Book book);    
	void editbook(int subscript, int code);     
	void editbook(int subscript, string name);  
	void editbook(int subscript, bool Is_Stock);
	void delbook(int subscript);   		 
	void listbooks();  				 
	void save(string filename = "books.db");    
	void load(string filename = "books.db");   


5.ReaderManager

private:
	vector <Reader> rdarr;//  洢      Ϣ
public:
	ReaderManager();
	~ReaderManager();
	Reader getreader(int subscript);
	void addreader(Reader reader);          			
	int findreader(string name); 					
	int findreader(int code); 					
	int findreader(Book book); 					
	void editreader(int subscript, Reader reader);  	
	void editreader(int subscript, string name);      	
	void editreader(int subscript, int code);        	
	void editreader(int subscript, Book book);      	
	void editreader(int subscript, bool Is_Borrowing); 	
	void delreader(int subscript);          			
	void listreaders();           				
	void save(string filename = "readers.db"); 		
	void load(string filename = "readers.db"); 		
