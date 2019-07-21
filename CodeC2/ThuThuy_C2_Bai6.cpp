//Chuong 2, Bai 6 : SU DUNG STACK DA XAY DUNG, DOI CO SO TU HE THAP PHAN SANG HE NHI PHAN
#include <stdio.h>
#include <iostream>
using namespace std;

//Khai bao cau truc STACK
struct Node
{
	int info;
	Node *link;
};
Node *sp;

//Khoi tao danh sach rong
void Init()
{
	sp = NULL;
}


//Kiem tra STACK rong
int isEmpty()
{
	if (sp==NULL)
		return 1;
	return 0;
}

//Them phan tu vao STACK
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//Lay phan tu ra khoi STACK
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//Ham doi co so tu he thap phan sang he 2
void Fr10To2 (int a)
{

	while ( a != 0)
	{
		int x = a % 2;
		Push(x); 
		a /= 2;
	}

}

//Xuat STACK
void Process_stack()
{
	Node *p;
	p = sp;
	do
	{	cout << p -> info;
		p = p -> link;
	}while (p!= NULL);
	cout << endl;
}

int main()
{
	int choice, x;
	system("cls");
	cout << " -------- BAI TAP 6, CHUONG 2--------" << endl;
	cout << "1. Khoi tao STACK rong" << endl;
	cout << "2. Chuyen doi co so tu he thap phan sang he nhi phan" << endl;
	cout << "3. Xuat STACK" << endl;
	cout << "4. Thoat" << endl;

	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Init();
				cout << "Ban vua khoi tao Stack rong thanh cong \n";
				break;

			case 2:
				int a;
				cout << "\nNhap gia tri he Thap phan can chuyen sang he nhi phan: ";
				cin >> a;
				Fr10To2(a);
				
				cout << "He Thap phan = "<< a << " -> He nhi phan = ";

				Process_stack();
				break;

			case 3:
				cout << "STACK hien tai la: "<< endl;
				Pop(x);
				break;

			case 4:
				cout << "GOODBYE ......!"<< endl;
				break;

			default:
				break;
		}
	}while (choice != 4);
	system ("pause");
	return 0;
}
