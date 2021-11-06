#include<bits/stdc++.h>

using namespace std;

class khen
{
protected:
	char hoTen[30];
	char boPhan[30];
public:
	void nhap();
	void xuat();
};
void khen::nhap()
{
	cout<<"Nhap ho va ten : ";fflush(stdin);gets(hoTen);
	cout<<"Nhap bo phan: ";fflush(stdin);gets(boPhan); 
}
void khen::xuat()
{
	cout<<hoTen<<"\t"<<boPhan;
}

class SinhVien: public khen
{ 
	float DTB;
public: 
	void nhap();
	void xuat();
	friend void DSkhen(SinhVien *a, int n);
};
void SinhVien::nhap()
{
	khen::nhap();
	cout<<"Nhap diem trung binh: ";cin>>DTB;
}
void SinhVien::xuat()
{
	khen::xuat();
	cout<<"\t"<<DTB<<endl;
}

class GV: public khen
{ 
	int CTNC;
public: 
	void nhap();
	void xuat(); 
	friend void DSkhen1(GV *b, int m);
};
void GV::nhap()
{
	khen::nhap();
	cout<<"Nhap so cong trinh nghien cuu: ";cin>>CTNC;
}
void GV::xuat()
{
	khen::xuat();
	cout<<"\t"<<CTNC<<"\t"<<endl;
}

class QL: public khen
{ 
	char nv[5];
public: 
	void nhap();
	void xuat(); 
	friend void DSkhen2(QL *c, int k);
};
void QL::nhap()
{
	khen::nhap();
	cout<<"Co hoan thanh tot cong viec duoc giao khong: ";fflush(stdin);gets(nv); 
	
}
void QL::xuat()
{
	khen::xuat();
	cout<<"\t"<<nv<<"\t"<<endl;
}
void DSkhen(SinhVien *a, int n)
{
	cout<<" Sinh vien: "<<endl;
    for(int i=0;i<n;i++)
    {
    	if(a[i].DTB >8)
        a[i].xuat();
	}
}
void DSkhen1(GV *b, int m)
{
	cout<<" Giang vien: "<<endl;
	for(int i=0;i<m;i++)
    {
    	if(b[i].CTNC >=2)
        b[i].xuat();
	}
}
void DSkhen2(QL *c, int k)
{
	cout<<" Nguoi quan ly: "<<endl;
	for(int i=0;i<k;i++)
	{
		if(strcmp(c[i].nv ,"co")==0)
		c[i].xuat();
	}

}

int main()
{
	
	SinhVien *a;
	int n;
	cout<<"Nhap so luong Sinh vien: ";cin>>n;
	a= new SinhVien[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap thong tin Sinh vien thu "<<i+1<<endl;
		a[i].nhap();
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Thong tin Sinh vien thu: "<<i+1<<"----"<<endl;
		a[i].xuat();
	}
	
	GV *b;
	int m;
	cout<<"Nhap so luong Giang vien: ";cin>>m;
	b= new GV[m];
	for(int i=0;i<m;i++)
	{
		cout<<"Nhap thong tin Giang vien thu "<<i+1<<endl;
		b[i].nhap();
	}
	for(int i=0;i<m;i++)
	{
		cout<<"Thong tin Giang vien thu: "<<i+1<<"----"<<endl;
		b[i].xuat();
	}
	
	QL *c;
	int k;
	cout<<"Nhap so luong Nguoi quan ly: ";cin>>k;
	c= new QL[k];
	for(int i=0;i<k;i++)
	{
		cout<<"Nhap thong tin Nguoi quan ly thu "<<i+1<<endl;
		c[i].nhap();
	}
	for(int i=0;i<k;i++)
	{
		cout<<"Thong tin Nguoi quan ly thu: "<<i+1<<"----"<<endl;
		c[i].xuat();
	}
	cout<<"========== DANH SACH KHEN THUONG ==========="<<endl;
	DSkhen(a,n);
	DSkhen1(b,m);
	DSkhen2(c,k);
}









