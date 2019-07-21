#include <stdio.h>
#include <iostream>
using namespace std;

//Cau 3.1
struct node{
	int info;
	node *link;
};
node *first;

//Cau3.2
void init()
{
	first = NULL;
}

//Cau 3.3
void process_list()
{
	node *p;
	p = first;
	while(p != NULL)
	{
		cout<<p->info<<"	";
		p = p->link;
	}
	cout<<endl;
}

//Cau 3.4
node *search(int x)
{
	node *p = first;
	while(p!= NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

//Cau 3.5
void insert_first(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = first;
	first = p;
}

//Cau 3.6
int delete_first()
{
	if(first != NULL)
	{
		node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//Cau 3.7
void insert_last(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
		node *q = first;
		while(q->link !=NULL)
			q = q->link;
		q->link = p;
	}
}

//Cau 3.8
int delete_last()
{
	if(first != NULL)
	{
		node *p, *q;
		p = first;
		q = first;
		while(p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if(p!= first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Cau 3.9
int searchanddelete(int x)
{
	if(first != NULL)
	{
		node *p, *q;
		p = first;
		q = first;
		while(p->info != x && p->link != NULL)
		{
			q=p;
			p = p->link;
		}
		if(p!= first && p->link != NULL)
		{
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else if(p->link == NULL && p->info == x)
		{
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

//Ham hoan doi
void swap(node *a, node * b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

//Cau 3.10
//sap xep danh sach co thu tu giam dan
void sort()
{
	node *p, *q, *min;
	p = first;
	while(p != NULL)
	{
		min = p;
		q = p->link;
		while(q!=NULL)
		{
		if(q->info > min->info)
			min = q;
		q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout<<"-------------BAI TAP CHUONG 2, BAI 3------------"<<endl;
	cout<<"1. Khoi tao danh sach rong"<<endl;
	cout<<"2. Them phan tu vao dau danh sach"<<endl;
	cout<<"3. Them phan tu vao cuoi danh sach"<<endl;
	cout<<"4. Xoa phan tu dau danh sach"<<endl;
	cout<<"5. Xoa phan tu cuoi danh sach"<<endl;
	cout<<"6. Xuat danh sach"<<endl;
	cout<<"7. Tim phan tu gia tri x trong danh sach va xoa no neu co"<<endl;
	cout<<"8. Sap xep danh sach"<<endl;
	cout<<"9. Thoat"<<endl;
	do
	{
		cout<<"Chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Khoi tao danh sach rong thanh cong"<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri x: ";
			cin>>x;
			insert_first(x);
			cout<<"Danh sach sau khi them la: ";
			process_list();
			break;
		case 3:
			cout<<"Nhap gia tri x: ";
			cin>>x;
			insert_last(x);
			cout<<"Danh sach sau khi them la: ";
			process_list();
			break;
		case 4:
			i = delete_first();
			if(i == 0)
				cout<<"Danh sach rong, khong the xoa!!!"<<endl;
			else
			{
				cout<<"Da xoa thanh cong"<<endl;
				cout<<"Danh sach sau khi xoa la: ";
				process_list();
			}
			break;
		case 5:
			i = delete_last();
			if(i == 0)
				cout<<"Danh sach rong, khong the xoa!!!"<<endl;
			else
			{
				cout<<"Da xoa thanh cong"<<endl;
				cout<<"Danh sach sau khi xoa la: ";
				process_list();
			}
			break;
		case 6:
			process_list();
			break;
		case 7:
			cout<<"Nhpa gia tri phan tu can tim: ";
			cin>>x;
			i = searchanddelete(x);
			if(i == 1)
			{
				cout<<"Tim thay phan tu x co gia tri = "<<x<<endl;
				cout<<"Danh sach sau khi xoa la: ";
				process_list();
			}
			else
				cout<<"Khong tim thay x!!!"<<endl;
			break;
		case 8:
				cout<<"Danh sach sau khi sap xep la: ";
				sort();
				process_list();
				break;
		case 9:
				cout<<"GOOD BYE ...!!!"<<endl;
				break;
		default:
			break;
		}
	}while(choice !=9);
	system("pause");
	return 0;
}