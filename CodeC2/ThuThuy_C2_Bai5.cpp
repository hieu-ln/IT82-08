#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//Cau 5.2
void init(int a[], int &sp)
{
	sp = -1;
}

//Cau 5.3
int isEmpty(int a[], int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}

//Cau 5.4
int isFull(int a[], int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}

//Cau 5.5
int push(int a[], int&sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//Cau 5.6
int pop(int a[], int& sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//Xuat danh sach
void process_stack(int a[], int sp)
{
	for(int i = 0; i<sp + 1; i++)
	{
		cout<<a[i]<<"	";
	}
	cout<<endl;
}
int main()
{
	int choice = 0;
	int x, i, a[MAX], sp;
	system("cls");
	cout<<"-------------BAI TAP CHUONG 2, BAI 5------------"<<endl;
	cout<<"1. Khoi tao stack rong"<<endl;
	cout<<"2. Them phan tu vao stack"<<endl;
	cout<<"3. Lay phan tu ra khoi stack"<<endl;
	cout<<"4. Kiem tra stack co rong khong"<<endl;
	cout<<"5. Kiem tra stack co day khong"<<endl;
	cout<<"6. Xuat stack"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"Chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout<<"Khoi tao danh stack thanh cong"<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri x: ";
			cin>>x;
			i = push(a, sp, x);
			cout<<"Stack sau khi them la: ";
			process_stack(a, sp);
			break;
		case 3:
			i = pop(a, sp, x);
			cout<<"Stack sau khi lay ra la: ";
			process_stack(a, sp);
			break;
		case 4:
			i = isFull(a, sp);
			if(i == 0)
				cout<<"STACK chua day!"<<endl;
			else
				cout<<"STACK day"<<endl;
			break;
		case 5:
			i = isEmpty(a, sp);
			if(i == 0)
				cout<<"STACK khong rong!"<<endl;
			else
				cout<<"STACK rong"<<endl;
			break;
		case 6:
			cout<<"STACK hien tai la: ";
			process_stack(a, sp);
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