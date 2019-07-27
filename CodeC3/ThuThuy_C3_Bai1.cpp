#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
#define MAX 5000
int a[MAX];
int n;
// Khoi tao danh sach ngau nhien
void random(int a[], int &n)
{
	cout<<"Nhap so phan tu: ";
	cin>>n;
	for(int i = 0; i<n; i++)
		a[i] = rand() % 1000 +1;
	cout<<"Danh sach sau khi khoi tao la: "<<endl;
	for(int i = 0; i<n; i++)
		cout<<a[i]<<"\t";
}
//Nhap danh sach
void in(int a[], int& n)
{
	cout<<"Nhap so phan tu: ";
	cin>>n;
	cout<<"Nhap gia tri cua cac phan tu: ";
	for(int i = 0; i<n; i++)
	{
		cout<<"a["<<i<<"] =";
		cin>>a[i];
	}
}
//Xuat danh sach
void out(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<a[i]<<"	";
	cout<<endl;
}

void coppyarr(int a[], int b[], int n)
{
	for(int i = 0; i<n; i++)
		b[i] = a[i];
}
//Inserttion sort
void insertionsort(int a[], int n)
{
	int i, key, j;
	for(i=1; i< n; i++)
	{
		key = a[i];
		j = i -1;
		while(j>=0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}
void swap(int &a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
//Selection sort
void selectionsort(int a[], int n)
{
	int i, j, min_idx;
	for(i=0; i<n - 1; i++)
	{
		min_idx = i;
		for(j = i + 1; j<n; j++)
			if( a[j] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}
//Interchange sort
void interchangesort(int a[], int n)
{
	for(int i = 0; i< n - 1; i++)
		for(int j = i+1; j<n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}
//bubble sort
void bubblesort(int a[], int n)
{
	int i, j;
	bool haveswap = false;
	for(i = 0; i<n - 1; i++)
	{
		haveswap = false;
		for(j = 0; j<n-i-1; j++)
		{
			if(a[j] >a[j+1])
			{
				swap(a[j], a[j+1]);
				haveswap = true;
			}
		}
		if(haveswap == false)
			break;
	}
}
//Quick Sort
void quicksort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i<j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i<=j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j)
		quicksort(a, left, j);
	if(i < right)
		quicksort(a, i, right);
}
//Ham quan ly con cua heap
//void shift(int a[], int i, int n)
//{
//	int j = 2 * i + 1;
//	if(j>=n)
//		return;
//	if( j+1 < n)
//		if( a[j] < a[j+1])
//			j++;
//	if(a[i] >= a[j])
//		return;
//	else
//	{
//		//swap(a[i], a[j]);
//		int x = a[i];
//		a[i] = a[j];
//		a[j] = x;
//		shift(a, j, n);
//	}
//}
////Heapsort
//void heapsort(int a[], int n)
//{
//	int i = n / 2 - 1;
//	while(i >= 0)
//	{
//		shift(a, i, n);
//		i--;
//	}
//	int right = n - 1;
//	while( right > 0)
//	{
//		swap(a[0], a[right]);
//		right--;
//		if(right >0)
//			shift(a, 0, right);
//	}
//}
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < n && a[l] > a[largest])
		largest = l;
	if(r < n && a[r] > a[largest])
		largest = r;
	if(largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapsort(int a[], int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for(int i = n - 1; i>= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
//Tim kiem tuan tu
void searchsequence(int a[], int n, int x)
{
	int i = 0;
	while( i < n && a[i] != x)
		i++;
	if( i== n)
		cout<<"Khong tim thay"<<endl;
	else
		cout<<"Tim thays tai vi tri: "<<i<<endl;
}
//Tim kiem nhi phan
int searchbinary(int a[], int left, int right, int x)
{
	if(right>left)
	{
		int mid = left + ( right - left) / 2;
		if( a[mid] == x)
			return mid;
		if(a[mid] > x)
			return searchbinary(a, left, mid - 1, x);
		return searchbinary(a, mid + 1, right, x);
	}
	return -1;
}
int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout<<"*********BAI TAP 1 - CHUONG 3**********"<<endl;
	cout<<"1. Khoi tao danh sach ngau nhien"<<endl;
	cout<<"2. Nhap danh sach "<<endl;
	cout<<"3. Xuat danh sach "<<endl;
	cout<<"4. Xep thu tu danh sach tu nho den lon bang Selection Sort "<<endl;
	cout<<"5. Xep thu tu danh sach tu nho den lon bang Insertion Sort "<<endl;
	cout<<"6. Xep thu tu danh sach tu nho den lon bang Bubble Sort "<<endl;
	cout<<"7. Xep thu tu danh sach tu nho den lon bang Interchange Sort "<<endl;
	cout<<"8. Xep thu tu danh sach tu nho den lon bang Quick Sort "<<endl;
	cout<<"9. Xep thu tu danh sach tu nho den lon bang Heap Sort "<<endl;
	cout<<"10. Tim kiem phan tu X bang phuong phap tim kiem tuan tu "<<endl;
	cout<<"11. Tim kiem phan tu X bang phuong phap tim kiem nhi phan"<<endl;
	cout<<"12. Thoat"<<endl;
	do
	{
		cout<<"\Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			random(a, n);
			break;
		case 2:
			in(a, n);
			break;
		case 3:
			out(a, n);
			break;
		case 4:
			coppyarr(a, b, n);
			start = clock();
			selectionsort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n< 100)
			{
				cout<<"DS sau khi sap xep voi Selection Sort: "<<endl;
				out(b, n);
			}
			if(duration > 0)
				cout<<"Thoi gian Selection Sort: "<<duration<<endl;
			break;
		case 5:
			coppyarr(a, b, n);
			start = clock();
			insertionsort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n< 100)
			{
				cout<<"DS sau khi sap xep voi Insertion Sort: "<<endl;
				out(b, n);
			}
			if(duration > 0)
				cout<<"Thoi gian Insertion Sort: "<<duration<<endl;
			break;
		case 6:
			coppyarr(a, b, n);
			start = clock();
			bubblesort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n< 100)
			{
				cout<<"DS sau khi sap xep voi Bubble Sort: "<<endl;
				out(b, n);
			}
			if(duration > 0)
				cout<<"Thoi gian Bubble Sort: "<<duration<<endl;
			break;
		case 7:
			coppyarr(a, b, n);
			start = clock();
			interchangesort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n< 100)
			{
				cout<<"DS sau khi sap xep voi Interchange Sort: "<<endl;
				out(b, n);
			}
			if(duration > 0)
				cout<<"Thoi gian Interchange Sort: "<<duration<<endl;
			break;
		case 8:
			coppyarr(a, b, n);
			start = clock();
			quicksort(b, 0, n-1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n< 100)
			{
				cout<<"DS sau khi sap xep voi Quick Sort: "<<endl;
				out(b, n);
			}
			if(duration > 0)
				cout<<"Thoi gian Quick Sort: "<<duration<<endl;
			break;
		case 9:
			coppyarr(a, b, n);
			start = clock();
			heapsort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if(n< 100)
			{
				cout<<"DS sau khi sap xep voi Heap Sort: "<<endl;
				out(b, n);
			}
			if(duration > 0)
				cout<<"Thoi gian Heap Sort: "<<duration<<endl;
			break;
		case 10:
			cout<<"Nhap so can tim: ";
			cin>>x;
			searchsequence(a, n, x);
			break;
		case 11:
			cout<<"Nhap so can tim: ";
			cin>>x;
			if(searchbinary(b,0, n-1, x) == -1 )
				cout<<"Khong tim thay"<<endl;
			else
				cout<<"Tim thay tai vi tri: "<<searchbinary(b,0, n-1, x)<<endl;
			break;
		case 12:
			cout<<"bye!!"<<endl;
			break;
		default:
			cout<<"Khong co lua chon nay"<<endl;
			break;
		}
	}while(choice != 12);
	system("pause");
	return 0;
}