#include<iostream>
#include<string>
#include<conio.h>
#include"Book.h"
using namespace std;
int main()
{
	BOOK book;
	book.Init();
	cout<<"Initail succeed!"<<endl;
	system("cls");
	if(book.isempty()==true)
	{
		cout<<"the libiary is empty, please input book message!"<<endl;
		book.creat();
		cout<<"succeed!!"<<endl;
		system("cls");
	}

	while(1)
	{
		cout<<"输入选项前边的序号："<<endl;
		cout<<"    =================Menu_Book===============||"<<endl;
		cout<<"    || 1             add_book                ||"<<endl;
		cout<<"    || 2           delete_book               ||"<<endl;
		cout<<"    || 3            find_book                ||"<<endl;
		cout<<"    || 4           modify_book               ||"<<endl;
		cout<<"    || 5              show                   ||"<<endl;
		cout<<"    || 6              exit                   ||"<<endl;
		cout<<"    ||========================================="<<endl;

		int i;
		cin>>i;
		switch(i)
		{
			case 1:
				{
					string number,name,people,time;
					int n;
					while(1)
					{
						cout<<"input insert_number,book_number,book_name,book_author,publication_time:"<<endl;
						cin>>n>>number>>name>>people>>time;
						if(book.isrepeat(number)==false)
						{
							book.insert(n,number,name,people,time);
							cout<<"insert succeed!"<<endl;
							break;
						}
						else
						{
							cout<<"repeat input:"<<endl;
						}
					}
					system("pause");
					system("cls");
				}break;
			case 2:
				{
					string number_1;
					cout<<"input the number of book for deleting:"<<endl;
					cin>>number_1;
					book.delete_book(number_1);
					system("pause");
					system("cls");
				}break;
			case 3:
				{
					string number_2;
					cout<<"input the number of book for finding:"<<endl;
					cin>>number_2;
					book.find(number_2);
					system("pause");
					system("cls");
				}break;
			case 4:
				{
					string number_3;
					cout<<"input the number of book for modifying"<<endl;
					
					cin>>number_3;
					book.change(number_3);
					system("pause");
					system("cls");
				}break;
			case 5:
				{
					book.show();
					system("pause");
					system("cls");
				}break;
			case 6:
				{
					system("pause");
					system("cls");
				}break;
			default:
				{
					system("pause");
					system("cls");
				}break;
		}
		if(i==6)
			break;
		cin.clear();
		cin.get();
	}
	return 0;

}