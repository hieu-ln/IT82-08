//#include <stdio.h>
//#include <iostream>
//using namespace std;
//struct Stack{
//	int info;
//	Stack *link;
//};
//Stack *sp;
//void init(){
//	sp = NULL;
//	cout << "Da khoi tao Stack rong\n";
//}
//void KiemTra(){
//	if(sp == NULL)
//		cout << "Stack rong\n";
//	else
//		cout << "Stack khong rong\n";
//}
//void Push(int x){
//	Stack *q = new Stack;
//	q -> info = x;
//	q->link=NULL;
//	if(sp==NULL)
//		sp = q;
//	else{
//		Stack *p = sp;
//		while(p->link!=NULL)
//			p=p->link;
//		p->link = q;
//	}
//	cout << "Da them phan tu x="<<x<<" vao Stack\n";
//}
//void Pop(){
//	Stack *p = sp;
//	Stack *q = new Stack;
//	while(p!=NULL)
//	{
//		q = p;
//		p = p->link;
//	}
//	if(p != NULL)
//		q->link = NULL;
//	else
//		sp = NULL;
//	delete p;
//}
//void xuat(){
//	Stack *p = sp;
//	cout << " <-- ";
//	while(p!=NULL)
//	{
//		cout << p->info << " <-- ";
//		p = p->link;
//	}
//	cout << endl;
//}
//void chuyendoi(int n){
//	Stack *p = new Stack;
//	int du;
//	while(n!=0){
//		du = n%2;
//		Push(du);
//		n=n/2;
//	}
//	xuat();
//}
//int main(){
//	int x;
//	int n;
//	int chon;
//	cout << "MENU:\n";
//	cout <<"1. Khoi tao Stack rong\n";
//	cout <<"2. Kiem tra Stack rong\n";
//	cout <<"3. Them 1 phan tu vao Stack\n";
//	cout <<"4. Xoa 1 phan tu trong Stack\n";
//	cout <<"5. Chuyen doi he thap phan sang he nhi phan\n";
//	cout <<"6. Thap Ha Noi\n";
//	cout <<"7. Thoat\n";
//	do{
//		cout << "Chon: ";
//		cin >>chon;
//		switch(chon){
//		case 1:
//			init();
//			break;
//		case 2:
//			KiemTra();
//			break;
//		case 3:
//			cout << "Nhap gia tri can them x=";
//			cin >>x;
//			Push(x);
//			xuat();
//			break;
//		case 4:
//			Pop();
//			break;
//		case 5:
//			cout << "Nhap so can chuyen tu thap phan sang nhi phan n=";
//			cin >>n;
//			chuyendoi(n);
//			break;
//		case 6:
//			break;
//		default:
//			break;
//		}
//	}while(chon!=7);
//	system("pause");
//	return 0;
//}