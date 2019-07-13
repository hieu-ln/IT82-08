//Chuong 2 - Bai 1 : Danh sach dac
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//cau 1.1
int a[MAX];
int n;

//Cau 1.2
void input(int a[], int &n)
{
	cout <<"Nhap vao so luong phan tu cua danh sach: ";
	cin >>n;
	cout <<"Nhap vao cac phan tu cua danh sach: " <<endl;
	for (int i = 0; i<n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

//cau 1.3
void output(int a[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

}

//cau 1.4 Tim phan tu trong mot phan tu trong danh sach
int search(int a[], int n, int x)
{
	int i = 0;
	while (i<n && a[i]!=x)
	{
		i++;
		if (i == n)
			return -1;
	}
	return i;
}

//cau 1.5 chen mot phan tu vao cuoi danh sach
int insert_last(int a[], int &n, int x)
{
	if(n<MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}

//cau 1.6 xoa 1 phan tu cuoi danh sach
int Delete_last(int a[], int &n)
{
	if (n>0)
	{
		n--;
		return 1;
	}
	return 0;
}

//cau 1.7 xoa 1 phan tu tai vi tri thu i
int Delete(int a[], int &n, int i)
{
	if (i >= 0 && i<n)
	{
		for (int j=i; j<n-1; j++)
		{
			a[j] = a[j+1];
		}
		n--;
		return 1;
	}
	return 0;
}

//cau 1.8 tim 1 phan tu trong danh sach va xoa phtu do
int SearchAndDelete(int a[], int &n, int x)
{
	for (int i=0; i<n; i++)
	{
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}

//main
int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout<<"				BTH So 1 _ Chuong 2 _ Danh sach dac				" << endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Tim phan tu co gia tri x trong danh sach"<<endl;
	cout<<"4. Them phan tu vao cuoi danh sach"<<endl;
	cout<<"5. Xoa phan tu vao cuoi danh sach"<<endl;
	cout<<"6. Xoa phan tu tai vi tri i"<<endl;
	cout<<"7. Tim phan tu voi gia tri x va xoa no neu co"<<endl;
	cout<<"8. Thoat"<<endl;

	do
	{
		cout <<"Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(a, n);
			cout <<"Ban vua nhap danh sach thanh cong! \n";
			break;
		case 2:
			cout <<"danh sach da nhap la: \n";
			output(a, n);
			break;
		case 3:
			cout <<"Vui long nhap x can tim: ";
			cin >> x;
			i = search(a, n, x);
			if(i == -1)
				cout <<"Tim khong thay phan tu co gia tri x" << x << endl;
			else
				cout <<"Tim thay tai vi tri i= " << i << endl;
			break;
		case 4:
			cout <<"Vui long nhap x can them vao cuoi dsach: ";
			cin >> x;
			i = insert_last(a, n, x);
			if (i == 0)
				cout <<"Danh sach da day, khong the them" << x << endl;
			else
				cout <<"Danh sach sau khi them vao phan tu x = \n";
				output(a,n);
			break;
		case 5:
			i = Delete_last(a, n);
			if(i>0)
			{
				cout << "Xoa thanh cong!" << endl;
				cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
				output(a, n);
			}
			else
				cout << "Danh sach rong khong co phan tu nao! " << endl;
			break;
		case 6:
			cout << "Vui long nhap vi tri can xoa, i= "; 
			cin >> i;
			i = Delete(a, n, i);
			if(i==1)
			{
				cout << "Xoa thanh cong!"<<endl;
				cout << "Danh sach sau khi xoa la: \n";
				output(a, n);
			}
			else 
				cout << "Khong co phan tu nao de xoa" << endl;
			break;
		case 7:
			cout << "Vui long nhap gia tri can xoa, x= ";
			cin >> x;
			i = SearchAndDelete(a, n, x);
			if (i==1)
			{
				cout << "Xoa thanh cong phan tu co gia tri x= " << x << endl;
				cout << "Danh sach sau khi xoa la: \n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa!";
			break;
		case 8:
			cout << "Goodbye!";
			break;
		default:
			break;
		}
	}
	while (choice != 8);
	system("pause");
	return 0;
}