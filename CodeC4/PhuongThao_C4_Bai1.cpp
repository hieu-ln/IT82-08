// Bai 1, chuong 4: CAY NHI PHAN TIM KIEM
#include <iostream>
using namespace std;
 
#define COUNT 8

// Cau 1.1: khai bao cau truc cay NPTK
 struct Node
 {
	 int info; // luu gia tri cua phan tu
	 Node *left; // luu phan tu dia chi ben trai cua cay
	 Node *right; // luu phan tu ben phai cua cay
 };
 
 Node *root;
 // cau 1.2: khoi tao cay rong
 void Init()
 {
	 root = NULL;
 }
 // cau 1.3: Them mot phan tu su dung de quy
 // khong su dung dia chi con tro
 int Insert_Node_Recursive ( int x, Node *q)
 {
	 if ( q-> info ==x)
		 return 0;
	 else if ( q-> info >x )
	 {
		 if (q-> left==NULL) 
		 {
			 Node *p = new Node;
			 p->info= x;
			 p->left = NULL;
			 p->right = NULL;
			 q->left = p;
			 return 1;
	 }
		 else 
			 return Insert_Node_Recursive (x, q->left);
 }
	 else
	 {
		 
		 if (q-> right==NULL) 
		 {
			 Node *p = new Node;
			 p->info= x;
			 p->left = NULL;
			 p->right = NULL;
			 q->right= p;
			 return 1;
		 }
		 else 
			 return Insert_Node_Recursive (x, q->right);
	 }
 }
// cau 1.3: Them mot phan tu su dung de quy
 // su dung dia chi con tro
void insert_node ( Node *&p, int x)
{
	if ( p==NULL) // chay den khi nao gap node cuoi trong cay
	{
		p= new Node;
		p->info = x;
		p-> left =NULL;
		p-> right =NULL;

	}
	else
	{
		if ( p->info==x)
			return; // da co node x trong cay
		else
			if (p->info > x)
				return insert_node ( p->left ,x);
			else
				return insert_node ( p->right ,x);
	}
}
// cau 1.4 tim mot phan tu dung de quy
Node *Search ( Node*p, int x)
{
	if (p!=NULL)
	{
		if (p->info==x)
			return p;
		else
			if ( x>p -> info)
				return Search ( p->right , x);
			else
				return Search (p->left, x);
	}
	return NULL;
}
// cau 1.5 xoa mot nut trong cay dung de quy
void SearchStandFor ( Node *&p, Node*&q)
{
	if (q->left ==NULL)
	{
		p->info =q-> info;
		p=q;
		q= q->right;
	}
	else
		SearchStandFor (p, q-> left);
}
int Delete (Node *&T, int x)
{
	if (T==NULL) return 0;
	if (T->info==x)
	{
		Node *p= T;
		if (T-> left == NULL) // bac 1
			T= T-> right;
		else if (T-> right == NULL) // bac 1
			T= T-> left;
		else // co 2 con
			SearchStandFor (p, T->right);
		delete p;
		return 1;
	}
	else if (T->info <x)
		return Delete (T->right ,x );
	else
		return Delete (T->left, x);
		 
}
// cau 1.6 duyet cay theo LNR dung de quy
void DuyetLNR ( Node *p)
{
	if (p!= NULL)
	{
		DuyetLNR (p->left );
		cout << p->info << " ";
		DuyetLNR (p->right);
	}
}
// cau 1.7: duyet cay thao NLR dung de quy
void DuyetNLR (Node *p)
{
	
	if (p!= NULL)
	{
		DuyetNLR (p->left);
		cout << p-> info<< " ";
		DuyetNLR  ( p->right);
	}
}
// cau 1.8: duyet cay theo thu tu LRN dung de quy
void DuyetLRN (Node *p)
{
		if ( p!= NULL) 
		{
			DuyetLRN (p->left);
			DuyetLRN ( p->right);
			cout << p->info << " ";
		}

}
// Ham dung de xuat cay nhi phan
void  print2DUtil  (Node *p , int space)
{
	// base case
	if (p== NULL)
		return;
		// increase distance between levels
	space += COUNT;
	// Process right child first
	print2DUtil (p->right, space);
	// Print current node after space
	// count
	cout << endl;
	for ( int i= COUNT ; i<space ; i++)
		cout << " ";
	cout << p->info << " ";
	// Process left child
	print2DUtil (p->left, space);					
}
// Wrapper over print2DUtil
void Process_Tree()
{
	// Pass initial space cout as 0
	print2DUtil (root,0);
}
int main()
{
	int choice =0;
	int x, i;
	Node *p;
	system ("cls");
	cout << " ------ BAI TAP 1, CHUONG 4, CAY NPTK ---------" << endl;
	cout << "1. Khoi tao CAY NPTK rong " << endl;
	cout << "2. Them phan tu vao CAY NPTK " << endl;
	cout << "3. Tim phan tu co gia tri x trong CAY NPTK " << endl;
	cout << "4. Xoa phan tu co gia tri x trong CAY NPTK " << endl;
	cout << "5. Duyet CAY NPTK theo  LNR " << endl;
	cout << "6. Duyet CAY NPTK theo  NLR " << endl;
	cout << "7. Duyet CAY NPTK theo  LRN " << endl;
	cout << "8. Xuat CAY NPTK " << endl;
	cout << "9. Thoat" << endl;
	do
	{
		cout << "\n Vui long chon so de thuc hien: ";
		cin>> choice;
		switch ( choice)
		{
		case 1:
			Init ();
			cout << " Ban vua khoi tao CAY NPTK thanh cong! \n ";
			break;
		case 2:
			cout << " Vui long nhap gia tri x can them : ";
			cin >>x;
			insert_node (root, x);
			cout << " CAY NPKT sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << " Vui long nhap gia tri x can tim ";
			cin >>x;
			p = Search (root,x);
			if( p!=NULL)
				cout << " Tim thay x =" << x<< " trong CAY NPTK " << endl;
			break;
		case 4:
			cout << " Vui long nhap gia tri x can xoa ";
			cin >>x;
			i = Delete (root,x);
			if( i==0)
				cout << " Khong tim thay x =" << x<< " de xoa! " << x<<  endl;
			else
			{
				cout << " Da xoa thanh cong phan tu x =" << x<< " trong cay NPTK " << x<<  endl;
				cout << " CAY NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << " Cay NPTK duyet theo LNR la: ";
			DuyetLNR (root);
			break;
		case 6:
			cout << " Cay NPTK duyet theo NLR la: ";
			DuyetNLR (root);
			break;
		case 7:
			cout << " Cay NPTK duyet theo LRN la: ";
			DuyetLRN (root);
			break;
		case 8:
			cout << " Cay NPTL nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << " Goodbye.....! " << endl;
			break;
		default:
				break;
		}
	} while(choice !=9);
	system("pause");
	return 0;
}