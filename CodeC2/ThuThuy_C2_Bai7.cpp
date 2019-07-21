#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//Cau 7.2
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

//Cau 7.3
int isEmpty(int a[], int &front, int &rear)
{
	if(front == rear)
		return 1;
	return 0;
}

//Cau 7.4
int isFull(int a[], int& front, int& rear)
{
	if((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	else
		return 0;
}

//Cau 7.5
int push(int a[], int& front, int& rear, int x)
{
	if(rear - front == MAX -1)
	{
		return 0;
	}
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX - 1)
		{
			for(int i = front; i<= rear; i++)
				a[i-front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}

//Cau 7.6
int pop(int a[], int& front, int &rear, int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x = a[front ++];
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}

//Xuat QUEUE
void process_queue(int a[], int f, int r)
{
	cout<<"a= "<<f<<"	r= "<<r<<endl;
	if(f<=r && f!= -1)
	{
		cout<<"<--	 ";
		for(int i = f; i<r + 1; i++)
		{
			cout<<a[i]<<"	";
		}
		cout<<"<--"<<endl;
	}
}
int main()
{
	int choice = 0;
	int x, i, a[MAX], f, r;
	system("cls");
	cout<<"-------------BAI TAP CHUONG 2, BAI 7------------"<<endl;
	cout<<"1. Khoi tao queue rong"<<endl;
	cout<<"2. Them phan tu vao queue"<<endl;
	cout<<"3. Lay phan tu ra khoi queue"<<endl;
	cout<<"4. Kiem tra queue co rong khong"<<endl;
	cout<<"5. Kiem tra queue co day khong"<<endl;
	cout<<"6. Xuat queue"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"Chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init(a, f, r);
			cout<<"Khoi tao queue rong thanh cong"<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri x: ";
			cin>>x;
			i = push(a, f, r, x);
			cout<<"Queue sau khi them la: ";
			process_queue(a, f, r);
			break;
		case 3:
			i = pop(a, f, r, x);
			cout<<"Queue sau khi lay ra la: ";
			process_queue(a, f, r);
			break;
		case 4:
			i = isFull(a, f, r);
			if(i == 0)
				cout<<"QUEUE chua day!"<<endl;
			else
				cout<<"QUEUE day"<<endl;
			break;
		case 5:
			i = isEmpty(a, f, r);
			if(i == 0)
				cout<<"QUEUE khong rong!"<<endl;
			else
				cout<<"QUEUE rong"<<endl;
			break;
		case 6:
			cout<<"QUEUE hien tai la: ";
			process_queue(a, f, r);
			break;
		case 7:
				cout<<"GOOD BYE ...!!!"<<endl;
				break;
		default:
			break;
		}
	}while(choice !=7);
	system("pause");
	return 0;
}