//#include <iostream>
//using namespace std;
//#define MAX 100
//int a[MAX], front, rear, x;
//void init(int a[], int &front, int &rear){
//	front = -1;
//	rear = -1;
//	cout << "Hang doi da duoc khoi tao thanh cong\n";
//}
//void isFull(int a[], int front, int rear){
//	if((rear - front) == MAX-1)
//		cout << "Hang doi day!!!\n";
//	else
//		cout << "Hang doi chua day\n";
//}
//void isEmpty(int a[], int front, int rear){
//	if(front == -1)
//		cout << "Hang doi rong\n";
//	else
//		cout << "Hang doi khong rong\n";
//}
//void push(int a[], int &front, int &rear, int x){
//	if((rear - front) == MAX - 1)
//		cout << "Hang doi day!!!\n";
//	else
//	{
//		if(front == -1)
//			front = 0;
//		if(rear == MAX-1){
//			for(int i = front; i <MAX-1; i++)
//				a[i-front] = a[i];
//			rear=MAX-1-front;
//			front = 0;
//		}
//		a[++rear]=x;
//		cout << "Da them phan tu thanh cong\n";
//	}
//}
//void pop(int a[], int &front, int &rear, int x){
//	if(front == -1)
//		cout << "Hang doi rong\n";
//	else
//	{
//		x = a[front++];
//		if(front > rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		cout << "Da lay phan tu thanh cong\n";
//	}
//}
//int main(){
//	int chon;
//	cout << "MENU\n";
//	cout <<"1. Khoi tao Queue rong\n";
//	cout <<"2. Kiem tra Queue rong\n";
//	cout <<"3. Kiem tra Queue day\n";
//	cout <<"4. Them 1 phan tu vao Queue\n";
//	cout <<"5. Xoa 1 phan tu vao Queue\n";
//	cout <<"6. Thoat\n";
//	do{
//		cout <<"Chon: ";
//		cin >> chon;
//		switch(chon){
//		case 1:
//			init(a, front, rear);
//			break;
//		case 2:
//			isEmpty(a, front, rear);
//			break;
//		case 3:
//			isFull(a,front, rear);
//			break;
//		case 4:
//			cout << "Nhap phan tu can them x=";
//			cin >> x;
//			push(a, front, rear, x);
//			break;
//		case 5:
//			pop(a, front, rear, x);
//			break;
//		default:
//			break;
//		}
//	}while(chon!=6);
//	system("pause");
//	return 0;
//}