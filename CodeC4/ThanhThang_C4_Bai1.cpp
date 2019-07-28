//#include<stdio.h>
//#include<iostream>
//using namespace std;
//
//#define COUNT 10
////Cau 1.1: Khai bao cau truc cay NPTK
//struct Node {
//	int info;
//	Node *left;
//	Node *right;
//};
//Node *root;
//
////Cau 1.2: Khoi tao cay rong
//void Init()
//{
//	root= NULL;
//}
//
////Cau 1.3: Them 1 phan tu su dung de quy,
////Khong su dung dia chi con tro
//int Insert_Node_Recursive(int x,Node *q)
//{
//	if(q->info==x)
//		return 0;
//	else if(q->info > x)
//	{
//		if(q->left == NULL)
//		{
//			Node *p= new Node;
//			p->info = x;
//			p->left = NULL;
//			p->right = NULL;
//			q->left = p;
//			return 1;
//		}
//		else
//			return Insert_Node_Recursive(x,q->left);
//	}
//	else
//	{
//		if(q->right == NULL)
//		{
//			Node *p= new Node;
//			p->info = x;
//			p->left = NULL;
//			p->right = NULL;
//			q->right = p;
//			return 1;
//		}
//		else
//			return Insert_Node_Recursive(x,q->right);
//	}
//}
////Cau 1.3: Them 1 phan tu su dung de quy
////Su dung dia chgi con tro
//void InsertNode(Node *&p,int x)
//{
//	if(p == NULL)
//	{
//		p= new Node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if(p->info == x)
//			return;//daco node co gia tri x
//		else if(p->info > x)
//			return InsertNode(p->left,x);
//		else
//			return InsertNode(p->right,x);
//	}
//}
////Cau 1.4: tim 1 phan tu bang de quy
//Node *Search(Node *p,int x)
//{
//	if(p!=NULL)
//	{
//		if(p->info ==x)
//			return p;
//		else
//			if(x > p->info)
//				return Search(p->right, x);
//			else
//				return Search(p->right, x);
//	}
//	return NULL;
//}
////Cau 1.5: Xoa mot nut trong cay dung de quy
//void SearchStandFor (Node *&p, Node*&q)
//{
//	if(q->left == NULL)
//	{
//		p->info =q->info;
//		p=q;
//		q = q->right;
//	}
//	else
//		SearchStandFor(p,q->left);
//}
//
//int Delete(Node *&T, int x)
//{
//	if(T==NULL) return 0;
//	if(T->info == x)
//	{
//		Node *p=T;
//		if(T->left==NULL)//bac 1
//			T=T->right;
//		else if(T->right == NULL)//bac 1
//			T = T->left;
//		else// co 2 con
//			SearchStandFor(p,T->right);
//		delete p;
//		return 1;
//	}
//	if(T->info < x) return Delete(T->right,x);
//	if(T->info > x) return Delete(T->left,x);
//}
////Cau 1.6: Duyet cay theo NLR dung de quy
//void DuyetLNR(Node *p)
//{
//	if(p != NULL)
//	{
//		DuyetLNR(p->left);
//		cout<<p->info<<" ";
//		DuyetLNR(p->right);
//	}
//}
////Cau 1.7: Duyet cay theo LNR dung de quy
//void DuyetNLR(Node *p)
//{
//	if(p != NULL)
//	{
//		cout<<p->info<<" ";
//		DuyetNLR(p->left);
//		DuyetNLR(p->right);
//	}
//}
////Cau 1.8: Duyet cay theo LRN dung de quy
//void DuyetLRN(Node *p)
//{
//	if(p != NULL)
//	{
//		DuyetLRN(p->left);
//		DuyetLRN(p->right);
//		cout<<p->info<<" ";
//
//	}
//}
//
//void print2DUtil(Node *p, int space)
//{
//	//base case
//	if(p==NULL)
//		return;
//	//Increase distance between levels
//	space += COUNT;
//	//process right child first
//	print2DUtil(p->right,space);
//	//print current node after space
//	//count
//	cout<<endl;
//	for(int i = COUNT;i < space;i++)
//		cout<<" ";
//	cout<<p->info<<"\n";
//	//process left child
//	print2DUtil(p->left,space);
//}
//
////wrapper over print2DUtil()
//void process_tree()
//{
//	//pass initial space count as 0
//	print2DUtil(root,0);
//}
//
//int main()
//{
//	int choice=0;
//	int x,i;
//	Node *p;
//	system("cls");
//	cout<<"------- BAI TAP 1, CHUONG 4, CAY NPTK------"<<endl;
//	cout<<"1.Khoi tao cay NPTK rong"<<endl;
//	cout<<"2.Them phan tu vao cay NPTK"<<endl;
//	cout<<"3.Tim phan tu co gia tri x trong cay NPTK"<<endl;
//	cout<<"4.Xoa phan tu co gia tri x trong cay NPTK"<<endl;
//	cout<<"5.Duyet cay NPTK theo LNR"<<endl;
//	cout<<"6.Duyet cay NPTK theo NLR"<<endl;
//	cout<<"7.Duyet cay NPTK theo LRN"<<endl;
//	cout<<"8.Xuat cay NPTK"<<endl;
//	cout<<"9.Thoat"<<endl;
//	do
//	{
//		cout<<"\nVui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			Init();
//			cout<<"Khoi tao cay NPTK thanh cong\n";
//			break;	
//		case 2:
//			cout<<"Vui long nhap gia tri x can them: ";
//			cin>>x;
//			InsertNode(root,x);
//			cout<<"Cay NPTK sau khi them la: ";
//			process_tree();
//			break;
//		case 3:
//			cout<<"Vui long nhap gia tri x can tim: ";
//			cin>>x;
//			p = Search(root,x);
//			if(p!=NULL)
//				cout<<"Tim thay x="<<x<<"trong cay NPTK"<<endl;
//			break;
//		case 4:
//			cout<<"Vui long nhap gia tri x can xoa: ";
//			cin>>x;
//			i=Delete(root,x);
//				if(i==0)
//				cout<<"Khong tim thay x="<<x<<"trong cay NPTK de xoa"<<endl;
//				else
//				{
//					cout<<"da xoa thanh cong phan tu x="<<x<<"trong cay NPTK";
//					cout<<"cay NPTK sau khi xoa la: ";
//					process_tree();
//				}
//				break;
//		case 5:
//			cout<<"Cay NPTK duyet theo LNR la: ";
//			DuyetLNR(root);
//			break;
//		case 6:
//			cout<<"Cay NPTK duyet theo NLR la: ";
//			DuyetNLR(root);
//			break;
//		case 7:
//			cout<<"Cay NPTK duyet theo LRN la: ";
//			DuyetLRN(root);
//			break;
//		case 8:
//			cout<<"Cay NPTK nhu sau: ";
//			process_tree();
//			break;
//		case 9:
//			cout<<"GOODBYE.......!"<<endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice!=9);
//	system("pause");
//	return 0;
//}