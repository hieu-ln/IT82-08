//Chuong 2, Bai 15: DANH SACH DAC
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
//Cau 1.1
int a[MAX], b[MAX], c[MAX], d[MAX], d2[MAX];
int n, m, count;

//Nhap vao danh sach
void input (int a[], int &n, char tenmang)
{
	cout << "So luong phan tu cua danh sach "<<tenmang<<": ";
	cin >> n;
	cout << "Cac phan tu cua danh sach I: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout <<tenmang<< "[" << i << "] = ";
		cin >> a[i];
	}
}

//Xuat danh sach
void output (int a[], int &n, char tenmang)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

}

//Chen phan tu vao cuoi ds
int insert (int c[], int &n, int x)
{
	if(n < MAX)
	{
		c[n] = x;
		n++;
		return 1;
	}
	else
		return 0;		
}

//Ham giao
void giao (int a[], int b[])
{
	count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i] == b[j])
					insert (c, count, a[i]);

	//xuat tap hop
	cout << "Cac phan tu thuoc tap hop giao cua 2 danh sach: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << c[i] << "\t";
	}
	cout << endl;
}

//Ham bu

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

void bu(int a[], int b[])
{
	int countd = 0;
	//truyen lan luot cac phan tu cua mang a, b cho mang d
	for (int i=0; i<n; i++)
		insert(d, countd, a[i]);
	for (int i=0; i<m; i++)
		insert(d, countd, b[i]);

		//xuat danh sach mang d 
	cout << "Cac phan tu thuoc mang d sau khi truyen vao cac phan tu tu danh sach a, b: " << endl;
	for (int i = 0; i < countd; i++)
	{
		cout << d[i] << "\t";
	}
	cout << endl;

	//duyet va xoa nhung phan tu trung nhau trong mang d 
	for (int i=0; i<countd-1; i++)
		for(int j=i+1; j<countd; j++)
			if (d[i] == d[j])
				Delete(d, countd, j);
	
	cout << "Cac phan tu thuoc mang d sau khi xoa cac phan tu trung nhau: " << endl;
	for (int i = 0; i < countd; i++)
	{
		cout << d[i] << "\t";
	}
	cout << endl;
	

	//duyet va xoa nhung phan tu trong mang d trung voi nhung phan tu trong mang c (mang c la tap hop giao cua a, b)
	for (int i=0; i<count; i++)
		for (int j=0; j< countd; j++)
		{
			if (c[i] == d[j])
				Delete(d, countd, j);
		}
	//xuat tap hop
	cout << "Cac phan tu thuoc tap hop bu cua 2 danh sach: " << endl;
	for (int i = 0; i < countd; i++)
	{
		cout << d[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int choice = 0;
	system("cls");
	cout << " -------- BAI TAP 1, CHUONG 2, DANH SACH DAC --------" << endl;
	cout << "1. Nhap danh sach I" << endl;
	cout << "2. Xuat danh sach I" << endl;
	cout << "3. Nhap danh sach II" << endl;
	cout << "4. Xuat danh sach II" << endl;
	cout << "5. Xuat ca 2 danh sach" << endl;
	cout << "6. Xuat tap hop giao cua 2 danh sach" << endl;
	cout << "7. Xuat tap hop phan bu cua 2 danh sach" << endl;
	cout << "8. Thoat" << endl;

	do
	{
		cout << "Chon: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				input (a, n, 'A');
				cout << "Danh sach I da duoc nhap thanh cong \n";
				break;
			case 2:
				cout << "Cac phan tu danh sach I: \n";
				output (a, n, 'A');
				break;
			case 3:
				input (b, m, 'B');
				cout << "Danh sach II da duoc nhap thanh cong \n";
				break;
			case 4:
				cout << "Cac phan tu danh sach II: \n";
				output (b, m, 'B');
				break;
			case 5:
				cout << "Cac phan tu danh sach I: \n";
				output (a, n, 'A');
				cout << "Cac phan tu danh sach II: \n";
				output (b, m, 'B');
				break;
			case 6:
				giao(a, b);
				break;
			case 7:
				bu(a, b);
				break;
			case 8: 
				cout << "\nGoodbye!" <<endl;
				break;
			default:
				break;
		}

	}while (choice != 8);
	system ("pause");
	return 0;
}