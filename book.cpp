#include"Book.h"
#include<iostream>
using namespace std;
void BOOK::Init()
{
	head=tail=new Node();
	length=0;
}
int BOOK::creat()
{
	Node *p;
	int n,f=0;
	string time;
	string name,people,number;
	cout<<"input the book of number:";
	cin>>n;
	while(f<n)
	{
		cout<<"input the number,name,people,time(example:2019/3/3): "<<endl;
		cin>>number>>name>>people>>time;
		if(isrepeat(number)==false)
		{
			p=new Node(number,name,people,time,NULL);
			tail->next=p;
			tail=p;
			length++;
			f++;
		}
		else
			cout<<"error! repeat input:"<<endl;
	}
	
	return 0;
}
int BOOK::insert(int n,string number,string name,string people,string time)
{
	int f=0;
	Node*p1=head;
	Node *p2;
	if(n<0||n>length)
	{
		cout<<"Error!!!"<<endl;
		return 0;
	}
	while(f<n)
	{
		p1=p1->next;
		f++;
	}
	p2=new Node(number,name,people,time,p1->next);
	if(p1==tail)tail=p2;
	p1->next=p2;
	length++;
	return 1;
}
int BOOK::delete_book(string number)
{
	Node*p=head->next;
	Node*q=head;
	int flag=0;
	while(p!=NULL)
	{
		if(p->book_number==number)
		{
			flag=1;
			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==1)
	{
		q->next=p->next;
		length--;
		cout<<"delet succeed!"<<endl;
	}else
	{
		cout<<"no qnmd!"<<endl;
	}
	return 0;

}
int BOOK::find(string number)
{
	Node *p=head->next;
	int flag=0;
	while(p!=NULL)
	{
		if(p->book_number==number)
		{
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==1)
		cout<<"result:"<<p->book_number<<" "<<p->book_name<<" "<<p->book_author<<" "<<p->publication_time<<" "<<endl;
	else
		cout<<"no!qnmd!"<<endl;
	return 0;

}
int BOOK::change(string number)
{
	Node *p=head->next;
	int flag=0;
	while(p!=NULL)
	{
		if(p->book_number==number)
		{
			flag=1;
			cout<<flag<<endl;
			break;
		}
		p=p->next;
	}
	string time;
	string name1,people,number1;
	cout<<"input number name people time: "<<endl;
	while(1)
	{
		cin>>number1>>name1>>people>>time;
		if(isrepeat(number1)==false&&flag==1)
		{
			cout<<flag<<endl;
			p->book_number=number1;
			p->book_name=name1;
			p->book_author=people;
			p->publication_time=time;
			break;
		}
		else
		{
			cout<<"error!"<<endl;
		}
	}
	return 0;
}
int BOOK::show()
{
	Node *p=head->next;
	while(p!=NULL)
	{
		cout<<p->book_number<<" "<<p->book_name<<" "<<p->book_author<<" "<<p->publication_time<<endl;
		p=p->next;
	}
	return 0;
}
bool BOOK::isrepeat(string number)
{
	int flag=0;
	Node *p=head->next;
	if(p==NULL)
	{
		return false;
	}
	while(p!=NULL)
	{
		if(p->book_number==number)
		{
			flag++;
			break;
		}
		p=p->next;
	}
	if(flag>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BOOK::isempty()
{
	if(head==tail)
		return true;
	else
		return false;
}