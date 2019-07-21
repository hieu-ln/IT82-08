//# include <iostream>
//# define MAX 100
//using namespace std;
//int a[MAX], n;
//void Nhap(int a[], int &n)
//{
//    cout<<"Nhap so phan tu: ";
//    cin>>n;
//    for( int i = 0; i < n; i++)
//    {
//        cout<<"a["<<i<<"] = ";
//        cin>>a[i];
//    }
//}
//void Xuat(int a[], int n)
//{
//    for(int i = 0; i < n; i++)
//    {
//        cout<<a[i]<<"\t"; 
//    }
//    cout<<endl;
//}
//void Tim(int a[], int n, int x)
//{
//    int i = 0;
//    while(i < n && a[i] != x)
//        i++;
//    if(i < n)
//        cout<<"Tim thay tai vi tri i = "<<i<<endl;
//    else
//        cout<<"Khong tim thay!!!"<<endl;
//}
//int Themcuoi(int a[], int& n, int x)
//{
//    if( n < MAX)
//    {
//        a[n] = x;
//		n++;
//        return 1;
//    }
//    else
//        return 0;
//}
//int Xoacuoi(int a[], int &n)
//{
//    if( n > 0)
//    {
//        n--;
//        return 1;
//    }
//    else
//        return 0;
//}
////Xóa phần tử tại ví trí thứ i
//int Xoa(int a[], int& n, int x)
//{
//    if(n > 0)
//	{
//        for(int i = x; i<n; i++)
//        {
//            a[i] = a[i+1];
//        }
//        n--;
//        return 1;
//    }
//    else
//        return 0;
//}
////Tìm và xóa 1 phần tử trong danh sách
//int Timvaxoa(int a[], int& n, int x)
//{
//    for(int i = 0; i<n; i++)
//    {
//        if(a[i] == x)
//		{
//			Xoa(a,n,i);
//			return 1;
//		}
//    }
//	return 0;
//}
//int main()
//{
//    int chon, x, n;
//    system("cls");
//    cout<<"**********BAI THUC HANH 1 - CHUONG 2*************"<<endl;
//    cout<<"1. Nhap danh sach"<<endl;
//    cout<<"2. Xuat danh sach"<<endl;
//    cout<<"3. Tim mot phan tu trong danh sach"<<endl;
//    cout<<"4. Them mot phan tu vao cuoi danh sach"<<endl;
//    cout<<"5. Xoa 1 phan tu cuoi danh sach"<<endl;
//    cout<<"6. Xoa phan tu o vi tri X"<<endl;
//    cout<<"7. Tim va xoa mot phan tu trong danh sach"<<endl;
//    cout<<"8. Thoat"<<endl;
//    do
//    {
//        cout<<"Chon so de thuc hien thao tac: ";
//        cin>>chon;
//        switch(chon)
//        {
//            case 1:
//                Nhap(a, n);
//                break;
//            case 2:
//                Xuat(a, n);
//                break;
//            case 3:
//                cout<<"Nhap phan tu can tim: ";
//                cin>>x;
//                Tim(a, n, x);
//                break;
//            case 4:
//                cout<<"Nhap phan tu can them: ";
//                cin>>x;
//                if(Themcuoi(a, n, x) == 1)
//                {
//                    cout<<"Danh sach sau khi them la: ";
//                    Xuat(a, n);
//                }
//                else
//                    cout<<"Khong the them!!!";
//                break;
//            case 5:
//                if(Xoacuoi(a, n) == 1)
//                {
//                    cout<<"Danh sach sau khi xoa la: ";
//                    Xuat(a, n);
//                }
//                else
//                    cout<<"Khong the xoa!!!";
//                break;
//            case 6:
//                cout<<"Nhap vi tri phan tu can xoa: ";
//                cin>>x;
//                if(Xoa(a, n, x) == 1)
//                {
//                    cout<<"Danh sach sau khi xoa la: ";
//                    Xuat(a, n);
//                }
//                else
//                    cout<<"Khong the xoa!!!";
//                break;
//            case 7:
//                cout<<"Nhap gia tri phan tu can xoa: ";
//                cin>>x;
//                if(Timvaxoa(a, n, x) == 1)
//                {
//                    cout<<"Danh sach sau khi xoa la: ";
//                    Xuat(a, n);
//                }
//                else
//                    cout<<"Khong the xoa!!!"<<endl;
//                break;
//            case 8:
//                cout<<"GOOD BYE !!!"<<endl;
//                break;
//            default:
//                cout<<"Lenh chon khong hop le, moi chon lai!!!"<<endl;
//                break;
//        }
//    }while(chon!=8);
//    system("pause");
//    return 0;
//}