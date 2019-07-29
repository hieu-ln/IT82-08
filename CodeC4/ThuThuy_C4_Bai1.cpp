#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 10

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void Init()
{
	root = NULL;
}

void Insert(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p->info = x;
		p->right = NULL;
		p->left = NULL;
	}
	else
	{
		if(p->info == x)
			return;
		else if(p->info > x)
			return Insert(p->left, x);
		else
			return Insert(p -> right, x);
	}
}
//1.4
Node *Search(Node *p, int x)
{
	if(p != NULL)
	{
		if(p->info == x)
			return p;
		else
			if(x > p->info)
				return Search(p->right, x);
			else
				return Search(p->left, x);
	}
	return NULL;
}
//1.5
void Searchstandfor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		Searchstandfor(q, q->left);
}

int Delete(Node *&T, int x)
{
	if(T==NULL)
		return 0;
	if(T->info == x)
	{
		Node *p = T;
			if(T->left ==NULL)
				T = T->right;
			else if(T->right == NULL)
				T = T->left;
			else
				Searchstandfor(p, T->right);
			delete p;
			return 1;
	}
	 else if(T->info < x)
		return Delete(T->right, x);
	 else
		 return Delete(T->left, x);
}
//1.6
void DuyetLNR(Node *p)
{
	if(p!= NULL)
	{
		DuyetLNR(p->left);
		cout<<p->info<<"	";
		DuyetLNR(p->right);
	}
}
//1.7
void DuyetNLR(Node *p)
{
	if(p!= NULL)
	{
		cout<<p->info<<"	";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
//1.8
void DuyetLRN(Node *p)
{
	if(p!= NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout<<p->info<<"	";
	}
}

void printNode(Node *p, int space)
{
	//Base case
	if(p == NULL)
		return;
	//Increase distance between levels
	space += COUNT;
	//Process right child first
	printNode(p->right, space);
	//Print current node after space
	//count
	cout<<endl;
	for(int i = COUNT; i < space; i++)
		cout<<" ";
	cout<<p->info<<endl;
	//Process left child
	printNode(p->left, space);
}

void Processtree()
{
	printNode(root, 0);
}

int main()
{
	int choice = 0, x;
	system("cls");
	cout<<"---------------- BAI TAP CHUONG 4 _ BAI 1 _ CAY NPTK -----------------"<<endl;
	cout<<"1. Khoi tao cay nhi phan rong"<<endl;
	cout<<"2. Them phan tu vao cay NPTK"<<endl;
	cout<<"3. Tim phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"4. Xoa phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"5. Duyet cay NPTK theo LNR"<<endl;
	cout<<"6. Duyet cay NPTK theo LRN"<<endl;
	cout<<"7. Duyet cay NPTK theo NLR"<<endl;
	cout<<"8. Xuat cay NPTK"<<endl;
	cout<<"9. Thoat"<<endl;
	do{
		cout<<"Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			Init();
			cout<<"Ban vua khoi tao cay thanh cong !!!"<<endl;
			break;
		case 2:
			cout<<"Vui long nhap gia tri x can them: ";
			cin>>x;
			Insert(root, x);
			cout<<"Cay nhi phan sau khi them la: ";
			Processtree();
			break;
		case 3:
			cout<<"Vui long nhap gia tri x can tim: ";
			cin>>x;
			if(Search(root, x) != NULL)
				cout<<"Tim thay x = "<<x<<" trong cay NPTK"<<endl;
			else
				cout<<"Khong tim thay x trong cay NPTK"<<endl;
			break;
		case 4:
			cout<<"Vui long nhap gia tri x can xoa: ";
			cin>>x;
			if(Delete(root, x) == 0)
				cout<<"Khong tim thay x = "<<x<<" de xoa!"<<endl;
			else
				{
					cout<<"Xoa thanh cong!!!"<<endl<<"Cay NPTK sau khi xoa la: ";
					Processtree();
				}
			break;
		case 5:
			cout<<"Duyet cay NPTK theo LNR: ";
			DuyetLNR(root);
			cout<<endl;
			break;
		case 6:
			cout<<"Duyet cay NPTK theo LRN: ";
			DuyetLRN(root);
			cout<<endl;
			break;
		case 7:
			cout<<"Duyet cay NPTK theo NLR: ";
			DuyetNLR(root);
			cout<<endl;
			break;
		case 8:
			cout<<"Cay NPTK: ";
			Processtree();
			break;
		case 9:
			cout<<"Good bye....!!!!! :"<<endl;
			break;
		default:
			break;
		}
	}while(choice != 9);
	system("pause");
	return 0;
}