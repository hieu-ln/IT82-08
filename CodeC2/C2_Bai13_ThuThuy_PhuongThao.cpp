#include <iostream>
using namespace std;

struct node 
{
	int sm;
	int hs;
	node *next; 
};

struct list
{
	node *head, *tail;
};


void Init (list &l)
{
	l.head = l.tail = NULL;
}


node *createNode ( int h, int s)
{
	node *p = new node;
	if( p == NULL)	
		exit(1);
	p->sm=s;
	p->hs=h;
	p->next = NULL;
	return p;
}
void  addTail( list &l, node *p)
{
	{
	if(l.head == NULL)	l.head=l.tail=p;
	else
	{
		l.tail->next=p;
		l.tail=p;
	}
	}
}

void Nhap ( list &l)
{
	int x,n;
	cout << " Bac cua da thuc: ";
	cin>> n;
	for ( int i = 0; i>=0;i--)
	{
		cout << " Nhap he so cua x^ "<<i<< ":"<< endl;
		cin >> x;
		node *p = createNode(x,i);
		addTail(l,p);
	}

}

void Cong( list &l, list l1, list l2)
{
	node *p = new node;
	node *q = new node;
	if( l1.head->sm > l2.head->sm)
	{
		l=l1;
		p=l2.head;
	}
	else
	{
	l=l2;
	p=l1.head;
	}
	q=l.head;
	while(q->sm > p->sm)
		q=q->next;
	while(q != NULL)
	{
	q->hs += p->hs;
	p=p->next;	q=q->next;
	}
} 

void Xuat( list &l )
{
	node *p = l.head;
	while( p!=l.tail)
	{
		if ( p->hs)
			cout<<p->hs << "x^" << p->sm;
			p=p->next;
		if ( p->hs)
		{
			if(p->hs > 0)	
				cout<< " + " ;
			else 
				cout<< " ";
		}
	
	}

}

int main()
{
	list l,l1,l2;
	Init(l); Init(l1); Init(l2);
	cout<< " Nhap da P(x): ";Nhap(l1);
	cout<< " Nhap da Q(x): ";Nhap(l2);
	cout<<" \nP(x) = "; Xuat(l1);
	cout<<" \nQ(x) = "; Xuat(l2);
	Cong(l,l1,l2);
	cout<<"\nR(x)  = ";Xuat(l);

	system("pause");
	return 0;
}