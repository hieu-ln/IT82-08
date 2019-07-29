////Bai 1.1
//#include <iostream>
//using namespace std;
//#define MAX 20
//int a[MAX];
//int n, x;
////Bai 1.2
//void input(int a[], int &n){
//	cout << "Nhap gia tri cac phan tu:\n";
//	for(int i = 0; i<n; i++)
//	{
//		cout<<"a["<<i<<"]=";
//		cin >> a[i];
//	}
//}
////Bai 1.3
//void output(int a[], int n){
//	cout <<"Danh sach cac phan tu da nhap:\n";
//	for(int i=0; i<n; i++)
//		cout << a[i] << "\t";
//	cout << endl;
//}
////Bai 1.4
//void InsertionSort(int a[], int n){
//	int x, i, j;
//	for(int i=1; i<n;i++)
//	{
//		x=a[i];
//		j=i-1;
//		while(0<=j && x < a[j])
//		{
//			a[j+1] = a[j];
//			j--;
//		}
//		a[j+1]=x;
//	}
//}
////Bai 1.5
//void swap(int &a, int &b){
//	int c;
//	c=a;
//	a=b;
//	b=c;
//}
//void SelectionSort(int a[], int n){
//	int min_pos, i, j;
//	for(i=0; i<n-1; i++)
//	{
//		min_pos = i;
//		for(j=i+1; j<n; j++)
//			if(a[j]<a[min_pos])
//				min_pos=j;
//		swap(a[min_pos], a[i]);
//	}
//}
////Bai 1.6
//void InterchangeSort(int a[], int n){
//	for(int i=0;i<n-1;i++)
//		for(int j=i+1; j<n; j++)
//			if(a[i]>a[j])
//				swap(a[i], a[j]);
//}
////Bai 1.7
//void BubbleSort(int a[], int n){
//	for(int i=0; i<n-1;i++)
//		for(int j=n-1;j>i;j--)
//			if(a[j-1]>a[j])
//				swap(a[j], a[j-1]);
//}
////Bai 1.8
//void QuickSort(int a[], int left, int right){
//	int x = a[(left+right)/2];
//	int i=left;
//	int j=right;
//	while(i<j)
//	{
//		while(a[i]<x) i++;
//		while(a[j]>x) j--;
//		if(i<=j){
//			swap(a[i],a[j]);
//			i++; j--;
//		}
//	}
//	if(left<j) QuickSort(a, left, j);
//	if(i<right) QuickSort(a, i, right);
//}
////Bai 1.9
//void shift(int a[], int i, int n){
//	int j=2*i+1;
//	if(j>=n)
//		return;
//	if(j+1 < n)
//		if(a[j]<a[j+1])
//			j++;
//	if(a[i] >= a[j])
//		return;
//	else{
//		int x=a[i];
//		a[i]=a[j];
//		a[j]=x;
//		shift(a, j, n);
//	}
//}
//void HeapSort(int a[], int n){
//	int i=n/2;
//	while(i>=0)
//	{
//		shift(a, i, n-1); i--;
//	}
//	int right=n-1;
//	while(right>0)
//	{
//		swap(a[0], a[right]);
//		right--;
//		if(right>0)
//			shift(a, 0, right);
//	}
//}
////Bai 1.10 - TIM KIEM TUAN TU
//int Search(int a[], int n, int x){
//	int i=0;
//	while(i<n && a[i]!=x)
//		i++;
//	if(i<n)
//		return i;
//	return -1;
//}
////Bai 1.11 - TIM KIEM NHI PHAN
//int BinarySearch(int a[], int n, int x){
//	int left=0, right=n-1, mid;
//	while(left<=right)
//	{
//		mid=(left+right)/2;
//		if(a[mid]==x) return mid;
//		if(x>a[mid]) left=mid+1;
//		else right=mid-1;
//	}
//	return -1;
//}
//int main(){
//	int chon;
//	cout << "<==========> BAI TAP CHUONG 3 <==========>\n";
//	cout << "MENU\n";
//	cout << "1. Nhap danh sach cac phan tu\n";
//	cout << "2. Xuat danh sach cac phan tu\n";
//	cout << "3. Ham sap xep danh sach bang thuat toan InserttionSort\n";
//	cout << "4. Ham sap xep danh sach bang thuat toan SelectionSort\n";
//	cout << "5. Ham sap xep danh sach bang thuat toan InterchangeSort\n";
//	cout << "6. Ham sap xep danh sach bang thuat toan BubbleSort\n";
//	cout << "7. Ham sap xep danh sach bang thuat toan QuickSort\n";
//	cout << "8. Ham sap xep danh sach bang thuat toan HeapSort\n";
//	cout << "9. Ham tim kiem tuan tu\n";
//	cout << "10. Ham tim kiem nhi phan\n";
//	cout << "11. Thoat\n";
//	do{
//		cout << "Chon lenh muon su dung: ";
//		cin >> chon;
//		switch(chon){
//		case 1:
//			cout << "Nhap so luong phan tu: ";
//			cin >> n;
//			input(a, n);
//			output(a, n);
//			break;
//		case 2:
//			output(a, n);
//			break;
//		case 3:
//			InsertionSort(a, n);
//			output(a,n);
//			break;
//		case 4:
//			SelectionSort(a,n);
//			output(a, n);
//		case 5:
//			InterchangeSort(a, n);
//			output(a,n);
//			break;
//		case 6:
//			BubbleSort(a, n);
//			output(a, n);
//			break;
//		case 7:
//			QuickSort(a, 0, n-1);
//			output(a, n);
//			break;
//		case 8:
//			HeapSort(a, n);
//			output(a, n);
//			break;
//		case 9:
//			cout << "Nhap gia tri can tim x=";
//			cin>>x;
//			if(Search(a, n, x) != -1)
//				cout << "Da tim thay gia tri x="<<x<<" trong mang\n";
//			else
//				cout << "Khong tim thay gia tri x="<<x<<" trong mang\n";
//			break;
//		case 10:
//			cout << "Nhap gia tri can tim x=";
//			cin>>x;
//			if(BinarySearch(a, n, x) != -1)
//				cout << "Da tim thay gia tri x="<<x<<" trong mang\n";
//			else
//				cout << "Khong tim thay gia tri x="<<x<<" trong mang\n";
//		}
//	}while(chon != 11);
//	system("pause");
//	return 0;
//}