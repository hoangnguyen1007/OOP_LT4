#include "PhanSo.h"

int ucln(int a, int b)
{
	if (b == 0) return a;
	return ucln(b, a % b);
}
void PhanSo::rut_gon()
{
	int u = ucln(tu, mau);
	tu /= u;
	mau /= u;
}
PhanSo::PhanSo(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}
istream& operator>>(istream& is, PhanSo& x)
{
	cout << "Nhap tu so: ";
	is >> x.tu;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap tu so: ";
		is >> x.tu;
	}
	cout << "Nhap mau so: ";
	is >> x.mau;
	while (cin.fail() || x.mau == 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap mau so: ";
		is >> x.mau;
	}
	return is;
}
ostream& operator<<(ostream& os, PhanSo& x)
{
	x.rut_gon();
	if (x.tu % x.mau == 0) cout << x.tu / x.mau;
	else if (x.tu < 0 && x.mau < 0) cout << -x.tu << "/" << -x.mau;
	else if (x.tu < 0 || x.mau < 0) cout << -abs(x.tu) << "/" << abs(x.mau);
	else cout << x.tu << "/" << x.mau;
	return os;
}
PhanSo PhanSo::operator+(const PhanSo& x) 
{
	int tu = this->tu * x.mau + x.tu * this->mau;
	int mau = this->mau * x.mau;
	return PhanSo(tu, mau);
}

PhanSo PhanSo::operator-(const PhanSo& x) 
{
	int tu = this->tu * x.mau - x.tu * this->mau;
	int mau = this->mau * x.mau;
	return PhanSo(tu, mau);
}

PhanSo PhanSo::operator*(const PhanSo& x) 
{
	int tu = this->tu * x.tu;
	int mau = this->mau * x.mau;
	return PhanSo(tu, mau);
}
int PhanSo::getTu()
{
	return tu;
}
PhanSo PhanSo::operator/(const PhanSo& x) 
{
	int tu = this->tu * x.mau;
	int mau = this->mau * x.tu;
	return PhanSo(tu, mau);
}
bool operator <(const PhanSo& a, const PhanSo& b)
{
	return (double)a.tu / a.mau < (double)b.tu / a.mau;
}
bool operator >(const PhanSo& a, const PhanSo& b)
{
	return (double)a.tu / a.mau > (double)b.tu / a.mau;
}

