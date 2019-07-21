#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//Cau 10.1
struct node{
	int info;
	node *link;
};
node *sp;
//Cau 10.2
void init()
{
	sp = NULL;
}

//Cau 10.3
int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}

//Cau 10.4
void push(int x)
{
	node *p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//Cau 10.5
int pop(int &x)
{
	if(sp != NULL)
	{
		node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//Xuat QUEUE
void process_stack()
{
	node *p = sp;
	do{
		cout<<p->info<<"	";
		p = p->link;
	}while(p!= NULL);
	cout<<endl;
}
int main()
{
	int choice = 0;
	int x;
	system("cls");
	cout<<"-------------BAI TAP CHUONG 2, BAI 10------------"<<endl;
	cout<<"1. Khoi tao stack rong"<<endl;
	cout<<"2. Them phan tu vao stack"<<endl;
	cout<<"3. Lay phan tu ra khoi stack"<<endl;
	cout<<"4. Xuat stack"<<endl;
	cout<<"5. Thoat"<<endl;
	do
	{
		cout<<"Chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Khoi tao queue rong thanh cong"<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri x: ";
			cin>>x;
			push(x);
			cout<<"STACK sau khi them la: ";
			process_stack();
			break;
		case 3:
			pop(x);
			cout<<"STACK sau khi lay ra la: ";
			process_stack();
			break;
		case 4:
			cout<<"STACK hien tai la: ";
			process_stack();
			break;
		case 5:
				cout<<"GOOD BYE ...!!!"<<endl;
				break;
		default:
			break;
		}
	}while(choice !=5);
	system("pause");
	return 0;
}