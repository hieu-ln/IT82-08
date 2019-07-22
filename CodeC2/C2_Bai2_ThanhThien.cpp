//Chuong 2 - Bai 1 : Danh sách co thu tu
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

//cau 2.1
int a[MAX];
int n;

//Cau 2.2: them phan tu vao danh sach
void swap (int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void quickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if( i <= j)
		{
			swap (a[i], a[j]); //doi cho
			i++;
			j--;
		}
	}
	if (left < j)
			quickSort(a, left, j);
	if (i < right)
		quickSort(a,i,right);
}
void input(int a[], int &n)
{
	cout <<"Nhap vao so luong phan tu cua danh sach: ";
	cin >>n;
	cout <<"Nhap vao cac phan tu cua danh sach (co thu tu tang dan): " <<endl;
	for (int i = 0; i<n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	quickSort(a, 0, n-1);
}

//Cau 2.3: xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

}

//cau 2.4 Tim phan tu trong danh sach (tim kiem tuan tu)
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

//cau 2.4 Tim phan tu trong danh sach (tim kiem nhi phan)
int searchBinary (int a[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2; //Tương đương (l+r)/2 nhưng ưu điểm để tránh tràn số khi l, r lớn

		//Nếu a[mid] = x, trả về chỉ số và kết thúc
		if (a[mid] == x)
			return mid;

		//Nếu a[mid] > x, thực hiện tìm kiếm nửa trái của hàm
		if (a[mid] == x)
			return searchBinary(a, l, mid - 1, x);

		//Nếu a[mid] < x, thực hiện tìm kiếm nửa phải của hàm
		return searchBinary(a, l, mid - 1, x);
	}
	 // Nếu không tìm thấy
	return -1;
}


//xoa phan tu tai vi tri thu i
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

//cau 2.6 tim 1 phan tu trong danh sach va xoa phtu do
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
	cout<<"3. Tim kiem tuan tu"<<endl;
	cout<<"4. Tim kiem nhi phan"<<endl;
	cout<<"5. Tim phan tu va xoa"<<endl;
	cout<<"6. Thoat"<<endl;

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
			cout <<"Vui long nhap x can tim: ";
			cin >> x;
			i = searchBinary(a,0,n,x);
			if(i == -1)
				cout <<"Tim khong thay phan tu co gia tri x" << x << endl;
			else
				cout <<"Tim thay tai vi tri i= " << i << endl;
			break;
		case 5:
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
		case 6:
			cout << "Goodbye!";
			break;
		default:
			break;
		}
	}
	while (choice != 6);
	system("pause");
	return 0;
}