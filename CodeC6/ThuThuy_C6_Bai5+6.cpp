#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

//Khai bao ma tran
#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void InitGraph()
{
	n = 0;
}

void InputGraphFromText()
{
	string line;
	ifstream myfile("mtts1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i = 0; i<n; i++)
			myfile>>vertex[i];
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				myfile>>a[i][j];
	}
	else
		cout<<"Mo file khong thanh cong...!!!"<<endl;
}

//Nhap ma tran ke cua do thi
void InputGraph()
{
	cout<<"Nhap so dinh cua do thi:";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for(int i = 0; i<n; i++)
		cin>>vertex[i];
	for(int i = 0; i<n; i++)
	{
		cout<<"Nhap vao dong thu "<<i+1<<": ";
		for(int j = 0; j<n; j++)
			cin>>a[i][j];
	}
}

//Xuat ma tran ke
void OutputGraph()
{
	cout<<setw(3)<<left;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			cout<<a[i][j]<<setw(3)<<left;
		cout<<endl;
	}
}

//Khia bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;

//Khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

int TonTai(int d, int D[], int nD)
{
	for(int i = 0; i<nD; i++)
		if(D[i]==d)
			return 1;
	return 0;
}

void TaoE()
{
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			if(a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

void SapxepE()
{
	for(int i = 0; i<nE-1; i++)
		for(int j =i +1; j<nE; j++)
			if(wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}

void Kruskal()
{
		for(int i = 0; i<nE; i++)
		{
			if(TonTai(E1[i], T1, nT)==1 && TonTai(E2[i], T2, nT)==1)
							continue;
			if(TonTai(E1[i], T2, nT)==1 && TonTai(E2[i], T1, nT)==1)
				continue;
			T1[nT] = E1[i];
			T2[nT] = E2[i];
			wT[nT] = wE[i];
			nT++;
			if(nT==n-1)
				break;
		}
		
}

void Output(bool vtName)
{
	int tong = 0;
	for(int i = 0; i<nT; i++)
	{
		if(vtName)
			cout<<endl<<"("<<vertex[T1[i]]<<", "<<vertex[T2[i]]<<") = "<<wT[i] ;
		else
			cout<<endl<<"("<<T1[i]<<", "<<T2[i]<<") = "<<wT[i];
		tong+=wT[i];
	}
	cout<<"\nTong = "<<tong;
}

int main()
{
	int choice, x;
	system("cls");
	cout<<"----------------BAI TAP 4, CHUONG 6--------------"<<endl;
	cout<<"1. Khoi tao MA TRAN KE rong"<<endl;
	cout<<"2. Nhap MA TRAN KE tu file text"<<endl;
	cout<<"3. Nhap MA TRAN KE"<<endl;
	cout<<"4. Xuat MA TRAN KE"<<endl;
	cout<<"5. Tim cay khung toi thieu bang KRUSKAL"<<endl;
	cout<<"6. Thoat"<<endl;
	do
	{
		cout<<"\nChon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout<<"Khoi tao MA TRAN KE rong thanh cong"<<endl;
			break;
		case 2:
			InputGraphFromText();
			cout<<"MA TRAN KE: "<<endl;
			OutputGraph();
			break;
		case 3:
			InputGraph();
			break;
		case 4:
			OutputGraph();
			break;
		case 5:
			TaoE();
			SapxepE();
			Kruskal();
			cout<<"Cay khung toi thieu voi KRUSKAL: "<<endl;
			Output(true);
			break;
		case 6:
			cout<<"GOODBYE...!!!"<<endl;
			break;
		default:
			break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}