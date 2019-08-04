#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 20

struct node{
	int info;
	node *link;
};
node *first[MAX];
int n;
char vertex[MAX];

node* sp;
node *front, *rear;

//STACK
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}
void pushS(int x)
{
	node *p = new node;
	p->info = x;
	p-> link = sp;
	sp = p;
}
int popS(int &x)
{
	if(sp != NULL)
	{
		node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//end STACK

//QUEUE
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front  = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int &x)
{
	if(front !=NULL)
	{
		node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//end QUEUE	

void initGraph()
{
	n = 0;
}

void insertLast(node *&first, node *p)
{
	if(first == NULL)
		first = p;
	else
	{
		node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("danhsachke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i = 0; i<n; i++)
		{
			myfile >> vertex[i];
		}
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >>u)
			{
				//Dinh u
				node* p = new node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i-1], p);
			}
			i++;
		}
	}
}
void inputGraph()
{
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for(int i = 0; i<n; i++)
	{
		cin>>vertex[i];
	}
	for(int i = 0; i<n+1; i++)
	{
		if(i>0)
			cout<<"Nhap DSK cua dinh thu: "<<i-1<<" ("<<vertex[i-1]<<") : ";
		int u;
		string str;
		while(getline(cin, str))
		{
			istringstream ss(str);
			while(ss >>u)
			{
				//Dinh u
				node* p = new node;
				p->info = u;
				p->link = NULL;
				insertLast(first[i-1], p);
			}
			break;
		}
	}
}

void outputGraph()
{
	for(int i = 0; i<n; i++)
	{
		cout<<"Dinh "<<i<<" ("<<vertex[i]<<") : ";
		node *p = first[i];
		while(p!= NULL)
		{
			cout<<p->info<<"   ";
			p = p->link;
		}
		cout<<endl;
	}
}
void output(int a[], int n)
{
	for(int i = 0; i<n; i++)
		cout<<vertex[a[i]]<<"   ";
	cout<<endl;
}

//BFS
int c[100], bfs[100];
int nbfs = 0;
void initC()
{
	for(int i= 0; i<n; i++)
		c[i] = 1;
}
void BFS(int v)
{
	int p;
	node *w;
	pushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while(w!= NULL)
		{
			if(c[w->info])
			{
				pushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int u = s;
	node* v = NULL;
	while(isEmptyS() ==0)
	{
		if(v == NULL)
			popS(u);
		v = first[u];
		while(v!=NULL)
		{
			if(c[v->info] == 1)
			{
				pushS(u);
				pushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				c[v->info] = 0;
				u = v->info;
				break;
			}
			v= v->link;
		}
	}
}
void search_by_BFS(int x, int v)
{
	int p;
	node *w;
	pushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		if(x==p)
		{
			cout<<"tim thay x= "<<x<<endl;
			return;
		}
		w = first[p];
		while(w!=NULL)
		{
			if(c[w->info])
			{
				pushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout<<"---------------BAI TAP CHUONG 5, BAI 5-----------------"<<endl;
	cout<<"1. Khoi tao DANH SACH KE rong"<<endl;
	cout<<"2. Nhap DANH SACH KE tu file text"<<endl;
	cout<<"3. Nhap DANH SACH KE"<<endl;
	cout<<"4. Xuat DANH SACH KE"<<endl;
	cout<<"5. Duyet do thi theo chieu rong BFS - DSLK"<<endl;
	cout<<"6. Duyet do thi theo chieu rong DFS - DSLK"<<endl;
	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
	cout<<"8. Thoat"<<endl;
	do{
		cout<<"Chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout<<"Khoi tao DANH SACH KE rong thanh cong "<<endl;
			break;
		case 2:
			inputGraphFromText();
			cout<<"Nhap DANH SACH KE tu file text thanh cong "<<endl;
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout<<"Nhap dinh xuat phat: ";
			cin>>x;
			nbfs = 0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet la: ";
			output(bfs, n);
			break;
		case 6:
			initStack();
			initC();
			cout<<"Nhap dinh xuat phat: ";
			cin>>x;
			ndfs = 0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet la: ";
			output(dfs, n);
			break;
		case 7:
			initQueue();
			initC();
			nbfs = 0;
			cout<<"Nhap gia tri x: ";
			cin>>x;
			search_by_BFS(x, 0);
			break;
		case 8:
			cout<<"GOODBYE...!!!!"<<endl;
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}