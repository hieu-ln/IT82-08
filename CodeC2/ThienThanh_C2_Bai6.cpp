//#include <iostream>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int sp;
//int x;
//void init(int a[], int &sp){
//	sp = -1;
//	cout << "Stack da duoc khoi tao\n";
//}
//void push(int a[], int &sp, int &x){
//	if(sp < MAX-1)
//		a[++sp]=x;
//}
//void pop(int a[], int &sp, int &x){
//	if(sp!=-1)
//		x=a[sp--];
//}
//void isFull(int a[], int &sp){
//	if(sp == MAX - 1)
//		cout << "Stack day!!!\n";
//	else
//		cout << "Stack chua day!!!\n";
//}
//void isEmpty(int a[], int &sp){
//	if(sp == -1)
//		cout << "Stack rong!!!\n";
//	else
//		cout << "Stack khong rong!!!\n";
//}
//void chuyendoi(){
//	int du;
//	int n;
//	int tam =0;
//	cout << "Nhap phan tu can chuyen doi: ";
//	cin >> n;
//	while(n!=0)
//	{
//		du = n%2;
//		push(a, sp, du);
//		n=n/2;
//	}
//}
//void xuatnp(){
//	int tam;
//	while(sp!=-1)
//	{
//		pop(a, sp, tam);
//		cout << tam;
//	}
//	cout <<endl;
//}
//int main(){
//	int chon;
//	cout << "MENU\n";
//	cout <<"1. Khoi tao Stack rong\n";
//	cout <<"2. Kiem tra Stack rong\n";
//	cout <<"3. Kiem tra Stack day\n";
//	cout <<"4. Them 1 phan tu vao Stack\n";
//	cout <<"5. Xoa 1 phan tu vao Stack\n";
//	cout <<"6. Chuyen doi so thap phan sang nhi phan\n";
//	cout <<"7. Xuat so nhi phan\n";
//	cout <<"8. Thoat\n";
//	do{
//		cout <<"Chon: ";
//		cin >> chon;
//		switch(chon){
//		case 1:
//			init(a, sp);
//			break;
//		case 2:
//			isEmpty(a,sp);
//			break;
//		case 3:
//			isFull(a,sp);
//			break;
//		case 4:
//			cout << "Nhap gia tri can them x=";
//			cin >> x;
//			push(a, sp, x);
//			if(sp < MAX-1){
//				cout << "Da them phan tu thanh cong\n";
//			}
//			else
//				cout << "Stack da day! Khong the them phan tu\n";
//			break;
//		case 5:
//			pop(a, sp, x);
//			if(sp!=-1){
//				cout << "Da lay phan tu thanh cong\n";
//			}
//			else
//				cout << "Stack rong! Khong the lay phan tu\n";
//			break;
//		case 6:
//			chuyendoi();
//			break;
//		case 7:
//			xuatnp();
//			break;
//		default:
//			break;
//		}
//	}while(chon!=8);
//	system("pause");
//	return 0;
//}