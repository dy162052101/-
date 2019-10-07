#include<string>
using namespace std;
struct Node
{
	string book_number;
	string book_name;
	string book_author;
	string publication_time;
	Node *next;
	Node(string number,string name,string p,string t,Node *n=NULL)
	{
		book_number=number;
		book_name=name;
		book_author=p;
		publication_time=t;
		next=n;
	}
	Node(Node *p=NULL)
	{
		next=p;
	}
};
class BOOK
{
private:
	Node *head;
	Node *tail;
	int length;
public:
	void Init();
	int creat();
	int insert(int n,string number,string name,string people,string time);
	int delete_book(string number);
	int find(string number);
	int change(string number);
	bool isrepeat(string number);
	bool isempty();
	int show();
	
};