//#include <stdio.h>
//#include <iostream>
//using namespace std;
//struct Queue{
//	int info;
//	Queue *link;
//};
//Queue *first;
//void init(){
//	first = NULL;
//	cout << "Da khoi tao Queue rong\n";
//}
//int isEmpty(){
//	if(first == NULL)
//		return 0;
//	else
//		return 1;
//}
//void Push(int x){
//	Queue *q = new Queue;
//	q->info = x;
//	q->link = NULL;
//	if(first == NULL)
//		first = q;
//	else{
//		Queue *p = first;
//		while(p->link!=NULL)
//			p = p->link;
//		p->link = q;
//		cout << "Da them thanh cong\n";
//	}
//}
//void Pop(){
//	Queue *p = first;
//	if(first == NULL)
//		cout <<"Hang doi rong\n";
//	else
//		first = p->link;
//	delete p;
//}
//void xuat(){
//	Queue *p = first;
//	cout << " <-- ";
//	while(p!=NULL)
//	{
//		cout << p->info << " <-- ";
//		p=p->link;
//	}
//	cout << endl;
//}
//int main(){
//	int x;
//	int chon;
//	cout << "MENU\n";
//	cout << "1. Khoi tao Queue rong\n";
//	cout << "2. Kiem tra Queue\n";
//	cout << "3. Them 1 phan tu vao Queue\n";
//	cout << "4. xoa 1 phan tu trong Queue\n";
//	cout << "5. Thoat\n";
//	do{
//		cout << "Chon: ";
//		cin >> chon;
//		switch(chon){
//		case 1:
//			init();
//			break;
//		case 2:
//			if(isEmpty() == 0)
//				cout << "Hang doi rong\n";
//			else
//				cout << "Hang doi khong rong\n";
//			break;
//		case 3:
//			cout << "Nhap gia tri can them x=";
//			cin >>x;
//			Push(x);
//			xuat();
//			break;
//		case 4:
//			Pop();
//			cout << "Da lay phan tu ra khoi Queue\n";
//			xuat();
//			break;
//		default:
//			break;
//		}
//	}while(chon!=5);
//	system("pause");
//	return 0;
//}
#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int stack1[1000], stack2[1000], stack3[1000], stack0[1000];
void chuyendia(int a,int b,int c,int n,int &sp)
{
	sp++;
	stack0[sp]=n-1;
	stack1[sp]=c;
	stack2[sp]=b;
	stack3[sp]=a;
	sp++;
	stack0[sp]=1;
	stack1[sp]=a;
	stack2[sp]=b;
	stack3[sp]=c;
	sp++;
	stack0[sp]=n-1;
	stack1[sp]=a;
	stack2[sp]=c;
	stack3[sp]=b;
}
void thaphanoi(int a,int b, int c, int n)
{
	stack0[0]=n;stack1[0]=a;stack2[0]=b;stack3[0]=c; 
	int sp=0;
	while (sp>=0)
	{
		sp--;
		if (stack0[sp+1]==1) printf("%c -> %c\t",stack1[sp+1],stack2[sp+1]);
		else
			chuyendia(stack1[sp+1],stack2[sp+1],stack3[sp+1],stack0[sp+1],sp);
	}
}
int main()
{
	int n,a=65,b=66,c=67;
	cout << "nhap so dia: ";
	cin >> n;
	thaphanoi(a,b,c,n);
	cout << endl;
	system("pause");
	return 0;
}
