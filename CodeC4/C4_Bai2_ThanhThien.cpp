//Bai 2, chuong 4: CAY NHI PHAN TIM KIEM
#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 10
//Cau 2.1: Khai bao cau truc cay NPTK
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Cau 2.2: Khoi tao cay rong:
void Init()
{
	root = NULL;
}

//Cau 2.3 (Cach 2): Them mot phan tu su dung DE QUY, su dung dia chi con tro
void InsertNode (Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p -> info = x;
		p -> left = NULL;
		p -> right = NULL;
	}
	else
	{
		if (p -> info == x)
			return; //đã có node giá tri x
		else if (p -> info > x)
			return InsertNode(p -> left, x);
		else
			return InsertNode(p -> right, x);
	}
}

//Cau 2.4: Tim mot phan tu ko dung DE QUY
Node *Search (Node *p, int x)
{
	while (p != NULL)
	{
		if (p -> info == x)
			return p;
		else
			if (x > p -> info)
				p=p->right;
			else
				p=p->left;
	}
	return NULL;
}

//Cau 2.5: Xoa mot nut trong cay dung DE QUY
void SearchStandFor (Node *&p, Node *&q)
{
	if (q -> left == NULL)
	{
		p -> info = q -> info;
		p = q;
		q = q -> right;
	}
	else
		SearchStandFor(p, q -> left);
}

int Delete (Node *&T, int x)
{
	if (T == NULL) return 0;
	if (T -> info == x)
	{
		Node *p = T;
		if (T -> left == NULL) //Bac 1
			T = T -> right;
		else if (T -> right == NULL) //Bac 1
			T = T -> left;
		else //có 2 con
			SearchStandFor(p, T -> right);
		delete p;
		return 1;
	}
	if (T -> info < x) return Delete(T -> right, x); 
	if (T -> info > x) return Delete(T -> left, x); 
}
// Khai bao cau truc Stack
struct Node_Stack
{
	int info;
	Node_Stack *link;
};

Node_Stack *sp;

// Khoi tao Stack rong
void Init_Stack_Empty()
{
	sp = NULL;
}

// Them mot phan tu vao Stack
void Push(int x)
{
	Node_Stack *p = new Node_Stack;
	p->info = x;
	p->link = sp;
	sp = p;
}

// Lay mot phan tu ra khoi Stack
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node_Stack *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// Duyet cay theo tu tu LNR (dung Stack)
void Process_LNR(Node *p)
{
	if (p != NULL)
	{
		Process_LNR(p->right);
		Push(p->info);
		Process_LNR(p->left);
	}
}

// Duyet cay theo tu tu LRN (dung Stack)
void Process_LRN(Node *p)
{
	if (p != NULL)
	{
		Push(p->info);
		Process_LNR(p->right);
		Process_LNR(p->left);
	}
}

// Duyet cay theo tu tu NLR (dung Stack)
void Process_NLR(Node *p)
{
	if (p != NULL)
	{
		Process_LNR(p->right);
		Process_LNR(p->left);
		Push(p->info);
	}
}

// DUYET CAY NHI PHAN
void print2DUtill(Node *p, int space)
{
	//BASE CASE
	if (p == NULL)
		return;

	//INCREASE DISTANCE BETWEEN LEVELS
	space = space + COUNT;

	//PROCESS RIGHT CHILD FIRST;
	print2DUtill(p->right, space);

	//PRINT CURRENT NODE AFTER SPACE
	//COUNT
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;

	//PROCESS LEFT CHILD
	print2DUtill(p->left, space);
}

void Process_Tree()
{
	//PASS INITIAL SPACE COUNT AS 0
	print2DUtill(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << " -------- BAI TAP 1, CHUONG 4, CAY NHI PHAN TIM KIEM --------" << endl;
	cout << "1. Khoi tao CAY NPTK rong " << endl;
	cout << "2. Them phan tu vao CAY NPTK " << endl;
	cout << "3. Tim phan tu co gia tri x trong CAY NPTK " << endl;
	cout << "4. Xoa phan tu co gia tri x trong CAY NPTK " << endl;
	cout << "5. Duyet cay NPTK theo LNR " << endl;
	cout << "6. Duyet cay NPTK theo NLR " << endl;
	cout << "7. Duyet cay NPTK theo LRN " << endl;
	cout << "8. Xuat CAY NPTK " << endl;
	cout << "9. Thoat " << endl;

	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;

		switch(choice)
		{	
			case 1:
				Init();
				cout << "Ban vua khoi tao CAY NPTK thanh cong!\n";
				break;

			case 2:
				cout << "Vui long nhap gia tri x can them: ";
				cin >> x;
				InsertNode(root, x);
				cout << "Cay NPTK sau khi them la: ";
				Process_Tree();
				break;

			case 3:
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				p = Search(root, x);
				if (p != NULL)
					cout << "Tim thay x = " << x << " trong CAY NPTK" << endl;
				else
					cout << "Khong tim thay x = " << x << " trong CAY NPTK" << endl;
				break;

			case 4:
				cout << "Vui long nhap gia tri x can xoa: ";
				cin >> x;
				i = Delete(root, x);
				if (i == 0)
					cout << "Khong tim thay x = " << x << " trong CAY NPTK" << endl;
				else
				{
					cout << "Da xoa thanh cong phan tu x = " << x << " trong CAY NPTK" << endl;
					cout << "CAY NPTK sau khi xoa la: ";
					Process_Tree();
				}
				break;

			case 5:
				cout << "CAY NPTK duyet theo LNR la: ";
				Process_LNR(root);
				while (sp != NULL)
				{
					Pop(x);
					cout << x << "\t";
				}
				cout << endl << endl;
				break;
				
			case 6:
				cout << "CAY NPTK duyet theo NLR la: ";
				Process_NLR(root);
				while (sp != NULL)
				{
					Pop(x);
					cout << x << "\t";
				}
				cout << endl << endl;
				break;

			case 7:
				cout << "CAY NPTK duyet theo LRN la: ";
				Process_LRN(root);
				while (sp != NULL)
				{
					Pop(x);
					cout << x << "\t";
				}
				cout << endl << endl;
				break;

			case 8:
				cout << "CAY NPTK nhu sau: ";
				Process_Tree();
				break;

			case 9: 
				cout << "\nGoodbye!" <<endl;
				break;
			default:
				break;
		}

	}while (choice != 9);
	system ("pause");
	return 0;
}