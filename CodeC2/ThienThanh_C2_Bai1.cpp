//#include <iostream>
//using namespace std;
//#define MAX 100
//int a[MAX], n;
//void input(int a[], int &n){
//	cout << "Nhap so luong phan tu: ";
//	cin >>n;
//	for(int i = 0; i < n;i++)
//	{
//		cout << "a["<<i<<"]=";
//		cin>>a[i];
//	}
//}
//void output(int a[], int n){
//	cout <<"DANH SACH CAC PHAN TU\n";
//	for(int i = 0; i < n;i++)
//	{
//		cout <<a[i]<<"\t";
//	}
//	cout << endl;
//}
//void search(int a[], int n){
//	int x;
//	cout << "Nhap gia tri can tim x=";
//	cin>>x;
//	int i =0;
//	while(i<n && a[i]!=x)
//	{
//		i++;
//	}
//	if(i==n)
//		cout << "Khong tim thay gia tri x="<<x<<" tai vi tri i="<<i<<" trong mang\n";
//	else
//		cout << "Da tim thay gia tri x="<<x<<" tai vi tri i="<<i<<" trong mang\n";
//}
//void them(int a[], int &n){
//	int x;
//	cout<<"Nhap gia tri can them vao cuoi danh sach x=";
//	cin>>x;
//	a[n]=x;
//	n++;
//	output(a,n);
//}
//void xoa(int a[], int &n){
//	n--;
//	output(a,n);
//}
//void xoataivitri(int a[], int &n){
//	int x;
//	cout <<"Nhap vi tri can xoa i=";
//	cin >>x;
//	for(int i = x; i<n-1;i++)
//	{
//		a[i] = a[i+i];
//	}
//	n--;
//	output(a,n);
//}
//void xoax(int a[], int &n){
//	int x;
//	cout <<"Nhap phan tu can xoa x=";
//	cin >> x;
//	int i=0;
//	while(i<n &&a[i]!=x){
//		i++;
//	}
//	if(i==n)
//		cout << "Khong tim thay phan tu x="<<x<<" trong mang\n";
//	else{
//		for(int j=i;j<n-n;j++){
//			a[j]=a[j+1];
//		}
//		n--;
//		output(a,n);
//	}
//}
//int main(){
//	int chon;
//	cout << "MENU\n";
//	cout <<"1. Nhap danh sach cac phan tu\n";
//	cout <<"2. Xuat phan tu trong danh sach\n";
//	cout <<"3. Tim 1 phan tu trong danh sach\n";
//	cout <<"4. Them 1 phan tu vao cuoi danh sach \n";
//	cout <<"5. Xoa 1 phan tu cuoi danh sach\n";
//	cout <<"6. Xoa phan tu tai vi tri\n";
//	cout <<"7. Tim va xoa 1 phan tu trong danh sach\n";
//	cout <<"8. Thoat\n";
//
//	do{
//		cout <<"Chon: ";
//		cin >> chon;
//		switch(chon){
//		case 1:
//			input(a,n);
//			break;
//		case 2:
//			output(a,n);
//			break;
//		case 3:
//			search(a,n);
//			break;
//		case 4:
//			them(a,n);
//			break;
//		case 5:
//			xoa(a,n);
//			break;
//		case 6:
//			xoataivitri(a,n);
//			break;
//		case 7:
//			xoax(a,n);
//			break;
//		default:
//			break;
//		}
//	}while(chon!=8);
//	system("pause");
//	return 0;
//}