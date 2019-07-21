#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//Cau 11.1
struct node{
	int info;
	node *link;
};
node *front, *rear;
//Cau 11.2
void init()
{
	front = NULL;
	rear = NULL;
}

//Cau 11.3
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}

//Cau 11.4
void push(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if(rear ==NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

//Cau 11.5
int pop(int &x)
{
	if(front != NULL)
	{
		node *p = front;
		front = p->link;
		x= p->info;
		if(front ==NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Xuat QUEUE
void process_queue()
{
	if(front != NULL)
	{
		node *p = front;
		cout<<"<--		";
		do{
			cout<<p->info<<"		";
			p = p->link;
		}while(p!= NULL);
		cout<<"<--"<<endl;
	}
}
int main()
{
	int choice = 0, i, x;
	system("cls");
	cout<<"-------------BAI TAP CHUONG 2, BAI 11------------"<<endl;
	cout<<"1. Khoi tao queue rong"<<endl;
	cout<<"2. Them phan tu vao queue"<<endl;
	cout<<"3. Lay phan tu ra khoi queue"<<endl;
	cout<<"4. Kiem tra queue co rong khong"<<endl;
	cout<<"5. Xuat queue"<<endl;
	cout<<"6. Thoat"<<endl;
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
			push( x);
			cout<<"Queue sau khi them la: ";
			process_queue();
			break;
		case 3:
			i = pop(x);
			if(i = 1)
			{
				cout<<"Queue sau khi lay ra la: ";
				process_queue();
			}
			else
				cout<<"Khong the lay ra!!!"<<endl;
			break;
		case 4:
			i = isEmpty();
			if(i == 0)
				cout<<"QUEUE khong rong!"<<endl;
			else
				cout<<"QUEUE rong"<<endl;
			break;
		case 5:
			cout<<"QUEUE hien tai la: ";
			process_queue();
			break;
		case 6:
				cout<<"GOOD BYE ...!!!"<<endl;
				break;
		default:
			break;
		}
	}while(choice !=6);
	system("pause");
	return 0;
}