//#include <iostream>
//using namespace std;
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *first;
//void init(){
//	first = NULL;
//	cout << "Da khoi tao mang thanh cong!\n";
//}
//void output(){
//	Node *p;
//	p = first;
//	cout << "Mang: ";
//	while(p!=NULL)
//	{
//		cout<<p->info<<"\t";
//		p=p->link;
//	}
//	cout <<endl;
//}
//Node *tim(){
//	int x;
//	cout << "Nhap phan tu can timx=";
//	cin >>x;
//	Node *p = first;
//	while(p!=NULL && p->info!=x)
//	{
//		p=p->link;
//	}
//	return p;
//}
//void themdau(){
//	int x;
//	cout << "Nhap phan tu can them x=";
//	cin>>x;
//	Node *p= new Node;
//	p->info = x;
//	p->link=first;
//	first = p;
//}
//void xoadau(){
//	if(first!=NULL){
//		Node *p = first;
//		first=p->link;
//		delete p;
//		output();
//	}
//	else
//		cout <<"Ham rong khong the xoa!!!";
//}
//void themcuoi(){
//	Node *p= first;
//	Node *q = new Node;
//	int x;
//	cout << "Nhap gia tri can them vao cuoi danh sach x=";
//	cin>>x;
//	q->info = x;
//	q->link = NULL;
//	if(first == NULL)
//		first = q;
//	else{
//		while(p->link!=NULL){
//			p=p->link;
//		}
//		p->link = q;
//	}
//}
//void xoacuoi(){
//	Node *p = first;
//	Node *q = NULL;
//	while(p->link!=NULL)
//	{
//		q=p;
//		p = p->link;
//	}
//	if(p!=first)
//		q->link = NULL;
//	else
//		first = NULL;
//	delete p;
//}
//void timvaxoa(){
//	int x;
//	cout << "Nhap gia tri can tim va xoa x=";
//	cin>>x;
//	Node *p = first;
//	Node *q = NULL;
//	if(first != NULL){
//	while(p->link!=NULL && p->info != x){
//		q = p;
//		p=p->link;
//	}
//	if(p->info != x)
//	{
//			cout << "Khong tim thay phan tu de xoa\n";
//	}
//	else
//		if(p==first){
//			if(p->link == NULL)
//				first=NULL;
//			else{
//				first=p->link;
//				delete p;
//			}
//		}
//		else{
//				q->link = p->link;
//				delete p;
//		}
//	}else
//		cout << "Mang rong!!!\n";
//}
//int main(){
//	int chon;
//	cout << "MENU\n";
//	cout <<"1. Khoi tao danh sach rong\n";
//	cout <<"2. Xuat phan tu trong danh sach\n";
//	cout <<"3. Tim phan tu trong danh sach\n";
//	cout <<"4. Them phan tu vao dau danh sach\n";
//	cout <<"5. Xoa phan tu dau danh sach\n";
//	cout <<"6. Them phan tu cuoi danh sach\n";
//	cout <<"7. Xoa phan tu cuoi danh sach\n";
//	cout <<"8. Tim va xoa phan tu trong danh sach\n";
//	cout <<"9. Thoat\n";
//	do{
//		cout <<"Chon: ";
//		cin >> chon;
//		switch(chon){
//		case 1:
//			init();
//			break;
//		case 2:
//			output();
//			break;
//		case 3:
//			if(tim()==NULL)
//				cout << "Khong tim thay phan tu x";
//			else
//				cout << "Da tim thay phan tu x="<<tim()<<" trong mang\n";
//			break;
//		case 4:
//			themdau();
//			output();
//			break;
//		case 5:
//			xoadau();
//			output();
//			break;
//		case 6:
//			themcuoi();
//			output();
//			break;
//		case 7:
//			xoacuoi();
//			output();
//			break;
//		case 8:
//			timvaxoa();
//			output();
//			break;
//		default:
//			break;
//		}
//	}while(chon!=9);
//	system("pause");
//	return 0;
//}