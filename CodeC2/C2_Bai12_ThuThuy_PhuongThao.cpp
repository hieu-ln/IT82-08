#include<iostream>
using namespace std;
struct Node
{
	int info;
	Node *next,*previous;
};
Node * first, *last;
//Tao danh sach rong
void init()
{
	first=NULL;
	last=NULL;
}

//Xuat danh sach
void process_list()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout<<p->info<<"	";
		p=p->next;
	}
	cout<<endl;
}

//Chen phan tu vao dau danh sach
void insert_first(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=first;
	p->previous=NULL;
	if(first!=NULL)
		first->previous=p;
	else
		last=p;
	first = p;
}

//Chen phan tu vao cuoi danh sach
void insert_last(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if(last!=NULL)
		last->next=p;
	else
		first=p;
	last=p;
}

//Xoa phan tu dau danh sach
int delete_first()
{	
	if(first!=NULL)
	{
		Node *p=first;
		first=first->next;
		delete p;
		if(first!=NULL)
			first->previous=NULL;
		else
			last=NULL;
		return 1;
	}
	return 0;
}

//Xoa phan tu cuoi danh sach
int delete_last()
{
	if(last!=NULL)
	{
		Node *p=last;
		last=last->previous;
		if(last!=NULL)
			last->next=NULL;
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Tim x trong danh sach
Node *search(int x)
{
	Node *p=first;
	while((p!=NULL)&&(p->info!=x))
		p=p->next;
	return p;
}

//Tim gia gi gan bang lon hon x

Node *search2(int x)
{
	Node *p = first, *q = first;
	int min = first->info;
	if(p == NULL)
		return NULL;
	while(p != NULL)
	{
		if(p->info == x)
			return p;
		else if((p ->info > x) && (p->info < min))
			{
				min = p->info;
				q = p;
			}
		p = p->next;
	}
	return q;
}
//Chen y vao truoc  phan tu x
int insert(int x, int y)
{
	Node*q=search2(x);
	if(q!=NULL)
	{
		if(q==last)
			insert_first(y);
		else
		{
			Node *p=new Node;
			p->info=y;
			p->previous=q->previous;
			(q->previous)->next=p;
			q->previous=p;
			p->next=q;
		}
		return 1;
	}
	return 0;
}
int delete_x (int x)
{
	Node*q=search(x);
	if(q!=NULL)
	{
		if(q==first)
		{
			if(delete_first())
			return 1;
		}
		else if(q==last)
		{
			if(delete_last())
				return 1;
		}
		else
			{
				Node *p=q->previous;
				Node *r=q->next;
				p->next=r;
				r->previous=p;
				delete q;
			}
	}
	return 0;
}
int main()
{
	init();
	int choice;
	cout<<"---------BAI TAP CHUONG 2, BAI 12-------------";
	cout<< "1. Khoi tao danh sach";
	cout<<"\n2. Duyet danh sach";
	cout<<"\n3. Them phan tu vao dau danh sach\n";
	cout<<"4. Them phan tu vao cuoi danh sach";
	cout<<"\n5. Xoa dau danh sach";
	cout<<"\n6. Xoa cuoi danh sach";
	cout<<"\n7. Tim va xoa phan tu x trong danh sach";
	cout<<"\n8. Chen y truoc phan tu x( hoac co gia tri gan voi x nhat va lon hon x)";
	cout<<"\n9.Thoat"<<endl;
	do{
		cout<<"Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				cout<<"khoi tao thanh cong\n";
				break;
			case 2:
				cout<<"Danh sach: ";
				process_list();
				break;
			case 3:
				int a;
				cout<<"nhap gia tri can them: ";
				cin >> a;
				insert_first(a);
				cout<<"Danh sach sau khi them la: ";
				process_list();
				break;
			case 4:
				int b;
				cout<<"nhap gia tri can them: ";
				cin >> b;
				insert_last(b);
				cout<<"Danh sach sau khi them la: ";
				process_list();
				break;
			case 5:
				if(delete_first()==1)
				{
					cout<<"Danh sach sau khi xoa la: ";
					process_list();
				}
				else
					cout<< "xoa khong thanh cong"<<endl;
				break;
			case 6:
				if(delete_last()==1)
				{
					cout<<"Danh sach sau khi xoa la: ";
					process_list();
				}
				else
					cout<< "xoa khong thanh cong"<<endl;
				break;
			case 7:
				int t;
				cout<< "Nhap gia tri phan tu can xoa: ";
				cin >> t;
				if(delete_x(t))

					cout<<" xoa phan tu "<<t<<"khong thanh cong vi khong co trong danh sach\n";
				else
				{
					cout<<"Danh sach sau khi xoa la: ";
					process_list();
				}
				break;
			case 8:
				int x, y;
				cout<<"nhap cac phan tu can tim: ";
				cin>>x;
				cout<<"Nhap gia tri phan tu can chen: ";
				cin>>y;
				cout<<y<<" se duoc chen truoc "<<search2(x)->info<<endl;
				if(insert(x,y)==1)
				{
					cout<<"Danh sach sau khi chen la: ";
					process_list();
				}
				else
					cout<<"chen khong thanh cong vi khong tim thay gia tri"<<x<<endl;
				break;
			case 9:
				cout<<"GOOD BYE...!!!"<<endl;
			default:
				break;
		}
	}while(choice !=9);
	system("pause");
	return 0;
}