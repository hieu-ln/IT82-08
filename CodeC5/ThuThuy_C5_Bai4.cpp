#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int a[MAX][MAX]; //mang 2 chieu
int n; //so dinh cua do thi
char vertex[MAX]; //ten dinh

// DSLK
struct node
{
	int info;
	node* link;
};
node *sp;
node *front, *rear;

//STaCK
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void pushS(int x)
{
	node *p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int &x)
{
	if(sp!= NULL)
	{
		node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
// end STACK

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
	{
		front = p;
	}
	else
		rear->link=p;
	rear = p;
}
int popQ(int &x)
{
	if(front != NULL)
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

//MA TRAN KE
void initGraph()
{
	n = 0;
}

// Nhap ma tran ke tu file co san
void inputGraphFromText()
{
	string line;
	ifstream file ("matranke1.txt");
	if(file.is_open())
	{
		file>>n;
		for(int i = 0; i<n; i++)
			file>>vertex[i];
		for(int i = 0; i< n; i++)
			for(int j = 0; j< n; j++)
				file>>a[i][j];
	/*	file.close();*/
	}
}

//Nhap ma tran ke tu ban phim
void inputGraph()
{
	cout<<"Nhap so dinh cua ma tran: ";
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cout<<"Nhap ten dinh: ";
		cin>>vertex[i];
		cout<<"Nhap vao dong thu "<<i+1<<" : ";
		for(int j = 0; j<n; j++)
			cin>>a[i][j];
	}
}

//Xuat ma tran ke
void outputGraph()
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j < n; j++)
			cout<<a[i][j]<<"   ";
		cout<<endl;
	}
}

void output(int a[], int n)
{
	for(int i = 0; i< n; i++)
		cout<<vertex[a[i]]<<"	";
}

//Duyet do thi theo BFS
int c[100], bfs[100];
int nbfs = 0;
void init()
{
	for(int i = 0; i<n; i++)
		c[i] = 1;
}
void BFS(int v) // v la dinh bat dau
{
	int w, p;
	pushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w<n; w++)
			if(c[w] && a[p][w] == 1)
			{
				pushQ(w);
				c[w] = 0;
			}
	}
}

//Duyet DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while(isEmptyS() == 0)
	{
		if(v == n)
			popS(u);
		for(v = 0; v<n; v++)
			if(a[u][v] != 0 && c[v] == 1)
			{
				pushS(u);
				pushS(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				v = v;
				break;
			}
	}
}

//Dung BFS tim kiem tren do thi
void searchByBFS(int x, int v)//v la dinh bat dau
{
	int w, p;
	pushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		if(x==p)
		{
			cout<<"Tim thay "<<x<<endl;
			return;
		}
		for(w = 0; w<n; w++)
			if(c[w] && a[p][w] == 1)
			{
				pushQ(w);
				c[w] = 0;
			}
	}
}

int main()
{
	int choice, x;
	system("cls");
	cout<<"---------------Bai tap 4, Chuong 5, Do thi---------------"<<endl;
	cout<<"1. Khoi tao ma tran ke rong"<<endl;
	cout<<"2. Nhap ma tran ke tu file co san"<<endl;
	cout<<"3. Nhap ma tran ke tu ban phim"<<endl;
	cout<<"4. Xuat ma tran ke"<<endl;
	cout<<"5. Duyet do thi theo BFS"<<endl;
	cout<<"6. Duyet do thi theo DFS"<<endl;
	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
	cout<<"8. Thoat"<<endl;
	do
	{
		cout<<"Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout<<"Khoi tao ma tran ke rong thanh cong...!!!"<<endl;
			break;
		case 2:
			inputGraphFromText();
			cout<<"Nhap ma tran ke tu file thanh cong...!!!"<<endl;
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			cout<<"Ma tran ke: "<<endl;
			outputGraph();
			break;
		case 5:
			initQueue();
			init();
			cout<<"Nhap dinh xuat phat: ";
			cin>>x;
			nbfs = 0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet: "<<endl;
			output(bfs, n);
			cout<<endl;
			break;
		case 6:
			initStack();
			init();
			cout<<"Nhap dinh xuat phat: ";
			cin>>x;
			ndfs = 0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet: "<<endl;
			output(dfs, n);
			cout<<endl;
			break;
		case 7:
			cout<<"Nhap gia tri x can tim: ";
			cin>>x;
			searchByBFS(x, 0);
			break;
		case 8:
			cout<<"GOODBYE.....!!!!!"<<endl;
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}