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
//void push(int a[], int &sp){
//	cout << "Nhap gia tri can them x=";
//	cin >> x;
//	if(sp < MAX-1){
//		a[++sp]=x;
//		cout << "Da them phan tu thanh cong\n";
//	}
//	else
//		cout << "Stack da day! Khong the them phan tu\n";
//}
//void pop(int a[], int &sp, int &x){
//	if(sp!=-1){
//		x=a[sp--];
//		cout << "Da lay phan tu thanh cong\n";
//	}
//	else
//		cout << "Stack rong! Khong the lay phan tu\n";
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
//int main(){
//	int chon;
//	cout << "MENU\n";
//	cout <<"1. Khoi tao Stack rong\n";
//	cout <<"2. Kiem tra Stack rong\n";
//	cout <<"3. Kiem tra Stack day\n";
//	cout <<"4. Them 1 phan tu vao Stack\n";
//	cout <<"5. Xoa 1 phan tu vao Stack\n";
//	cout <<"6. Thoat\n";
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
//			push(a, sp);
//			break;
//		case 5:
//			pop(a, sp, x);
//			break;
//		default:
//			break;
//		}
//	}while(chon!=6);
//	system("pause");
//	return 0;
//}